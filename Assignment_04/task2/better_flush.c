#include <omp.h>
#include <stdio.h>

int main() {
   int data, flag = 0;
   #pragma omp parallel num_threads(2)
   {
      if (omp_get_thread_num()==0) {
         data = 42;
         //flush both flag and data to ensure flag write doesnt start before data is in main mem
         #pragma omp flush(flag, data) 
         flag = 1;
         //flush flag to ensure that flag is in main memory
         #pragma omp flush(flag)
      }
      else if (omp_get_thread_num()==1) {
         #pragma omp flush(flag, data) //WTF? 
         while (flag < 1) {
            #pragma omp flush(flag, data) //MORE WTF?
         }

         //again, wtf? 
         #pragma omp flush(flag, data)
         printf("flag=%d data=%d\n", flag, data);
      }
   }
   return 0;
}