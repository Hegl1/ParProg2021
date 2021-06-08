#ifndef __N_BODY_H__
#define __N_BODY_H__

#define G 6.6e-10
#define MAX_DIM 500
#define MAX_MASS 5

typedef struct body_struct {
    //[0] = X, [1] = Y, [2] = Z
    float position[3];
    float velocity[3];
    int mass;
} body;

void initialize_bodies(body* bodies, int size);
void update_velocities_naive(body* bodies, int size);
void update_positions(body* bodies, int size);

#endif