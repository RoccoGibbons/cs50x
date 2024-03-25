#include <stdio.h>
#include <math.h>

int company(long long card, int length);
int luhn(long long card, int length);

int main(){
    long long card;
    
    printf("Enter your credit card number here: ");
    scanf("%lli", &card);;

    int length = log10(card);
    length++;

    int valid = luhn(card, length);

    if(valid == 1){
        int comp = company(card, length);
        if(comp == 1){
            printf("VISA");
        }
        else if(comp == 2){
            printf("MASTERCARD");
        }
        else if(comp == 3){
            printf("AMERICAN EXPRESS");
        }
        else{
            printf("INVALID LENGTH");
        }
    }
    else{
        printf("INVALID LUHN EQUATION");
    }
    return 0;
}

int company(long long card, int length){
    int first = (int)(card / pow(10, length - 1));

    int mastercard[] = {51, 52, 53, 54, 55};
    int americanexpress[] = {34, 37};
    int visa = 4;

    if(first == visa){
        if(length == 13 || length == 16){
            return 1;
        }
    }

    int first2 = (int)(card / pow(10, length-2));

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

int luhn(long long card, int length){
    int array[length];
    long long tempcard = card;
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
            if(doubled[i] > 9){
                test += doubled[i] % 10;
                doubled[i] /= 10;
                test += doubled[i];
            }
            else{
                test += doubled[i];
            }
        }
    }
    else{
        for(int i = 0; i < sizeOfDoubled-1; i++){
            if(doubled[i] > 9){
                test += doubled[i] % 10;
                doubled[i] /= 10;
                test += doubled[i];
            }
            else{
                test += doubled[i];
            }
        }
        int x = array[0] * 2;
        if(x > 9){
            test += x % 10;
            x /= 10;
            test += x;
        }
        else{
            test += array[0] * 2;
        }
    }

    for(int i = length-1; i >= 0; i-=2){
        test += array[i];
    }

    if(test % 10 == 0){
        return 1;
    }
    return 0;
}