#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "n_body.h"


static float calculate_radius_squared(float len1, float len2) {
    float r = len2-len1;
    if (abs(r) < 0.0000000000001){
        // if 2 masses get on the same spot, big shit occurs -> probably fix? 
        return 1;
    } else{
        //
        float ret = r < 0 ?  -1 * (r*r) :  r*r;
        return ret;
    }
}

void initialize_bodies(body* bodies, int size){
    unsigned int seed = 8;
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
                //mix of elastic and plastic push
                bodies[i].position[j] = MAX_DIM;
                bodies[i].velocity[j] /= 10;
            } else if (pos < 0){
                bodies[i].position[j] = 0;
                bodies[i].velocity[j] /= 10;
            }else {
                bodies[i].position[j] = pos;
            }
        }
    }
}
