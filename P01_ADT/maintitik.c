/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 29 Agustus 2024*/
/***********************************/
#include <stdio.h>
#include "titik.h"
#include "titik.c"

int main() {
	//kamus main
	Titik A;
	Titik B;
	
	//algoritma
	printf("Halo, ini driver modul Titik\n");

	//buat Titik A dengan absis 3 dan ordinat 4
	makeTitik(&A);
	setAbsis(&A, 3);
	setOrdinat(&A, 4);

	//buat Titik B dengan absis 5 dan ordinat 12
	makeTitik(&B);
	setAbsis(&B, 5);
	setOrdinat(&B, 12);

	//tampilkan Titik A dan B
	printf("\nTitik A:");
	printf("\n  Absis   = %d", getAbsis(A));
	printf("\n  Ordinat = %d", getOrdinat(A));

	printf("\n\nTitik B:");
	printf("\n  Absis   = %d", getAbsis(B));
	printf("\n  Ordinat = %d", getOrdinat(B));
	
	//tampilkan apakah Titik A merupakan titik origin
	printf("\n\nApakah titik A berada di titik origin? %s", isOrigin(A) ? "Ya" : "Tidak");

	//tampilkan kuadran Titik A
	printf("\n\nKuadran titik A adalah %d", Kuadran(A));

	//geser Titik A sejauh (2, 3)
	geserXY(&A, 2, 3);
	printf("\n\nTitik A setelah digeser sejauh (2, 3):");
	printf("\n  Absis   = %d", A.absis);
	printf("\n  Ordinat = %d", A.ordinat);

	//refleksi Titik A terhadap sumbu X dan Y
	refleksiSumbuX(&A);
	printf("\n\nTitik A setelah direfleksi terhadap sumbu X:");
	printf("\n  Absis   = %d", A.absis);
	printf("\n  Ordinat = %d", A.ordinat);

	refleksiSumbuY(&A);
	printf("\n\nTitik A setelah direfleksi terhadap sumbu Y:");
	printf("\n  Absis   = %d", A.absis);
	printf("\n  Ordinat = %d", A.ordinat);
	
	//tampilkan jarak antara Titik A dan B
	printf("\n\nJarak antara titik A dan B adalah %.2f\n", Jarak(A, B));
	
	return 0;
}
