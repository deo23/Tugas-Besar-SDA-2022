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

int main(){
	Queue Q;
	CreateQueue(&Q);
	int jumlahAntrian = 0;

	int option;

	do{
		system("cls");
		puts("MENU UTAMA");
		puts("[1] Registrasi");
		puts("[2] Panggil Antrian");
		puts("[3] Daftar Antrian");
		puts("[4] Riwayat Antrian");
		puts("[5] Keluar");

		printf("Pilih : ");
		scanf("%d", &option);

		if (option == 1){
			Registrasi(&Q);
			jumlahAntrian++;
			PrintQueue(Q);
			system("pause");
		}
		else if (option == 2){
			prosesAntrian(&Q);
			PrintQueue(Q);
			system("pause");
		}else if (option == 3){
			PrintQueue(Q);
			system("pause");
		}else if (option == 4){
			system("pause");
		}else if (option == 5){
			printf("\nTerima kasih telah menggunakan Aplikasi Layanan Dokter Hewan");
			exit(0);
		}else{
			printf("Maaf, masukan Anda salah. Silahkan coba lagi\n");
			system("pause");
		}
	}while (option != 5);

	return 0;
}
