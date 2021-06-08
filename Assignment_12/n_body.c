#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "n_body.h"


static float calculate_radius_squared(float len1, float len2) {
    float r = len2-len1;
    if (r < 0.0000000000001){
        //maybe rework? 
        return 1;
    } else{
        return r*r;
    }
}

void initialize_bodies(body* bodies, int size){
    unsigned int seed = 2;
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<3; ++j){
            bodies[i].position[j] = rand_r(&seed) % MAX_DIM;
            bodies[i].velocity[j] = 0;
        }
        bodies[i].mass = (rand_r(&seed) % MAX_MASS) + 1;
    }
}

void update_velocities_naive(body* bodies, int size){
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<size; ++j){
            if(i != j){
                float numerator = G * (bodies[i].mass + bodies[j].mass);
                    for (int k = 0; k<3; ++k){
                        float force = numerator / calculate_radius_squared(bodies[i].position[k], bodies[j].position[k]);
                        bodies[i].velocity[k] = bodies[i].velocity[k] + force/bodies[i].mass;
                    }
            }
        }
    }
}

void update_positions(body* bodies, int size){
    for (int i = 0; i<size; ++i){
        for (int j = 0; j<3; ++j){
            float pos = bodies[i].position[j] + bodies[i].velocity[j];
            if(pos > MAX_DIM) {
                //fully plastic push
                bodies[i].position[j] = MAX_DIM;
                bodies[i].velocity[j] = 0;
            } else if (pos < 0){
                bodies[i].position[j] = 0;
                bodies[i].velocity[j] = 0;
            }else {
                bodies[i].position[j] = pos;
            }
        }
    }
}
