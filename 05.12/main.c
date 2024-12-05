#include <stdio.h>
#include <stdbool.h>

int main(int argc, char** argv){
   FILE* file = fopen("input.txt", "r");
   char line[80] = {0};
   int rules[1175][2];
   bool rule_phase = true;
   short int iteration = 0;
   short int csv_c = 0;
   bool eol = false;
   bool exit = false;
   short int numc = 0;

   short int num_buf_l = 0;
   short int num_buf_r = 0;
   int sum = 0;

   while (fgets(line, 80, file) != NULL) {
      if(line[1] == 0){
         rule_phase = false;
      }

      if (rule_phase == true) {
         rules[iteration][0] = ((line[0] - 48) * 10) + line[1] - 48;
         rules[iteration][1] = ((line[3] - 48) * 10) + line[4] - 48;
         //printf("%d|%d\n", rules[iteration][0], rules[iteration][1]);
      }

      while (eol == false && rule_phase == false && line[1] != 0) {
         num_buf_l = ((line[csv_c] - 48) * 10) + line[csv_c + 1] - 48;
         num_buf_r = ((line[csv_c + 3] - 48) * 10) + line[csv_c + 4] - 48;

         for (int i = 0; i < 1175; i++) {
            if(rules[i][1] == num_buf_l){
               if(rules[i][0] == num_buf_r){
                  //printf("WRONG %d-%d/%d-%d\n", rules[i][1], num_buf_l, rules[i][0], num_buf_r);
                  char buffer[2];
                  buffer[0] = line[csv_c];
                  buffer[1] = line[csv_c + 1];
                  line[csv_c] = line[csv_c + 3];
                  line[csv_c + 1] = line[csv_c + 4];
                  line[csv_c + 3] = buffer[0];
                  line[csv_c + 4] = buffer[1];
                  csv_c = 0;
                  numc = 0;
                  break;
               }
            }
         }
         if(exit){break;}

         for (int i = 0; i < 1175; i++) {
            if(rules[i][0] == num_buf_r){
               if(rules[i][1] == num_buf_l){
                  //printf("WRONG %d-%d/%d-%d\n", rules[i][1], num_buf_l, rules[i][0], num_buf_r);
                  char buffer[2];
                  buffer[0] = line[csv_c];
                  buffer[1] = line[csv_c + 1];
                  line[csv_c] = line[csv_c + 3];
                  line[csv_c + 1] = line[csv_c + 4];
                  line[csv_c + 3] = buffer[0];
                  line[csv_c + 4] = buffer[1];
                  csv_c = 0;
                  numc = 0;
                  break;
               }
            }
            }
         if(exit){break;}

         //printf("%d,%d:",num_buf_l, num_buf_r);
         if(line[csv_c + 5] != ','){
            eol = true;
            numc = (numc + 1) / 2;
            sum = sum + (line[numc * 3] - 48) * 10 + (line[numc * 3 + 1]) - 48;
            printf("MID%d, SUM%d @ %s",numc, sum, line);
         }
         else {
            csv_c+= 3;
            numc++;
         }
      }
      numc = 0;
      exit = false;
      csv_c = 0;
      iteration++;
      eol = false;

      printf("SUM:%d", sum);
   }

   return 0;
}
