#include <stdbool.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <string.h>

   int main(int argc, char **argv) {
   FILE *file = fopen("input.txt", "r");
   int levels[1000][30] = {0};
   char line[50];

   char *token;
   short int ycounter = 0;
   short int xcounter = 0;

   while (fgets(line, 50, file) != NULL) {
      token = strtok(line, " ");
      xcounter = 0;
      while (token != NULL) {
          //printf("%s@%d-%d a:%d", token, ycounter, xcounter, atoi(token));
          levels[ycounter][xcounter] = atoi(token);
          token = strtok(NULL, " ");
          xcounter++;
      }
      ycounter++;
   }

   for (int i = 0; i < 1000; i++) {
      for (int n = 0; n < 30; n++) {
         printf("%d, ", levels[i][n]);
      }
      printf("\n");
   }

   int iteration = 0;
   int safe_counter = 0;
   int diff = 0;
   bool contin = true;
   int bigger = 0;
   short int problemc = 0;
   short int n = 0;
   short int avg = 0;

   for (int i = 0; i < 1000; i++) {
      while (levels[i][n + 1] != 0){
         diff = levels[i][n] - levels[i][n + 1];
         if (diff < 0) {
            avg--;
         }
         if (diff > 0) {
            avg++;
         }
         n++;
      }

      if (avg <= 0) {
         bigger = -1;
      }
      else if (avg > 0) {
         bigger = 1;
      }

      n = 0;
      avg = 0;

      while (levels[i][iteration + 1] != 0) {
         diff = levels[i][iteration] - levels[i][iteration + 1];
         if (abs(diff) > 3 || abs(diff) == 0) {
            problemc++;
            contin = false;
         }

            if (levels[i][iteration] < levels[i][iteration + 1] && bigger == -1) {

            }
            else if (levels[i][iteration] > levels[i][iteration + 1] && bigger == 1) {

            }
            else {
               contin = false;
               problemc++;
               //printf("WRONG - %d, %d\n", levels[i][iteration], levels[i][iteration +1]);
            }

         iteration++;
      }
      if (contin == true || problemc == 1) {
         safe_counter++;
      }
      else {
         contin = true;
      }
      problemc = 0;
      iteration = 0;
   }

   printf("safec %d", safe_counter);
   fclose(file);
   return 0;
}
