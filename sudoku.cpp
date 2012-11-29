#include "sudoku.h"
#include <stdio.h>
//using namespace std;


Sudoku::Sudoku()
{
}


void Sudoku::initSudoku()
{
    int i;
    int j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
          mMatrix[i][j]=0;
        }
    }
}

void Sudoku::initArray(int array[])
{
    int i;
    for(i=0;i<9;i++)
    {
       array[i]=0;
    }
}

int Sudoku::completed()
{
    int i;
    int j;
    int ret;
    ret=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if( mMatrix[i][j]!=0){
                ret++;
            }
        }
    }
    return ret;
}

void Sudoku::getRow(int index, int array[])
{
    int j;
    initArray(array);
    for(j=0;j<9;j++){
        array[j]=mMatrix[index][j];
    }
}

void Sudoku::getColumn(int index, int array[])
{
    int i;
    initArray(array);
    for(i=0;i<9;i++){
        array[i]=mMatrix[i][index];
    }
}

void Sudoku::getBlock(int ixRow, int ixColumn, int array[])
{
    int i;
    int j;
    int k=0;
    initArray(array);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           array[k]=mMatrix[ixRow*3+i][ixColumn*3+j];
           k++;
        }
    }
}

int Sudoku::checkArray(int array[])
{
    int i;
    int j;
    int ret=0;
    int x;

    for(i=0;i<9-1;i++){
        if (array[i] ==0) continue;
        for(j=i+1;j<9;j++){
             if( array[i]==array[j]){
                 ret=-1;
                 return ret;
             }
        }
    }
    return ret;
}

int Sudoku::checkSudoku()
{
    int ret=0;
    int i;
    int j;
    int arr[9];
    for(i=0;i<9;i++){
        getRow (i,arr);
        ret =checkArray( arr);
        if (ret<0){
        return ret;
        }
    }
    for(j=0;j<9;j++){
        getColumn (j,arr);
        ret =checkArray( arr);
        if (ret<0){
          return ret;
        }
    }
        for(i=0;i<3;i++){
             for(j=0;j<3;j++){
                 getBlock (i,j ,arr);
                 ret =checkArray( arr);
                 if (ret<0){
                 return ret;
                 }
             }
        }

    return ret;
}


void Sudoku::showSudoku()
{
    int i;
    int j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(mMatrix[i][j]==0){
             printf("___|");
            }else{
                printf("_%d_|",mMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

void Sudoku::setValue(int row, int column, int value)
{
    mMatrix[row][column]=value;
}

