#include <stdio.h>

int main(void){
    int size;
    //prompt user for positive int
    do{
        printf("\nSize: ");
        scanf_s("%i", &size);
    }
    while(size < 1);
    
    //print n by n grid of bricks
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}