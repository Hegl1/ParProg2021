#include <stdio.h>
#include <stdlib.h>
#include "n_body.h"

//TODO implement proper behaviour for bouncing at borders
//TODO tune parameters so model behaves ... more watchable


int main(int argc, char** argv){

    if (argc < 3){
        printf("Wrong number of arguments. Usage: ./n_bodies.out <number of bodies> <number of timesteps>");
        return EXIT_FAILURE;
    }

    int size = atol(argv[1]);
    int steps = atol(argv[2]);

    body bodies[size];


    initialize_bodies(bodies, size);
    for (int i = 0; i<steps; ++i){
        update_velocities_naive(bodies, size);
        update_positions(bodies, size);  
    }
    

    printf("%f\n", bodies[1].position[0]);
    printf("%f\n", bodies[1].position[1]);
    printf("%f\n", bodies[1].position[2]);
    
    
}