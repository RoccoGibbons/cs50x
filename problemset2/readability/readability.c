#include <stdio.h>
#include <math.h>

int numberOfWords(char *text);
int numberOfLetters(char *text);
int numberOfSentences(char *text);
void grader(int grade);

int main(){
    char text[500];
    printf("Text: ");
    fgets(text, 500, stdin);

    int wordCount = numberOfWords(text);
    int letterCount = numberOfLetters(text) -1;
    int sentenceCount = numberOfSentences(text);

    float L = 100.0 * ((float)letterCount / (float)wordCount);
    float S = 100.0 * ((float)sentenceCount / (float)wordCount);

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    grader(grade);

    return 0;
}

int numberOfWords(char *text){
    int wordCount = 0;
    for(int i = 0; i <= 500; i++){
        if((int)text[i] == 32){
            wordCount++;
        }
        else if(text[i] == '\000'){
            wordCount++;
            return wordCount;
        }
    }
    return -1;
}

int numberOfLetters(char *text){
    int letterCount = 0;
    for(int i = 0; i <= 500; i++){
        if((int)text[i] == 32 || (int)text[i] == 33 || (int)text[i] == 44 || (int)text[i] == 46 || (int)text[i] == 63){
            continue;
        }
        else if(text[i] == '\000'){
            return letterCount;
        }
        else{
            letterCount++;
        }
    }
    return -1;
}

int numberOfSentences(char *text){
    int sentenceCount = 0;
    for(int i = 0; i <= 500; i++){
        if((int)text[i] == 33 || (int)text[i] == 46 || (int)text[i] == 63){
            sentenceCount++;
        }
        else if(text[i] == '\000'){
            return sentenceCount;
        }
    }
    return -1;
}

void grader(int grade){
    if(grade <= 1){
        printf("Before Grade 1\n");
    }
    else if(grade >= 16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i", grade);
    }
}