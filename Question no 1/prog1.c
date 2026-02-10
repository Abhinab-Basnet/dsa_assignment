#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

char stack[MAX];
int top=-1;

//Push function
void push(char ch){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=ch;
}

//Pop Function
char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return 0;
    }
    return stack[top--];
}

//Function to check matching brackets
int is_Matching_Pair(char open, char close){
    if(open=='(' && close==')'){
        return 1;
    }
    if(open=='{' && close=='}'){
        return 1;
    }
    if(open=='[' && close==']'){
        return 1;
    }
    return 0;
}

//Function to check balanced parantheses
int is_Balanced(char expr[]){
    top=-1;

    for (int i=0;i<strlen(expr);i++){
        //if bracket is opening then push to stack
        if(expr[i]=='(' || expr[i]=='{' || expr[i]=='['){
            push(expr[i]);
        }
        //if closing bracket
        else if(expr[i]==')' || expr[i]=='}' || expr[i]==']'){
            if(top==-1)
            return 0;

            char popped=pop();

            if(is_Matching_Pair(popped,expr[i])){
                return 0;
            }
        }
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }

}

int main(){
    char expr[100];

    printf("Enter expression: ");
    fgets(expr, sizeof(expr), stdin);

    if(is_Balanced(expr)){
        printf("Expression id Balanced. \n");
    }
    else{
        printf("Expression is not balanced.\n");
    }
    return 0;
}