#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int lengthOfString(string myString);
void sort(int array[], int length);

int main(int argc, char **argv){
    if(argc == 1){
        printf("Usage: ./plurality [candidate ...]");
    }
    else{
        const int votesPerVoter = 3;
        int numberOfCandidates = argc - 1;
        int numberOfPairs;
        string candidateList[numberOfCandidates];
        int candidateScore[numberOfCandidates];

        if(numberOfCandidates == 1){
            printf("%s", candidateList[0]);
            return 0;
        }
        else{
            //Calculation to find number of pairs depending on how many candidates there are without repeats
            int n = numberOfCandidates - 1;
            numberOfPairs = (0.5 * (n * n)) + (0.5 * n);
        }

        string pairsOfCandidates[numberOfPairs][2];

        //Converts argv to more understandable variable name whilst removing ./tideman.exe
        for(int i = 0; i < numberOfCandidates; i++){
            candidateList[i] = argv[i+1];
            candidateScore[i] = 0;
        }
        
        //Puts all the candidates into pairs
        int index1 = 0;
        int index2 = 1;
        for(int i = 0; i < numberOfPairs; i++){
            pairsOfCandidates[i][0] = candidateList[index1];
            pairsOfCandidates[i][1] = candidateList[index2];
            if(index2 >= numberOfCandidates - 1){
                index1++;
                index2 = index1 + 1;
            }
            else{
                index2++;
            }
        }

        int numberOfVoters;
        printf("Number of voters: ");
        scanf("%i", &numberOfVoters);

        string votes[numberOfVoters][votesPerVoter];
        
        //Stores all votes in a 2d array
        for(int i = 0; i < numberOfVoters; i++){
            for(int j = 0; j < votesPerVoter; j++){
                string vote;
                vote = (string) malloc(100);

                printf("Rank %i: ", j+1);
                scanf("%s", vote);

                int length = lengthOfString(vote);
                vote = (string) realloc(vote, length);

                int validCandidate = 0;
                for(int k = 0; k < numberOfCandidates; k++){
                    if(strcmp(vote, candidateList[k]) == 0){
                        validCandidate = 1;
                    }
                }
                if(validCandidate == 1){
                    votes[i][j] = vote;
                }
                else{
                    printf("This is not a valid candidate option\n");
                    j--;
                }
            }
            printf("\n");
        }
        
        int x,y;
        for(int i = 0; i < numberOfVoters; i++){
            for(int j = 0; j < numberOfPairs; j++){
                for(int k = 0; k < votesPerVoter; k++){
                    //Find the index of each value in each pair in the user votes
                    if(strcmp(pairsOfCandidates[j][0], votes[i][k]) == 0){
                        x = k;
                        break;
                    }
                    if(strcmp(pairsOfCandidates[j][1], votes[i][k]) == 0){
                        y = k;
                        break;
                    }
                }
                //The lower one the user entered first/ before other option so is preferred
                if(x < y){
                    for(int l = 0; l < numberOfCandidates; l++){
                        if(strcmp(votes[i][x], candidateList[l]) == 0){
                            candidateScore[l]++;
                        }
                    }
                }
                else if(y < x){
                    for(int l = 0; l < numberOfCandidates; l++){
                        if(strcmp(votes[i][y], candidateList[l]) == 0){
                            candidateScore[l]++;
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
    }
    return 0;
}

//Calculates the true length of the string to remove garbage data from end
int lengthOfString(string myString){
    for(int i = 0; i <= 100; i++){
        if(myString[i] == '\000'){
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