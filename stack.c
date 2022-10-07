#include "stack.h"

#define ITEM 50
#define EXP_SIZE 200

// intializes the operator stack
void optrinit(operatorstack *s){
    s->array = (char*)malloc(sizeof(char)*ITEM);
    s->top = -1;
}

// initializes the operand stack
void opndinit(operandstack *s){
    s->array = (num *)malloc(sizeof(num)*ITEM);
    s->top = -1;
}

// returns true if operator stack is full
int optrstackfull(operatorstack s){
    if (s.top == ITEM - 1){
        //printf("Stack full");
        return 1;
    }
    else
        return 0;
}

// returns true if operand stack is full
int opndstackfull(operandstack s){
    if (s.top == ITEM - 1){
        //printf("Stack full");
        return 1;
    }
    else
        return 0;
}

// returns true if operator stack is empty
int optrstackempty(operatorstack s){
    if(s.top == -1){
        //printf("Stack empty");
        return 1;
    }
    else
        return 0;
}

// returns true if operand stack is empty
int opndstackempty(operandstack s){
    if(s.top == -1){
        //printf("Stack empty");
        return 1;
    }
    else
        return 0;
}

// pushes operator in operator stack
void pushoperator(operatorstack* s, char ch){
    if(optrstackfull(*s)){
        printf("Stack overflow");
    }
    else {
        s->top++;
        s->array[s->top] = ch;
    }
    return;
}

// pushes operand into operand stack
void pushoperand(operandstack *s, num n){
    num* p = NULL;
    p = &n;
    if (opndstackfull(*s)){
        printf("Stack overflow");
    }
    else{
        s->top++;
        s->array[s->top] = *p;
    }
    return;
}

// pops the top element from operand stack
num popoperand(operandstack *s){
    num* e = NULL;
    if(opndstackempty(*s) != 1){
        e = &(s->array[s->top]);
        s->top--;
    }
    return *e;
}

// pops the top element from operator stack
char popoperator(operatorstack *s){
    char e = '#';
    if(optrstackempty(*s) != 1){
        e = s->array[s->top];
        s->top--;
    }
    return e;
}

// returns the top operator element
char peekoperator(operatorstack s){
    return s.array[s.top];
}

// returns the top num element
num peekoperand(operandstack s){
    return s.array[s.top];
}
