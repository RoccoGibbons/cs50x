#include <stdio.h>
#include <math.h>

int company(long card, int length);
int luhn(long card, int length);

int main(){
    long card;
    printf("Enter your credit card number here: ");
    scanf("%li", &card);;
    int length = log10(card);
    length++;
    luhn(card, length);

    return 0;
}

int company(long card, int length){
    // 0 = invalid, 1 = visa, 2  = mastercard, 3 = americanexpress
    int first = (int)(card / pow(10, length));

    int mastercard[] = {51, 52, 53, 54, 55};
    int americanexpress[] = {34, 37};
    int visa = 4;

    if(first == visa){
        if(length == 13 || length == 16){
            return 1;
        }
    }
    int first2 = (int)(card / pow(10, length-1));

    for(int i = 0; i < 5; i++){
        if(first2 == mastercard[i]){
            if(length == 16){
                return 2;
            }
            return 0;
        }
    }
    for(int i = 0; i < 2; i++){
        if(first2 == americanexpress[i]){
            if(length == 15){
                return 3;
            }
            return 0;
        }
    }

    return 0;
}

int luhn(long card, int length){
    int array[length];
    int tempcard = card;
    int test = 0;

    for(int i = 0; i < length; i++){
        array[length-(i+1)] = tempcard % 10;
        tempcard /= 10;
    }

    int sizeOfDoubled;
    int odd = 0;
    if(length%2 == 0){
        sizeOfDoubled = length/2;
    }
    else{
        sizeOfDoubled = (length-1)/2;
        odd = 1;
    }

    int doubled[sizeOfDoubled];
    int j = 0;
    for(int i = length-2; i > 0; i-=2){
        doubled[j] = array[i] * 2;
        j++;
    }

    if(odd == 1){
        for(int i = 0; i < sizeOfDoubled; i++){
            test += doubled[i];
        }
    }
    else{
        for(int i = 0; i < sizeOfDoubled-1; i++){
            test += doubled[i];
        }
        test += array[0] * 2;
    }
    //test equals every other number from the second to last multiplied by 2
    
    
    return 0;
}