#include <stdio.h>
#include <string.h>

void greyscale(FILE *input);
void reflected(FILE *input);
void blurred(FILE *input);
void edges(FILE *input);
void header(FILE *input, FILE *output);

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: ./filter [flag] infile");
    }
    
    FILE *input = fopen(argv[2], "r");

    if(strcmp(argv[1], "-g") == 0){
        greyscale(input);
    }
    else if(strcmp(argv[1], "-r") == 0){
        printf("r");
        reflected(input);
    }
    else if(strcmp(argv[1], "-b") == 0){
        blurred(input);
    }
    else if(strcmp(argv[1], "-e") == 0){
        edges(input);
    }
    else{
        printf("Invalid flag, must be -g -r -b or -e");
        return 1;
    }
    

    return 0;
}

void greyscale(FILE *input){
    FILE *output = fopen("greyscale.bmp", "w");


}
void reflected(FILE *input){
    FILE *output = fopen("reflected.bmp", "w");
    
}
void blurred(FILE *input){
    FILE *output = fopen("blurred.bmp", "w");
    
}
void edges(FILE *input){
    FILE *output = fopen("edges.bmp", "w");
    
}

void header(FILE *input, FILE *output){

}