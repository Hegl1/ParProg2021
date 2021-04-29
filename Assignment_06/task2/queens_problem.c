#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Number of solutions found
int solutions = 0;

void placeQ(int queens[], int row, int column, int N) {
    
    for(int i = 0; i < row; i++) {
        // Vertical check
        if (queens[i] == column) {
            return;
        }
        
        // Diagonal check
        if (abs(queens[i] - column) == (row - i))  {
            return;
        }
    }
    
    // Set the queen
    queens[row] = column;
    
    //Placed final queen, found a solution
    if(row == N-1) {
        solutions++;  
    }
    
    else {
        // Increment row
        for(int i = 0; i < N; i++) {
            placeQ(queens, row + 1, i, N);
        }
    }
}

void solve(int N, int *boards[]) {
    for(int i = 0; i < N; i++) {
        placeQ(boards[i], 0, i, N);
    }
}

int** alloc_matrix(int m, int n){

    int **p;

    if((p = calloc(m, sizeof(int*)))){

        for(int i = 0; i < m; i++){

            if(!(p[i] = calloc(n, sizeof(int)))){

                printf("\nNo memory for line %d", i);
                exit(EXIT_FAILURE);
            }
        }
    }else
    {
        printf("\nMalloc failed!");
        exit(EXIT_FAILURE);
    }

    return p;
}

void free_matrix(int **mat, int N) { 
    
    for (int i = 0; i < N; i++){
        free(mat[i]);
    }
    free(mat);
}

int main(int argc, char*argv[]) {
    int N = 5;

    if (argc > 1) {
        N = atoi(argv[1]);
    }

    int **boards = alloc_matrix(N,N);

    double startTime = omp_get_wtime();   
    solve(N, boards);
    double endTime = omp_get_wtime();

    free_matrix(boards, N);

    printf("\nNumber of solutions: %d", solutions); 
    printf("\nExecution time: %2.5f\n", (endTime - startTime));
    
    return 0;
}