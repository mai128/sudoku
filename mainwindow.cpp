#include <QInputDialog>
#include <QString>
#include <QFile>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QMap>
#include <QTime>
#include <QTranslator>



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudokuform.h"
#include "aboutdialog.h"
#include "recordsdialog.h"


const QString DATABASE_FILE_NAME ="sudoku.sdb";


QString sqlStrGameGradesCreationQuery =
        "CREATE TABLE game_grades("
        "id INTEGER PRIMARY KEY NOT NULL,"
        "title TEXT(20) NOT NULL)";


QString sqlStrGameCreationQuery=
        "CREATE TABLE games ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "grade INTEGER NOT NULL ,"
        "FOREIGN KEY (grade) REFERENCES game_grades(id))";

QString sqlStrGameItemsCreationQuery =
        "CREATE TABLE game_items("
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL ,"
        "game_id INTEGER NOT NULL ,"
        "game_row INTEGER NOT NULL,"
        "game_column INTEGER NOT NULL,"
        "game_value  INTEGER NOT NULL,"
        "FOREIGN KEY (game_id) REFERENCES games(id))";


QString sqlStrRecordsCreationQuery =
        "CREATE TABLE records ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL ,"
        "game_id INTEGER NOT NULL ,"
        "name TEXT(40) NOT NULL ,"
        "error_count INTEGER NOT NULL ,"
        "duration INTEGER NOT NULL  )";

QString sqlGetGameCategories = "select * from game_grades";
QString sqlGetAllGames = "select * from games";
QString sqlGetAllGamesInGrade = "select * from games where grade = %1";
QString sqlInsertGameWiner  ="INSERT INTO records(game_id, name, error_count, duration) VALUES(%1, '%2', %3, %4 )";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    mApPath =QCoreApplication::applicationDirPath();
    mSudokuFileName =mApPath+"/" + DATABASE_FILE_NAME;
    mCurrentGameId=0;

    QFile sFile(mSudokuFileName);
    if(!sFile.exists())
    {
       openSudokuDb();
        createSudokuTables();
    }else{
        openSudokuDb();
    }

    ui->setupUi(this);

    errorCount=0;
    mTimeElapsed=0;
    mCurrentGameId=0;
    mCurrentGameGrade=0;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    mSudokuForm = new SudokuForm(this);
    setCentralWidget(mSudokuForm);
    statusBar()->showMessage(QString::number(0)+ " Errors");
    setWindowTitle(QString("sudoku %1").arg(mCurrentGameId));

    connect(mSudokuForm,SIGNAL(incrError()),this,SLOT(incrementErrorCount()));
    connect(mSudokuForm,SIGNAL(startGame()),this,SLOT(startTheGame()));
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionAbout,SIGNAL(triggered()),this,SLOT(about()));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newPlay()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(savePlay()));
    connect(ui->actionClear,SIGNAL(triggered()),mSudokuForm,SLOT(setClearSudoku()));
    connect(ui->actionShow_winers,SIGNAL(triggered()),this,SLOT(showWiners()));
    connect(mSudokuForm,SIGNAL(endGame()),this,SLOT(endOfGame()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::startTheGame()
{
    mStartTime=QTime::currentTime();
}

void MainWindow::endOfGame()
{
    mEndTime=QTime::currentTime();
    mTimeElapsed= mStartTime.secsTo(mEndTime);
    recordWiner();
}

void MainWindow::incrementErrorCount()
{
    errorCount++;
    statusBar()->showMessage(QString::number(errorCount)+ " Errors");
}
void MainWindow::about()
{
    AboutDialog  dlg(this);
    dlg.exec();
}

void MainWindow::newPlay()
{
    QMap <QString, int> map;

    QStringList items;

    QSqlQuery query;
    int gameId;

    query.exec(QString(sqlGetGameCategories));
    while(query.next()){
        map.insert( query.value(1).toString(),query.value(0).toInt());
         items.append(query.value(1).toString());
    }

        bool ok;
        QString item = QInputDialog::getItem(this, tr("Νεο παιγνίδι"),
                                             tr("Επίπεδο δυσκολίας:"), items, 0, false, &ok);
        if (ok && !item.isEmpty()){
            query.exec(QString(sqlGetAllGamesInGrade).arg(map[item]));
            int rowCount = getGameCount(query);
            if (rowCount ==0)return;
            int randomValue = randInt(1,rowCount);
            query.exec(QString(sqlGetAllGamesInGrade).arg(map[item]));
            while(query.next()){
                randomValue--;
                if(randomValue==0){
                gameId = query.value(0).toInt();
                mSudokuForm->loadGame(gameId);
                mCurrentGameId= gameId;
                mCurrentGameGrade=query.value(1).toInt();
                errorCount=0;
                setWindowTitle(QString("sudoku %1").arg(mCurrentGameId));
                break;
                }
            }
        }

}

void MainWindow::savePlay()
{
    QMap <QString, int> map;

    QStringList items;

    QSqlQuery query;
    int gameId;

    query.exec(QString(sqlGetGameCategories));
    while(query.next()){
        map.insert( query.value(1).toString(),query.value(0).toInt());
         items.append(query.value(1).toString());
    }

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Αποθήκευση Παιγνιδιού"),
                                         tr("Επίπεδο δυσκολίας : "), items, 0, false, &ok);
    if (ok && !item.isEmpty()){
        mSudokuForm->savaGame(map[item]);

        query.exec(QString(sqlGetAllGames));


        if(query.last()){
            gameId = query.value(0).toInt();
            mSudokuForm->saveGameItems(gameId);
            this->statusBar()->showMessage(QString::number(gameId));
        }
    }


}

void MainWindow::closeEvent(QCloseEvent *event)
{
     if (maybeClose()) {
         event->accept();
     } else {
         event->ignore();
     }
}

bool MainWindow::maybeClose()
{
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, tr("Sudoku"),
          tr("Τερματισμός εφαρμογής.\n"
          "Σίγουρα θέλετε να τερματίσετε?"),
          QMessageBox::Ok | QMessageBox::Cancel);
    if (ret == QMessageBox::Ok)
       return true;
    else if (ret == QMessageBox::Cancel)
       return false;
    return true;
}

bool MainWindow::openSudokuDb()
{
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(mSudokuFileName);
    // Open databasee
    bool ret=mDb.open();
    return ret;
}

bool MainWindow::createQuery(QString sqlStr )
{
    bool ret ;
    QSqlQuery query;
    ret = query.exec(sqlStr );
    return ret;
}
bool MainWindow::createSudokuTables()
{

    bool ret=true;

    ret =createStructure();
    if(ret){
        insertData();
    }
    return ret;
}


bool MainWindow::createStructure()
{
    bool ret;

    QFile structure_file(":/data_structure.sql");
    ret = executeSqlFromFile(structure_file );

    return ret;
}

bool MainWindow::insertData()
{
    bool ret;

    QFile data_file(":/data.sql");
    ret = executeSqlFromFile(data_file);

    return ret;
}

bool MainWindow::executeSqlFromFile(QFile &theFile )
{
    bool ret;

    if(!theFile.open(QIODevice::ReadOnly| QIODevice::Text)){
        return false;
    }

    while(!theFile.atEnd()){
        QByteArray line =theFile.readLine();
      //  QString
       ret= createQuery(tr(line));
    }
    theFile.close();
    return ret ;
}

void MainWindow::setCurrentGameId(int gameId)
{
    mCurrentGameId = gameId;
}

int MainWindow::getCurrentGameId()
{
    return mCurrentGameId;
}

int MainWindow::randInt(int low, int high)
{
    return qrand()%((high+1)-low)+low;
}

int MainWindow::getGameCount(QSqlQuery query)
{
    int ret=0;
    while (query.next()){
        ret++;
    }
    return ret;
}
void MainWindow::recordWiner()
{
    bool ok;

    QSqlQuery query;

    QString str= QString("You win in %1 seconds in sudoku  id  %2 Level %3")
            .arg(QString::number(mTimeElapsed))
            .arg(QString::number(mCurrentGameId))
            .arg(QString::number(mCurrentGameGrade));

    QString name = QInputDialog::getText(this, str,
                                         tr("Name :"), QLineEdit::Normal,
                                         "", &ok);
    if (ok && !name.isEmpty()){
        QString(sqlInsertGameWiner)
                  .arg(mCurrentGameId).arg(name).arg(errorCount).arg(mTimeElapsed);
        query.exec(QString(sqlInsertGameWiner)
             .arg(mCurrentGameId).arg(name).arg(errorCount).arg(mTimeElapsed));
    }

}

void MainWindow::showWiners()
{
    RecordsDialog *dlg = new RecordsDialog(this);
    dlg->setWindowTitle("Games and Winners");
    dlg->exec();
    delete dlg;
}

