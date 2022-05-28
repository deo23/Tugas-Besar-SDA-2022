#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/***** Manajemen Queue *****/
/* Membuat Queue kosong 
   I.S. Belum terbentuk Queue 
   F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q){
	(*Q).Front = Nil;
	(*Q).Rear = Nil;
}

/* Untuk mengetahui apakah Queue kosong atau tidak. 
   mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear (Q) = Nil
   Sebaliknya mengirimkan 0 jika Queue tidak kosong 
*/
bool IsQueueEmpty(Queue Q){
	if (Q.Front == Nil && Q.Rear == Nil) {
		return 1;
	} else {
		return 0;
	}
}


/* Mengirimkan jumlah elemen queue jika Q berisi atrian dan mengirimkan 0 jika Q kosong */ 
int NBElmt(Queue Q){
	addrNQ P;
    int jmlElement = 0;

	if(IsQueueEmpty(Q)){
		jmlElement = 0;
	} else{
        Q.Front = P;
        do {
            jmlElement++;
            P->next = P;
        } while(P != Nil);
	}

	return jmlElement;
}


/* Melakukan pengecekan kategori penyakit hewan berdasarkan nilai prioritas antrian */
char *kategoriPenyakit(int Penyakit){
	if (Penyakit<4){
		return "Ringan";
	} else if (Penyakit<7){
		return "Sedang";
	} else if (Penyakit<10){
		return "Berat";
	}	
}

/* Menentukan nilai prioritas suatu antrian berdasarkan jumlah penyakit yang diderita */
int hitungPrioritas(int Ringan, int Sedang, int Berat){
	int nilai = 1;
	if (Berat >= 1){
		nilai += 4;
	}
	if (Sedang >= 2){
		nilai += 3;
	}
	if (Ringan >= 3){
		nilai += 2;
	}
	
	return nilai;
}


/* Mengupgrade waktu mulai dan waktu selesai pelayanan */
void setTime (Queue *Q){
	addrNQ temp, prev;
	
	temp = Front(*Q);
	
	if (Front(*Q) == Rear(*Q)){
		Info(temp).waktuTunggu = 0;
		Info(temp).waktuMulai = Info(temp).waktuDatang;
		Info(temp).waktuAkhir = Info(temp).waktuMulai + Info(temp).waktuEstimasi;
	} else {
		do {
			if(temp == Front(*Q)){
				Info(temp).waktuTunggu = 0;
				Info(temp).waktuMulai = Info(temp).waktuDatang;
				Info(temp).waktuAkhir = Info(temp).waktuMulai + Info(temp).waktuEstimasi;
			} else {
				if(prev->info.waktuAkhir > Info(temp).waktuDatang){
					Info(temp).waktuTunggu = prev->info.waktuAkhir - Info(temp).waktuDatang;
				}
				else Info(temp).waktuTunggu = 0;
				Info(temp).waktuMulai = Info(temp).waktuTunggu + Info(temp).waktuDatang;
				Info(temp).waktuAkhir = Info(temp).waktuMulai + Info(temp).waktuEstimasi;
			}
			prev = temp;
			temp = Next(temp);
		} while(temp != NULL);
	}
}

