#ifndef CMATHEMATICS_H
#define CMATHEMATICS_H

typedef unsigned char bool;
#define false 0
#define true !false

// array containing hexadecimal digits in order
extern char hex[16];

/**
 * calculates the number of arguments in a __VA_ARGS__ list
 * @param type the type of the argument in the list
 * @param ... the list
 * @return the number of arguments in the list
 */
#define NUMARGS(type, ...) (sizeof((type[]){0.0f, ##__VA_ARGS__}) / sizeof(type) - 1)

/**
 * finds the maximum of two values
 * @param i1 the first value
 * @param i2 the second value
 * @return the larger element
 */
#define MAX(i1, i2) (i1 > i2 ? i1 : i2)

/**
 * finds the minimum of two values
 * @param i1 the first value
 * @param i2 the second value
 * @return the larger element
 */
#define MIN(i1, i2) (i1 < i2 ? i1 : i2)

/**
 * method to determine if an integer exists in an array
 * @param arr the array
 * @param noElements the number of elements in the array
 * @param target the target element
 * @return if the element exists in the array
 */
bool containsUint(unsigned int *arr, unsigned int noElements, unsigned int target);

/**
 * method to reverse an array between two bounds
 * @param arr the array
 * @param i the left bound
 * @param f the right bound
 */
void reverseArray(unsigned char *arr, int i1, int i2);

/**
 * method to rotate an array to the left using the reversal algorithm
 * @param arr the array
 * @param d the number of positions to shift
 * @param n the length of the array
 */
void leftRotate(unsigned char *arr, int d, int n);

/**
 * method to rotate an array to the right using the reversal algorithm
 * @param arr the array
 * @param d the number of positions to shift
 * @param n the length of the array
 */
void rightRotate(unsigned char *arr, int d, int n);

unsigned long long rightRotateLL(unsigned long long w, unsigned int d);
unsigned int rightRotateI(unsigned int w, unsigned int d);
unsigned char rightRotateC(unsigned char w, unsigned int d);

unsigned long long leftRotateLL(unsigned long long w, unsigned int d);
unsigned int leftRotateI(unsigned int w, unsigned int d);
unsigned char leftRotateC(unsigned char w, unsigned int d);

void randomCharArray(unsigned char *arr, int n);

/**
 * method to divide and get the remainder
 * @param num the number to divide by
 * @param divisor the divisor
 * @param quotient the pointer to where to store the quotient
 * @param remainder the pointer to where to store the remainder
 */
void divMod(unsigned int num, unsigned int divisor, unsigned int *quotient, unsigned int *remainder);

/**
 * method to divide and get the remainder with long long
 * @param num the number to divide by
 * @param divisor the divisor
 * @param quotient the pointer to where to store the quotient
 * @param remainder the pointer to where to store the remainder
 */
void divModLL(unsigned long long num, unsigned long long divisor, unsigned long long *quotient, unsigned long long *remainder);

/**
 * method to calculate the number of digits required to represent an integer in a specific base
 * @param val the integer
 * @param base the base
 * @return the number of digits
 */
unsigned int numDigits(unsigned int val, unsigned int base);

/**
 * method to calculate the number of digits required to represent an integer in a specific base with long long
 * @param val the integer
 * @param base the base
 * @return the number of digits
 */
unsigned long long numDigitsLL(unsigned long long val, unsigned long long base);

/**
 * method to scan a string in hexadecimal format and return its byte array representation
 * @param str the hexadecimal string
 * @param bytes the number of bytes in the output
 * @return the byte array with the hexadecimal data
 */
unsigned char *scanHex(char *str, int bytes);

/**
 * method to output a byte array as a hexadecimal string
 * @param arr the byte array
 * @param noBytes the number of bytes
 * @param delim word delimiter
 * @param delimN the size of the delimiter
 * @param wordSize number of bytes in a word
 * @return the formatted string
 */
unsigned char *printByteArr(unsigned char *arr, int noBytes, unsigned char *delim, int delimN, int wordSize);

#endif