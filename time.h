#ifndef time_H
#define time_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct{
	int hour;
	int min;
} time; 

time substractTime(time start, time end);
time addTime(time start, time end);
int compareTime(time start, time end);

#endif
