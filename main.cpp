#include <stdio.h>
#include "sudoku.h"

int main(int argc, char * argv[])
{
   int r;
   int c;
   int value=10;

   int ret;

   Sudoku S;
   S.initSudoku();

   while(value>=0){
        system("cls");

        S.showSudoku();
        if(checkSudoku()!=0){
           printf("\nCheck for error\n");
        }else{
           printf("\n\n");
        }

        if(S.completed()==81 && S.checkSudoku()==0){
            printf("\Bravo!!!\n");
            break;
        }

        printf("\nCompleted %d of 81\n",S.completed());
        do{
        printf("\nGive row [0-8]: ");
        scanf("%d",&r);
        } while (r<0 || r>8);
        do{
        printf("\nGive Column [0-8]: ");
        scanf("%d",&c);
        } while (r<0 || c>8);
       do{
        printf("\nGive value [0-9] or -1 for exit.\nCell[%d][%d]: ",r,c);
        scanf("%d",&value);
        S.setValue(r,c,value);
        } while (value <-1 || value>9);
   }

    return 0;
}
