/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul ADT Queue II representasi kontigu dengan array, 
               model II: head bergeser/jelajah */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 04 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue2.h"

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  for (i = 1; i <= 5; i++) {
    (*Q).wadah[i] = '#';
  }
  Head2(*Q) = 0;
  Tail2(*Q) = 0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
// int Head2(tqueue2 Q) {
//   /* Kamus Lokal */
//   /* Algoritma */
//   return Q.head;
// }
#define Head2(Q) (Q).head //implementasi fisik macro

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
// int Tail2(tqueue2 Q);
// int Tail2(tqueue2 Q) {
//   /* Kamus Lokal */
//   /* Algoritma */
//   return Q.tail;
// }
#define Tail2(Q) (Q).tail //implementasi fisik macro

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Tail2(Q) == 0;
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Tail2(Q) == 5 && Head2(Q) == 1;
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Head2(Q) == Tail2(Q) && Head2(Q) != 0;
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isEmptyQueue2(Q)) {
    return Q.wadah[Head2(Q)];
  }
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isEmptyQueue2(Q)) {
    return Q.wadah[Tail2(Q)];
  }
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (isEmptyQueue2(Q)) {
    return 0;
  } else {
    return Tail2(Q) - Head2(Q) + 1;
  }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  for (i = 1; i <= 5; i++) {
    printf("%c, ", Q.wadah[i]);
  }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  for (i = Head2(Q); i <= Tail2(Q); i++) {
    if (Q.wadah[i] != '#') {
      printf("%c, ", Q.wadah[i]);
    }
  }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Tail2(Q) == 5;
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  if (isTailStop(*Q) && (!isFullQueue2(*Q))) {
    for (i = Head2(*Q); i <= Tail2(*Q); i++) {
      (*Q).wadah[i - Head2(*Q) + 1] = (*Q).wadah[i];
      (*Q).wadah[i] = '#';
    }
    Tail2(*Q) = Tail2(*Q) - Head2(*Q) + 1;
    Head2(*Q) = 1;
  }
}

/*procedure enqueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E) {
  /* Kamus Lokal */

  /* Algoritma */
  if (isFullQueue2(*Q)) {
    printf("Queue penuh\n");
  } else {
    if (isEmptyQueue2(*Q)) {
      Head2(*Q) = 1;
      Tail2(*Q) = 1;
    } else if (!isFullQueue2(*Q)) {
      if (isTailStop(*Q)) {
        resetHead(Q);
      }
      Tail2(*Q)++;
    }
    (*Q).wadah[Tail2(*Q)] = E;
  }
}

/*procedure dequeue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E) {
  /* Kamus Lokal */
  
  /* Algoritma */
  if (!isEmptyQueue2(*Q)) {
    *E = (*Q).wadah[Head2(*Q)];
    (*Q).wadah[Head2(*Q)] = '#';
    if (isOneElement2(*Q)) {
      Head2(*Q) = Tail2(*Q) = 0;
    } else {
      Head2(*Q)++;
    }
  } else {
    *E = '@';
  }
}

/*procedure enqueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N) {
  /* Kamus Lokal */
  char E;
  int i;
  
  /* Algoritma */
  if (N <= 5 - sizeQueue2(*Q)){
    for (i = 1; i <= N; i++) {
      printf("Masukkan elemen ke-%d: ", i);
      scanf(" %c", &E);
      enqueue2(Q, E);
    }
  }
}

/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  if (sizeQueue2(Q1) == sizeQueue2(Q2)) {
    for (i = Head2(Q1); i <= Tail2(Q1); i++) {
      if (Q1.wadah[i] != Q2.wadah[i]) {
        return false;
      }
    }
    return true;
  }
  return false;
}
