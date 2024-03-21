#include <stdio.h>

int main(){
    int size;
    do{
        printf("Enter height of pyramid: ");
        scanf("%d", &size);
        printf("\n");
    }while(size < 1);
    
    int x = size -1;
    for(int i = 0; i < size; i++){
        for(int j = x; j > 0; j--){
            printf(" ");
        }
        x--;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= i; k++){
                printf("#");
            }
            printf("  ");
        }
        printf("\n");
    }

    return 0;
}