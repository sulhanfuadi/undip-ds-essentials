/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 20 September 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"

/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
  /* Kamus Lokal */
  int i;

  /* Algoritma */
  for (i = 1; i <= 10; i++) {
    (*T).wadah[i] = '#';
  }
  (*T).top = 0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
// int top (Tstack T) {
//   /* Kamus Lokal */
//   /* Algoritma */
//   return T.top;
// }
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
// char infotop (Tstack T) {
//   /* Kamus Lokal */
//   /* Algoritma */
//   return T.wadah[T.top];
// }
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
  /* Kamus Lokal */

  /* Algoritma */
  return (top(T) == 0);
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
  /* Kamus Lokal */

  /* Algoritma */
  return (top(T) == 10);
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
  /* Kamus Lokal */
  /* Algoritma */
  if (!isFullStack(*T)) {
    top(*T)++;
    infotop(*T) = E;
  }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
  /* Kamus Lokal */
  /* Algoritma */
  if (!isEmptyStack(*T)) {
    *X = infotop(*T);
    infotop(*T) = '#';
    top(*T)--;
  }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T) {
  /* Kamus Lokal */
  int i;
  /* Algoritma */
  for (i = 1; i <= 10; i++) {
    printf("%c", T.wadah[i]);
    if (i < top(T)) {
      printf(";");
    }
  }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T) {
  /* Kamus Lokal */
  int i;
  /* Algoritma */
  for (i = 1; i <= top(T); i++) {
    printf("%c", T.wadah[i]);
    if (i < top(T)) {
      printf(";");
    }
  }
}

/* function isPalindromStack(X: string) -> boolean
  {mengembalikan True jika string X adalah palindrom} */
// boolean isPalindromStack(char X[]) {
//   Tstack T1;
//   boolean palindrome = true;
//   int i, len;
//   createStack(&T1);
//   len = strlen(X);
//   for (i = 0; i < len / 2; i++) {
//     push(&T1, X[i]);
//   }
//   if (len % 2 == 1) {
//     i++;
//   }
//   while (!isEmptyStack(T1) && palindrome) {
//     char E;
//     pop(&T1, &E);
//     if (E != X[i]) {
//       palindrome = false;
//     }
//     i++;
//   }
//   return palindrome;
// }

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N) {
  /* Kamus Lokal */
  char E;
  int i;

  /* Algoritma */
  for (i = 0; i < N; i++) {
    if (isFullStack(*T)) break;
    printf("Masukkan elemen ke-%d: ", i + 1);
    scanf(" %c", &E);
    push(T, E);
  }
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) bila belum penuh atau menjadi kosong bila stack penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E) {
  /* Kamus Lokal */
  char X;
  
  /* Algoritma */
  if (!isFullStack(*T)) {
    push(T, E);
  } else {
    while (!isEmptyStack(*T)) {
      pop(T, &X);
    }
  }
}

/*procedure pushZuma ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau berkurang 1 elemen bila E bernilai sama dengan top }
	{Proses: menumpuk top atau menghapus elemen top }
    {contoh: T=['A','B','C'], E='C' menjadi T=['A','B']}*/
void pushZuma (Tstack *T, char E)  {
  /* Kamus Lokal */
  char X;

  /* Algoritma */
  if (!isEmptyStack(*T) && E == infotop(*T)) {
    pop(T, &X);
  } else {
    push(T, E);
  }
}
