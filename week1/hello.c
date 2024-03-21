#include <stdio.h>

float input();

int main(void){
    float x, y;
    x = input();
    y = input();
    printf("\n%.2f", x/y);
    return 0;
}

float input(){
    float n;
    printf("\nEnter the first number: ");
    scanf_s("%f", &n);
    return n;
}