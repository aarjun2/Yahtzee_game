#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings 
#define PI 3.14159265 	// defined as a global variable 



#include <stdio.h> 	// necessary to use printf () and scanf () 
#include <math.h>	//necessary to include power and square root functions   
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time () 

int roll_dice(void);
void reroll_dice(int arr[]);
int computepoints_1(int values[], int comb_option, int size, int* one_value);
int computepoints_2(int values[], int comb_option, int size, int* two_value);
int computepoints_3(int values[], int comb_option, int size, int* three_value);
int computepoints_4(int values[], int comb_option, int size, int* four_value);
int computepoints_5(int values[], int comb_option, int size, int* five_value);
int computepoints_6(int values[], int comb_option, int size, int* six_value);
int one_value_calc(int values[], int size);
int two_value_calc(int values[], int size);
int three_value_calc(int values[], int size);
int four_value_calc(int values[], int size);
int five_value_calc(int values[], int size);
int six_value_calc(int values[], int size);
int array_sort(int values[], int size);
void clear_function();