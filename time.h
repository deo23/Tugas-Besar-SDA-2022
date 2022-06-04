/* File :  time.h
 * Desk :  ADT Time
 * Tgl  :  29/05/22	
 * Oleh : Muhammad Deo Audha Rizki
 */	  
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
/* Mengurangi waktu start dengan end
Mengirim hasil pengurangan dari start dan end jika hasilnya >0
Mengirim 0 jika hasil pengurangannya <0
Author: Muhammad Deo Audha Rizki
*/
time addTime(time start, time end);
/* Menambahkan waktu start dengan end
Mengirim hasil penambahan dari start dan end jika
Author: Muhammad Deo Audha Rizki
*/
int compareTime(time start, time end);
/* Membandingkan apakah start >= end
Mengirim hasil 1 jika start > end
Mengirim hasil 0 jika start < 0
Author: Muhammad Deo Audha Rizki
*/

time convertMinToTime(time t);

#endif
