/* File : pohon1.c */
/* Deskripsi : realisasi body ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 22 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function Alokasi( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree Alokasi(infotype E) { //representasi fisik fungsi
  //kamus lokal
  bintree P;

  //algoritma
  P = (bintree) malloc(sizeof(node));
  if (P != NIL) {  //alokasi berhasil
    akar(P) = E;
    info(P) = E;
    left(P) = NIL;
    right(P) = NIL;
  }
  return P;
}

/* procedure Dealokasi (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
void Dealokasi (bintree *P) {
  //kamus lokal

  //algoritma
  if(*P != NIL){ //jika ada pohon P
    left(*P) = NIL;
    right(*P) = NIL;
  }
  free(*P); //mengosongkan memori
  *P = NIL; //mengatur pointer ke NIL
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree Tree (infotype akar, bintree left, bintree right) {
  //kamus lokal
  bintree P;

  //algoritma
  P = Alokasi(akar);
  if (P != NIL) { //alokasi berhasil
    left(P) = left;
    right(P) = right;
  }
  return P;
}

/****** SELEKTOR *****/
/*function GetAkar (P : BinTree) -> infotype
{ Mengirimkan nilai Akar pohon biner P }*/
infotype GetAkar(bintree P) {
  //kamus lokal

  //algoritma
  return akar(P);
}

/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
  //kamus lokal

  //algoritma
  return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
  //kamus lokal

  //algoritma
  return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
  //kamus lokal

  //algoritma
  return (P == NIL);
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return false;
  } else { //kasus pohon tidak kosong
    return IsEmptyTree(GetLeft(P)) && IsEmptyTree(GetRight(P));
  }
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return false;
  } else { //kasus pohon tidak kosong
    return !IsEmptyTree(GetLeft(P)) && !IsEmptyTree(GetRight(P));
  }
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return false;
  } else { //kasus pohon tidak kosong
    return !IsEmptyTree(GetLeft(P)) && IsEmptyTree(GetRight(P));
  }
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return false;
  } else { //kasus pohon tidak kosong
    return IsEmptyTree(GetLeft(P)) && !IsEmptyTree(GetRight(P));
  }
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    printf("( )");
  } else { //kasus pohon tidak kosongs
    printf("%c(", GetAkar(P));
    PrintPrefix(GetLeft(P)); //rekursif anak pohon P sebelah kiri
    printf(",");
    PrintPrefix(GetRight(P)); //rekursif anak pohon P sebelah kanan
    printf(")");
  }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else { //kasus pohon tidak kosong
    return 1 + NbElm(GetLeft(P)) + NbElm(GetRight(P));
    // 1 untuk akar, rekursif untuk anak kiri dan kanan
  }
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else { //kasus pohon tidak kosong
    if (IsDaun(P)) { //kasus pohon daun
      return 1;
    } else { //kasus pohon tidak kosong dan bukan daun
      return NbDaun(GetLeft(P)) + NbDaun(GetRight(P));
      // rekursif untuk anak kiri dan kanan
    }
  }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
  //kamus lokal

  //algoritma
  if (a > b) { //a lebih besar dari b
    return a;
  } else { //b lebih besar dari a atau sama dengan a
    return b;
  }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
  /*kamus lokal*/

  /*algoritma*/
  if (IsEmptyTree(P)) { /*kasus kosong*/
    return 0;
  } else if (NbElm(P) == 1) { /*kasus pohon 1 elemen*/
    return 0;
  } else { /*kasus lebih dari 1 elemen dan tidak kosong*/
    return 1 + max2(Tinggi(GetLeft(P)), Tinggi(GetRight(P)));
    // 1 untuk akar, max dari tinggi anak kiri dan kanan
  }
}

/******* PENAMBAHAN ELEMEN bintree ********/

/******* PENGHAPUSAN ELEMEN ********/

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return false;
  } else if (GetAkar(P) == X) { //kasus pohon tidak kosong dan akar sama dengan X
    return true;
  } else { //kasus pohon tidak kosong dan akar tidak sama dengan X
    return SearchX(GetLeft(P), X) || SearchX(GetRight(P), X);
  }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
/*asumsi: procedure ini hanya akan mengubah elemen X yang paling cepat ditemukan*/
void UpdateX(bintree *P, infotype X, infotype Y) {
  //kamus lokal

  //algoritma
  if (!IsEmptyTree(*P)) { //kasus pohon tidak kosong
    if (GetAkar(*P) == X) { //kasus akar sama dengan X
      akar(*P) = Y;
    } else { //kasus akar tidak sama dengan X
      if (SearchX(GetLeft(*P), X)){ //jika X ada di anak pohon P sebelah kiri
        UpdateX(&left(*P), X, Y);
      } else { //jika X ada di anak pohon P sebelah kanan
        UpdateX(&right(*P), X, Y);
      }
    }
  }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else if (GetAkar(P) == X) { //kasus pohon tidak kosong dan akar sama dengan X
    return 1 + CountX(GetLeft(P), X) + CountX(GetRight(P), X);
    // 1 untuk akar, rekursif untuk anak kiri dan kanan
  } else { //kasus pohon tidak kosong dan akar tidak sama dengan X
    return CountX(GetLeft(P), X) + CountX(GetRight(P), X);
    // rekursif untuk anak kiri dan kanan
  }
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return true;
  } else if (IsUnerLeft(P)) { //kasus pohon unerleft
    return true;
  } else { //kasus pohon bukan unerleft
    return IsEmptyTree(GetRight(P)) && IsSkewLeft(GetLeft(P));
    // anak kanan kosong dan rekursif untuk anak kiri
  }
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return true;
  } else if (IsUnerRight(P)) { //kasus pohon unerright
    return true;
  } else { //kasus pohon bukan unerright
    return IsEmptyTree(GetLeft(P)) && IsSkewRight(GetRight(P));
    // anak kiri kosong dan rekursif untuk anak kanan
  }
}

/* procedure PrintPrefixSwalow(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixSwalow(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    printf("( )");
  } else { //kasus pohon tidak kosongs
    printf("%c", GetAkar(P));
    if (!IsEmptyTree(GetLeft(P)) || !IsEmptyTree(GetRight(P))) { // cek jika ada anak
      printf("(");
      PrintPrefixSwalow(GetLeft(P));
      if (!IsEmptyTree(GetRight(P))) { // cek jika anak kanan tidak kosong
        printf(",");
        PrintPrefixSwalow(GetRight(P));
      }
      printf(")");
    }
  }
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else {
    if (GetAkar(P) == X) { //kasus akar sama dengan X
      return 1;
    } else {
      if (LevelX(GetLeft(P), X) != 0) { //kasus X ditemukan di anak kiri
        return 1 + LevelX(GetLeft(P), X);
      } else if (LevelX(GetRight(P), X) != 0) { //kasus X ditemukan di anak kanan
        return 1 + LevelX(GetRight(P), X);
      } else { //kasus X tidak ditemukan
        return 0;
      }
    }
  }
}

/*function CountLevelT(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT(bintree P, int T) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
  } else {
    if (T == 1) { //kasus tingkat 1
      return 1; //hanya akar
    } else {
      return CountLevelT(GetLeft(P), T - 1) + CountLevelT(GetRight(P), T - 1);
      // rekursif untuk anak kiri dan kanan
      // T - 1 karena level akar sudah dihitung
    }
  }
}

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return '#';
  } else {
    if (IsDaun(P)) { //kasus pohon daun
      return GetAkar(P);
    } else {
      if (!IsEmptyTree(GetLeft(P))) { //kasus anak kiri tidak kosong
        return GetDaunTerkiri(GetLeft(P));
      } else { //kasus anak kiri kosong
        return GetDaunTerkiri(GetRight(P));
      }
    }
  }
}

/*function FrekuensiX(L:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree L }*/
float FrekuensiX(bintree P, infotype X) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { //kasus pohon kosong
    return 0;
    // menangani kasus error divide by zero
  } else {  //kasus pohon tidak kosong
    return (float) CountX(P, X) / NbElm(P);
    // menghitung rasio kemunculan X dibandingkan ukuran pohon
  }
}

/*function CountVocal(L:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree L}*/
int CountVocal(bintree L) {
  //kamus lokal

  //algoritma
  if (IsEmptyTree(L)) { //kasus pohon kosong
    return 0;
  } else { //kasus pohon tidak kosong
    if (GetAkar(L) == 'A' || GetAkar(L) == 'a' || GetAkar(L) == 'I' || GetAkar(L) == 'i' || GetAkar(L) == 'U' || GetAkar(L) == 'u' || GetAkar(L) == 'E' || GetAkar(L) == 'e' || GetAkar(L) == 'O' || GetAkar(L) == 'o') { //kasus akar huruf vokal
      return 1 + CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
      // 1 untuk akar, rekursif untuk anak kiri dan kanan
    } else { //kasus akar bukan huruf vokal
      return CountVocal(GetLeft(L)) + CountVocal(GetRight(L));
      // rekursif untuk anak kiri dan kanan
    }
  }
}

/*function Modus(L:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
  // kamus lokal
  infotype temp;
  int count;
  char modus;

  // algoritma
  if (!IsEmptyTree(P)) { //kasus pohon tidak kosong
    temp = GetAkar(P);
    count = CountX(P, temp);
    modus = temp;
    if (CountX(P, Modus(GetLeft(P))) > count) { //jika modus di sebelah kiri lebih besar
      modus = Modus(GetLeft(P));
      count = CountX(P, modus);
    } else if (CountX(P, Modus(GetRight(P))) > count) { //jika modus di sebelah kanan lebih besar
      modus = Modus(GetRight(P));
      count = CountX(P, modus);
    }
  } else { //kasus pohon kosong
    modus = '#'; // Return a default value if the tree is empty
  }
  return modus;
}
