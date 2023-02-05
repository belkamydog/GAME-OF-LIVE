#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#define ROW 25
#define COL 80
#define SPEED 100

int **create(void) {
    int **arr = malloc(ROW * COL * sizeof(int) + ROW * sizeof(int *));
    int *pointer = (int *)(arr + ROW);
    for (int i = 0; i < ROW; i++) {
        arr[i] = pointer + COL * i;
    }
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void copy(int **arr, int **new_arr) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = new_arr[i][j];
        }
    }
}
int count_neighbors(int **arr, int row_now, int col_now) {
    int counter = 0;
    for (int i = row_now - 1; i <= row_now + 1; i++) {
        for (int j = col_now - 1; j <= col_now + 1; j++) {
            if (i >= 0 && i < ROW && j >= 0 && j < COL && arr[i][j] == 1) counter++;
        }
    }
    if (arr[row_now][col_now] == 1) counter -= 1;
    return counter;
}

void action(int **arr, int **new_arr) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int neighbors = count_neighbors(arr, i, j);
            if (arr[i][j] == 1 && neighbors < 2) {
                new_arr[i][j] = 0;
            } else if (neighbors > 3) {
                new_arr[i][j] = 0;
            } else if (neighbors == 3) {
                new_arr[i][j] = 1;
            } else if (arr[i][j] == 1 && neighbors == 2) {
                new_arr[i][j] = 1;
            }
        }
    }
}

void screen(int **arr) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr[i][j] == 0)
                printw(" ");
            else
                printw("@");
        }
        printw("\n");
    }
}

void alive_structures(int **arr) {
    printf(
        "Hellow dear user!\n You have access to 3 organismes\n input:\n 1 for GLIDER\n 2 for BUS\n 3 for "
        "KARAVAI\n 4 for GLIDER GUN\n Else for all");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        arr[3][10] = 1;
        arr[3][11] = 1;
        arr[3][12] = 1;
        arr[2][12] = 1;
        arr[1][11] = 1;  // GLIDER
    } else if (choice == 2) {
        arr[4][10] = 1;
        arr[5][11] = 1;
        arr[5][12] = 1;
        arr[5][13] = 1;
        arr[5][14] = 1;
        arr[4][14] = 1;
        arr[3][14] = 1;
        arr[2][13] = 1;  // bus
    } else if (choice == 3) {
        arr[9][40] = 1;
        arr[10][39] = 1;
        arr[10][41] = 1;
        arr[11][38] = 1;
        arr[11][41] = 1;
        arr[12][39] = 1;
        arr[12][40] = 1;
        arr[13][38] = 1;
        arr[13][41] = 1;
        arr[14][38] = 1;
        arr[14][40] = 1;
        arr[15][39] = 1;  // karavai
    } else if (choice == 4) {
        arr[4][0] = 1;
        arr[5][0] = 1;
        arr[4][1] = 1;
        arr[5][1] = 1;
        arr[4][10] = 1;
        arr[5][10] = 1;
        arr[6][10] = 1;
        arr[3][11] = 1;
        arr[7][11] = 1;
        arr[2][12] = 1;
        arr[8][12] = 1;
        arr[2][13] = 1;
        arr[8][13] = 1;
        arr[5][14] = 1;
        arr[3][15] = 1;
        arr[7][15] = 1;
        arr[4][16] = 1;
        arr[5][16] = 1;
        arr[6][16] = 1;
        arr[5][17] = 1;
        arr[2][20] = 1;
        arr[3][20] = 1;
        arr[4][20] = 1;
        arr[2][21] = 1;
        arr[3][21] = 1;
        arr[4][21] = 1;
        arr[1][22] = 1;
        arr[5][22] = 1;
        arr[0][24] = 1;  // GLIDER GUN
        arr[1][24] = 1;
        arr[5][24] = 1;
        arr[6][24] = 1;
        arr[2][34] = 1;
        arr[3][34] = 1;
        arr[2][35] = 1;
        arr[3][35] = 1;
    } else {
        arr[9][40] = 1;
        arr[10][39] = 1;
        arr[10][41] = 1;
        arr[11][38] = 1;
        arr[11][41] = 1;
        arr[12][39] = 1;
        arr[12][40] = 1;
        arr[13][38] = 1;
        arr[13][41] = 1;
        arr[14][38] = 1;
        arr[14][40] = 1;
        arr[15][39] = 1;  // karavai
        arr[3][10] = 1;
        arr[3][11] = 1;
        arr[3][12] = 1;
        arr[2][12] = 1;
        arr[1][11] = 1;  // GLIDER
        arr[4][10] = 1;
        arr[5][11] = 1;
        arr[5][12] = 1;
        arr[5][13] = 1;
        arr[5][14] = 1;
        arr[4][14] = 1;
        arr[3][14] = 1;
        arr[2][13] = 1;  // bus
        arr[4][0] = 1;   // GLIDER GUN
        arr[5][0] = 1;
        arr[4][1] = 1;
        arr[5][1] = 1;
        arr[4][10] = 1;
        arr[5][10] = 1;
        arr[6][10] = 1;
        arr[3][11] = 1;
        arr[7][11] = 1;
        arr[2][12] = 1;
        arr[8][12] = 1;
        arr[2][13] = 1;
        arr[8][13] = 1;
        arr[5][14] = 1;
        arr[3][15] = 1;
        arr[7][15] = 1;
        arr[4][16] = 1;
        arr[5][16] = 1;
        arr[6][16] = 1;
        arr[5][17] = 1;
        arr[2][20] = 1;
        arr[3][20] = 1;
        arr[4][20] = 1;
        arr[2][21] = 1;
        arr[3][21] = 1;
        arr[4][21] = 1;
        arr[1][22] = 1;
        arr[5][22] = 1;
        arr[0][24] = 1;
        arr[1][24] = 1;
        arr[5][24] = 1;
        arr[6][24] = 1;
        arr[2][34] = 1;
        arr[3][34] = 1;
        arr[2][35] = 1;
        arr[3][35] = 1;
    }
}

int main(void) {
    int **arr = create();
    int **new_arr = create();
    alive_structures(arr);
    stdscr = initscr();
    while (wgetch(stdscr) != 'q') {
        timeout(SPEED);
        action(arr, new_arr);
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
