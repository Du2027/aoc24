#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>

int main(int argc, char** argv){
    FILE* file = fopen("input.txt", "r");
    int levels[1000][30];
    char line[50];
    int iteration = 0;
    int level_iteration = 0;
    int level_array_iteration = 0;
    char next;
    char buffer[3];

    while(fgets(line, 50, file) != NULL){
        next = line[0];
        while (next == 32 || next <= '9' && next >= '0') {
            buffer[0] = line[level_iteration];
            buffer[1] = line[level_iteration + 1];
            levels[iteration][level_array_iteration] = atoi(buffer);
            level_iteration += 3;
            level_array_iteration++;
        }
        level_iteration = 0;
        level_array_iteration = 0;
        iteration++;
    }

    /*for (int i = 0; i < 100; i++) {
        for (int n = 0; n < 30; n++) {
        }
        printf("\n");
        }*/

    iteration = 0;
    int safe_counter = 0;
    int diff = 0;
    bool contin = true;
    int bigger = 0;
    for (int i = 0; i < 1000; i++) {
            if(levels[i][0] < levels[i][1]){
                bigger = -1;
            }
            else if(levels[i][0] > levels[i][1]){
                bigger = 1;
            }
        while (levels[i][iteration] != 0) {
            printf("%d ",levels[i][iteration]);
            iteration++;


            diff = levels[i][iteration] - levels[i][iteration + 1];
            if(diff < 0){diff = diff * -1;}
            if(diff > 3){
                break;
            }
            if(levels[i][iteration] < levels[i][iteration +1] && bigger == -1){

            }
            else if(levels[i][iteration] > levels[i][iteration +1] && bigger == 1){

            }
            else {
                contin = false;
            }
        }
        if (contin == true) {
            safe_counter++;
        }
        else {
            contin = true;
        }
        iteration = 0;
        printf("\n");
    }
    printf("safec %d", safe_counter);

    return 0;
}
