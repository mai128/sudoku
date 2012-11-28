#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku
{

public:
    Sudoku();

    void initSudoku();
    void initArray(int *array);
    int completed();
    void getRow (int index,int array[] );
    void getColumn (int index,int array[]);
    void getBlock (int ixRow,int ixColumn ,int array[] );
    int checkArray(int array[]);
    int checkSudoku();
    void showSudoku();
    void setValue(int row, int column, int value);

private:
    int mMatrix[9][9];

};

#endif // SUDOKU_H
