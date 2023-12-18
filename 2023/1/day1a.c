
#define LINESIZE 51
#include <stdio.h>
#include <stdlib.h>

int get_calibration_value(FILE* cal_file){
    if(cal_file == NULL){
        printf("File not open, failing.\n");
        return -1;
    }
    char line[LINESIZE];
    int sum = 0;
    int d2;
    int d1 = -1;
    int lineN=1;
    while(fgets(line, LINESIZE, cal_file) != NULL){
        for(int i = 0; i < LINESIZE; i++){
            char cur = line[i];
            if(cur == '\0'){
                break;
            }
            if('0' <= cur && cur <= '9'){
                if(d1 == -1){
                    d1 = cur - '0';
                }
                d2 = cur - '0';
            }
        }
        sum += d1*10+d2;
        printf("Value %d for line %d, sum=%d\n", d1*10+d2, lineN, sum);
        lineN++;
        d1=-1;
    }
    return sum;
}

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Should have 1 argument, has %d\n", argc-1);
        return -1;
    }
    FILE* file = fopen(argv[1], "r");
    int cal = get_calibration_value(file);
    fclose(file);
    printf("Calibration value is: %d\n", cal);
    return 0;
}
