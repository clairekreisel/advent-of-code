#include "../util/substring_at.c"
#include <stdio.h>

int main(){
printf("Substring %s in %s at %d: %d\n", "a", "cba", 2, substring_at("a", 2, "cba"));
printf("Substring %s in %s at %d: %d\n", "orple", "grunorplemango", 4, substring_at("orple", 4, "grunorplemango"));
}
