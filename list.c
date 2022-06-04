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
   First(*L)=Nil;
}

/**** Manajemen Memory ****/
address Alloct(infoPenyakit  X)
{/* Mengirimkan  address  hasil Alloct    sebuah elemen */
 /* Jika Alloct  berhasil, maka  address tidak nil, dan misalnya  */
 /* menghasilkan   P,  maka info(P)=X,  Next(P)=Nil;               */
 /* Jika Alloct  gagal,  mengirimkan  Nil 			   */
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

/**** Pencarian sebuah elemen List ****/

boolean FSearch(List L, address P)
{ /* Mencari apakah ada elemen List yang beralamat P  */
  /* Mengirimkan true jika ada, false jika tidak ada  */
  /* List Tidak mungkin kosong  */
	//Kamus Lokal
  address PTemp=First(L);
  boolean found=false;
  
  //Algoritma
  while((PTemp!=Nil)&&(!found)){
    if(PTemp==P) {
		found=true;
    } else { 
		PTemp=Next(PTemp);     
    }
      
  } /* PTemp==Nil or found / ketemu */
  return found;
}

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst(List *L, infoPenyakit X)
{  /* I.S  : L mungkin kosong          */
   /* F.S  : Melakukan Alloct sebuah elemen dan             */
   /*        menambahkan elemen pertama dengan nilai X jika  */
   /*        Alloct berhasil 				     */
   //Kamus Lokal
   address P=Alloct(X);
   
   //Algoritma
   if(P!=Nil) { /* Alloct Berhasil */
      InsertFirst(&(*L),P);
	}
}

void InsVLast(List *L, infoPenyakit X)
{ /* I.S  : L mungkin kosong          */
  /* F.S  : Melakukan Alloct sebuah elemen dan                */
  /*        menambahkan elemen list di akhir; elemen terakhir  */
  /*        yang baru bernilai X jika Alloct berhasil,        */	
  /*	    Jika Alloct gagal: I.S = F.S		       */
    //Kamus Lokal
     address P=Alloct(X);
     
    //Algoritma
     if(P!=Nil){
	 	InsertLast(&(*L),P);
     }
}

/**** Penghapusan Elemen ****/

void DelVFirst(List *L, infoPenyakit *X)
{ /* I.S    : List tidak kosong  		                 */
  /* F.S    : Elemen pertama List dihapus, nilai info disimpan   */
  /*	      pada X dan alamat elemen pertama  di-deAlloct 	 */
  //Kamus Lokal
  address  P;
  
  //Algoritma
  DelFirst(&(*L),&P); /* Hapus elemen pertama, blm dideAlloct */
  *X=Info(P); 		/* info dari First disimpan di X       */
  DeAlloct(&P);	  
}

void DelVLast(List *L, infoPenyakit *X)
{  /* I.S    : List tidak kosong  		                 */
   /* F.S    : Elemen terakhir list dihapus, nilai info disimpan */
   /*	      pada X dan alamat elemen terakhir di-deAlloct 	 */
   //Kamus Lokal
   address P;
   DelLast(&(*L),&P); 
   
	//Algoritma    
   *X=Info(P);	
   DeAlloct(&P);
}
	

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/* Penambahan Elemen Berdasarkan Alamat 		*/

void InsertFirst(List *L, address P)
{ /* I.S   : Sembarang, P sudah diAlloct		*/
  /* F.S   : Menambahkan elemen ber-address P, sebagai  */
  /*         elemen pertama				*/
    Next(P)=First(*L);
    First(*L)=P;
}

void InsertAfter(List *L, address P, address Prec)
{ /* I.S   : Prec pastilah elemen  dan bukan elemen terakhir  */
  /*         P sudah diAlloct 					  */
  /* F.S   : Insert P sebagai elemen sesudah elemen beralamat Prec*/
	Next(P)=Next(Prec);
	Next(Prec)=P;
}

void InsertLast(List  *L, address P)
{ /* I.S   : Sembarang, P sudah diAlloct			*/
  /* F.S   : P ditambahkan  sebagai elemen terakhir yang baru	*/
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

/* ****** PENGHAPUSAN SEBUAH ELEMEN	*********   */
void DelFirst (List *L, address *P)
{ /* I.S   : List tidak kosong 	*/
  /* F.S   : P adalah alamat elemen pertama list sebelum penghapusan */
  /*         Elemen List berkurang satu (mungkin menjadi kosong)     */
  /* First elemen yang baru adalah suksesor elemen pertama yang lama */
          
      *P=First(*L);
      First(*L)=Next(First(*L));
      Next(*P)=Nil;
    
 }


void DelLast(List *L, address *P)
{ /* I.S   : List tidak kosong  */
  /* F.S   : P adalah alamat elemen terakhir list sebelum penghapusan */
  /*	     Elemen list berkurang 1 (mungkin menjadi kosong)	      */
  /*         Last elemen baru adalah predessesor elemen pertama yang  */
  /*         lama, jika  ada					      */
  
  //Kamus Lokal   	
  address Last,PrecLast;
  
  //Algoritma
  Last=First(*L);
  /* dari catatan di kelas */	
  if(Next(Last)==Nil)  { /* hanya 1 elemen */
	  DelFirst(&(*L),&(Last));
  }	else { /* Lebih dr 1 elemen */
	  PrecLast=Nil;
	  while(Next(Last)!=Nil){   /* Maju sampai elemen terakhir */
		  PrecLast=Last;     
		  Last=Next(Last);
	  } /* Next(Last)=Nil */
	  *P=Last;
	  Next(PrecLast)=Nil;
    }
}

void DelAfter(List *L, address *Pdel, address Prec)
{  /* I.S   : List tidak kosong, Prec adalah anggota List	*/
   /* F.S   : Menghapus Next(Prec) :				*/
   /*         Pdel adalah alamat elemen List yang dihapus	*/
	*Pdel=Next(Prec);
	Next(Prec)=Next(*Pdel);
}


/* *************PROSES SEMUA ELEMEN ****************   */
void PrintInfo(List L, char **C)
{ /* I.S   : List mungkin kosong 	*/
  /* F.S   : Jika list tidak kosong, semua info yang disimpan pada */
  /*         elemen list di-print			  	   */
  /*         Jika list kosong, hanya menuliskan "List Kosong"	   */
  
  //Kamus Lokal
  address P=First(L);
  char empty;
  //Algoritma
  if( P==Nil) { 
  	  printf("%67.c 	List Kosong !\n", empty);
  } else { /* List tidak kosong */
  		int j = 1;
	    do { 
	    	printf("  ");
	 		printf("%67.c %d. %s --> %s\n", empty, j++, C[P->info.Penyakit-1], P->info.kategori);
		  	P=Next(P);
	    } while(P!=Nil); 
	 }
}

int NbElmt(List L)
{ /* Mengirimkan banyaknya elemen list, mengirimkan Nol jika kosong */

	//Kamus Lokal
  address P;
  
  //Algoritma
  int NbEl=0;
  if(ListEmpty(L)){
 	return 0;
  } else { /* Tidak kosong */
	      P=First(L);
       	  do {
		    	NbEl++;  
		    	P=Next(P);  
	      }while(P!=Nil);
  	}
    return NbEl;		      
}

/******************************************************/
/***   		PROSES TERHADAP LIST		    ***/
/******************************************************/
void DelAll(List *L)
{ /* Delete semua elemen list, dan alamat elemen di-deAlloct */

	//Kamus Lokal
   infoPenyakit X;
   
   //Algoritma
   while(!ListEmpty(*L)) {
	  DelVFirst(&(*L),&X);
   } /* kosong */
}

void CopyList(List L1, List *L2)
{ /* I.S   : L1 sembarang 				*/
  /* F.S   : L1 dan L2 menunjuk ke list yang sama 	*/
  /*         tidak ada Alloct/deAlloct 		*/
   *L2=L1;	
}

#endif
