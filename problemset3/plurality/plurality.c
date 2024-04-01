#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shorten(char string[]);
void sort(int sorted[], int argc, int voters);

int main(int argc, char **argv){
    if(argc == 1){
        printf("./plurality.exe candidate1 candidate2....");
    }
    else{
        int numberOfVotesForCandidate[argc];
        for(int i = 0; i < argc; i++){
            numberOfVotesForCandidate[i] = 0;
        }

        int voters;
        printf("Number of voters: ");
        scanf("%i", &voters);

        for(int i = 0; i < voters; i++){
            char *vote;
            vote = (char*) malloc(100);

            printf("Vote: ");
            scanf("%s", vote);

            int length = shorten(vote);
            vote = (char*) realloc(vote, length);

            for(int j = 1; j < argc; j++){
                if(strcmp(vote, argv[j]) == 0){
                    numberOfVotesForCandidate[j]++;
                }
                else if(j == argc - 1){
                    printf("Invalid vote\n");
                }
            }

            free(vote);
            }

        int sorted[argc];
        for(int i = 0; i < argc; i++){
            numberOfVotesForCandidate[i] = sorted[i];
        }
        sort(sorted, argc, voters);

        for(int i = 0; i < argc; i++){
            printf("%i ", sorted[i]);
        }

    }
    return 0;
}

int shorten(char string[]){
    for(int i = 0; i <= 100; i++){
        if(string[i] == '\000'){
            return i;
        }
    }
    return -1;
}

void sort(int sorted[], int argc, int voters){
    for(int i = 0; i < argc-1; i++){
        if(sorted[i] > sorted[i+1]){
            int temp = sorted[i];
            sorted[i] = sorted[i+1];
            sorted[i+1] = temp;
        }
    }
}