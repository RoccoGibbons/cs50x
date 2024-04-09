#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct person{
    struct person *parents[2];
    char alleles[2];
}person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *createFamily(int generations);
char randomAllele();
void printFamily(person *p, int generation);
void freeFamily(person *p);

int main(){
    srand(time(0));

    person *p = createFamily(GENERATIONS);

    printFamily(p, 0);

    freeFamily(p);

    return 0;
}

person *createFamily(int generations){
    person *new = malloc(sizeof(person));

    if (generations > 1){
        person *parent0 = createFamily(generations - 1);
        person *parent1 = createFamily(generations - 1);

        new->parents[0] = parent0;
        new->parents[1] = parent1;

        new->alleles[0] = parent0->alleles[rand() % 2];
        new->alleles[1] = parent1->alleles[rand() % 2];
    }

    else{
        new->parents[0] = NULL;
        new->parents[1] = NULL;

        new->alleles[0] = randomAllele();
        new->alleles[1] = randomAllele();
    }

    return new;
}

void printFamily(person *p, int generation){
    if (p == NULL){
        return;
    }

    for (int i = 0; i < generation * INDENT_LENGTH; i++){
        printf(" ");
    }

    if (generation == 0){
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1){
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else{
        for (int i = 0; i < generation - 2; i++){
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    printFamily(p->parents[0], generation + 1);
    printFamily(p->parents[1], generation + 1);
}

char randomAllele(){
    int r = rand() % 3;
    if (r == 0){
        return 'A';
    }
    else if (r == 1){
        return 'B';
    }
    else{
        return 'O';
    }
}

void freeFamily(person *p){
    if(p == NULL){
        return;
    }

    freeFamily(p->parents[0]);
    freeFamily(p->parents[1]);

    free(p);
}