#include "time.h"

time substractTime(time start, time end) {
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

time addTime(time start, time end){
	time add;
	 add.hour = start.hour + end.hour;
	 add.min = start.min + end.min;
	if(add.min>59)
	{
		add.hour++;
		add.min=add.min-60;
	}
	return add;
}

int compareTime(time start, time end) {
	time diff;
   while (end.min > start.min) {
      --start.hour;
      start.min += 60;
   }
   diff.min = start.min - end.min;
   diff.hour = start.hour - end.hour;
   if(diff.hour >= 0){
   	return 1;
   }else{
   	return 0;
   }
}
