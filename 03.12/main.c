#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
   char line[5000] = {0};
   FILE* file = fopen("input.txt", "r");

   if (file == NULL) {
      printf("Error opening file!\n");
      return 1;
   }

   int iteration = 0;
   int mul_it = 0;
   short int zahlpos = 0;

   char num1[4] = {'0'};
   num1[3] = 0;
   char num2[4] = {'0'};
   num2[3] = 0;

   int sum = 0;
   bool enabled = true;

   while (fgets(line, 5000, file)) {
      while (line[iteration] != 0) {
         if(line[iteration] == 'm' && enabled == true){
            if(line[iteration + 1] == 'u' && line[iteration + 2] == 'l' && line[iteration + 3] == '('){
               mul_it = iteration + 4;
               zahlpos = 0;

               // Num1
               while (line[mul_it] >= '0' && line[mul_it] <= '9') {
                  num1[zahlpos] = line[mul_it];
                  mul_it++;
                  zahlpos++;
               }
               if(zahlpos != 3){
                  switch (zahlpos) {
                     case 2:
                        num1[2] = 0;
                        break;
                     case 1:
                        num1[1] = 0;
                        break;
                  }
               }

               zahlpos = 0;

               // Num2
               if (line[mul_it] == ',') {
                  mul_it++;
                  while (line[mul_it] >= '0' && line[mul_it] <= '9') {
                     num2[zahlpos] = line[mul_it];
                     mul_it++;
                     zahlpos++;
                  }
                  if(zahlpos != 3){
                     switch (zahlpos) {
                        case 2:
                           num2[2] = 0;
                           break;
                        case 1:
                           num2[1] = 0;
                           break;
                     }
                  }
               }
               else {
                  memset(num1, '0', sizeof(num1));
                  num1[3] = 0;
               }
               if(line[mul_it] == ')'){
                  sum = sum + (atoi(num1) * atoi(num2));
                  memset(num1, '0', sizeof(num1));
                  num1[3] = 0;
                  memset(num2, '0', sizeof(num2));
                  num2[3] = 0;
               }
               else {
                  memset(num1, '0', sizeof(num1));
                  num1[3] = 0;
                  memset(num2, '0', sizeof(num2));
                  num2[3] = 0;
               }
            }
         }
         else if(line[iteration] == 'd' && line[iteration + 1] == 'o' && line[iteration + 2] == '(' && line[iteration + 3] == ')'){
            enabled = true;
         }
         else if(line[iteration] == 'd' && line[iteration + 1] == 'o' && line[iteration + 2] == 'n' && line[iteration+3] == 39 && line[iteration+4] == 't' && line[iteration+5] == '(' && line[iteration+6] == ')'){
            enabled = false;
         }
         iteration++;
      }
      iteration = 0;
   }
   printf("%d", sum);
   fclose(file);
}
