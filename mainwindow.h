#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QCloseEvent>
#include <QTime>
class SudokuForm;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool openSudokuDb();
    bool createSudokuTablesQuery(QString sqlStr);

    bool createSudokuTables();

    void setCurrentGameId(int gameId);
    int  getCurrentGameId();
    int randInt(int low, int high);
    int getGameCount(QSqlQuery query);

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    SudokuForm *mSudokuForm;
    QSqlDatabase mDb;
    int errorCount;

    QSqlDatabase mSudokuDb;
    QString mApPath;
    QString mSudokuFileName;
    QString mApplicationName;
    int mCurrentGameId;
    int mCurrentGameGrade;
    QTime mStartTime;
    QTime mEndTime;
    int mTimeElapsed;

private:
    bool maybeClose();
private slots:
    void startTheGame();
    void endOfGame();
    void incrementErrorCount();
    void about();
    void newPlay();
    void savePlay();
    void recordWiner();
    void showWiners();
};

#endif // MAINWINDOW_H
