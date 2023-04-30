#include <stdio.h>
#include <stdlib.h>

#include "lib/Stack.h"

int sherching (char *a,char c_start,char c_end){
    int endis;
    for(int i=0;a[i]!='\0';i++){

        if (a[i]==c_end)
            return i;
        
        if ((a[i]==')')&&(a[i]!=c_end))
            return 0;
        
        if ((a[i]==']')&&(a[i]!=c_end))
            return 0;

        if ((a[i]=='}')&&(a[i]!=c_end))
            return 0;
        
        if (a[i]=='('){
            endis=sherching(&a[i+1],'(',')');
            if ((endis)==0)
                return 0;
            i=endis;
        }

        else if (a[i]=='['){
            endis=sherching(&a[i+1],'[',']');
            if ((endis)==0)
                return 0;
            i=endis;
        }

        else if (a[i]=='{'){
            endis=sherching(&a[i+1],'{','}');
            if ((endis)==0)
                return 0;
            i=endis;
        }

        else if (a[i]==c_start){
            endis=sherching (&a[i+1],c_start,c_end);
            if ((endis)==0)
                return 0;
            i=endis;
        }

    }
    return 0;
}
int test (char *a){
    int endis;
    for(int i=0;a[i]!='\0';i++){

        if(a[i]==')')
        return 0;
        if(a[i]==']')
        return 0;
        if(a[i]=='}')
        return 0;

        if(a[i]=='('){
            endis=sherching(&a[i+1],'(',')');
            if ((endis)==0)
                return 0;
            i=endis;
        }
        else if(a[i]=='['){
            endis = sherching(&a[i+1],'[',']');
            if ((endis)==0)
                return 0;
            i=endis;
        }
        else if(a[i]=='{'){
            endis=sherching(&a[i+1],'{','}');
            if ((endis)==0)
                return 0;
            i=endis;
        }
    }
    return 1;
}


int main(){
    
    char a[] = "[qskldjf qsfk qskldfj jfqsdfkl]"; //true
    char b[] = "[(abc)()]";//true
    char c[] = "{[()]}";//true
    char d[] = "([)]"; //false
    char e[] = "((())()"; //false
    
    
    /*
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
    */
    printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n",test(a),test(b),test(c),test(d),test(e));
    return 0;
}
