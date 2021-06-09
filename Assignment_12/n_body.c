#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "n_body.h"


static float calculate_radius_squared(float len1, float len2) {
    float r = len2-len1;
    r = r < 0 ? -1 * (r*r) :  r*r;
    return r;
}

void initialize_bodies(body* bodies, int size){
    srand(time(NULL));
    unsigned int seed = rand();
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<3; ++j){
            bodies[i].position[j] = rand_r(&seed) % MAX_DIM;
            bodies[i].velocity[j] = 0;
        }
        bodies[i].mass = ((rand_r(&seed) % MAX_MASS) + 500) * 1000;
    }
}

void update_velocities_naive(body* bodies, int size){
    #pragma omp parallel for collapse(2)
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<size; ++j){
            if(i != j){
                float numerator = G * (bodies[i].mass + bodies[j].mass);
                for (int k = 0; k<3; ++k){
                    float radius = calculate_radius_squared(bodies[i].position[k], bodies[j].position[k]);
                    float force;
                    if (fabs(radius) < 0.5){
                        force = 0;
                    } else{
                        force = numerator / radius;
                    }
                    bodies[i].velocity[k] += force/bodies[i].mass;
                }
            }
        }
    }
}

void update_positions(body* bodies, int size){
    #pragma omp parallel for collapse(2)
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<3; ++j){
            float update = bodies[i].position[j] + bodies[i].velocity[j];
            if (update > MAX_DIM){
                bodies[i].velocity[j] = 0;
            }else if(update<0){
                bodies[i].velocity[j] = 0;
            } else{
                bodies[i].position[j] = update;
            }
            
        }
    }
}

void print_bodies_to_file(body* bodies, int size){
    FILE* file = fopen (OUT_FILE, "a");
    for (int j = 0; j<3; ++j){
        for (int i = 0; i<size; ++i){
            fprintf(file, "%f ", bodies[i].position[j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
    fclose(file);
}
