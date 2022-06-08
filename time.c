/* File :  time.c
 * Desk :  ADT Time
 * Tgl  :  29/05/22	
 * Oleh : Muhammad Deo Audha Rizki
 */	
#include "time.h"

time substractTime(time start, time end) {
/* Mengurangi waktu start dengan end
Mengirim hasil pengurangan dari start dan end jika hasilnya >0
Mengirim 0 jika hasil pengurangannya <0
Author: Muhammad Deo Audha Rizki
*/
	time diff;
   while (end.min > start.min) {
      --start.hour;
      start.min += 60;
   }
   diff.min = start.min - end.min;
   diff.hour = start.hour - end.hour;
   if (diff.hour < 0){
   	diff.hour = 0;
   	diff.min = 0;
   }
   return diff;
}


time addTime(time start, time end)
{
/* Menambahkan waktu start dengan end
Mengirim hasil penambahan dari start dan end jika
Author: Muhammad Deo Audha Rizki
*/
	time t3;
    t3.hour=start.hour+end.hour+(start.min+end.min)/60;
    t3.min=(start.min+end.min)%60;
    
    if(t3.hour > 23){
    	t3.hour = t3.hour - 24;
	}
    
    return t3;
}

int compareTime(time start, time end) {
/* Membandingkan apakah start >= end
Mengirim hasil 1 jika start > end
Mengirim hasil 0 jika start < 0
Author: Muhammad Deo Audha Rizki
*/
	int t1,t2;
	
	t1 = (60*start.hour) + start.min;
	t2 = (60*end.hour) + end.min;
	
	if(t1 >= t2){
		return 1;
	}else{
		return 0;
	}
}	


time convertMinToTime(time t){
/* Mengonversi waktu dari menit ke Jam dan menit
Author: Muhammad Deo Audha Rizki
*/

	time update;
	
	update.hour = t.min/60;
	update.min = t.min %60;
	
	if(update.hour > 23){
    	update.hour = update.hour - 24;
	}
	
	return update;
}

int checkTime (time J)
{
/* Mengecek apakah waktu valid atau tidak
Return 1 jika valid
Return 0 jika tidak valid
Author: Muhammad Deo Audha Rizki
*/

    if(((J.hour >= 0) && (J.hour <= 23)) && ((J.min >= 0) && (J.min <= 59))){
    	return 1;
	}else{
		return 0;
	}
}
