/*
	Modified		:   Berliana Elfada
                        Muhammad Deo Audha Rizki
                        Suci Awalia Gardara
	Date Modified 	: 16 Mei 2022
	Version			: 1.0
*/
#include <stdio.h>
#include "queue.h"
/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
* Jika alokasi berhasil, modul mengembalikan P; Info(P) = X,
Next(P) = NULL.
* P adalah pointer yang menunjuk ke node Queue sebagai hasil
alokasi.
* Jika alokasi gagal, modul mengembalikan NULL.
*/
addrNQ Alokasi(infotype X){
	addrNQ P;
    P = (addrNQ)malloc(sizeof(NodeQueue));

    if(P != NULL) { /* Berhasil  */
        Info(P) = X;
        Next(P) = NULL;
        return P;
   	} else {
   		return NULL;
	}
}


/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
*/
void Dealokasi(addrNQ *P){
	(*P)->next = NULL;
    free(*P);
}


/***** Manajemen Queue *****/
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) =
Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
*/
void CreateQueue(Queue *Q){
	(*Q).Front = Nil;
	(*Q).Rear = Nil;
}

/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
*/
int IsQueueEmpty(Queue Q){
	if (Q.Front == Nil && Q.Rear == Nil) {
		return 1;
	} else {
		return 0;
	}
}

/* Memasukkan info baru ke dalam Queue dengan aturan FIFO */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear
yang lama mengaitkan pointernya ke node yang baru */
void enQueue(Queue *Q, infotype data){

//deklarasi
	addrNQ P;
	
	//algoritma
	P = Alokasi(data); //memesan tempat di memori untuk antrian baru
	if (CekAntrianKosong(*Q) == 1){ //jika antrian masih kosong
		(*Q).Front = P;
		(*Q).Rear = P;
	} else { //jika antrian tidak kosong
		(*Q).Rear->next = P;
		(*Q).Rear = P;
	}
}


/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO dan memasukkan data yang terhapus ke dalam file*/
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong */
void deQueue(Queue *Q){
	if(IsQueueEmpty(*Q)==1){
		puts("============================================");
		printf("Maaf Antrian Kosong.\n");
	}
	else {
		addrNQ P;
		P = Front(*Q);
		if (Front(*Q)==Rear(*Q)){
			Front(*Q)=NULL;
			Rear(*Q)=NULL;
		}
		else{
			Front(*Q) = Next(Front(*Q));
		}
		Next(P)=NULL;

		printf("============================================\n");
		printf("Antrian Berikutnya : %s\n", Info(P).namaHewan);
		printf("Silahkan Menuju Ruang Pemeriksaan\n");

		EntryHistoryFile(P);
		Dealokasi(&P);
		EntryQueueFile(Q);
	}
}

/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau
mengirimkan 0 jika Q kosong
*/
int NBElmt(Queue Q){
	addrNQ P;

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
/* Menampilkan daftar penyakit yang diambil dari variabel global ArrDisease
   dan mengelompokkannya ke dalam kategori
*/
void printPenyakit(){
	int i;
	for (i=0; i<9; i++){
		printf("				  	%d. %s\n",i+1, arrPenyakit[i]);
	}
}


/* Mengembalikan nilai string apakah Ringan, Sedang atau Berat berdasarkan penyakit yang diderita
*/
char *kategoriPenyakit(int penyakit){
	if (penyakit < 4){
		return "Ringan";
	}else if (penyakit < 7){
		return "Sedang";
	}else if (penyakit < 10){
		return "Berat";
	}
}

/* Mengembalikan nilai integer berupa waktu pemeriksaan setiap penyakit berdasarkan kategori penyakit
*/
int cekWaktuPelayanan(int Penyakit){
	if (Penyakit<4){
		return 15; 
	} else if (Penyakit<7){
		return 30;
	} else if (Penyakit<10){
		return 45;
	}
}

/* Proses : Mengembalikan nilai integer berupa perhitungan nilai prioritas berdasarkan jumlah penyakit dan kategori penyakit
   I.S : variabel count bernilai 1
   F.S : Nilai variabel count tetap atau berubah
*/
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

/* Mengembalikan nilai integer untuk waktu pemeriksaan berdasarkan jumlah setiap penyakit yang diderita
*/
int hitungWaktuPelayanan(int Ringan, int Sedang, int Berat){
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

/* Proses : Menghitung dan mengubah waktu tunggu, waktu mulai, dan waktu selesai jika terjadi
             perubahan urutan antrian
   I.S : Semua waktu belum ada nilai atau tidak sesuai
   F.S : Nilai semua waktu berubah seiring adanya perubahan urutan queue
*/
void setTime (Queue *Q){
	addrNQ temp, prev;
	
	temp = Front(*Q);
	
	if (Front(*Q) == Rear(*Q)){
		Info(temp).waktuTunggu = 0;
		Info(temp).waktuMulai = Info(temp).waktuDatang;
		Info(temp).waktuSelesai = Info(temp).waktuMulai + Info(temp).waktuPelayanan;
	} else {
		do {
			if(temp == Front(*Q)){
				Info(temp).waktuTunggu = 0;
				Info(temp).waktuMulai = Info(temp).waktuDatang;
				Info(temp).waktuSelesai = Info(temp).waktuMulai + Info(temp).waktuPelayanan;
			} else {
				if(prev->info.waktuSelesai > Info(temp).waktuDatang){
					Info(temp).waktuTunggu = prev->info.waktuSelesai - Info(temp).waktuDatang;
				}
				else Info(temp).waktuTunggu = 0;
				Info(temp).waktuMulai = Info(temp).waktuTunggu + Info(temp).waktuDatang;
				Info(temp).waktuSelesai = Info(temp).waktuMulai + Info(temp).waktuPelayanan;
			}
			prev = temp;
			temp = Next(temp);
		} while(temp != NULL);
	}
}

/* Proses : Menampilkan menu registrasi dan menerima masukan pengguna yang akan dimasukkan ke dalam Queue
   I.S : Data queue belum dimasukkan
   F.S : Data dari inputan pengguna dimasukkan ke dalam queue dan menampilkan isi daftar antrian
*/
void Registrasi(Queue *Q){
	system("cls");
	infotype X;
	CreateList(&X.listPenyakit);
	infoPenyakit Y;
	
	int tempPenyakit[9];
	int i, totalPenyakit;
	
	printf("					====================================\n");
	printf("					              Registrasi\n");
	printf("					====================================\n");
	printf("					Nama Hewan                  : "); scanf("%s", &X.namaHewan);
	fflush(stdin);
	printf("					Datang di menit ke          : "); scanf("%d", &X.waktuDatang);
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
		Y.waktuEstimasi = PeriksaWaktuEstimasi(tempPenyakit[i]);
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
	X.nilaiPrioritas = HitungNilaiPrioritas(countR, countS, countB);
	X.waktuEstimasi = HitungWaktuEstimasi(countR, countS, countB);
	enQueue(Q, X);
	HitungWaktu(*(&Q));

	printf("\n");
	printf("					 *** Anda Sudah Terdaftar! *** \n\n");
}

/* Proses : Memasukkan data-data queue yang terinput ke dalam file daftar-antrian.txt
           dan mengubah seluruh isi file seiring terjadinya perubahan urutan
   I.S : File mungkin kosong atau tidak ada
   F.S : Jika file tersebut tidak ada, program mengirimkan pesan eror
  		 Jika ada, program akan meng-overwrite data-data queue
*/
void EntryQueueFile(Queue *Q); //Deo

/* Proses : Memasukkan data-data queue yang terhapus ke dalam file riwayat-antrian.txt
  		   secara berurutan
   I.S : File mungkin kosong atau tidak ada
   F.S : Jika file tersebut tidak ada, program mengirimkan pesan eror
  		 Jika file ada, program akan memasukkan data-data queue yang terhapus tanpa menimpa data
  		 sebelumnya
*/
void EntryHistoryFile(addrNQ P); //Deo

/* Proses : Membaca seluruh isi file daftar-antrian.txt
   I.S : File mungkin tidak ada atau mungkin ada
   F.S : Jika file tidak ditemukan, program mengirimkan pesan eror
         Jika file ada, program menampilkan isi dari file daftar-antrian.txt
*/
void PrintQueue(Queue Q); //Deo

/* Proses : Membaca seluruh isi file riwayat-antrian.txt
   I.S : File mungkin tidak ada atau mungkin ada
   F.S : Jika file tidak ditemukan, program mengirimkan pesan eror
         Jika file ada, program menampilkan isi dari file riwayat-antrian.txt
*/
void PrintHistory(); //Deo

