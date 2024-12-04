#include <stdio.h>
#include <string.h>

// from putils
#define COLOR_RED "\x1b[1;31m"
#define COLOR_GREEN "\x1b[1;34m"
#define COLOR_YELLOW "\x1b[1;33m"
#define COLOR_BLUE "\x1b[1;32m"
#define COLOR_PURPLE "\x1b[1;35m"
#define COLOR_CYAN "\x1b[1;36m"
#define COLOR_RESET "\x1b[0m"

int main(int argc, char** argv){
   FILE* file = fopen("input.txt", "r");
   char map[140][142] = {0};              // last char == 0
   char line[142] = {0};
   short int iteration = 0;
   short int xmas_c = 0;

   while(fgets(line, 142, file) != NULL){
      strcpy(map[iteration] ,line);
      iteration++;
   }

   for (int i = 0; i < 140; i++) {
      //printf("%d\n", i);
      if(i <= 9){
         printf("  ");
      }
      else if(i <= 99){
         printf(" ");
         }
      printf("%d ", i);
      for (int n = 0; n < 140; n++) {
         if(map[i][n] == 'X'){
            printf("%s%c%s", COLOR_RED ,map[i][n], COLOR_RESET);
            if (n >= 3 && i >= 3 && map[i - 1][n - 1] == 'M') {
               if (map[i - 2][n - 2] == 'A' && map[i - 3][n - 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i - 1][n - 1], map[i - 2][n - 2], map[i - 3][n - 3]);
                  printf("%d", xmas_c);
               }
            }
             if (i >= 3 && map[i - 1][n] == 'M') {
               if (map[i - 2][n] == 'A' && map[i - 3][n] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i - 1][n], map[i - 2][n], map[i - 3][n]);
                  printf("%d", xmas_c);
               }
            }
            if (i >= 3 && n <= 136 && map[i - 1][n + 1] == 'M') {
               if (map[i - 2][n + 2] == 'A' && map[i - 3][n + 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i - 1][n + 1], map[i - 2][n + 2], map[i - 3][n + 3]);
                  printf("%d", xmas_c);
               }
            }


            if (n >= 3 && map[i][n - 1] == 'M') {
               if (map[i][n - 2] == 'A' && map[i][n - 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i][n - 1], map[i][n - 2], map[i][n - 3]);
                  printf("%d", xmas_c);
               }
            }
            if (n <= 136 &&map[i][n + 1] == 'M') {
               if (map[i][n + 2] == 'A' && map[i][n + 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i][n + 1], map[i][n + 2], map[i][n + 3]);
                  printf("%d", xmas_c);
               }
            }


            if (n >= 3  && i <= 138 && map[i + 1][n - 1] == 'M') {
               if (map[i + 2][n - 2] == 'A' && map[i + 3][n - 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i + 1][n - 1], map[i + 2][n - 2], map[i + 3][n - 3]);
                  printf("%d", xmas_c);
               }
            }
            if (i <= 138 && map[i + 1][n] == 'M') {
               if (map[i + 2][n] == 'A' && map[i + 3][n] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i + 1][n], map[i + 2][n], map[i + 3][n]);
                  printf("%d", xmas_c);
               }
            }
            if (n <= 136  && i <= 138 && map[i + 1][n + 1] == 'M') {
               if (map[i + 2][n + 2] == 'A' && map[i + 3][n + 3] == 'S') {
                  xmas_c++;
                  printf("%c@%c@%c", map[i + 1][n + 1], map[i + 2][n + 2], map[i + 3][n + 3]);
                  printf("%d", xmas_c);
               }
            }
         }

         else {
            printf("%c", map[i][n]);
         }
      }
      printf("\n");
   }
   printf("\n%d",xmas_c);
   fclose(file);
   return 0;
}
