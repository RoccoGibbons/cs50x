#include <stdio.h>

int main(){
    printf("What is your name? ");
    char name[100];
    scanf("%[^\n]s", name);
    printf("Hello, %s", name);
    return 0;
}