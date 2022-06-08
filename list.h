/* File :  list.h
 * Desk :  Deklarasi list berkait dgn representasi fisik pointer. Representasi address dgn pointer
 * Oleh :  ANI RAHMANI / 23501007 
 * Tgl  :  25/10/01	
 * Modifikasi : Berliana Elfada
 				Muhammad Deo Audha Rizki
 				Suci Awalia Gardara
 * Tanggal : 30/05/22
 */	  


/* List :  */

#ifndef list1_H
#define list1_H 

#include "boolean.h"
#include <stdlib.h>

#define Nil  NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

typedef struct{
	int Penyakit;
	int waktuEstimasi;
	char kategori[8];
}infoPenyakit;                                        
typedef struct tElmtlist *address;
typedef struct  tElmtlist{
	infoPenyakit info;
	address next;
}ElmtList;

/* Definisi  List                   */
/* List Kosong  :  First(L) = Nil   */
/* Setiap elemen dengan address P dapat diacu Info(P),Next(P)       */
/* Elemen terakhir  List :jika addressnya Last, maka next(Last)=Nil */

typedef struct {
	address First;
}List;

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty(List  L);                        
/*  Mengirim true jika List kosong  */

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List *L);
/* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/
//Author: Suci

/**** Manajemen Memory ****/
address Alloct(infoPenyakit  X);
 /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */
//Author: Suci Awalia Gardara


/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/

void InsVLast(List *L, infoPenyakit X);
/* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */	
/*	  Jika alokasi gagal: I.S = F.S			     */
//Author: Berliana Elfada

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P);
/* I.S   : Sembarang, P sudah dialokasi			*/
/* F.S   : Menambahkan elemen ber-address P, sebagai    */
/*         elemen pertama				*/
//Author: Suci Awalia Gardara

void InsertLast(List  *L, address P);
/* I.S   : Sembarang, P sudah dialokasi				*/
/* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/
//Author: Berliana Elfada

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L, char **C);
/* I.S   : List mungkin kosong 	*/
/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
/*         elemen list di-print					 */
/*         Jika list kosong, hanya menuliskan "List Kosong"	 */
//Author: Berliana Elfada



#endif
