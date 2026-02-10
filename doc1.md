## Checking Balanced Parantheses Using Stack in C

## INTRODUCTION
This document describes a C program that checks whether a given mathematical expression contains a balanced number of parentheses. The program uses the **stack data structure** implemented using an array and follows the **LIFO(Last In First Out)** principle.
In this program, a stack is used to keep track of opening brackets while scanning the expression.
## OBJECTIVES
To write a C program that check whether a given mathematical expression has a balanced number of parentheses using the **stack data structure.**

## ALGORITHM STEPS

1. Start

2. Initialize

 - Declare a stack of size MAX.

 - Set top = -1 to indicate an empty stack.

3. Input

- Read the mathematical expression as a string.

4. Scan the Expression

- Traverse the expression character by character from left to right.

5. If Opening Parenthesis Found

- If the character is (, {, or [, push it onto the stack.

6. If Closing Parenthesis Found

 - If the character is ), }, or ]:

  1. Check if the stack is empty.

   - If empty, the expression is not balanced → Stop.

  2. Pop the top element from the stack.

  3. Check whether the popped opening parenthesis matches the current closing parenthesis.

    - If they do not match, the expression is not balanced → Stop.

7. After Complete Traversal

 - Check if the stack is empty:

   - If empty, the expression is balanced.

   - If not empty, the expression is not balanced.

8. Display Result

 - Print whether the expression has balanced or unbalanced parentheses.

9. Stop

## DATA STRUCTURES USED

## Stack Definition

The stack is implemented using an array of characters.
```bash
#define MAX 100
char stack[MAX];
int top = -1;
```
**Explanation**

- **stack[MAX]**

Stores opening brackets encountered in the expression.

- **top** 

Keeps tracks of index of the topmost element in the stack.

-  **top=-1** indicates that the stack is empty.

The stack is used to temporarily store opening bracket until a corresponding closing bracket is found.

## DESCRIPTION OF FUNCTIONS IMPLEMENTED

1. **push(char ch)**

**Purpose:**

Pushes an opening bracket onto the stack.

**Description**

The top index is incremented first and then the character is sorted at that position.
```bash
void push(char ch){
stack[++top]=ch;
}
```
2. **pop()**

**Purpose:**

Removes and returns the top element from the stack.

**Description:**

The character at the current top position is returned and then top is decremented.
```bash
char pop(){
return stack[top --];
}
```
3. **is_Matching_Pair(char open, char close)**

**Purpose:**

Checks whether an opening bracket matches the corresponding closing brackets.

**Description**

Returns 1 if the brackets match, otherwise return 0.

4. **is_Balanced(char exp[])**

**Purpose:**

Determine whether the given expression has balanced parentheses.

**Description:**

. Scan the expression character by character.
. Pushes opening brackets onto the stack.
. Pops and matches brackets when a closing bracket is found.
. Return 1 if balanced, otherwise 0.

## ORGANIZATION OF THE main() FUNCTION
The main() function is organised as follow:

1. Declares a character array to store the input expression.

2. Accepts the expression from the user.

3. Calls the isBalanced() function.

4. Display whether the expression is balanced or not.

## CONCLUSION
The program successfully checks whether a mathematical expression has balanced parantheses using a stack. It correctly detects missing, extra or mismatched brackets by following the LIFO principle of stack operartions.