#include <stdio.h>

int lengthChecker(char plaintext[]);
void substitution(char plaintext[], int length, char *key[]);
char lower(char letter);
char upper(char letter);

int main(int argc, char **argv){
    if(argc != 2){
        printf("Usage: ./substitution key\n");
    }
    else if(argv[1][26] != '\000'){
        printf("Key must contain 26 characters");
    }
    else{
        char plaintext[100];
        printf("plaintext: ");
        fgets(plaintext, 100, stdin);

        int length = lengthChecker(plaintext);

        substitution(plaintext, length, argv);

    }
    return 0;
}

int lengthChecker(char plaintext[]){
    int length;
    for(int i = 0; i < 100; i++){
        if(plaintext[i] == '\000'){
            length = i;
            return length;
        }
    }
    return -1;
}

void substitution(char plaintext[], int length, char *key[]){
    char ciphertext[length];
    char alphabetL[] = {"abcdefghijklmnopqrstuvwxyz"};
    char alphabetU[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    
    for(int i = 0; i < length; i++){
        for(int j = 0; j < 27; j++){
            if(plaintext[i] == alphabetL[j]){
                ciphertext[i] = lower(*key[j]);
            }
            else if(plaintext[i] == alphabetU[j]){
                ciphertext[i] = upper(*key[j]);
            }
        }
    }
    printf("ciphertext: %s\n", ciphertext);
}

char lower(char letter){
    if(letter >= 65 && letter <= 90){
        letter = letter + 32;
    }
    return letter;
}

char upper(char letter){
    if(letter >= 97 && letter <= 122){
        letter = letter - 32;
    }
    return letter;
}