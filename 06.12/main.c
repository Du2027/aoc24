#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char** argv){
   char map[132][132] = {0};
   char line[132] ={0};
   FILE* file = fopen("input.txt", "r");
   short int iteration = 0;
   short int pos[2];
   int stepc = 0;
   bool end = false;

   while ((fgets(line, 132, file)) != NULL) {
      for (int i = 0; i < 132; i++) {
         map[iteration][i] = line[i];
         if(map[iteration][i] == '^'){
            pos[0] = iteration;
            pos[1] = i;
         }
      }
      iteration++;
   }

   while (end == false) {
      if(map[pos[0]][pos[1]] == '^' && pos[0] > 0 && map[pos[0] - 1][pos[1]] != '#'){
         map[pos[0]][pos[1]] = 'X';
         pos[0]--;
         map[pos[0]][pos[1]] = '^';
      }
      if (map[pos[0]][pos[1]] == '^' && map[pos[0] - 1][pos[1]] == '#') {
         map[pos[0]][pos[1]] = '>';
      }

      if (map[pos[0]][pos[1]] == '>' && pos[1] > 0 && map[pos[0]][pos[1] + 1] != '#') {
         map[pos[0]][pos[1]] = 'X';
         pos[1]++;
         map[pos[0]][pos[1]] = '>';
      }
      if (map[pos[0]][pos[1]] == '>' && map[pos[0]][pos[1] + 1] == '#') {
         map[pos[0]][pos[1]] = '_';
      }

      if (map[pos[0]][pos[1]] == '_' && pos[1] < 129 && map[pos[0] + 1][pos[1]] != '#') {
         map[pos[0]][pos[1]] = 'X';
         pos[0]++;
         map[pos[0]][pos[1]] = '_';
      }
      if (map[pos[0]][pos[1]] == '_' && map[pos[0] + 1][pos[1]] == '#') {
         map[pos[0]][pos[1]] = '<';
      }

      if (map[pos[0]][pos[1]] == '<' && pos[1] > 0 && map[pos[0]][pos[1] - 1] != '#') {
         map[pos[0]][pos[1]] = 'X';
         pos[1]--;
         map[pos[0]][pos[1]] = '<';
      }
      if (map[pos[0]][pos[1]] == '<' && map[pos[0]][pos[1] - 1] == '#') {
         map[pos[0]][pos[1]] = '^';
      }
      if(pos[0] == 130 || pos[0] == 0 || pos[1] == 130 || pos[1] == 0){
         end = true;
      }
   }
   for (int i = 0; i < 130; i++) {
      for (int n = 0; n < 130; n++) {
         if(map[i][n] == 'X'){
            stepc++;
         }
      }
      printf("%s", map[i]);
   }
   printf("%d", stepc);
   return 0;
}
