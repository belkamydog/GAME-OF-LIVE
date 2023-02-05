#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define ROW 20
#define COL 80
#define SPEED 100

int **create(void){
    int **arr = malloc(ROW * COL * sizeof(int) + ROW * sizeof(int*));
    int *pointer = (int *) (arr + ROW);
    for (int i = 0; i < ROW; i++){
        arr[i] = pointer + COL * i;
    }
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
                arr[i][j] = 0;
        }
    }
    return arr;
}

void output(int **arr){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            printf("%2d", arr[i][j]);
        }
        printf("\n");
    }
}

void copy(int **arr, int **new_arr){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            arr[i][j] = new_arr[i][j];
        }
    }
}
int count_neighbors(int **arr, int row_now, int col_now){
    int counter = 0;
    for (int i = row_now - 1; i <= row_now + 1; i++){
        for (int j = col_now - 1; j <= col_now + 1; j++){
            if (i >= 0 && i < ROW && j >= 0 && j < COL && arr[i][j] == 1)
                counter++;
        }
    }
    if (arr[row_now][col_now] == 1)
        counter-=1;
    return counter;
}

void extreme_situation(int row_now, int col_now) {
	
}

void action(int **arr, int **new_arr){
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            int neighbors = count_neighbors(arr, i, j);
            if (arr[i][j] == 1 && neighbors < 2){
                new_arr[i][j] = 0;
            }
            else if (neighbors > 3){
                new_arr[i][j] = 0;
            }
            else if (neighbors == 3) {
                new_arr[i][j] = 1;
            }
            else if (arr[i][j] == 1 && (neighbors == 2 || neighbors == 3)){
                new_arr[i][j] = 1;
            }
        }
    }
}

void screen(int **arr){
    for(int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++) {
            if(arr[i][j] == 0)
                printw(" ");
            else
                printw("@");
        }
        printw("\n");
    }
}

int main(void)
{   char input;
    int **arr = create();
    arr[3][10] = 1; arr[3][11] = 1; arr[3][12] = 1; arr[2][12] = 1; arr[1][11] = 1; // GLIDER
    //arr[4][10] = 1; arr[5][11] = 1; arr[5][12] = 1; arr[5][13] = 1; arr[5][14] = 1; arr[4][14] = 1; arr[3][14] = 1; arr[2][13] = 1;  // bus
    int **new_arr = create();
    stdscr = initscr();
    while (input != 'q'){
    	timeout(SPEED);
        action(arr, new_arr);
        input = wgetch(stdscr);
        clear();
       	screen(new_arr);
        copy(arr, new_arr);
        refresh();
    }
    endwin();
    free(arr);
    free(new_arr);
    return 0;
}
