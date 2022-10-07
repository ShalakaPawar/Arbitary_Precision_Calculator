#ifndef NUMBER_H
#define NUMBER_H

#define PLUS 1
#define MINUS -1

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>

//structure to store each digit - similar to doubly linked list
struct number{
    int digit;
    struct number *next;
    struct number *prev;
};

// structure to store the sign and head of entered nu,ber
struct num{
    int sign;
    number *number_head;
};

typedef struct number number;
typedef struct num num;

// to intialize the head of number 
void init_num(num *n);

// to form num by creating nodes of digits and appending to list
void add_digit_to_num(num *n, int d);

// print the formed num
void traverse_num(num n);

// returns count of digits in the given num
int count_num(num n);

// freeing the num list denoting the number
void destroy_num(num *n);

// add digit to beginning of num linked list
void insert_beg(num *n, int d);

// removes extra zeroes from the beginning of num linked list
void rm_zero(num* N);

// return true if nu,ber  
int isNumZero(num n);


/*********************** Functions to be performed *********************************/

// perform addition on two num linked lists
num* addition_num(num n1, num n2);

// perform subtraction on two num linked lists
num* subtract_num(num n1, num n2);

// perform multiplication on two num linked lists
num* mult_num(num n1, num n2);

// perform division on two num linked lists
num* division_num(num n1, num n2);


#endif