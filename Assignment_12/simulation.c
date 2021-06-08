#include <stdio.h>
#include <stdlib.h>
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


    initialize_bodies(bodies, size);
    for (int i = 0; i<steps; ++i){
        update_velocities_naive(bodies, size);
        update_positions(bodies, size);  
    }
    

    printf("%f\n", bodies[1].position[0]);
    printf("%f\n", bodies[1].position[1]);
    printf("%f\n", bodies[1].position[2]);

    printf("%f\n", bodies[2].position[0]);
    printf("%f\n", bodies[2].position[1]);
    printf("%f\n", bodies[2].position[2]);

    printf("%f\n", bodies[0].position[0]);
    printf("%f\n", bodies[0].position[1]);
    printf("%f\n", bodies[0].position[2]);
    
    
}