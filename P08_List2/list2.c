/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait single circular, representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 08 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

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
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
	//kamus lokal
	
	//algoritma
	free(*P); //mengosongkan memori
	*P = NIL; //membuat isi P menjadi NIL/kosong
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
  //kamus lokal
  
  //algoritma
  First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
  //kamus lokal
  
  //algoritma
  return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
  //kamus lokal
  address P;
  
  //algoritma
  P = First(L);
  if (P == NIL) {
    return false; // List kosong
  }
  return (next(P) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
  //kamus lokal
  address P;
  
  //algoritma
  if (IsEmptyList(L)) {
    printf("List is empty.\n");
  }
  P = First(L);
  do {
    printf("%c ", info(P));
    P = next(P);
  } while (P != First(L));
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) {
    return 0;
  }
  P = First(L);
  count = 0;
  do {
    count++;
    P = next(P);
  } while (P != First(L));
  return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
  //kamus lokal
  address P;
  address Last;
  
  //algoritma
  P = Alokasi(V);
  if (P != NIL) { //alokasi berhasil
    if (IsEmptyList(*L)) { //kosong
      First(*L) = P;
      next(P) = First(*L);
    } else { //tidak kosong
      Last = First(*L);
      while (next(Last) != First(*L)) {
        Last = next(Last);
      }
      //endwhile: Last = elemen terakhir
      next(P) = First(*L);
      next(Last) = P;
      First(*L) = P;
    }
  }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
  //kamus lokal
  address P, Last;

  //algoritma
  P = Alokasi(V);
  if (P != NIL) {
    if (IsEmptyList(*L)) { //kosong
      First(*L) = P;
      next(P) = First(*L);
    } else { //tidak kosong
      Last = First(*L);
      while (next(Last) != First(*L)) {
        Last = next(Last);
      }
      next(P) = First(*L);
      next(Last) = P;
    }
  } 
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
  //kamus lokal
  address P, Last;
  
  //algoritma
  if (!IsEmptyList(*L)) { //
    P = First(*L);
    *V = info(P);
    if (IsOneElm(*L)) { //hanya satu elemen
      First(*L) = NIL;
    } else { //lebih dari satu elemen
      Last = First(*L);
      while (next(Last) != First(*L)) {
        Last = next(Last);
      }
      //endwhile: Last = elemen terakhir
      First(*L) = next(P);
      next(Last) = First(*L);
    }
    Dealokasi(&P);
  } else { //kosong
    *V = '#';
  }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
  //kamus lokal
  address P, BeforeLast;
  
  //algoritma
  if (!IsEmptyList(*L)) { //cek kosong
    if (IsOneElm(*L)) { //hanya satu elemen
      P = First(*L);
      *V = info(P);
      First(*L) = NIL;
    } else { //lebih dari satu elemen
      BeforeLast = First(*L);
      while (next(next(BeforeLast)) != First(*L)) {
        BeforeLast = next(BeforeLast);
      }
      //endwhile: BeforeLast = elemen sebelum elemen terakhir
      P = next(BeforeLast);
      *V = info(P);
      next(BeforeLast) = First(*L);
    }
    Dealokasi(&P);
  } else { //kosong
    *V = '#';
  }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
  //kamus lokal
  address P, BeforeX;
  
  //algoritma
  if (!IsEmptyList(*L)) { //cek kosong
    if (IsOneElm(*L)) { //hanya satu elemen
      P = First(*L);
      if (info(P) == X) {
        First(*L) = NIL;
        Dealokasi(&P);
      }
    } else { //lebih dari satu elemen
      BeforeX = First(*L);
      while ((next(BeforeX) != First(*L)) && (info(next(BeforeX)) != X)) { //ketika BeforeX bukan elemen terakhir dan elemen setelah BeforeX bukan elemen X
        BeforeX = next(BeforeX);
      }
      //endwhile: BeforeX = elemen sebelum elemen X
      if (info(next(BeforeX)) == X) { //elemen setelah BeforeX adalah elemen X
        P = next(BeforeX);
        next(BeforeX) = next(P);
        Dealokasi(&P);
      }
    }
  }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
  //kamus lokal
  address P;
  
  //algoritma
  if (IsEmptyList(L)) { //kosong
    *A = NIL;
  } else { //tidak kosong
    P = First(L);
    *A = NIL;
    do {
      if (info(P) == X) {
        *A = P;
        break;
      }
      P = next(P);
    } while (P != First(L) && *A == NIL);
  }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
  //kamus lokal
  address P;
  
  //algoritma
  if (!IsEmptyList(*L)) { //cek kosong
    P = First(*L);
    do {
      if (info(P) == X) {
        info(P) = Y; //ganti nilai X dengan Y
      }
      P = next(P);
    } while (P != First(*L));
  }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
  //kamus lokal
  address P, BeforeP, AfterP;
  
  //algoritma
  if (!IsEmptyList(*L)) { //cek kosong
    if (!IsOneElm(*L)) { //lebih dari satu elemen
      P = First(*L);
      BeforeP = First(*L);
      do {
        AfterP = next(P);
        next(P) = BeforeP;
        BeforeP = P;
        P = AfterP;
      } while (P != First(*L));
      //endwhile: P = First(*L)
      next(First(*L)) = BeforeP; //sambungkan elemen terakhir ke elemen pertama
      First(*L) = BeforeP; //ubah elemen pertama menjadi elemen terakhir
    }
  }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) {
    return 0;
  }
  P = First(L);
  count = 0;
  do {
    if (info(P) == X) {
      count++;
    }
    P = next(P);
  } while (P != First(L));
  return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
  //kamus lokal
  int total, count;
  
  //algoritma
  count = CountX(L, X);
  total = NbElm(L);
  if (total > 0) {
    return (float) count / total;
  } else { //meanangani kasus divide by zero
    return 0.00;
  }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) {
    return 0;
  }
  P = First(L);
  count = 0;
  do {
    if (info(P) == 'A' || info(P) == 'I' || info(P) == 'U' || info(P) == 'E' || info(P) == 'O' || info(P) == 'a' || info(P) == 'i' || info(P) == 'u' || info(P) == 'e' || info(P) == 'o') {
      count++; //jika terdapat huruf vokal, increment banyaknya huruf vokal
    }
    P = next(P);
  } while (P != First(L));
  return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) {
    return 0;
  }
  P = First(L);
  count = 0;
  do {
    if ((info(P) == 'N' && info(next(P)) == 'G') || (info(P) == 'n' && info(next(P)) == 'g')) { //jika terdapat kombinasi NG
      count++;
    }
    P = next(P);
  } while (P != First(L));
  return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
  //kamus lokal
  address P, NodeX;
  
  //algoritma
  SearchX(*L, X, &NodeX);
  if (NodeX != NIL) { //jika X ditemukan
    P = Alokasi(V);
    if (P != NIL) {
      next(P) = next(NodeX);
      next(NodeX) = P;
    }
  }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
  //kamus lokal
  address P, BeforeX, NodeX;
  
  //algoritma
  SearchX(*L, X, &NodeX);
  if (NodeX != NIL) { //jika X ditemukan
    P = Alokasi(V);
    if (P != NIL) {
      if (NodeX == First(*L)) { //jika X adalah elemen pertama
        InsertVFirst(L, V);
      } else { //jika X bukan elemen pertama
        BeforeX = First(*L);
        while (next(BeforeX) != NodeX) {
          BeforeX = next(BeforeX);
        }
        //endwhile: BeforeX = elemen sebelum elemen X
        next(P) = NodeX; //sambungkan elemen yang baru ke elemen X
        next(BeforeX) = P; //ubah elemen sebelum elemen X menjadi elemen yang baru
      }
    }
  }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
  //kamus lokal
  address NodeX, P;
  
  //algoritma
  SearchX(*L, X, &NodeX);
  if (NodeX != NIL) { //jika X ditemukan
    P = next(NodeX); //elemen P adalah elemen setelah X
    *V = info(P);
    next(NodeX) = next(P); //alamat next X menjadi alamat next P
    Dealokasi(&P);
  } else {
    *V = '#';
  }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
  //kamus lokal
  address NodeX, PrevBeforeX, P;
  
  //algoritma
  SearchX(*L, X, &NodeX);
  if (NodeX != NIL) { //jika X ditemukan
    if (NodeX == First(*L)) { //jika X adalah elemen pertama
      DeleteVLast(L, V);
    } else { //jika X bukan elemen pertama
      PrevBeforeX = First(*L);
      while (next(next(PrevBeforeX)) != NodeX) {
        PrevBeforeX = next(PrevBeforeX);
      }
      //endwhile: PrevBeforeX = elemen sebelum elemen BeforeX
      P = next(PrevBeforeX); //elemen P adalah elemen sebelum X
      *V = info(P);
      next(PrevBeforeX) = next(P);
      Dealokasi(&P);
    }
  } else {
    *V = '#';
  }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
  //kamus lokal
  address P, BeforeX, NodeX;
  
  //algoritma
  if (!IsEmptyList(*L)) {
    do {
      SearchX(*L, X, &NodeX);
      if (NodeX != NIL) { //jika X ditemukan
        if (NodeX == First(*L)) { //jika X adalah elemen pertama
          DeleteVFirst(L, &X);
        } else { //jika X bukan elemen pertama
          BeforeX = First(*L);
          while (next(BeforeX) != NodeX) { //
            BeforeX = next(BeforeX);
          }
          //endwhile: BeforeX = elemen sebelum elemen NodeX
          P = NodeX; //elemen P adalah elemen X yang akan dihapus
          next(BeforeX) = next(P); //alamat next BeforeX menjadi alamat next P
          Dealokasi(&P);
        }
      }
    } while (NodeX != NIL); //selagi X ditemukan
  }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) {
    printf("0\n");
  } else {
    P = First(L);
    count = 0;
    do {
      count++;
      if (info(P) == X) {
        printf("%d ", count);
      }
      P = next(P);
    } while (P != First(L));
  }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
  //kamus lokal
  address P;
  int max, count;
  
  //algoritma
  if (IsEmptyList(L)) {
    return 0;
  }
  P = First(L);
  max = 0;
  do {
    count = CountX(L, info(P));
    if (count > max) {
      max = count;
    }
    P = next(P);
  } while (P != First(L));
  return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
  //kamus lokal
  address P;
  int count, max;
  infotype mod;
  
  //algoritma
  if (IsEmptyList(L)) {
    return '#'; //asumsi: '#' merupakan karakter default
  }
  P = First(L);
  max = 0;
  do {
    count = CountX(L, info(P));
    if (count > max) {
      max = count;
      mod = info(P);
    }
    P = next(P);
  } while (P != First(L));
  return mod;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
  address P1, P2;

  CopyList(L1, L);
  if (!IsEmptyList(L2)) {
    P1 = First(*L);
    while (next(P1) != First(*L)) {
      P1 = next(P1);
    }
    //endwhile: next(P1) == First(*L) {P1 adalah elemen terakhir}
    P2 = First(L2);
    next(P1) = P2; //sambungkan elemen terakhir L1 ke elemen pertama L2
    while (next(P2) != First(L2)) {
      P2 = next(P2);
    }
    //endwhile: next(P2) == First(L2) {P2 adalah elemen terakhir}
    next(P2) = First(*L); //sambungkan elemen terakhir L2 ke elemen pertama L {jadi sirkular}
  }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
  address P, Q;
  int mid, count, i;

  CreateList(L1);
  CreateList(L2);
  count = NbElm(L);
  i = 1;
  if (count > 0) {
    mid = count / 2;
    P = First(L);
    while (i <= mid) {
      InsertVLast(L1, info(P));
      P = next(P);
      i++;
    }
    while (P != First(L)) {
      InsertVLast(L2, info(P));
      P = next(P);
    }
    //set circular L1
    if (!IsEmptyList(*L1)) {
      Q = First(*L1);
      while (next(Q) != First(*L1)) {
        Q = next(Q);
      }
      next(Q) = First(*L1);
    }
    //set circular L2
    if (!IsEmptyList(*L2)) {
      Q = First(*L2);
      while (next(Q) != First(*L2)) {
        Q = next(Q);
      }
      next(Q) = First(*L2);
    }
  }
}
/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
  address P;

  CreateList(L2);
  P = First(L1);
  if (P != NIL) { //jika L1 tidak kosong
    do {
      InsertVLast(L2, info(P));
      P = next(P);
    } while (P != First(L1)); //selagi P bukan elemen terakhir
  }
}
