#include <stdio.h>
#include <stdlib.h>


typedef struct Stack{
    char* t;
    int n;
} Stack;



Stack* createStack(int capacity){
    char* t = (char *) malloc(capacity * sizeof(char));
    Stack* s = (Stack*) malloc(sizeof(Stack));
    (*s).t = t;
    s->n=0;
    return s;
}

Stack* createDefaultStack(){
    return createStack(50);
}

void deleteStack(Stack* s){
    free(s->t);
    free(s);
}

void push(Stack* s,char c){
    char* tab = s->t;
    tab[s->n] = c;
    s->n++;
}

char pop(Stack* s){
    if(s->n == 0)
        return 0;

    char* tab = s->t;
    char val = tab[(s->n) -1];
    s->n--;
    return val;
}

int size(Stack* s){
    return s->n;
}

char isEmpty(Stack* s){
    return !(s->n);
}

void printStack(Stack *s){
    
    char* tab = s->t;
    int size = s->n;

    if(size == 0){
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < size -1; i++)
    {
        printf("%c,",tab[i]);
    }
    printf("(%c)]\n",tab[size-1]);    
}