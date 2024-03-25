#include <stdio.h>

int main(int argc, char *argv[]){
    for(int i = 0; i < argc; i++){
        char *test = argv[i];
        printf("%s\n", test);
    }
    return 0;
}