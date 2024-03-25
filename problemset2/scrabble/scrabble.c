#include <stdio.h>

int score(char s[]);
void lowerCase(char s[]);

int main(){
    char player1[20];
    char player2[20];
    printf("Player1: ");
    scanf("%s", player1);
    printf("Player2: ");
    scanf("%s", player2);


    // lowerCase(player1);
    // lowerCase(player2);

    int score1 = score(player1);
    int score2 = score(player2);

    if(score1 == score2){
        printf("Tie!\n");
    }
    else if(score1 > score2){
        printf("Player1 wins!\n");
    }
    else if(score1 < score2){
        printf("Player2 wins!\n");
    }
    else{
        return 1;
    }
    return 0;
}

int score(char s[]){
    int score = 0;
    char one[] = {'a', 'e', 'i', 'l', 'n', 'o', 'r', 's', 't', 'u'};
    char two[] = {'d', 'g'};
    char three[] = {'b', 'c', 'm', 'p'};
    char four[] = {'f', 'h', 'v', 'w', 'y'};
    char five[] = {'k'};
    char eight[] = {'j', 'x'};
    char ten[] = {'q', 'z'};

    int next = 0;
    for(int i = 0; i < 20; i++){
        if(s[i] == '\000'){
            return score;
        }
        for(int j = 0; j < 10; j++){
            if(s[i] == one[j]){
                score++;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 2; j++){
            if(s[i] == two[j]){
                score+=2;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 4; j++){
            if(s[i] == three[j]){
                score+=3;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 5; j++){
            if(s[i] == four[j]){
                score+=4;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 1; j++){
            if(s[i] == five[j]){
                score+=5;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 2; j++){
            if(s[i] == eight[j]){
                score+=8;
                next = 1;
                break;
            }
        }
        if(next == 1){
            next = 0;
            continue;
        }
        for(int j = 0; j < 2; j++){
            if(s[i] == ten[j]){
                score+=10;
                next = 1;
                break;
            }
        }
    }
    return 0;
}

void lowerCase(char s[]){
    for(int i = 0; i < 100; i++){
        if(s[i] == '\000'){
            break;
        }
        else{
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = s[i] + 32;
            }
        }
    }
}