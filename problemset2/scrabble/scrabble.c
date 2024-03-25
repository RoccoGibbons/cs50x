#include <stdio.h>

int lowercase(char input[], int length);
int scores(char input[], int length);

int main(){
    int length = 20;
    char player1[length];
    char player2[length];
    printf("Player1: ");
    scanf("%s", player1);
    printf("Player2: ");
    scanf("%s", player2);

    int length1 = lowercase(player1, length);
    int length2 = lowercase(player2, length);

    int score1 = scores(player1, length1);
    int score2 = scores(player2, length2);
    
    if(score1 == score2){
        printf("Tie!\n");
    }
    else if(score1 > score2){
        printf("Player 1 wins\n");
    }
    else if(score1 < score2){
        printf("Player 2 wins\n");
    }
    else{
        return 1;
    }
    return 0;
}

int lowercase(char input[], int length){
    int count = 0;
    for(int i = 0; i < length; i++){
        if(input[i] == '\000'){
            return count;
        }
        else if(input[i] >= 65 && input[i] <= 90){
            input[i] += 32;
        }
        count++;
    }
    return 1;
}

int scores(char input[], int length){
    int score = 0;

    char one[] = {'a', 'e', 'i', 'l', 'n', 'o', 'r', 's', 't', 'u'};
    char two[] = {'d', 'g'};
    char three[] = {'b', 'c', 'm', 'p'};
    char four[] = {'f', 'h', 'v', 'w', 'y'};
    char five[] = {'k'};
    char eight[] = {'j', 'x'};
    char ten[] = {'q', 'z'};

    for(int i = 0; i < length; i++){
        for(int j = 0; j < 10; j++){
            if(input[i] == one[j]){
                score++;
            }
            else if(input[i] == two[j]){
                score+=2;
            }
            else if(input[i] == three[j]){
                score+=3;
            }
            else if(input[i] == four[j]){
                score+=4;
            }
            else if(input[i] == five[j]){
                score+=5;
            }
            else if(input[i] == eight[j]){
                score+=8;
            }
            else if(input[i] == ten[j]){
                score+=10;
            }
        }
    }
    return score;
}
