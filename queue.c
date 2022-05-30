/*
Program : queue.c
Author : Berliana Elfada
        Muhammad Deo Audha Rizki
        Suci Awalia Gardara
Deskripsi: Body file dari ADT Queue
Tanggal : 16 Mei 2022

Modified : Berliana Elfada
        Muhammad Deo Audha Rizki
        Suci Awalia Gardara
Date Modified 	: 30 Mei 2022
Version			: 2.0
*/
#include <stdio.h>
#include "queue.h"
#include "time.h"


time latestSelesai; //Variabel Global untuk menampung waktu selesai terakhir

/***** Manajemen memori *****/
addrNQ Alokasi(infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
* Jika alokasi berhasil, modul mengembalikan P; Info(P) = X,
Next(P) = NULL.
* P adalah pointer yang menunjuk ke node Queue sebagai hasil
alokasi.
* Jika alokasi gagal, modul mengembalikan NULL.
Author: Berliana Elfada
*/
	//Kamus Lokal
	addrNQ P;
	//Algoritma
    P = (addrNQ)malloc(sizeof(NodeQueue));

    if(P != NULL) { /* Berhasil  */
        Info(P) = X;
        Next(P) = NULL;
        return P;
   	} else {
   		return NULL;
	}
}


void Dealokasi(addrNQ *P){
/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
Author: Berliana Elfada
*/
	(*P)->next = NULL;
    free(*P);
}


/***** Manajemen Queue *****/
void CreateQueue(Queue *Q){
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) =
Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
Author: Suci Awalia Gardara
*/
	(*Q).Front = Nil;
}

int IsQueueEmpty(Queue Q){
/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
Author: Suci Awalia Gardara
*/
	if (Q.Front == Nil) {
		return 1;
	} else {
		return 0;
	}
}

void enQueue(Queue *Q, infotype X){
/* Memasukkan info baru ke dalam Queue dengan urutan berdasarkan prioritas */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear
yang lama mengaitkan pointernya ke node yang baru 
Author: Muhammad Deo Audha Rizki
*/
	//Kamus Lokal
	addrNQ P, temp;
	
	//Algoritma
	P = Alokasi(X);
	if(P != Nil){
		if(IsQueueEmpty((*Q)) || Info(P).prioritas > Info(Front(*Q)).prioritas){
			Next(P) = Front(*Q);
			Front(*Q) = P;
		}
		else{
			temp = Front(*Q);
			while((Next(temp) != Nil) && (Info(Next(temp)).prioritas >= Info(P).prioritas)){
				temp = Next(temp);
			}
			Next(P) = Next(temp);
			Next(temp) = P;
		}
	}
}


void deQueue(Queue *Q){
/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO dan memasukkan data yang terhapus ke dalam file*/
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong 
Author: Muhammad Deo Audha Rizki
*/
	//Kamus Lokal
	addrNQ P;
	
	//Algoritma
	if(IsQueueEmpty(*Q)){
		puts("============================================");
		printf("Maaf Antrian Kosong.\n");
	}
	else{
		P = Front(*Q);
		if(Next(P) == Nil){
			Front(*Q) = Nil;
		}
		else{
			Front(*Q) = Next(Front(*Q));
		}
		Next(P) = Nil;
		latestSelesai.hour = Info(P).waktuSelesai.hour;
		latestSelesai.min = Info(P).waktuSelesai.min;
		Dealokasi(&P);
	}
}


int NBElmt(Queue Q){
/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau
mengirimkan 0 jika Q kosong
Author: Suci Awalia Gardara
*/
	//Kamus Lokal
	addrNQ P;
	//Algoritma
	int count = 0;

	P = Front(Q);
	while (P != Nil){
		count++;
		P = Next(P);
	}

	return count;
}


char *arrPenyakit[9] = {
	"Penyakit Kulit",
	"Luka Ringan",
	"Bersin",
	"Cacingan",
	"Diare",
	"Luka Dalam",
	"Kerongkongan Berlendir dan Berbau Busuk",
	"Penyakit Kuning",
	"Terkena Virus"
};
/***** Algoritma Program *****/

void printPenyakit(){
/* Menampilkan daftar penyakit yang diambil dari variabel global ArrDisease
dan mengelompokkannya ke dalam kategori
Author: Berliana Elfada
*/
	//Kamus Lokal
	int i;
	//Algoritma
	for (i=0; i<9; i++){
		printf("				  	%d. %s\n",i+1, arrPenyakit[i]);
	}
}


char *kategoriPenyakit(int penyakit){
/* Mengembalikan nilai string apakah Ringan, Sedang atau Berat berdasarkan penyakit yang diderita
Author: Suci Awalia Gardara
*/
	if (penyakit < 4){
		return "Ringan";
	}else if (penyakit < 7){
		return "Sedang";
	}else if (penyakit < 10){
		return "Berat";
	}
}


int cekWaktuPelayanan(int Penyakit){
/* Mengembalikan nilai integer berupa waktu pemeriksaan setiap penyakit berdasarkan kategori penyakit
Author: Berliana Elfada
*/
	if (Penyakit<4){
		return 15; 
	} else if (Penyakit<7){
		return 30;
	} else if (Penyakit<10){
		return 45;
	}
}

int hitungPrioritas(int Ringan, int Sedang, int Berat){
/* Proses : Mengembalikan nilai integer berupa perhitungan nilai prioritas berdasarkan jumlah penyakit dan kategori penyakit
   I.S : variabel count bernilai 1
   F.S : Nilai variabel count tetap atau berubah
   Author: Suci Awalia Gardara
*/
	//Kamus Lokal
	int nilai = 1;
	//Algoritma
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


int hitungWaktuPelayanan(int Ringan, int Sedang, int Berat){
/* Mengembalikan nilai integer untuk waktu pemeriksaan berdasarkan jumlah setiap penyakit yang diderita
Author: Berliana Elfada
*/
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}


void setTime(Queue *Q){
/* Proses : Menghitung dan mengubah waktu tunggu, waktu mulai, dan waktu selesai jika terjadi
             perubahan urutan antrian
   I.S : Semua waktu belum ada nilai atau tidak sesuai
   F.S : Nilai semua waktu berubah seiring adanya perubahan urutan queue
   Author: Suci Awalia Gardara
   Modified: Muhammad Deo Audha Rizki
*/
	//Kamus Lokal
	addrNQ P, prev;
	//Algoritma
	P = Front(*Q);
	if((latestSelesai.hour == 0 && latestSelesai.min == 0) || compareTime(latestSelesai, Info(P).waktuDatang)==0){
		Info(P).waktuTunggu.hour = 0;
		Info(P).waktuTunggu.min = 0;
		Info(P).waktuMulai.hour = Info(P).waktuDatang.hour;
		Info(P).waktuMulai.min = Info(P).waktuDatang.min;
	}
	else{
		Info(P).waktuTunggu = substractTime(latestSelesai, Info(P).waktuDatang) ;
		Info(P).waktuMulai.hour = latestSelesai.hour;
		Info(P).waktuMulai.min = latestSelesai.min;
	}
	
	Info(P).waktuSelesai = addTime(Info(P).waktuMulai, Info(P).waktuPelayanan);
	prev = P;
	P = Next(P);
	while(P != Nil){
		Info(P).waktuTunggu = substractTime(Info(prev).waktuSelesai, Info(P).waktuDatang);
		Info(P).waktuMulai = addTime(Info(P).waktuTunggu, Info(P).waktuDatang);
		Info(P).waktuSelesai = addTime(Info(P).waktuMulai, Info(P).waktuPelayanan);
		prev = P;
		P = Next(P);
	}
}

/* Proses : Menampilkan menu registrasi dan menerima masukan pengguna yang akan dimasukkan ke dalam Queue
   I.S : Data queue belum dimasukkan
   F.S : Data dari inputan pengguna dimasukkan ke dalam queue dan menampilkan isi daftar antrian
*/
void Registrasi(Queue *Q){
/* Proses : Menampilkan menu registrasi dan menerima masukan pengguna yang akan dimasukkan ke dalam Queue
   I.S : Data queue belum dimasukkan
   F.S : Data dari inputan pengguna dimasukkan ke dalam queue dan menampilkan isi daftar antrian
   Author: Muhammad Deo Audha Rizki
*/
	system("cls");
	//Kamus Lokal
	infotype X;
	CreateList(&X.listPenyakit);
	infoPenyakit Y;
	char empty;
	int panjang;
	int tempPenyakit[9];
	int i, totalPenyakit;
	
	//Algoritma
	printf("%35.c%c",empty,254);
 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("%c", 254);
 printf("\n%35.c%c%18.c  ___   ______       _______     __         _____      _____",empty,254,empty);printf("%3.c",empty);printf("%19.c%c\n",empty,254);
 printf("%35.c%c%18.c //       ||     ||    ||       //%c%c       //         //   %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 printf("%35.c%c%18.c %c%c__     ||     ||    ||      //__%c%c     //         //     %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c    %c%c    ||     ||    ||     //    %c%c    %c%c         %c%c     //",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c  __//    ||     ||    ||    //      %c%c    %c%c____     %c%c___//",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 
    printf("%35.c%c",empty,254);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",254);
    printf("%35.c%c",empty,177);for(panjang=0; panjang<100; panjang++){printf("%c",177);}printf("%c",177);
 printf("\n%35.c",empty);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}  
 printf("\n%19.c   &&              &&/    &&&&&&&&&   &&&&&&&&   //&&&&&&&&  //&&&&&&&&   //&&&&&&    &&              &&/   &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c    &&            &&/     &&             &&      &&/         &&          /&&    &&     &&            &&/    &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c     &&          &&/      &&             &&      &&/         &&          /&&    &&      &&          &&/     &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c      &&        &&/       &&&&&&&&&      &&      &&&&&&&&&   &&&&&&&&&   /&&&&&&&&       &&        &&/      &&   &&          &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c       &&      &&/        &&             &&            /&&   &&          /&& &&           &&      &&/       &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c        &&    &&/         &&             &&            /&&   &&          /&&  &&           &&    &&/        &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c         &&&&&&/          &&&&&&&&&&     &&      &&&&&&&//   &&&&&&&&&   /&&    &&          &&&&&&/         &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty); 
printf("\n\n\n\n");
	printf("					====================================\n");
	printf("					              Registrasi\n");
	printf("					====================================\n");
	printf("					Nama Hewan                  : "); scanf("%s", &X.namaHewan);
	fflush(stdin);
	printf("					Datang pada pukul (JJ:MM)   : "); scanf("%02d:%02d", &X.waktuDatang.hour, &X.waktuDatang.min);
	fflush(stdin);
	
	printf("\n");
	printf("					       *** List Penyakit ***\n");
	printPenyakit();
	printf("\n");
	printf("					Jumlah Penyakit             : "); scanf("%d", &totalPenyakit);
	puts("					No. Penyakit yang Diderita  : ");
	for (i=0; i<totalPenyakit; i++){
	    printf("					");
		scanf("	%d", &tempPenyakit[i]);
	}
	
	int countR = 0;
	int countS = 0;
	int countB = 0;
	for (i=0; i<totalPenyakit; i++){
		Y.Penyakit = tempPenyakit[i];
		strcpy(Y.kategori, kategoriPenyakit(tempPenyakit[i]));
		Y.waktuEstimasi = cekWaktuPelayanan(tempPenyakit[i]);
		InsVLast(&X.listPenyakit, Y);
		
		if ((tempPenyakit[i]>0) && (tempPenyakit[i]<4)){
			countR++;
		}
		if ((tempPenyakit[i]>=4) && (tempPenyakit[i]<7)){
			countS++;
		}
		if ((tempPenyakit[i]>=7) && (tempPenyakit[i]<10)){
			countB++;
		}
	}
	X.prioritas = hitungPrioritas(countR, countS, countB);
	X.waktuPelayanan.min = hitungWaktuPelayanan(countR, countS, countB);
	X.waktuPelayanan.hour = 0;
	enQueue(Q, X);

	setTime(*(&Q));
	

	printf("\n");
	printf("					 *** Anda Sudah Terdaftar! *** \n\n");
}

/* Proses : Memasukkan data-data queue yang terinput ke dalam file daftar-antrian.txt
           dan mengubah seluruh isi file seiring terjadinya perubahan urutan
   I.S : File mungkin kosong atau tidak ada
   F.S : Jika file tersebut tidak ada, program mengirimkan pesan eror
  		 Jika ada, program akan meng-overwrite data-data queue
*/

void PrintQueue(Queue Q){
	system ("cls");
	addrNQ P;
	char empty;
	int panjang;
	int i=1, j;
	
	P = Q.Front;
	printf("%35.c%c",empty,254);
 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("%c", 254);
 printf("\n%35.c%c%18.c  ___   ______       _______     __         _____      _____",empty,254,empty);printf("%3.c",empty);printf("%19.c%c\n",empty,254);
 printf("%35.c%c%18.c //       ||     ||    ||       //%c%c       //         //   %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 printf("%35.c%c%18.c %c%c__     ||     ||    ||      //__%c%c     //         //     %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c    %c%c    ||     ||    ||     //    %c%c    %c%c         %c%c     //",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c  __//    ||     ||    ||    //      %c%c    %c%c____     %c%c___//",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 
    printf("%35.c%c",empty,254);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",254);
    printf("%35.c%c",empty,177);for(panjang=0; panjang<100; panjang++){printf("%c",177);}printf("%c",177);
 printf("\n%35.c",empty);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}  
 printf("\n%19.c   &&              &&/    &&&&&&&&&   &&&&&&&&   //&&&&&&&&  //&&&&&&&&   //&&&&&&    &&              &&/   &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c    &&            &&/     &&             &&      &&/         &&          /&&    &&     &&            &&/    &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c     &&          &&/      &&             &&      &&/         &&          /&&    &&      &&          &&/     &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c      &&        &&/       &&&&&&&&&      &&      &&&&&&&&&   &&&&&&&&&   /&&&&&&&&       &&        &&/      &&   &&          &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c       &&      &&/        &&             &&            /&&   &&          /&& &&           &&      &&/       &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c        &&    &&/         &&             &&            /&&   &&          /&&  &&           &&    &&/        &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c         &&&&&&/          &&&&&&&&&&     &&      &&&&&&&//   &&&&&&&&&   /&&    &&          &&&&&&/         &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty); 
printf("\n\n\n\n");
	printf("					====================================\n");
	printf("						      Daftar Antrian\n");
	printf("					====================================\n");
		
	if(IsQueueEmpty(Q)){
		printf("\n					* Tidak Ada Antrian yang Terdaftar *\n\n");
	} else {
		while(P != Nil){
			printf("					No. Antrian                 : %d\n", i++);
			printf("					Nama Hewan                  : %s\n", (P)->info.namaHewan);
			printf("					Datang pada pukul           : %02d:%02d\n", (P)->info.waktuDatang.hour, (P)->info.waktuDatang.min);
			puts("					Penyakit yang Diderita      :");
			PrintInfo(P->info.listPenyakit, arrPenyakit);
			printf("					Nilai Prioritas             : %d\n", (P)->info.prioritas);
			printf("					Estimasi Waktu Pelayanan    : %02d:%02d\n", (P)->info.waktuPelayanan.hour, (P)->info.waktuPelayanan.min);
			printf("					Waktu Tunggu Pelayanan      : %02d:%02d\n", (P)->info.waktuTunggu.hour, (P)->info.waktuTunggu.min);
			printf("					Waktu Mulai Pelayanan       : %02d:%02d\n", (P)->info.waktuMulai.hour, (P)->info.waktuMulai.min);
			printf("					Waktu Selesai Pelayanan     : %02d:%02d\n", (P)->info.waktuSelesai.hour, (P)->info.waktuSelesai.min);
			
			printf("					------------------------------------\n");
			
			P = Next(P);
		}		
	}
}

void PrintNode(addrNQ P){
	if(P != Nil){
			printf("					Nama Hewan                  : %s\n", (P)->info.namaHewan);
			printf("					Datang pada pukul           : %02d:%02d\n", (P)->info.waktuDatang.hour, (P)->info.waktuDatang.min);
			puts("					Penyakit yang Diderita      :");
			PrintInfo(P->info.listPenyakit, arrPenyakit);
			printf("					Nilai Prioritas             : %d\n", (P)->info.prioritas);
			printf("					Estimasi Waktu Pelayanan    : %02d:%02d\n", (P)->info.waktuPelayanan.hour, (P)->info.waktuPelayanan.min);
			printf("					Waktu Tunggu Pelayanan      : %02d:%02d\n", (P)->info.waktuTunggu.hour, (P)->info.waktuTunggu.min);
			printf("					Waktu Mulai Pelayanan       : %02d:%02d\n", (P)->info.waktuMulai.hour, (P)->info.waktuMulai.min);
			printf("					Waktu Selesai Pelayanan     : %02d:%02d\n", (P)->info.waktuSelesai.hour, (P)->info.waktuSelesai.min);
			
			printf("					------------------------------------\n");	
	}
}

void prosesAntrian(Queue *Q){
	system ("cls");
	addrNQ P;
	infotype R;	
	int i=1;
	char pilih;
	char empty;
	int panjang;
	P = (*Q).Front;
	printf("%35.c%c",empty,254);
 printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); printf("%c", 254);
 printf("\n%35.c%c%18.c  ___   ______       _______     __         _____      _____",empty,254,empty);printf("%3.c",empty);printf("%19.c%c\n",empty,254);
 printf("%35.c%c%18.c //       ||     ||    ||       //%c%c       //         //   %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 printf("%35.c%c%18.c %c%c__     ||     ||    ||      //__%c%c     //         //     %c%c",empty,254,empty,92,92,92,92,92,92,92,92,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c    %c%c    ||     ||    ||     //    %c%c    %c%c         %c%c     //",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%17.c%c\n",empty,254);
 printf("%35.c%c%18.c  __//    ||     ||    ||    //      %c%c    %c%c____     %c%c___//",empty,254,empty,92,92,92);printf("%3.c",empty);printf("%18.c%c\n",empty,254);
 
    printf("%35.c%c",empty,254);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}printf("%c\n",254);
    printf("%35.c%c",empty,177);for(panjang=0; panjang<100; panjang++){printf("%c",177);}printf("%c",177);
 printf("\n%35.c",empty);for(panjang=0; panjang<100; panjang++){printf("%c",empty);}  
 printf("\n%19.c   &&              &&/    &&&&&&&&&   &&&&&&&&   //&&&&&&&&  //&&&&&&&&   //&&&&&&    &&              &&/   &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c    &&            &&/     &&             &&      &&/         &&          /&&    &&     &&            &&/    &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c     &&          &&/      &&             &&      &&/         &&          /&&    &&      &&          &&/     &&   &&          &&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c      &&        &&/       &&&&&&&&&      &&      &&&&&&&&&   &&&&&&&&&   /&&&&&&&&       &&        &&/      &&   &&          &&&&&&&",empty,empty);printf("%20.c\n",empty);
 printf("%19.c       &&      &&/        &&             &&            /&&   &&          /&& &&           &&      &&/       &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c        &&    &&/         &&             &&            /&&   &&          /&&  &&           &&    &&/        &&   &&          &&   ",empty,empty);printf("%20.c\n",empty);
 printf("%19.c         &&&&&&/          &&&&&&&&&&     &&      &&&&&&&//   &&&&&&&&&   /&&    &&          &&&&&&/         &&   &&&&&&&&&   &&&&&&&",empty,empty);printf("%20.c\n",empty); 
printf("\n\n\n\n");
	printf("					====================================\n");
	printf("						   Proses Antrian\n");
	printf("					====================================\n");
	
	if (P == Nil) { // Jika Queue Kosong
		printf("\n					* Tidak Ada Antrian yang Terdaftar *\n\n");
    } else {
		while(P != Nil){
			printf("					No. Antrian                 : %d\n", i++);
			printf("					Nama Hewan                  : %s\n", (P)->info.namaHewan);
			printf("					Datang pada pukul           : %02d:%02d\n", (P)->info.waktuDatang.hour, (P)->info.waktuDatang.min);
			puts("					Penyakit yang Diderita      :");
			PrintInfo(P->info.listPenyakit, arrPenyakit);
			printf("					Nilai Prioritas             : %d\n", (P)->info.prioritas);
			printf("					Estimasi Waktu Pelayanan    : %02d:%02d\n", (P)->info.waktuPelayanan.hour, (P)->info.waktuPelayanan.min);
			printf("					Waktu Tunggu Pelayanan      : %02d:%02d\n", (P)->info.waktuTunggu.hour, (P)->info.waktuTunggu.min);
			printf("					Waktu Mulai Pelayanan       : %02d:%02d\n", (P)->info.waktuMulai.hour, (P)->info.waktuMulai.min);
			printf("					Waktu Selesai Pelayanan     : %02d:%02d\n", (P)->info.waktuSelesai.hour, (P)->info.waktuSelesai.min);
			
			printf("					------------------------------------\n");
			P = Next(P);
			R = InfoFront(*Q);
			printf("					Memulai Proses Pelayanan Untuk %s? [Y/N] ", R.namaHewan);
			fflush(stdin);
			scanf("%c", &pilih);
			
			if(pilih == 'Y' || pilih == 'y'){
				deQueue(Q);
				printf("\n");
				printf("					       *** Harap bersabar ***\n");
				printf("					  *** Hewan Anda Sedang Diobati ***\n\n");
			} 
			else if(pilih == 'N' || pilih == 'n'){
				printf("					***  Silahkan Kembali Ke Antrian ***\n");
			}
		}
	}
}

addrNQ cariData (Queue Q){
	
	addrNQ P = Front(Q);
	char namaHewan[25];
	
	
	printf("Nama Kucing : ");
	scanf("%s", &namaHewan);
	fflush(stdin);
	while((P != NULL)){
		if(strcmp(P->info.namaHewan, namaHewan) == 0){
			return P;
		}
		P = Next(P);	
	}
	return Nil;
} 


