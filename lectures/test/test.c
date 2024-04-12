#include <stdio.h>
#include <stdlib.h>

int main(){
    const int length = 45; 
    FILE *f = fopen("test.txt", "r");
    char *buffer;

    while(fgets(buffer, length, f)){
        printf("%s", buffer);
    }
    
    return 0;
}