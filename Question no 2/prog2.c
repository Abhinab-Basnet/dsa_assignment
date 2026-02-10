//Write a program to convert an infix mathematical expression to postfix and evaluate it.


#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}

int priority(char x){
    if(x=='+'|| x =='-')
    return 1;
    if (x =='*'|| x == '/')
    return 2;
    return 0;
}
void infix_to_postfix(char infix[], char postfix[]){
    int i ,k =0;
    char ch;

    for (i=0; infix[i]!='\0';i++){
        ch = infix[i];

        if(isdigit(ch)){
            postfix[k++]=ch;
        }
        else if(ch=='('){
            while(top!= -1 && stack[top]!='('){
                postfix[k++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && priority(stack[top])>=priority(ch)){
                postfix[k++]=pop();
            }
            push(ch);
        }
    }
    while(top!=-1){
        postfix[k++]=pop();
    }
    postfix[k]='\0';
}
int evaluate_postfix(char postfix[]){
    int i;
    int op1, op2, result;
    top=-1;

    for(i=0; postfix[i]!='\0';i++){
        if(isdigit(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            op2=pop();
            op1=pop();

            switch(postfix[i]){
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
            }
            push(result);
        }
    }
    return pop();
}

int main(){
    char infix[MAX], postfix[MAX];
    int value;
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infix_to_postfix(infix,postfix);
    printf("Postfix Expression: %s\n", postfix);

    value = evaluate_postfix(postfix);
    printf("Evaluated Result: %d\n", value);

    return 0;

}