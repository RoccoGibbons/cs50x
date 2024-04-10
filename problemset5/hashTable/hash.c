#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
// #include <stdint.h>
//This is for me to understand how hash tables work as I didn't quite understand them

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
    char *name;
    int age;
    struct person *next;
}person;

person *hashTable[TABLE_SIZE];

unsigned int hash(char *name);
void initialise();
void printTable();
bool hashTableInsert(person *p);
person *lookup(char *name);
person *delete(char *name);

int main(){
    initialise();

    person sam = {.name = "sam", .age = 15};
    person rocco = {.name = "rocco", .age = 16};
    person alfie = {.name = "alfie", .age = 43};
    person michael = {.name = "michael", .age = 5};
    person will = {.name = "will", .age = 21};
    person teyani = {.name = "teyani", .age = 67};
    person jasmine = {.name = "jasmine", .age = 16};
    person russ = {.name = "russ", .age = 50};
    person jo = {.name = "jo", .age = 47};
    person liam = {.name = "liam", .age = 14};
    person jack = {.name = "jack", .age = 17};

    hashTableInsert(&sam);
    hashTableInsert(&rocco);
    hashTableInsert(&alfie);
    hashTableInsert(&michael);
    hashTableInsert(&will);
    hashTableInsert(&teyani);
    hashTableInsert(&jasmine);
    hashTableInsert(&russ);
    hashTableInsert(&jo);
    hashTableInsert(&liam);
    hashTableInsert(&jack);

    printTable();

    person *tmp = lookup("alfie");
    if(tmp == NULL){
        printf("Not found\n");
    }
    else{
        printf("Found %s\n", tmp->name);
    }

    delete("alfie");
    printTable();
    tmp = lookup("alfie");
    if(tmp == NULL){
        printf("Not found \n");
    }
    else{
        printf("Found %s\n", tmp->name);
    }

    return 0;
}

unsigned int hash(char *name){
    int length = strlen(name);
    unsigned int hashValue = 0;
    for(int i = 0; i < length; i++){
        hashValue += name[i];
        hashValue = (hashValue * name[i]) % 10;
    }
    return hashValue;
}

void initialise(){
    for(int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
}

void printTable(){
    printf("Start\n");
    for(int i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i] == NULL){
            printf("%i\t---\n", i);
        }
        else{
            printf("%i\t", i);
            person *tmp = hashTable[i];
            while(tmp != NULL){
                printf("%s -", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hashTableInsert(person *p){
    if(p ==  NULL) return false;
    int index = hash(p->name);

    p->next = hashTable[index];
    hashTable[index] = p;    
    return true;
}

person *lookup(char *name){
    int index = hash(name);
    person *tmp = hashTable[index];
    while(tmp != NULL && strcmp(tmp->name, name) != 0){
        tmp = tmp-> next;
    }
    return tmp;
}

person *delete(char *name){
    int index = hash(name);
    person *tmp = hashTable[index];
    person *prev = NULL;
    while(tmp != NULL && strcmp(tmp->name, name) != 0){
        prev = tmp;
        tmp = tmp-> next;
    }
    if(tmp != NULL) return NULL;
    if(prev == NULL){
        hashTable[index] = tmp-> next;
    }
    else{
        prev->next = tmp->next;
    }
    return tmp;
}