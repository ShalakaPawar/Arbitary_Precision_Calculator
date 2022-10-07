#include "number.h"

typedef struct operatorstack{
    int top;
    char* array;
}operatorstack;

typedef struct operandstack{
    int top;
    num* array;
}operandstack;

void operatorinit(operatorstack *s);
void operandinit(operandstack *s);
int optrstackfull(operatorstack s);
int opndstackfull(operandstack s);
int optrstackempty(operatorstack s);
int opndstackempty(operandstack s);
int opndstackempty(operandstack s);
void pushoperand(operandstack *s, num n);
void pushoperator(operatorstack* s, char ch);
char popoperator(operatorstack *s);
num popoperand(operandstack *s);
char peekoperator(operatorstack s);
num peekoperand(operandstack s);