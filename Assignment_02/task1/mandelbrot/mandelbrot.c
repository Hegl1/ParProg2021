#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// Include that allows to print result as an image
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// Default size of image
#define X 1280
#define Y 720
#define MAX_ITER 10000


void calc_mandelbrot(uint8_t image[Y][X]) {
	double startTime = omp_get_wtime();
	double x;
	double y;
	double cx;
	double cy;
	int iteration;
	double x_tmp;
	for(int j = 0; j < Y; j++){
		cy = ((float)j) * 2/((float)Y) - 1.0;
		for(int i = 0; i < X; i++){
			x = 0.0;
        	y = 0.0;
        	cx = ((float)i) * 3.5/((float)X) - 2.5;
        	iteration = 0;
        	while (x*x + y*y <= 4 && iteration < MAX_ITER){
            	x_tmp = x*x - y*y + cx;
            	y = 2*x*y + cy;
            	x = x_tmp;
            	iteration = iteration + 1;
			}
			
			image[j][i] = 255 - (iteration / MAX_ITER * 255);
		}
	}
	double endtime = omp_get_wtime();
	printf("\ntime: %2.4f", (endtime - startTime));
}

int main() {
	uint8_t image[Y][X];

	calc_mandelbrot(image);

	const int channel_nr = 1, stride_bytes = 0;
	stbi_write_png("mandelbrot.png", X, Y, channel_nr, image, stride_bytes);
	return EXIT_SUCCESS;
}