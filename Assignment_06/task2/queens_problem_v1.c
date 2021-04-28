#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define IND(y, x) ((y) * (N) + (x))

void printMatrix(int N, int *board){
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++)
            printf("%d\t",board[IND(i,j)]);
        printf("\n");
    }
}

int is_attack(int i, int j, int *board, int N) {
    int k, l;

    // checking for column j
    for(k = 1; k <= i - 1; k++) {
        if(board[IND(k,j)] == 1){
            return 1;
        }
    }

    // checking upper right diagonal
    k = i - 1;
    l = j + 1;

    while (k >= 1 && l <= N) {
        if (board[IND(k,l)] == 1){
            return 1;
        }
        k = k + 1;
        l = l + 1;
    }

    // checking upper left diagonal
    k = i - 1;
    l = j - 1;
    while (k >= 1 && l >= 1) {
        if (board[IND(k,l)] == 1){
            return 1;
        }
    
        k = k - 1;
        l = l - 1;
    }

    return 0;
}

int n_queen(int row, int n, int N, int *board) {
    if (n == 0){
        return 1;
    }

    for (int j = 1; j <= N; j++) {
        if(!is_attack(row, j, board, N)) {
            board[IND(row,j)] = 1;  
            if (n_queen(row + 1, n - 1, N, board)){
                return 1;
            }   
            board[IND(row,j)] = 0; //backtracking
        }
    } 
    return 0;
}

int main(int argc, char **argv) {
    int N = 5;

    if (argc > 1) {
        N = atoi(argv[1]);
    }

    int *board =  malloc(sizeof(double) * N * N);

    for(int i = 0; i < N; i++) {
        for(int j=0; j< N; j++){
            board[IND(i,j)] = 0;
        }
    }

    n_queen(1, N, N, board);

    printMatrix(N,board);

    free(board);
    return 0;
}