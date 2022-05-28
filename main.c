/* Program : main.c
 * Deskripsi : main driver Aplikasi Layanan Dokter Hewan
 * Nama : Hilma Sri Rahayu
 * Tanggal : 22 Juli 2021
 * Update : 1 Agustus 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "queue.h"

int main (){
	system("cls");

	Queue Q;
	CreateQueue(&Q);
	
	char menuPilihan;
	
	do{
	    
	    
	    printf("					====================================\n");
	    printf("					||  1. Registrasi                 ||\n");
	    printf("					||  2. Tampil Antrian              ||\n");
	    printf("					||  3. Proses Pelayanan           ||\n");
	    printf("					||  4. Keluar                     ||\n");
	    printf("					====================================\n\n");
	    printf("					Menu Pilihan : "); scanf(" %c", &menuPilihan);
    	
    	    if(menuPilihan == '1'){
    		
    		Registrasi(&Q);
    		system("pause");	
		
		}
		else if(menuPilihan == '2'){
		
			PrintQueue(Q);
			system("pause");

		}
		else if(menuPilihan == '3'){
		
			deQueue(&Q);
			system("pause");

		}
		else if(menuPilihan == '4'){
		
			printf("					====================================\n");
			printf("					||       Sampai Jumpa Lagi        ||\n");
			printf("					====================================\n");
			exit(0);

		}
		else{
		
			printf("\n");
			printf("					====================================\n");
			printf("					||       Masukan Anda Salah       ||\n");
			printf("					||       Masukan Angka 1-4!       ||\n");
			printf("					||       Silakan Coba Lagi        ||\n");
			printf("					====================================\n");
			system("pause");
	
		}
	
	} while(menuPilihan != '4');
	
	return 0;

}

