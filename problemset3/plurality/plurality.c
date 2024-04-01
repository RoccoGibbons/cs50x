#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfString(char string[]);
void sort(int array[], int length);

int main(int argc, char **argv){
    if(argc == 1){
        printf("Usage: ./plurality [candidate ...]");
    }

    else{
        int amountOfCandidates = argc - 1;

        char* candidateList[amountOfCandidates];
        for(int i = 1; i < argc; i++){
            candidateList[i-1] = argv[i];
        }

        int candidateVotes[amountOfCandidates];
        for(int i = 0; i < amountOfCandidates; i++){
            candidateVotes[i] = 0;
        }

        int voters;
        printf("Number of voters: ");
        scanf("%i", &voters);

        for(int i = 0; i < voters; i++){
            char *vote;
            vote = (char*) malloc(100);

            printf("Vote: ");
            scanf("%s", vote);

            int length = lengthOfString(vote);
            vote = (char*) realloc(vote, length);

            for(int j = 0; j < amountOfCandidates; j++){
                if(strcmp(vote, candidateList[j]) == 0){
                    candidateVotes[j]++;
                    break;
                }
                else if(j == argc - 1){
                    printf("Invalid vote\n");
                }
            }

            free(vote);
        }
        
        int sorted[amountOfCandidates];

        for(int i = 0; i < amountOfCandidates; i++){
            sorted[i] = candidateVotes[i];
        }

        sort(sorted, amountOfCandidates);

        int biggest = sorted[amountOfCandidates-1];

        for(int i = 0; i < amountOfCandidates; i++){
            if(candidateVotes[i] == biggest){
                printf("%s\n", candidateList[i]);
            }
        }
    }
    return 0;
}

int lengthOfString(char string[]){
    for(int i = 0; i <= 100; i++){
        if(string[i] == '\000'){
            return i;
        }
    }
    return -1;
}

void sort(int array[], int length) {
    for(int i = 0; i < length - 1; ++i) { 
        int swapped = 0;
        for (int j = 0; j < length - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
    if (swapped == 0) {
      break;
    }
  }
}