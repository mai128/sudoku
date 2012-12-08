#ifndef SUDOKUFORM_H
#define SUDOKUFORM_H

#include <QWidget>

class Sudoku;

namespace Ui {
class SudokuForm;
}

class SudokuForm : public QWidget
{
    Q_OBJECT

public:
    explicit SudokuForm(QWidget *parent = 0);
    ~SudokuForm();


    void setSomeValues();

    void setValueToCell(int row, int column, int value, bool bold=true);
    void savaGame(int grade);
    void saveGameItems(int gameId);
    void loadGame(int gameId);
protected:
    void mousePressEvent(QMouseEvent * event);
    void selectCellValue(int row, int column);

signals:
    void incrError();
    void startGame();
    void endGame();
private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void evaluate();
    void clear();
    void setClearSudoku();

private:
    Ui::SudokuForm *ui;
    Sudoku *mSudoku;


};

#endif // SUDOKUFORM_H
