#define LINESIZE 51
#define NRED 12
#define NBLU 14
#define NGRE 13

#include <stdio.h>
#include <stdlib.h>
#include "../util/substring_at.c"
#include "../util/substr_int.c"

int game_possible(char* game, int len){
    int i = 5;
    int id = substr_int(game, &i);
    char cur = game[i];
    i+=2;
    int cur_n;
    while(cur != '\0'){
        cur_n = substr_int(game, &i);
        i++;
        if(substring_at("green", i, game)){
            if(cur_n > NGRE){
                return 0;
            }
            i += 5;
        }
        else if(substring_at("blue", i, game)){
            if(cur_n > NBLU){
                return 0;
            }
            i += 4;
        }
        else if(substring_at("red", i, game)){
            if(cur_n > NRED){
                return 0;
            }
            i += 4;
        }
        cur = game[i];
        i+=2;
    }
    return id;
}


int get_game_sum(FILE* game_file){
    if(game_file == NULL){
        printf("File not open, failing.\n");
        return -1;
    }
    char line[LINESIZE];
    int sum = 0;
    while(fgets(line, LINESIZE, game_file) != NULL){
         sum += game_possible(line, LINESIZE);
    }
    return sum;
}






int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Should have 1 argument, has %d\n", argc-1);
        return -1;
    }
    FILE* file = fopen(argv[1], "r");
    int sum = get_game_sum(file);
    fclose(file);
    printf("Sum is: %d\n", sum);
    return 0;
}
