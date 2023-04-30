#include <stdio.h>
#include <stdlib.h>

#include "lib/Stack.h"

// Mohamed solution
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


// Houssam solution 
// this function test if the parenthesis are blanced or not
// text is a null terminated string
// return 0 if not balanced 
// retrun other value if balanced
char isParenthesisBalaced(char* text){
    
    //get a stack of size 50
    Stack* stack = createDefaultStack();
    
    // loop thro the string char by char
    for(int i=0;text[i]!='\0';i++){
        char c = text[i];
        
        //push opening characteres 
        if(c == '{' || c == '[' || c == '(' ){
            push(stack,c);
            continue;
        }


        // test with closing characters
        if(c == '}'){
            char val = pop(stack);
            if(val != '{')
                return 0;
        }

        if(c == ']'){
            char val = pop(stack);
            if(val != '[')
                return 0;
        }

        if(c == ')'){
            char val = pop(stack);
            if(val != '(')
                return 0;
        }
    }
    
    //if the stack is not empty retrun 0
    return (stack->n == 0);
}

int main(){
    
    char a[] = "[qskldjf qsfk qskldfj jfqsdfkl]"; //true
    char b[] = "[(abc)()]";//true
    char c[] = "{[()]}";//true
    char d[] = "([)]"; //false
    char e[] = "((())()"; //false
    

    //Moh solution
    printf("moh solution \n");
    printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n",test(a),test(b),test(c),test(d),test(e));
    
    //Houssam solution
    printf("Houssam solution \n");
    printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\n",
        isParenthesisBalaced(a),
        isParenthesisBalaced(b),
        isParenthesisBalaced(c),
        isParenthesisBalaced(d),
        isParenthesisBalaced(e));
    
    return 0;
}
