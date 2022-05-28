#include "Queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

/***** Manajemen memori *****/
/* Mengirimkan address hasil alokasi sebuah elemen dengan info X.
 * Jika alokasi berhasil, modul mengembalikan P; Info(P) = X, Next(P) = NULL.
 * P adalah pointer yang menunjuk ke node Queue sebagai hasil alokasi.
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

/* Melakukan pencetakan daftar penyakit hewan */
void printPenyakit(){
	int i;
	for (i=0; i<9; i++){
		printf("				  	%d. %s\n",i+1, arrPenyakit[i]);
	}
}


/* Mengembalikan waktu estimasi pelayanan berdasarkan nilai prioritas antrian */
int cekWaktuPelayanan(int Penyakit){
	if (Penyakit<4){
		return 15; 
	} else if (Penyakit<7){
		return 30;
	} else if (Penyakit<10){
		return 45;
	}
}

/* Menghitung waktu estimasi pelayanan */
int hitungWaktuPelayanan(int Ringan, int Sedang, int Berat){
	return (Ringan*15) + (Sedang*30) + (Berat*45);
}

