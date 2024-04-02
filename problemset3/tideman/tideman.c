#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfString(char string[]);
void sort(int array[], int length);

int main(int argc, char **argv){
    const int votesPerVoter = 3;
    int numberOfCandidates = argc - 1;
    char* candidateList[numberOfCandidates];
    int candidateScore[numberOfCandidates];

    //Converts argv to more understandable variable name whilst removing ./tideman.exe
    for(int i = 0; i < numberOfCandidates; i++){
        candidateList[i] = argv[i+1];
        candidateScore[i] = 0;
    }

    int numberOfVoters;
    printf("Number of voters: ");
    scanf("%i", &numberOfVoters);

    char* votes[numberOfVoters][votesPerVoter];
    
    //Stores all votes in a 2d array
    for(int i = 0; i < numberOfVoters; i++){
        for(int j = 0; j < votesPerVoter; j++){
            char* vote;
            vote = (char*) malloc(100);

            printf("Rank %i: ", j+1);
            scanf("%s", vote);

            int length = lengthOfString(vote);
            vote = (char*) realloc(vote, length);

            votes[i][j] = vote;
        }
        printf("\n");
    }

    //Calculate score for each candidate
    for(int i = 0; i < numberOfVoters; i++){
        for(int j = 0; j < votesPerVoter; j++){
            for(int k = 0; k < numberOfCandidates; k++){
                if(strcmp(votes[i][j], candidateList[k]) == 0){
                    if(j == 0){
                        //first vote
                        candidateScore[k] += 3;
                    }
                    else if(j == 1){
                        //second vote
                        candidateScore[k] += 2;
                    }
                    else if(j == 2){
                        //third vote
                        candidateScore[k]++;
                    }
                }
            }
        }
    }

    int leastToMost[numberOfCandidates];
    for(int i = 0; i < numberOfCandidates; i++){
        leastToMost[i] = candidateScore[i];
    }

    sort(leastToMost, numberOfCandidates);
    int biggest = leastToMost[numberOfCandidates-1];

    //Prints candidates with highest score
    for(int i = 0; i < numberOfCandidates; i++){
        if(candidateScore[i] == biggest){
            printf("%s\n", candidateList[i]);
        }
    }
    return 0;
}

//Calculates the true length of the string to remove garbage data from end
int lengthOfString(char string[]){
    for(int i = 0; i <= 100; i++){
        if(string[i] == '\000'){
            return i;
        }
    }
    return -1;
}

//Bubble sort algorithm so I can find the highest number of votes that a candidate recieved
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