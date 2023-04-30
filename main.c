#include <stdio.h>
#include <stdlib.h>

#include "lib/Stack.h"

int main(){
    Stack* s = createStack(10);

    printStack(s);
    printf("isEmpty? %d \n",isEmpty(s));


    push(s,8);
    push(s,5);
    push(s,2);

    printStack(s);

    int a = pop(s);
    printf("a=%d \n", a );
    printStack(s);

    push(s,8);
    printStack(s);

    printf("isEmpty? %d \n",isEmpty(s));

    while (!isEmpty(s))
    {
        int a = pop(s);
        printf("%d \n", a);
    }

    printStack(s);
    

    deleteStack(s);

    return 0;
}
