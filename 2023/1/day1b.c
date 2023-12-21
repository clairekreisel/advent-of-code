
#define LINESIZE 51
#include <stdio.h>
#include <stdlib.h>
#include "../util/substring_at.c"
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
    int val = -1;
    while(fgets(line, LINESIZE, cal_file) != NULL){
        for(int i = 0; i < LINESIZE; i++){
            char cur = line[i];
            if(cur == '\0'){
                break;
            }
            if('0' <= cur && cur <= '9'){
                val = cur - '0';
            }
            else if(cur == 'o' && substring_at("ne", i+1, line)){
                val = 1;
                i+=2;
            }
            else if(cur == 't'){
                if(substring_at("hree", i+1, line)){
                    val = 3;
                    i+=4;
                }
                else if(substring_at("wo", i+1, line)){
                    val=2;
                    i+=2;
                }
            }
            else if(cur == 'f'){
                if(substring_at("our", i+1, line)){
                    val = 4;
                    i+=3;
                }
                else if(substring_at("ive", i+1, line)){
                    val=5;
                    i+=3;
                }
            }
            else if(cur == 's'){
                if(substring_at("ix", i+1, line)){
                    val = 6;
                    i+=2;
                }
                else if(substring_at("even", i+1, line)){
                    val=7;
                    i+=4;
                }
            }
            else if(cur == 'e' && substring_at("ight", i+1, line)){
                val = 8;
                i+=4;
            }
            else if(cur == 'n' && substring_at("ine", i+1, line)){
                val = 9;
                i+=3;
            }
            if(d1 == -1){
                d1 = val;
            }
            d2 = val;
        }
        sum += d1*10+d2;
        printf("Value %d for line %d:%s, sum=%d\n", d1*10+d2, lineN, line, sum);
        lineN++;
        d1= -1;
        val = -1;
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
