/* File : pohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 06 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"

/************************ PROTOTYPE ************************/
/****** Manajemen Memori ******/
/* function AlokasiTree3( E: infotype)-> bintree3 */
/* {menghasilkan alokasi memori pohon } */
bintree3 AlokasiTree3(infotype E) {
   /*kamus lokal*/
   bintree3 P;

   /*algoritma*/
   /* Memesan ruang ke memori */
   P = (bintree3) malloc(sizeof(node3));
   if (P != NIL) { /* Alokasi berhasil */
      parent(P) = NIL;
      info(P) = E;
      visited(P) = false;
      left(P) = NIL;
      right(P) = NIL;
   }
   return P;
}

/********** PEMBUATAN POHON BARU ***********/
/* function Tree(A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
   /*kamus lokal*/
   bintree3 P;

   /*algoritma*/
   P = AlokasiTree3(X);
   if (P != NIL) {
      parent(P) = A;
      info(P) = X;
      visited(P) = V;
      left(P) = kiri;
      right(P) = kanan;
   }
   return P;
}

/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree) { /*jika ada pohon P*/
      visited(P) = false;
      if (IsBiner(P)) { /*jika pohon biner*/
         resetVisited(left(P));
         resetVisited(right(P));
      } else {
         if (IsUnerLeft(P)) { /*jika pohon unerleft (pohon hanya memiliki subpohon kiri)*/
            resetVisited(left(P));
         } else { /*jika pohon unerright*/
            resetVisited(right(P));
         }
      }
   }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   return (P == NIL);
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      return (IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
      /*jika pohon daun, maka anak kiri dan anak kanan kosong*/
   } else { /*jika tidak ada pohon P*/
      return false;
   }
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      return (!IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
      /*jika pohon biner, maka anak kiri dan anak kanan tidak kosong*/
   } else { /*jika tidak ada pohon P*/
      return false;
   }
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      return (!IsEmptyTree(left(P)) && IsEmptyTree(right(P)));
      /*jika pohon unerleft, maka anak kiri tidak kosong dan anak kanan kosong*/
   } else { /*jika tidak ada pohon P*/
      return false;
   }
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      return (IsEmptyTree(left(P)) && !IsEmptyTree(right(P)));
      /*jika pohon unerright, maka anak kiri kosong dan anak kanan tidak kosong*/
   } else { /*jika tidak ada pohon P*/
      return false;
   }
}

/*PENELUSURAN*/
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      printf("%c", akar(P));
      if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
         printf("(");
         printDFS(left(P));
         printf(",");
         printDFS(right(P));
         printf(")");
      } else { /*jika tidak ada anak*/
         printf("()");
      }
   }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      printf("%c", akar(P));
      if (akar(P) == X) { /*jika akar sama dengan X*/
         printf("\n");
      } else { /*jika akar tidak sama dengan X*/
         if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
            printf("(");
            printPathX(left(P), X);
            printf(",");
            printPathX(right(P), X);
            printf(")");
         }
      }
   }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      printf("%c", akar(P));
      if (akar(P) == X && IsDaun(P)) { /*jika akar sama dengan X dan pohon daun*/
         printf("\n");
      } else { /*jika akar tidak sama dengan X atau bukan pohon daun*/
         if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
            printf("(");
            printPathDaunX(left(P), X);
            printf(",");
            printPathDaunX(right(P), X);
            printf(")");
         }
      }
   }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      printf("%c", akar(P));
      if (IsDaun(P)) { /*jika pohon daun*/
         printf("\n");
      } else { /*jika bukan pohon daun*/
         if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
            printf("(");
            printAllPaths(left(P));
            printf(",");
            printAllPaths(right(P));
            printf(")");
         }
      }
   }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (IsEmptyTree(P)) { /*kasus pohon kosong*/
      return 0;
   } else { /*kasus pohon tidak kosong*/
      return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
      /* 1 untuk akar, rekursif untuk anak kiri dan kanan */
   }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (IsEmptyTree(P)) { /*kasus pohon kosong*/
      return 0;
   } else { /*kasus pohon tidak kosong*/
      if (IsDaun(P)) { /*kasus pohon daun*/
         return 1;
      } else { /*kasus pohon tidak kosong dan bukan daun*/
         return NbDaun(left(P)) + NbDaun(right(P));
         /* rekursif untuk anak kiri dan kanan */
      }
   }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b) {
   /*kamus lokal*/

   /*algoritma*/
   if (a > b) { /*a lebih besar dari b*/
      return a;
   } else { /*b lebih besar dari a atau sama dengan a*/
      return b;
   }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (IsEmptyTree(P)) { /*kasus pohon kosong*/
      return -1;
   } else if (NbElmTree(P) == 1) { /*kasus pohon 1 elemen*/
      return 0;
   } else { /*kasus lebih dari 1 elemen dan tidak kosong*/
      return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
      /* 1 untuk akar, rekursif untuk anak kiri dan kanan */
   }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
   /*kamus lokal*/

   /*algoritma*/
   if (IsEmptyTree(P)) { /*kasus pohon kosong*/
      return 0;
   } else { /*kasus pohon tidak kosong*/
      if (parent(P) == NIL) { /*kasus akar*/
         return 1;
      } else { /*kasus bukan akar*/
         return 1 + Level(parent(P));
      }
   }
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
   /*kamus lokal*/

   /*algoritma*/
   if (IsEmptyTree(P)) { /*kasus pohon kosong*/
      return 0;
   } else { /*kasus pohon tidak kosong*/
      if (T == 1) { /*kasus tingkat 1*/
         return 1; /*hanya akar*/
      } else {
         return CountLevelT(left(P), T - 1) + CountLevelT(right(P), T - 1);
         /* rekursif untuk anak kiri dan kanan */
         /* T - 1 karena level akar sudah dihitung */
      }
   }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
   /*kamus lokal*/

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      if (Level(P) == N) { /*jika level sama dengan N*/
         printf("%c ", akar(P));
      } else { /*jika level tidak sama dengan N*/
         PrintLevel(left(P), N);
         PrintLevel(right(P), N);
      }
   }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
   /*kamus lokal*/
   int i;

   /*algoritma*/
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      for (i = 1; i <= Tinggi(P) + 1; i++) { /*mencetak level dari terkecil ke terbesar*/
         PrintLevel(P, i);
      }
   } else { /*jika tidak ada pohon P*/
      printf("Pohong kosong\n");
   }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus List1 ***/
//printList sudah ADA di List1.h

/*procedure Pconcat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {
   /*kamus lokal*/
   address P;

   /*algoritma*/
   if (First(*Asli) == NIL) { /*kasus list Asli kosong*/
      First(*Asli) = First(Tambahan);
   } else { /*kasus list Asli tidak kosong*/
      P = First(*Asli);
      while (next(P) != NIL) { /*mencari elemen terakhir list Asli*/
         P = next(P);
      }
      next(P) = First(Tambahan);
   }
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan) {
   /*kamus lokal*/
   List1 L;
   address P;

   /*algoritma*/
   CreateList(&L);
   if (First(Asli) == NIL) { /*kasus list Asli kosong*/
      First(L) = First(Tambahan);
   } else { /*kasus list Asli tidak kosong*/
      P = First(Asli);
      while (next(P) != NIL) { /*mencari elemen terakhir list Asli*/
         P = next(P);
      }
      First(L) = First(Asli);
      next(P) = First(Tambahan);
   }
   return L;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P) {
   /*kamus lokal*/
   List1 L, L1, L2;

   /*algoritma*/
   CreateList(&L);
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      InsertVLast(&L, akar(P));
      if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
         L1 = LinearPrefix(left(P));
         L2 = LinearPrefix(right(P));
         Pconcat(&L, L1);
         Pconcat(&L, L2);
      }
   }
   return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P) {
   /*kamus lokal*/
   List1 L, L1, L2;

   /*algoritma*/
   CreateList(&L);
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
         L1 = LinearPosfix(left(P));
         L2 = LinearPosfix(right(P));
         Pconcat(&L, L1);
         Pconcat(&L, L2);
      }
      InsertVLast(&L, akar(P));
   }
   return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P) {
   /*kamus lokal*/
   List1 L, L1, L2;

   /*algoritma*/
   CreateList(&L);
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
         L1 = LinearInfix(left(P));
         Pconcat(&L, L1);
      }
      InsertVLast(&L, akar(P));
      if (!IsEmptyTree(left(P)) || !IsEmptyTree(right(P))) { /*jika ada anak*/
         L2 = LinearInfix(right(P));
         Pconcat(&L, L2);
      }
   }
   return L;
}

/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P) {
   /*kamus lokal*/
   List1 L, L1, L2;
   int i;

   /*algoritma*/
   CreateList(&L);
   if (!IsEmptyTree(P)) { /*jika ada pohon P*/
      for (i = 1; i <= Tinggi(P) + 1; i++) { /*mencetak level dari terkecil ke terbesar*/
         L1 = LinearPrefix(P);
         Pconcat(&L, L1);
      }
   }
   return L;
}
