/***************************************************************************
 **  The PROJECT_NAME project is a set of free, open source
 **  applications.
 **  (C) 2010-2012 by PERIKLIS KIORPES(Greece) <periklis.kiorpes@gmail.com>
 **  All rights reserved.
 **
 **  This program is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This program is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with this program (COPYING.PROJECT_NAME file).
 **  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/
/***************************************************************************
 **	 CLASS    : SudokuForm
 **  FILENAME : sudokuform.h
 **  DATE     : 29/11/2012
 **	 USER     : periklis
 ***************************************************************************/

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
