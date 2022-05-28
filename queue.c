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
	addrNQ P, travel, before, after;
	//Membuat node baru dengan nama P
	P = Alokasi(data);
	//Insert in First Queue
	if (IsQueueEmpty(*Q) == 1){
		Front(*Q) = P;
		Rear(*Q) = P;
	}
	//Insert Ketika waktu mulai pada Rear kurang dari waktu kedatangan node baru
	else if (Info(Rear(*Q)).waktuMulai < Info(P).waktuDatang){
		Next(Rear(*Q)) = P;
		Rear(*Q) = P;
	}
	//Insert Ketika waktu mulai pada rear lebih dari atau sama dengan waktu kedatangan node baru
	else if (Info(Rear(*Q)).waktuMulai >= Info(P).waktuDatang){
		//Jika hanya terdapat 1 node pada queue
		if(Front(*Q) == Rear(*Q)){
			//jika waktu kedatangan node baru sama seperti waktu kedatangan front
			if (Info(P).waktuDatang == Info(Front(*Q)).waktuDatang){
				//Jika prioritas Front kurang dari node baru
				if (Info(Front(*Q)).prioritas < Info(P).prioritas){
					Next(P) = Front(*Q);
					Front(*Q) = P;
				}
				//Jika prioritas Front lebih dari aau sama dengan dari node Baru
				else {
					Next(Front(*Q)) = P;
					Rear(*Q) = P;
				}
			}
			//Jika waktu kedatangan node baru tidak sama dengan waktu kedatangan front
			else {
				Next(Front(*Q)) = P;
				Rear(*Q) = P;
			}
		}
		//Jika terdapat 2 atau lebih node pada queueu
		else{
			//Jika waktu kedatangan front sama dengan waktu kedatangan node baru
			if(Info(P).waktuDatang == Info(Front(*Q)).waktuDatang){
				//jika prioritas front kurang dari prioritas node baru
				if (Info(Front(*Q)).prioritas < Info(P).prioritas){
					Next(P) = Front(*Q);
					Front(*Q) = P;
				}
				//Jika prioritas front lebih dari atau sama dengan prioritas node baru
				else if (Info(Front(*Q)).prioritas >= Info(P).prioritas){
					//pointer menunjuk front
					travel = Front(*Q);
					//pointer berjalan ke node selanjutnya jika prioritas node baru kurang
					//dari atau sama dengan prioritas node yang ditunjuk travel, dan node travel
					//selanjutnya tidak NULL
					while (Info(P).prioritas <= Info(travel).prioritas && Next(travel)!=NULL){
						before = travel;
						travel = Next(travel);
					}
					//Kondisi kondisi ketika travel berhenti bergerak (endwhile)
					if (Info(P).prioritas > Info(travel).prioritas && Next(travel)==NULL){
						Next(before)=P;
						Next(P)=travel;
					}
					else if (Info(P).prioritas <= Info(travel).prioritas && Next(travel)==NULL){
						Next(travel) = P;
						Rear(*Q) = P;
					}
					else if (Info(P).prioritas > Info(travel).prioritas && Next(travel)!=NULL){
						Next(before)=P;
						Next(P)=travel;
					}
				}
			}
			//Jika waktu kedatangan node baru tidak sama dengan waktu kedatangan front
			else if(Info(P).waktuDatang != Info(Front(*Q)).waktuDatang){
				travel = Front(*Q);
				//Travel berjalan seperti pada line 133
				while (Info(travel).waktuDatang == Info(Front(*Q)).waktuDatang && Next(travel)!=NULL){
					before = travel;
					travel = Next(travel);
				}
				//Kondisi kondisi ketika travel berhenti bergerak (endwhile)
				if (Info(travel).waktuDatang != Info(Front(*Q)).waktuDatang && Next(travel)==NULL){
					if (Info(travel).prioritas < Info(P).prioritas){
						Next(before) = P;
						Next(P) = travel;
					}
					else {
						Next(travel) = P;
						Rear(*Q) = P;
					}
				}
				else if (Next(travel)==NULL){
					Next(travel) = P;
					Rear(*Q) = P;
				}
				else if (Info(travel).waktuDatang != Info(Front(*Q)).waktuDatang){
					if (Info(travel).prioritas < Info(P).prioritas){
						Next(before) = P;
						Next(P) = travel;
					}
					else {
						//travel berjalan pada node yang waktu kedatangannya tidak sama dengan front
						while (Info(travel).prioritas >= Info(P).prioritas && Next(travel)!=NULL){
							before = travel;
							travel = Next(travel);
						}
						//kondisi ketika travel bergerak dan berhenti di tengah queue (bukan rear)
						if (Next(travel)!=NULL){
							after = Next(travel);
							if (Info(travel).prioritas <= Info(P).prioritas){
								Next(before)=P;
								Next(P)=travel;
							}
							else {
								//travel akan berjalan lagi hingga urutan belakang pada prioritas yang sama
								// dengan node baru
								while (Info(travel).prioritas <= Info(after).prioritas){
									if (Info(travel).prioritas > Info(after).prioritas){
										Next(P)=after;
										Next(travel) = P;
									}
									travel = after;
									after = Next(after);
								}
							}

						}
						//kondisi ketika travel sudah bergerak higga rear dan berhenti di rear
						else if (Next(travel)==NULL){
							if(Info(travel).prioritas < Info(P).prioritas){
								Next(before)=P;
								Next(P) = travel;
								Rear(*Q) = travel;
							}
							else if(Info(travel).prioritas >= Info(P).prioritas){
								Next(travel) = P;
								Rear(*Q) = P;
							}
						}
					}
				}
			}
		}
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
		printf("%67.c Maaf Antrian Kosong.\n");
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

		
		Dealokasi(&P);
		
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
	printf("					Nama Kucing                  : "); scanf("%s", &X.namaHewan);
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
	X.waktuPelayanan = hitungWaktuPelayanan(countR, countS, countB);
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
	
	int i=1, j;
	int lenght;
	
	P = Q.Front;
		
	printf("					====================================\n");
	printf("						      Daftar Antrian\n");
	printf("					====================================\n");
		
	if(IsQueueEmpty(Q)){
		printf("\n					* Tidak Ada Antrian yang Terdaftar *\n\n");
	} else {
		while(P != Nil){
			printf("					No. Antrian                 : %d\n", i++);
			printf("					Nama Kucing                  : %s\n", (P)->info.namaHewan);
			printf("					Datang di menit ke          : %d\n", (P)->info.waktuDatang);
			puts("					Penyakit yang Diderita      :");
			PrintInfo(P->info.listPenyakit, arrPenyakit);
			printf("					Nilai Prioritas             : %d\n", (P)->info.prioritas);
			printf("					Estimasi Waktu Pelayanan    : %d\n", (P)->info.waktuPelayanan);
			printf("					Waktu Tunggu Pelayanan      : %d\n", (P)->info.waktuTunggu);
			printf("					Waktu Mulai Pelayanan       : %d\n", (P)->info.waktuMulai);
			printf("					Waktu Selesai Pelayanan     : %d\n", (P)->info.waktuSelesai);
			
			printf("					------------------------------------\n");
			
			P = Next(P);
		}		
	}
}

void PrintHistory(); 

boolean PrintData(Queue Q, char *namaHewan){
/* mengirim true jika elemen x ada pada Q,
dan false jika x tidak ditemukan pada Q
skema pencarian dengan boolean
*/
 address P;
 boolean found;
 infotype X;
 
 found = false;
 
 printf("					Nama Kucing                  : "); scanf("%s", &X.namaHewan);
 fflush(stdin);
 while((P != NULL) && (!found)){
	if(strcpy (Info(Front(Q)).namaHewan, namaHewan)){
   	found = true;
  	}
  	else{
   		P = next(P);
  	}
 }
 return found;
}
