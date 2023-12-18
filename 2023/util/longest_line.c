#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define MAXC 255

int longest_line(char* filepath);

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("Requires at least one file\n");
        return EINVAL;
    }
    int cur_line;
    for(int i = 1; i < argc; i++){
        cur_line = longest_line(argv[i]);
        printf("Longest line in %s is %d chars long.\n", argv[i], cur_line);
    }
    return 0;
}

int longest_line(char* filepath){
    FILE* curf = fopen(filepath, "r");
    char line[MAXC];
    int max_len = -1;
    int cur_len = 0;
    while(fgets(line, MAXC, curf) != NULL){
        for(int i = 0; i < MAXC; i++){
            if(line[i] == '\n'){
                if(cur_len > max_len){
                    max_len = cur_len;
                }
                cur_len = 0;
                break;
            }
            else{
                cur_len++;
            }
        }
    }
    fclose(curf);
    return max_len;
}

