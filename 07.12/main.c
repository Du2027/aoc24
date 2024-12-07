#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define COLOR_RED "\x1b[1;31m"
#define COLOR_GREEN "\x1b[1;34m"
#define COLOR_YELLOW "\x1b[1;33m"
#define COLOR_BLUE "\x1b[1;32m"
#define COLOR_PURPLE "\x1b[1;35m"
#define COLOR_CYAN "\x1b[1;36m"
#define COLOR_RESET "\x1b[0m"

int main(int argc, char** argv){
   bool found = false;
   FILE* file = fopen("input.txt", "r");
   char line_buff[50] = {0};
   short int line_it = 0;
   short int num_it = 0;
   unsigned long long int true_sum = 0;
   unsigned long long int endsum = 0;
   unsigned long long int sumbuffer = 0;
   char buffer[20] = {0};
   char num_chr[15][8] = {0};
   short int buffpos = 0;
   short int numc = 0;
   short int sum_it = 0;
   short int phase = 1;

   while ((fgets(line_buff, 50, file)) != NULL) {
      while (line_buff[num_it] != ':') {
         buffer[num_it] = line_buff[num_it];
         num_it++;
      }
      true_sum = strtoull(buffer, NULL, 10);
      memset(buffer, 0, sizeof(buffer));
      printf("%lld", true_sum);

      line_it = num_it + 2;
      num_it = 0;
      printf(": ");
      while (line_buff[line_it] != 0) {
         while (line_buff[num_it + line_it] >= '0' && line_buff[num_it + line_it] <= '9') {
            num_chr[numc][buffpos] = line_buff[num_it + line_it];
            num_it++;
            buffpos++;
         }
         numc++;
         buffpos = 0;
         line_it = line_it + num_it + 1;
         num_it = 0;
      }
      line_it = 0;

      short int nums[numc];
      char operations[numc - 1];
      memset(operations, '+', sizeof(operations));
      memset(nums, 0, sizeof(nums));

      for (int i = 0; i < numc; i++) {
         nums[i] = atoi(num_chr[i]);
         printf("%d ", nums[i]);
      }
      printf("\n");
      while (true) {
         sumbuffer = 0;
         if(phase == 3){
            memset(operations, '*', sizeof(operations));
         }
         if(phase == 4){
            memset(operations, '+', sizeof(operations));
         }
         for (int n = 0; n < numc  - 1; n++) {
            if(phase == 2){
               operations[sum_it] = '*';
            }
            if(phase == 2 && sum_it > 0){
               operations[sum_it - 1] = '+';
            }
            if(phase == 4){
               operations[sum_it] = '*';
            }
            sumbuffer = nums[0];  // Start with first number
            for (int i = 0; i < numc - 1; i++) {
               if(operations[i] == '+'){
                  sumbuffer = sumbuffer + nums[i + 1];
               }
               if (operations[i] == '*') {
                  sumbuffer = sumbuffer * nums[i + 1];
               }
            }
            if(sumbuffer == true_sum){
               printf("%lld\n", sumbuffer);
               break;
            }
            else {
               printf("%lld\n%s\n", sumbuffer, operations);
               sumbuffer = 0;
            }
            if(phase == 3 || phase == 1){
               break;
            }
            sum_it++;
         }
         memset(operations, '+', sizeof(operations));
         sum_it = 0;
         phase++;
         printf("%s%lld - %lld @ %d%s\n", COLOR_RED, true_sum, sumbuffer,phase, COLOR_RESET);
         if (sumbuffer == true_sum) {
            endsum = endsum + true_sum;
            break;
         }
         if(phase == 5){
            break;
         }
      }
      phase = 1;

      memset(num_chr, 0, sizeof(num_chr));
      numc = 0;
   }
   numc = 0;
   printf("\nEndsum : %lld\n", endsum);
   return 0;
}
