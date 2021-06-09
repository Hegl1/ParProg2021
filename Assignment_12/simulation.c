#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include "n_body.h"

//TODO implement proper behaviour for bouncing at borders
//TODO tune parameters so model behaves ... more watchable
// Major flaw: when to point masses get to close to each otther (and eventually overlap), 
//proper speed change cannot be calculated -> maybe this results in the odd corner behaviour


int main(int argc, char** argv){

    if (argc < 3){
        printf("Wrong number of arguments. Usage: ./n_bodies.out <number of bodies> <number of timesteps>");
        return EXIT_FAILURE;
    }

    int size = atol(argv[1]);
    int steps = atol(argv[2]);

    body bodies[size];
    remove(OUT_FILE);
    initialize_bodies(bodies, size);
    print_bodies_to_file(bodies, size);

    #ifdef TIME_MES
    double start_time = omp_get_wtime();
    #endif

    for (int i = 0; i<steps; ++i){
        update_velocities_naive(bodies, size);
        update_positions(bodies, size); 
        #ifndef TIME_MES
        print_bodies_to_file(bodies, size);
        #endif
    }

    #ifdef TIME_MES
    double end_time = omp_get_wtime();
    printf("time: %5.2f\n", end_time - start_time);
    #endif

    
}