/* File : list1.c */
/* Deskripsi : realisasi body ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 01 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"

/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) {
	//kamus lokal
	address P;

	//algoritma
	P = (address) malloc(sizeof(Elm));
	if (P != NIL) { //ruang memori tersedia
		info(P) = E;
		next(P) = NIL;
	}
	return P;
}

/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke NIL  
	Proses: Melakukan pengosongan address P} */
void Dealokasi (address *P) {
	//kamus lokal
	
	//algoritma
	free(*P); //mengosongkan memori
	*P = NIL; //membuat isi P menjadi NIL/kosong
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List1)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List1 *L) {
	//kamus lokal
	
	//algoritma
	First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List1) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List1 L) {
	//kamus lokal
	
	//algoritma
	return (First(L) == NIL);
}

/**************** PENELUSURAN ****************/
/*procedure PrintList(input L:List1)
{I.S. L terdefinisi; F.S. :-}
{Proses: menampilkan info semua elemen list L} */
void PrintList(List1 L) {
	//kamus lokal
	address P;
	
	//algoritma
	P = First(L);
	while (P != NIL) { //selagi isi P tidak NIL
		printf("%c ",info(P));
		P = next(P);
	}
}

/*function NbElm(L:List1) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List1 L) {
	//kamus lokal
	address P;
	int count;
	
	//algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		count++;
		P = next(P);
	}
	return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List1 *L, infotype V ) {
	//kamus lokal
	address P;
	
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) { //kosong
			First(*L) = P;
		} else { //tidak kosong
			next(P) = First(*L);
			First(*L) = P;
		}
	}
}

/*Procedure InsertVLast(input/output L:List1, input V:infotype )
{ I.S. L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List1 *L, infotype V ) {
	//kamus lokal
	address P;
	address Last;
	
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		if (IsEmptyList(*L)) { //kosong
			First(*L) = P;
		} else { //tidak kosong
			Last = First(*L);
			while (next(Last) != NIL) {
				Last = next(Last);
			}
			//endwhile: Last = elemen terakhir
			next(Last) = P;
		}
	}
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi,  }
{ F.S. L tetap, atau berkurang elemen pertamanya.
Proses: Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List1 *L, infotype *V) {
	//kamus lokal
	address P;
	
	//algoritma
	P = First(*L);
	if (P == NIL) { //list kosong
		*V = '#';
	} else {
		*V = info(P);
		First(*L) = next(P);
		Dealokasi(&P);
	}
}

/*Procedure DeleteVLast(input/output L:List1, output V:infotype )
{ I.S. L terdefinisi }
{ F.S. L tetap atau berkurang elemen terakhirnya.
Proses: Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. default nilai V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List1 *L, infotype *V){
	//kamus lokal
	address P;
	address prec;
	address last;

	//algoritma
	if (First(*L) == NIL) {  //list kosong
		*V = '#';
	} else {
		prec = NIL;
		last = First(*L);
		while (next(last) != NIL){
			prec = last;
			last = next(last);
		}
		//endwhile: last elemen terakhir sejati
		*V = info(last);
		if (prec != NIL) {
			next(prec) = NIL;
			last = NIL;
		} else { //satu elemen
			First(*L) = NIL;
		}
	}
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List1, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Proses: Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List1 L, infotype X, address A) {
	//kamus lokal
	address P;
	
	//algoritma
	A = NIL;
	P = First(L);
	while (P != NIL && A == NIL) {
		if (info(P) == X) {
			A = P;
		}
		P = next(P);
	}
	//endwhile: sudah di elemen terakhir atau X sudah ketemu
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Proses: Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	address Q;
	
	//algoritma
	P = First(*L);
	Q = NIL;
	while (P != NIL && Q == NIL) { //Q == NIL, berati belum ketemu
		if (info(P) == X) {
			Q = P;
			info(P) = Y; //ubah X menjadi Y
		}
		P = next(P);
	}
}

/*Procedure Invers(input/output L:List1)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {'i','t','u'} menjadi {'u','t','i'} }*/
void Invers(List1 *L){
	//kamus lokal
	List1 L1;
	address P;

	//algoritma
	CreateList(&L1);
	P = First(*L);
	while(P != NIL){
		InsertVFirst(&L1, info(P)); //masukkan info(P) ke L1 di awal
		P = next(P);
	}
	*L = L1;
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*function CountX(L:List1, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int count;
	
	//algoritma
	P = First(L);
	count = 0;
	while (P != NIL) {
		if (info(P) == X) {
			count++;
		}
		P = next(P);
	}
	return count;
}

/*function FrekuensiX(L:List1, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List1 L, infotype X) {
	//kamus lokal
	int count, total;
	
	//algoritma
	if(NbElm(L) == 0){  //kasus error division by zero
		return 0;
  } else {
		count = CountX(L,X);
		total = NbElm(L);
		return (float) count / total;
	}
}

/*Procedure SearchAllX(input L:List1, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi (1,2,3,...nbElm(L)) kemunculan elemen X dalam list L }*/
void SearchAllX(List1 L, infotype X) {
	//kamus lokal
	address P;
	int i;
	
	//algoritma
	P = First(L);
	i = 1;
	while (P != NIL) {
		if (info(P) == X) {
			printf("%d ",i);
		}
		P = next(P);
		i++;
	}
}

/*Procedure UpdateAllX(input/output L:List1, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau semua elemen bernilai X berubah menjadi Y. 
Proses : mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(List1 *L, infotype X, infotype Y) {
	//kamus lokal
	address P;
	
	//algoritma
	P = First(*L);
	while (P != NIL) {
		if (info(P) == X) {
			info(P) = Y;
		}
		P = next(P);
	}
}

/* Procedure InsertVAfter(input/output L:List1, input V:infotype, input VA:infotype )
{ I.S. List L mungkin kosong, V, S terdefinisi }
{ F.S. L tetap, atau bertambah 1 elemen (VA) pada posisi setelah elemen berinfo V}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=VA sebagai elemen setelah elemen V list linier L yg mungkin kosong } */
void InsertVAfter(List1 *L, infotype V, infotype VA ) {
	//kamus lokal
	address P;
	address Q;
	
	//algoritma
	P = Alokasi(V);
	if (P != NIL) {
		info(P) = VA;
		Q = First(*L);
		while (Q != NIL && info(Q) != V) {
			Q = next(Q);
		}
		//endwhile: Q == NIL atau info(Q) == V
		if (Q != NIL) { //elemen V ditemukan
			next(P) = next(Q);
			next(Q) = P;
		} else { //elemen V tidak ditemukan
			Dealokasi(&P);
		}
	}
}

/*function MaxMember(L:List1) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List1 L) {
	//kamus lokal
	address P;
	int max;
	int count;
	
	//algoritma
	P = First(L);
	max = 0;
	while (P != NIL) {
		count = CountX(L,info(P));
		if (count > max) {
			max = count;
		}
		P = next(P);
	}
	return max;
	// return CountX(L, Modus(L)); //menggunakan fungsi Modus
}

/*function Modus(L:List1) -> infotype */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
infotype Modus(List1 L) {
	//kamus lokal
	address P;
	int max;
	int count;
	infotype modus;
	
	//algoritma
	P = First(L);
	max = 0;
	while (P != NIL) {
		count = CountX(L,info(P));
		if (count > max) {
			max = count;
			modus = info(P);
		}
		P = next(P);
	}
	return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List1, input L2:List1, output L:List1)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List1 L1, List1 L2, List1 *L) {
	//kamus lokal
	address P;
	
	//algoritma
	if (IsEmptyList(L1)) { //L1 kosong
		*L = L2;
	} else if (IsEmptyList(L2)) { //L2 kosong
		*L = L1;
	} else { //L1 dan L2 tidak kosong
		*L = L1;
		P = First(L1);
		while (next(P) != NIL) {
			P = next(P);
		}
		next(P) = First(L2);
	}
}

/*Procedure SplitList(input L:List1, output L1:List1, output L2:List1)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List1 L, List1 *L1, List1 *L2) {
	//kamus lokal
	address P, Q;
	infotype V;
	int mid, i;

	//algoritma
	CreateList(L1);
	CreateList(L2);
	mid = NbElm(L) / 2;
	
	P = First(L);
	for (i = 0; i < mid; i++) {
			InsertVLast(L1, info(P));  // Memasukkan elemen ke L1
			P = next(P);
	}

	while (P != NIL) {
			InsertVLast(L2, info(P));  // Memasukkan elemen ke L2
			P = next(P);
	}
}

/*Procedure CopyList(input L1:List1, output L2:List1)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List1 L1, List1 *L2) {
	//kamus lokal
	address P;
	
	//algoritma
	CreateList(L2);
	P = First(L1);
	while (P != NIL) {
		InsertVLast(L2,info(P));
		P = next(P);
	}
}
