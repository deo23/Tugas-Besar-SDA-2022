/*
Program : queue.h
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
#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
#include "time.h"

#define Info(P) (P)->info
#define Next(P) (P)->next
#define InfoFront(Q) (Q).Front->info
#define InfoRear(Q) (Q).Rear->info
#define Front(Q) (Q).Front
#define Rear(Q) (Q).Rear

typedef struct NodeQueue *addrNQ;


typedef struct{
    char namaHewan[20];
	time waktuDatang;
	List listPenyakit;
	time waktuMulai;
	time waktuTunggu;
	time waktuPelayanan;
	time waktuSelesai;
	int prioritas;
} InfoCustomer;
typedef InfoCustomer infotype;

typedef struct NodeQueue{
	infotype info;
	addrNQ next;
} NodeQueue;
typedef struct{
	addrNQ Front;
	addrNQ Rear;
} Queue;

/***** Manajemen memori *****/


addrNQ Alokasi(infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
* Jika alokasi berhasil, modul mengembalikan P; Info(P) = X,
Next(P) = NULL.
* P adalah pointer yang menunjuk ke node Queue sebagai hasil
alokasi.
* Jika alokasi gagal, modul mengembalikan NULL.
Author: Berliana Elfada
*/

void Dealokasi(addrNQ *P);
/* Melakukan dealokasi elemen P (pointer menunjuk ke alamat node
queue).
* I.S.: P terdefinisi.
* F.S.: P dikembalikan ke sistem.
Author: Berliana Elfada
*/

/***** Manajemen Queue *****/
void CreateQueue(Queue *Q);
/* Membuat sebuah Queue kosong dengan Front(Q) = Nil dan Rear (Q) =
Nil
I.S. Belum terbentuk Queue
F.S. Sudah terbentuk Queue
Author: Suci
*/

int IsQueueEmpty(Queue Q);
/* Mengetahui apakah Queue kosong atau tidak.
mengirimkan 1 jika Queue Kosong yaitu Front(Q) = Nil dan Rear
(Q) = Nil
Sebaliknya 0 (Queue tidak kosong)
Author: Suci Awalia Gardara
*/


void enQueue(Queue *Q, infotype data);
/* Memasukkan info baru ke dalam Queue dengan urutan berdasarkan prioritas */
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info baru (data) menjadi Rear yang baru dengan node Rear
yang lama mengaitkan pointernya ke node yang baru 
Author: Muhammad Deo Audha Rizki
*/


void deQueue(Queue *Q);
/* Proses: Mengambil info pada Front(Q) dan mengeluarkannya dari
Queue dengan aturan FIFO dan memasukkan data yang terhapus ke dalam file*/
/* I.S. Q mungkin kosong atau Q mungkin berisi antrian */
/* F.S. info yang diambil = nilai elemen Front pd I.S. */
/* Front(Q) menunjuk ke next antrian atau diset menjadi NIll, Q
mungkin kosong 
Author: Muhammad Deo Audha Rizki
*/


int NBElmt(Queue Q); 
/* Mengirimkan banyaknya elemen queue jika Q berisi atrian atau
mengirimkan 0 jika Q kosong
Author: Suci Awalia Gardara
*/

/***** Algoritma Program *****/

void printPenyakit();
/* Menampilkan daftar penyakit yang diambil dari variabel global ArrDisease
   dan mengelompokkannya ke dalam kategori
   Author: Berliana Elfada
*/

char *kategoriPenyakit(int penyakit);
/* Mengembalikan nilai string apakah Ringan, Sedang atau Berat berdasarkan penyakit yang diderita
Author: Suci Awalia Gardara
*/


int cekWaktuPelayanan(int penyakit);
/* Mengembalikan nilai integer berupa waktu pemeriksaan setiap penyakit berdasarkan kategori penyakit
Author: Berliana Elfada
*/


int hitungPrioritas(int Ringan, int Sedang, int Berat);
/* Proses : Mengembalikan nilai integer berupa perhitungan nilai prioritas berdasarkan jumlah penyakit dan kategori penyakit
   I.S : variabel count bernilai 1
   F.S : Nilai variabel count tetap atau berubah
   Author: Suci Awalia Gardara
*/


int hitungWaktuPelayanan(int Ringan, int Sedang, int Berat); 
/* Mengembalikan nilai integer untuk waktu pemeriksaan berdasarkan jumlah setiap penyakit yang diderita
Author: Berliana Elfada
*/


void setTime(Queue *Q);
/* Proses : Menghitung dan mengubah waktu tunggu, waktu mulai, dan waktu selesai jika terjadi
             perubahan urutan antrian
   I.S : Semua waktu belum ada nilai atau tidak sesuai
   F.S : Nilai semua waktu berubah seiring adanya perubahan urutan queue
   Author: Suci Awalia Gardara
   Modified: Muhammad Deo Audha Rizki
*/


void Registrasi(Queue *Q);
/* Proses : Menampilkan menu registrasi dan menerima masukan pengguna yang akan dimasukkan ke dalam Queue
   I.S : Data queue belum dimasukkan
   F.S : Data dari inputan pengguna dimasukkan ke dalam queue dan menampilkan isi daftar antrian
   Author: Muhammad Deo Audha Rizki
*/

void PrintQueue(Queue Q);
/* Proses : Menampilkan semua elemen pada antrian
   I.S : Antrean belum ditampilkan
   F.S : Antrean Sudah Ditampilkan
   Author: Muhammad Deo Audha Rizki
*/

void PrintNode(addrNQ P);
/* Proses : Menampilkan elemen dengan alamat P
   I.S : Antrean belum ditampilkan
   F.S : Antrean Sudah Ditampilkan
   Author: Muhammad Deo Audha Rizki
*/

void prosesAntrian(Queue *Q);
/* Proses : Menampilkan elemen antrian sebelum di dequeue
   I.S : elemen belum ditampilkan dan belum di dequeue
   F.S : elemen Sudah Ditampilkan dan sudah di dequeue
   Author: Muhammad Deo Audha Rizki
*/

addrNQ cariData (Queue Q);
/* Proses : Mencari data dengan key search nama pada queue
   Mengirim True jika data ditemukan, mengirim Nil jika data tidak ditemukan
   Author: Muhammad Deo Audha Rizki
*/
#endif // QUEUE_H
