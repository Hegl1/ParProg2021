import random
import os
import math

MAX_DIM = 100
G = 1e-4

class Body:

    def __init__(self, x, y, z, vel_x, vel_y, vel_z, mass):
        self.position = [x,y,z]
        self.mass = mass
        self.velocity = [vel_x, vel_y, vel_z]

    def update_position(self):
        for i in range(3):
            update = self.position[i] + self.velocity[i]
            if not (update > MAX_DIM or update < 0):
                self.position[i] = update
            elif update > MAX_DIM:
                self.position[i] = MAX_DIM
                self.velocity[i] = -1 * self.velocity[i]
            else:
                self.position[i] = 0
                self.velocity[i] = -1 * self.velocity[i]

    def update_velocities(self, body_list):
        for body in body_list:
            numerator = G * self.mass * body.mass
            for i in range(3):
                radius = self.get_radius_one_dim_squared(body, i)
                if abs(radius) > 1:
                    force = numerator / radius
                    self.velocity[i] += force/self.mass

    def get_radius_one_dim_squared(self, body, dim):
        r = body.position[dim] - self.position[dim]
        if r > 0:
            return r*r
        else:
            return -1 * (r*r)

    def get_total_radius(self, body):
        return math.sqrt(abs(self.get_radius_one_dim_squared(body, 0)) + abs(self.get_radius_one_dim_squared(body, 1)) + abs(self.get_radius_one_dim_squared(body, 2)))

        
    
def init_bodies(num_bodies):
    body_list = list()
    
    for _ in range(num_bodies):
        body_list.append(
            Body(random.uniform(0.0, MAX_DIM), random.uniform(0.0, MAX_DIM), random.uniform(0.0, MAX_DIM), 0, 0, 0, random.randint(100, 10000))
        )
    return body_list

def update_velocities(body_list):
    for body in body_list:
        body.update_velocities(body_list)

def update_positions(body_list):
    for body in body_list:
        body.update_position()


def write_body_list_to_file(body_list):
    with open("simulation.out", "a") as out_file:
        for body in body_list:
            out_file.write(f'{body.position[0]} ')
        out_file.write("\n")
        for body in body_list:
            out_file.write(f'{body.position[1]} ')
        out_file.write("\n")
        for body in body_list:
            out_file.write(f'{body.position[2]} ')
        out_file.write("\n")
        out_file.write("\n")

def clear_file():
    if os.path.exists("simulation.out"):
        os.remove("simulation.out")

def main():
    bod_list = init_bodies(2)
    iterations = 500
    clear_file()
    for _ in range(iterations):
        update_velocities(bod_list)
        update_positions(bod_list)
        write_body_list_to_file(bod_list)

if __name__ == '__main__':
    main()





        