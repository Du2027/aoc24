#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//from putils
int* bubblesort_int(int arr[], int size){
   int buffer;
   for (int i = 0; i < size - 1; i++) {
      for (int n = 0; n < size - 1 - i; n++) {
         if (arr[n] > arr[n+1]) {
            buffer = arr[n];
            arr[n] = arr[n+1];
            arr[n+1] = buffer;
         }
      }
   }
   return arr;
}

//from putils again
int count_dupes(int arr[], int to_count, int size){
   if(size <= 0){
      return 0;
   }

   int dupecount = 0;
   for (int i = 0; i < size; i++) {
      if(arr[i] == to_count){
         dupecount++;
      }
   }
   return dupecount;
}

int main(int argc, char** argv){
   FILE *file = fopen("input.txt", "r");
   char line[15];
   char buffer[6];
   int num_left[1000];
   int num_right[1000];
   int iteration = 0;
   int diff_sum = 0;
   int similarity_score = 0;

   if(file == NULL){
      printf("FILEERR\n");
      return -1;
   }

   while (fgets(line, sizeof(line), file)) {
      buffer[0] = line[0];
      buffer[1] = line[1];
      buffer[2] = line[2];
      buffer[3] = line[3];
      buffer[4] = line[4];
      num_left[iteration] = atoi(buffer);

      buffer[0] = line[8];
      buffer[1] = line[9];
      buffer[2] = line[10];
      buffer[3] = line[11];
      buffer[4] = line[12];
      num_right[iteration] = atoi(buffer);
      iteration++;
   }

   bubblesort_int(num_left, sizeof(num_left) / sizeof(int));
   bubblesort_int(num_right, sizeof(num_right) / sizeof(int));

   int int_buffer = 0;
   for (int i = 0; i < 1000; i++) {
      int_buffer = num_left[i] - num_right[i];

      if(int_buffer < 0){int_buffer = int_buffer * -1;}
      diff_sum = diff_sum + int_buffer;
   }
   printf("Difference sum : %d\n", diff_sum);

   //part 2
   for (int i = 0; i < 1000; i++) {
      similarity_score = similarity_score + num_left[i] * count_dupes(num_right, num_left[i], sizeof(num_right) / sizeof(int));
   }
   printf("Similarity score : %d\n", similarity_score);

   fclose(file);
   return 0;
}
