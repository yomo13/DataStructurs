#include <stdio.h>
#include <stdlib.h>


typedef struct Stack{
    int* t;
    int n;
} Stack;



Stack* createStack(int capacity){
    int* t = (int *) malloc(capacity * sizeof(int));
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

void push(Stack* s,int n){
    int* tab = s->t;
    tab[s->n] = n;
    s->n++;
}

int pop(Stack* s){
    if(s->n == 0)
        return -1;

    int* tab = s->t;
    int val = tab[(s->n) -1];
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
    
    int* tab = s->t;
    int size = s->n;

    if(size == 0){
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < size -1; i++)
    {
        printf("%d,",tab[i]);
    }
    printf("(%d)]\n",tab[size-1]);    
}