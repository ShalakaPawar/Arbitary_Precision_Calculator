#include "number.h"

// to intialize the head of number 
void init_num(num *n){
    n = (num*)malloc(sizeof(num));
    n->sign = PLUS;
    n->number_head = NULL;
    return;
}

// to form num by creating nodes of digits and appending to list
void add_digit_to_num(num *n, int d){
    number *newnode = NULL;
    newnode = (number *)malloc(sizeof(number));
    if(newnode != NULL){
        newnode->digit = d;
        newnode->next = newnode->prev = NULL;
    }
    else
        return;
    
    // num linked list is empty - 1st digit of num
    if(n->number_head == NULL){
        n->number_head = newnode;
        return;
    }

    number* p = n->number_head;
    // remove extra zeroes on the left
    while (p->next){
        p = p->next;
    }
    p->next = newnode;
    newnode->prev = p;
    return;
}

// delete the num node - destroy the number entirely
void destroy_num(num *n){
    number *p, *q;
    p = n->number_head;

    while(p){
        q = p;
        p = p->next;
        free(q);
    }
    n->number_head = NULL;
    n->sign = PLUS;
    //printf("\nDestroyed");
    return;
}

// prints the number stored 
void traverse_num(num n){
    number *p = NULL;
    p = n.number_head;
    printf("\nNumber : ");
    if (isNumZero(n)){
        n.sign = PLUS;
    }
    if (n.sign == MINUS){
        printf("-");
    }
    while(p){
        printf("%d",p->digit);
        p = p->next;
    }
    return;
}

// returns the number of digits in the number
int count_num(num n){
    number *p;
    p = n.number_head;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

//insertion at the beginning
void insert_beg(num *n, int d){
    number *newnode = NULL;
    newnode = (number *)malloc(sizeof(number));
    if (newnode != NULL){
        newnode->digit = d;
        newnode->next = newnode->prev = NULL;
    }
    else 
        return;

    if (n->number_head == NULL){
        n->number_head = newnode;
        return;
    }

    number *p = NULL;
    p = n->number_head;

    p->prev = newnode;
    newnode->next = p;
    n->number_head = newnode;
    return;
}

//removing the extra zeroes generated on the left side of the number
void rm_zero(num* N){
    number* p = NULL;
    p = N->number_head;
    int length = count_num(*N);
    //length-1: if the number is zero so one zero must be there
    for (int i = 0; i < length - 1; ++i){
        if (p->digit == 0){
            N->number_head = p->next;
            N->number_head->prev = NULL;
            p->next = NULL;
            free(p);
            p = N->number_head;
        }
        else 
            return;
    }
}

//checking if the number = 0
int isNumZero(num n){
    number* p = NULL;
    p = n.number_head;
    while(p){
        if (p->digit != 0){
            return 0;   //indicating not zero
        }
        p = p->next;
    }
    n.sign = PLUS;
    return 1;
}


/******************* FUNTIONS PERFORMED ****************/

num* addition_num(num n1, num n2);
num* subtract_num(num n1, num n2);
num* mult_num(num n1, num n2);
num* division_num(num n1, num n2);