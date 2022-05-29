/* Program : main.c
 * Deskripsi : main driver Aplikasi Layanan Dokter Hewan
 * Modified	:   Berliana Elfada
                Muhammad Deo Audha Rizki
                Suci Awalia Gardara
 *Date Modified : 39 Mei 2022
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
	
	char empty;
 int panjang;
 
 
	do{
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
		printf("%67.c------------------------------------\n",empty);
		printf("%67.c            MAIN MENU           \n",empty);
		printf("%67.c====================================\n",empty);
		printf("%67.c  [1] Registrasi                 \n",empty);
		printf("%67.c  [2] Tampil Antrean             \n",empty);
		printf("%67.c  [3] Cari Data Kucing           \n",empty);
		printf("%67.c  [4] Panggil Antrean            \n",empty);
		printf("%67.c  [5] Keluar                     \n",empty);
		printf("%67.c====================================\n\n",empty);	
	    printf("%67.c Menu Pilihan : ",empty); scanf(" %c", &menuPilihan);

    	
    	if(menuPilihan == '1'){
    		
    		Registrasi(&Q);
    		system("pause");
			system("cls");
		
		}
		else if(menuPilihan == '2'){
		
			PrintQueue(Q);
			system("pause");
			system("cls");

		}
		else if(menuPilihan == '3'){
			
			
		

		}
		else if(menuPilihan == '4'){
			
		
			prosesAntrian(&Q);
			system("pause");
			system("cls");

		}else if(menuPilihan == '5'){
			
			printf("					====================================\n");
			printf("					||       Sampai Jumpa Lagi !      ||\n");
			printf("					====================================\n");
			system("pause");
		}
		else{
		
			printf("\n");
			printf("					====================================\n");
			printf("					||       Masukan Anda Salah       ||\n");
			printf("					||       Masukan Angka 1-5!       ||\n");
			printf("					||       Silakan Coba Lagi        ||\n");
			printf("					====================================\n");
			system("pause");
	
		}
	
	} while(menuPilihan != '5');
	
	return 0;

}
