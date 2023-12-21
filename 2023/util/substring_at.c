#include <stdio.h>
//returns bool (0 if false, 1 if true) if substring is at the location
//if substring length > 255, assumes it is not null terminated, returns 0
#define CCK_SUBSTRING_AT_MAX_SUB_LEN 255
#define CCK_SUBSTRING_AT__DEBUG 0
int substring_at(char* substring, int loc, char* string){
    for(int i = 0; i < CCK_SUBSTRING_AT_MAX_SUB_LEN; i++){
        if(substring[i] == '\0'){
            return 1;
        }
        else if(substring[i] != string[loc+i]){
            #if CCK_SUBSTRING_AT__DEBUG == 1
            printf("Mismatch at %d, %c != %c\n", loc+i, substring[i], string[loc+i]);
            #endif
            return 0;
        }
        else if(string[loc+i] == '\0'){
            #if CCK_SUBSTRING_AT__DEBUG == 1
            printf("End of string.\n");
            #endif
            return 0;
        }
    }
    #if CCK_SUBSTRING_AT__DEBUG == 1
    printf("Substring longer than max length %d\n", CCK_SUBSTRING_AT_MAX_SUB_LEN);
    #endif
    return 0;
}
