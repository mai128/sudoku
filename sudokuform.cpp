#include <QDebug>
#include <QKeyEvent>
#include <QAction>
#include <QSqlQuery>

#include "sudokuform.h"
#include "ui_sudokuform.h"
#include "numberselectiondialog.h"
#include "sudoku.h"
#include "mainwindow.h"
#include<QSqlTableModel>

QString sqlInsertGame  ="INSERT INTO games(grade ) VALUES (%1)";
QString sqlInsertGameItem  ="INSERT INTO game_items (game_id,game_row, game_column, game_value) VALUES (%1,%2,%3,%4)";
QString sqlGetAllGameItemsInId = "select * from game_items where game_id =%1";

QString sqlGetAllGameItemsInGrade = "select * from games where grade = %1";
SudokuForm::SudokuForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SudokuForm)
{
    ui->setupUi(this);
    mSudoku = new Sudoku;

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            QTableWidgetItem *item =new QTableWidgetItem( QString(""));
            item->setTextAlignment(Qt::AlignCenter);
            item->setFlags(item->flags()^Qt::ItemIsEditable);
            QFont font;
            font = item->font();
            font.setPointSize(28);
            if(((i/3)+(j/3))%2==0){
                item->setBackground(Qt::lightGray);
                           }
            item->setFont(font);
            ui->tableWidget->setItem(i,j,item);
        }
    }

    ui->tableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

    QAction* evaluateAction = new  QAction("Evaluate",this);
    QAction* clearAction = new  QAction("Clear",this);
    ui->tableWidget->addAction(evaluateAction);
    ui->tableWidget->addAction(clearAction);
    connect (evaluateAction,SIGNAL(triggered()),this,SLOT(evaluate()));
    connect (clearAction,SIGNAL(triggered()),this,SLOT(clear()));
   // setSomeValues();
}


SudokuForm::~SudokuForm()
{
    delete  mSudoku ;
    delete ui;

}

void SudokuForm::mousePressEvent(QMouseEvent *event)
{
    // to do
    if(event->button()== Qt::RightButton){
       selectCellValue(ui->tableWidget->currentItem()->row(),
       ui->tableWidget->currentItem()->column()) ;
    }
}

void SudokuForm::selectCellValue(int row, int column)
{
    NumberSelectionDialog dlg( this );
    int theValue;

    QFont font;
    font = ui->tableWidget->item(row,column)->font();
    if(font.bold())return;

    if( dlg.exec() == QDialog::Accepted ){
        theValue = dlg.myValue();
        mSudoku->setValue(row,column,theValue);
        if(theValue!=0){
        ui->tableWidget->item(row,column)->setText(QString::number(theValue));
        }else{
            ui->tableWidget->item(row,column)->setText("");
        }
        if(mSudoku->checkSudoku()!=0){
          emit incrError();
        }
        if(mSudoku->completed()==81 && mSudoku->checkSudoku()==0){
            emit endGame();
        }

    }
}
void SudokuForm::on_tableWidget_cellDoubleClicked(int row, int column)
{
    selectCellValue(row, column);


}

void SudokuForm::evaluate()
{
    QFont font;
    font = ui->tableWidget->currentItem()->font();
    if(font.bold())return;

    selectCellValue(ui->tableWidget->currentItem()->row(),
    ui->tableWidget->currentItem()->column()) ;
}
void SudokuForm::clear()
{
    QFont font;
    font = ui->tableWidget->currentItem()->font();
    if(font.bold())return;

    int row =ui->tableWidget->currentItem()->row();
    int column= ui->tableWidget->currentItem()->column();
    mSudoku->setValue(row,column,0);
    ui->tableWidget->item(row,column)->setText("");

    if(mSudoku->checkSudoku()!=0){
//           ui->tableWidget->item(row,column)->setBackgroundColor(red());
      emit incrError();
    }

}
void SudokuForm::setClearSudoku()
{
     mSudoku->initSudoku();
     for(int i=0;i<ui->tableWidget->rowCount();i++){
         for(int j=0;j<ui->tableWidget->columnCount();j++){
            setValueToCell(i,j,0, false);
         }
     }
}

void SudokuForm::setSomeValues()
{

   mSudoku->initSudoku();
   setValueToCell(0, 0, 1);
   setValueToCell(0, 3, 5);
   setValueToCell(0, 4, 3);
   setValueToCell(0, 6, 4);

   setValueToCell(1, 2, 4);
   setValueToCell(1, 3, 6);

   setValueToCell(2, 0, 9);
   setValueToCell(2, 7, 7);

   setValueToCell(3, 3, 8);
   setValueToCell(3, 5, 1);
   setValueToCell(3, 7, 4);
   setValueToCell(3, 8, 5);

   setValueToCell(4, 0, 8);
   setValueToCell(4, 8, 9);

   setValueToCell(5, 0, 5);
   setValueToCell(5, 1, 2);
   setValueToCell(5, 3, 4);
   setValueToCell(5, 5, 9);

   setValueToCell(6, 1, 1);
   setValueToCell(6, 8, 3);

   //setValueToCell(7, 5, 4);
   setValueToCell(7, 6, 9);

   setValueToCell(8, 0, 2);
   setValueToCell(8, 2, 6);
   setValueToCell(8, 4, 5);
   setValueToCell(8, 5, 3);
   setValueToCell(8, 8, 1);

}


void SudokuForm::setValueToCell(int row, int column, int value, bool bold)
{
    QTableWidgetItem *item = ui->tableWidget->item(row,column);
    mSudoku->setValue(row,column,value);
    if(value==0){
        item->setText("");
    }else{
        item->setText(QString::number(value));
    }
    QFont font;
    font.setPointSize(32);
    font.setBold(bold);
    item->setFont(font);
}

void SudokuForm::savaGame(int grade)
{
    QSqlQuery query;

    query.exec(QString(sqlInsertGame).arg(grade));
}

void SudokuForm::saveGameItems(int gameId)
{
    int row[9];

    QSqlQuery query;
    for(int i=0;i<9;i++){
        mSudoku->getRow(i,row);
        for(int j=0;j<9;j++){
            if(row[j]!=0)
            query.exec(QString(sqlInsertGameItem
                 .arg(gameId).arg(i).arg(j).arg(row[j])));

        }
    }
}

void SudokuForm::loadGame(int gameId)
{
    setClearSudoku();
    QSqlQuery query;
    query.exec(QString(sqlGetAllGameItemsInId.arg(gameId)));
    while(query.next()){
        setValueToCell(query.value(2).toInt(), query.value(3).toInt(), query.value(4).toInt());
    }
    emit startGame();

}
