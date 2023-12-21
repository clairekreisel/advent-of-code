

int substr_int(char* str, int* i){
    char cur = str[*i];
    int val = 0;
    while(cur >= '0' && cur <= '9'){
        val *= 10;
        val += cur - '0';
        cur = str[i];
    }
    return val;
}

