#include <omp.h>
#include <stdio.h>

int main() {
   int data, flag = 0;
   #pragma omp parallel num_threads(2)
   {
      if (omp_get_thread_num()==0) {
         data = 42;
         //flush both flag and data to ensure that data gets written before flag
         #pragma omp flush(flag, data) 
         flag = 1;
         //flush flag to ensure that flag is in main memory
         #pragma omp flush(flag)
      }
      else if (omp_get_thread_num()==1) {
         #pragma omp flush(flag, data)
         while (flag < 1) {
            //includes data to prevent reordering the for loop after the flush statement in line line 25
            #pragma omp flush(flag, data)
         }

         //includes flag to ensure that the flush happens after the while loop
         #pragma omp flush(data)
         printf("flag=%d data=%d\n", flag, data);
      }
   }
   return 0;
}