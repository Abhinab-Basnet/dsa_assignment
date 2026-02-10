## Infix to Postfix Conversion and Evaluation using Stack

## INTRODUCTION
This program converts a given infix mathematical expression into its equivalent postfix expression and evaluates the postfix expression using stack data structures. Stack follows the LIFO(Last In First Out) principle and are ideal for expression evaluation.

## OBJECTIVES
To write a C program that:
1. Converts a given **infix mathematical expression** into its equivalent **postfix expression**.
2. Evaluate the postfix expression using the **stack data structure**.

## ALGORITHM STEPS

## Part A: Infix to Postfix Conversion

1. Start

2. Initialize

   - Declare a character stack of size MAX.

   - Set top = -1 to indicate an empty stack.

   - Declare an empty array postfix.

3. Input

   - Read the infix expression.

4. Scan the Infix Expression

   - Traverse the infix expression character by character.

5. If Operand Found

   - If the character is a digit, append it directly to the postfix expression.

6. If Opening Parenthesis Found

   - Push ( onto the stack.

7. If Closing Parenthesis Found

   - Pop operators from the stack and append them to the postfix expression until ( is encountered.

   - Pop and discard the ( from the stack.

8. If Operator Found

   - While the stack is not empty and the precedence of the operator on the stack is greater than or equal to the current operator:

   - Pop the operator from the stack and append it to the postfix expression.

   - Push the current operator onto the stack.

9. After Complete Traversal

   - Pop all remaining operators from the stack and append them to the postfix expression.

10. Terminate Postfix Expression

   - Add null character \0 at the end.

## Part B: Evaluation of Postfix Expression

1. Initialize

   - Reset stack (top = -1).

2. Scan the Postfix Expression

   - Traverse the postfix expression character by character.

3. If Operand Found

   - Convert character to integer and push it onto the stack.

4. If Operator Found

   - Pop two operands from the stack.

    - First pop → second operand (op2)

    - Second pop → first operand (op1)

   - Perform the operation based on the operator.

   - Push the result back onto the stack.

5. After Complete Traversal

   - Pop the final value from the stack. This is the evaluated result.

## DATA STRUCTURE USED
The program uses **stack** implemented using an array to store operators during infix to postfix conversion and operands during postfix evaluation.
```bash
#define MAX 100
char stack[MAX];
int top = -1;
```
**Explanation**


- **Stack[MAX]**

stores operators(+,-,*,/,(,)) during conversion and operands during evaluation.

-  **top**

keep track of index of the top element in the stack.

- **top = -1** indicates that the stack is empty.

## DESCRIPTION OF FUNCTION IMPLEMENTED

1. **push(char x)**

Purpose:

Pushes an element onto the stack.
```bash
void push(char x) {
    stack[++top] = x;
}
```
2. **pop()**

Purpose:

Removes and returns the top element from the stack.
```bash
char pop() {
    return stack[top--];
}
```
3. **priority(char x)**

Purpose:

Returns the precedence of operators.
```bash
int priority(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}
```
4. **infix_to_postfix(char infix[], char postfix[])**

Purpose:

Converts an infix to postfix form.

Description:

.Operands are added directly to postfix expression.
.Operators are pushed based on precedence.
.Parentheses control operator popping.
```bash
void infix_to_postfix(char infix[], char postfix[]){
    int i ,k =0;
    char ch;

    for (i=0; infix[i]!='\0';i++){
        ch = infix[i];

        if(isdigit(ch)){
            postfix[k++]=ch;
        }
        else if(ch==')'){
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
```
5. **evaluate_postfix(char postfix[])**

Purpose:

Evaluates the postfix expression using a stack.

Description:

- Operands are pushed onto the stack.
- Operators pop two operands and compute the result.
- Final result remain at the top of the stack.
```bash
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
                case '/': result = op1 / op2: break;
            }
            push(result);
        }
    }
    return pop();
}
```
## ORGANIZATION OF main() FUNCTION

1. Reads the infix expression from the user.

2. Converts infix to postfix.

3. Displays postfix expression.

4. Evaluates postfix expression.

5. Displays the final result.

```bash
int main(){
    char inifix[MAX], postfix[MAX];
    int value;
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);

    infix_to_postfix(infix,postfix);
    printf("Postfix Expression: %s\n", postfix);

    value = evaluate_postfix(postfix);
    printf("Evaluated Result: %d\n", value);

    return 0;
    
}
```
## SAMPLE OUTPUT
```bash
Enter infix expression: (3+5)*2
Postfix Expression: 35+2*
Evaluated Result: 16
```

## CONCLUSION
This program demonstrate the effective use of stack to convert an infix expression into  postfix form and evaluate it. The approach simplifies expression evaluation by eliminating parentheses and precedance rules, making it efficient and reliable.