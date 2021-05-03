# Assignment 6

## Task 2

### Sequentiell Solution

The program iterates through all columns and rows to try every possible field to place a queen without being attacked by another. Our solution prints all possible solutions for a N x N - field but they are not distinct. So for example mirrored solutions and things like that are counted as seperate solution.

So the main alogrithm looks like this:

```c
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
```

### Parallel Version

The parallel version starts threads before the iteration through the columns begins, so for every column there is a seperate thread which executes the recursive call tree to check how queens can be placed.

And every Thread gets a seperate localSum variable and after every thread has executed, the localSums are added together via an atomic, so no wrong results can occur due to race conditions.

```c
void solve(int N, int *boards[]) {
    #pragma omp parallel
    {
        int localSolution = 0;
        #pragma omp for schedule(dynamic)
            for(int i = 0; i < N; i++) {
                placeQ(boards[i], 0, i, N, &localSolution);
            }
        #pragma omp atomic
            solutions += localSolution;
    }
}
```

schedule(dynamic) is used to give every thread the same amount of work dynamically, because the work per thread can variate.

## Measurements

| Input size | queens_problem.c | parallel 1 thread | parallel 2 threads | parallel 4 threads | parallel 8 threads | number of solutions |
| :--------: | :--------------- | ----------------- | ------------------ | ------------------ | ------------------ | ------------------- |
|     8      | 0.00026          | 0.00482           | 0.00038            | 0.00327            | 0.00039            | 92                  |
|     10     | 0.00671          | 0.00226           | 0.00226            | 0.00605            | 0.00367            | 724                 |
|     12     | 0.21284          | 0.06667           | 0.07366            | 0.07190            | 0.07055            | 14200               |

by Tobias Hosp, Marcel Alexander Huber, Thomas Klotz
