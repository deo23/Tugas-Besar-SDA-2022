/* File :  list.c
 * Desk :  Deklarasi list berkait dgn representasi fisik pointer. Representasi address dgn pointer
 * Oleh :  ANI RAHMANI / 23501007 
 * Tgl  :  25/10/01	
 * Modifikasi : Berliana Elfada
 				Muhammad Deo Audha Rizki
 				Suci Awalia Gardara
 * Tanggal : 30/05/22
   Version : 1.0
 */	  


#ifndef list1_C
#define list1_C 

#include "boolean.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty(List  L)                        
{  /*  Mengirim true jika List kosong  */

   	return(First(L)==Nil);	
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList(List *L)
{  /* I.S  :  Sembarang    		*/
/* F.S  :  Terbentuk  List kosong  	*/
//Author: Suci
   First(*L)=Nil;
}

/**** Manajemen Memory ****/
address Alloct(infoPenyakit  X)
{ /* Mengirimkan  address  hasil alokasi    sebuah elemen */
 /* Jika alokasi  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Nest(P)=Nil;               */
 /* Jika alokasi  gagal,  mengirimkan  Nil 			   */
//Author: Suci Awalia Gardara
 	//Kamus Lokal
   address P;
   
   //Algoritma
   P=(address)malloc(sizeof(ElmtList));
   if(P!=Nil) { /* Berhasil  */
   		Info(P)=X;
		Next(P)=Nil;
   }
   return P;	   
}

void DeAlloct(address *P)
{ /* I.S  : P terdefinisi      				*/
  /* F.S  : P dikembalikan ke  sistem 			*/
  /*   	    Melakukan deAlloct, pengembalian address P */
    Next(*P)=Nil; 	
    free(*P);	
}
/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/


void InsVLast(List *L, infoPenyakit X)
{ /* I.S  : L mungkin kosong          */
/* F.S  : Melakukan alokasi sebuah elemen dan                */
/*        menambahkan elemen list di akhir; elemen terakhir  */
/*        yang baru bernilai X jika alokasi berhasil, 	     */	
/*	  Jika alokasi gagal: I.S = F.S			     */
//Author: Berliana Elfada
     address P=Alloct(X);
     
    //Algoritma
     if(P!=Nil){
	 	InsertLast(&(*L),P);
     }
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi			*/
/* F.S   : Menambahkan elemen ber-address P, sebagai    */
/*         elemen pertama				*/
//Author: Suci Awalia Gardara
    Next(P)=First(*L);
    First(*L)=P;
}


void InsertLast(List  *L, address P)
{ /* I.S   : Sembarang, P sudah dialokasi				*/
/* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/
//Author: Berliana Elfada
		//Kamus Lokal
      address Last;
      
      //Algoritma
      if(ListEmpty(*L)) { /* Jika kosong, Insert elemen pertama */
	   InsertFirst(&(*L),P);     
      } else { /* tdk kosong */
	    Last=First(*L);  
            while(Next(Last)!=Nil)  { /* menuju ke last */
	          Last=Next(Last);
	    } /* Next(Last)==Nil */
	  
	  Next(Last)=P;	  
      }
}

/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L, char **C)
{ /* I.S   : List mungkin kosong 	*/
/* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
/*         elemen list di-print					 */
/*         Jika list kosong, hanya menuliskan "List Kosong"	 */
//Author: Berliana Elfada
  
  //Kamus Lokal
  address P=First(L);
  
  //Algoritma
  if( P==Nil) { 
  	  printf("List Kosong !\n");
  } else { /* List tidak kosong */
  		int j = 1;
	    do { 
	    	printf("								      ");
	 		printf("%d. %s --> %s (%d menit)\n", j++, C[P->info.Penyakit-1], P->info.kategori, Info(P).waktuEstimasi);
		  	P=Next(P);
	    } while(P!=Nil); 
	 }
}
#endif
