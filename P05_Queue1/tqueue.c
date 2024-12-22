/* Program   : tqueue.c */
/* Deskripsi : file BODY modul ADT Queue representasi kontigu dengan array, 
               model I: head selalu di posisi 0 atau 1 */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 27 September 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue.h"

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi elemen dengan huruf '-', head=tail=0 }*/ 
void createQueue(tqueue *Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  for (i = 1; i <= 10; i++) {
    (*Q).wadah[i] = '-';
  }
  head(*Q) = 0;
  tail(*Q) = 0;
}

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Q.wadah[head(Q)];
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Q.wadah[tail(Q)];
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return tail(Q);
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  for (i = 1; i <= 10; i++) {
    printf("%c, ", Q.wadah[i]);
  }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen tak kosong ke layar}*/
void viewQueue(tqueue Q) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  if (!isEmptyQueue(Q)) {
    for (i = head(Q); i <= tail(Q); i++) {
      if (Q.wadah[i] != '-') {
        printf("%c, ", Q.wadah[i]);
      }
    }
  }
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return head(Q) == 0;
}

/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return tail(Q) == 10;
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q) {
  /* Kamus Lokal */

  /* Algoritma */
  // return (Q.head == Q.tail) && (Q.head != 0);
  return head(Q) == 1 && tail(Q) == 1;
}

/*procedure enqueue( input/output Q:tQueue, input e: character )
{I.S.: Q dan e terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char e) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isFullQueue(*Q) && !isEmptyQueue(*Q)) {
    tail(*Q)++;
    (*Q).wadah[tail(*Q)] = e;
  } else if (isEmptyQueue(*Q)) {
    head(*Q) = 1;
    tail(*Q) = 1;
    (*Q).wadah[tail(*Q)] = e;
  }
}

/*procedure deQueue( input/output Q:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead(Q) atau e='-' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *e) {
  /* Kamus Lokal */
  int i;
  
  /* Algoritma */
  if (!isEmptyQueue(*Q)) {
    *e = infoHead(*Q);
    for (i = head(*Q); i < tail(*Q); i++) {
      (*Q).wadah[i] = (*Q).wadah[i + 1];
    }
    (*Q).wadah[tail(*Q)] = '-';
    tail(*Q)--;
    if (isOneElement(*Q)) {
      head(*Q) = 0;
      tail(*Q) = 0;
    }
  }
}

/* procedure enqueue1(input/output Q:queue, input e:character)
{I.S.: Q dan e terdefinisi }
{F.S.: Q bertambah 1 elemen atau penuh}
{Proses: menambah elemen queue, jika Q penuh, elemen pertama/head dihapus} */
void enqueue1(tqueue *Q, char e) {
  /* Kamus Lokal */
  char temp;

  /* Algoritma */
  if (isFullQueue(*Q)) {
    dequeue(Q, &temp);
  }
  enqueue(Q, e);
}

/*function maxlength(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int maxlength(tqueue Q1, tqueue Q2) {
  /* Kamus Lokal */

  /* Algoritma */
  if (sizeQueue(Q1) > sizeQueue(Q2)) {
    return sizeQueue(Q1);
  } else {
    return sizeQueue(Q2);
  }
}

/*procedure enqueue2( input/output Q1:tQueue, input/output Q2:tQueue, input e: character )
{I.S.: e terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek dari Q1 atau Q2} */
void enqueue2(tqueue *Q1, tqueue *Q2, char e) {
  /* Kamus Lokal */

  /* Algoritma */
  if (sizeQueue(*Q1) <= sizeQueue(*Q2)) {
    enqueue(Q1, e);
  } else {
    enqueue(Q2, e);
  }
}

/*procedure dequeue2( input/output Q1:tQueue, input/output Q2:tQueue, output e: character )
{I.S.: }
{F.S.: e=infohead Q1 atau Q2 atau e='-' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
void dequeue2(tqueue *Q1, tqueue *Q2, char *e) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isEmptyQueue(*Q1) && !isEmptyQueue(*Q2)) {
    if (sizeQueue(*Q1) <= sizeQueue(*Q2)) {
      dequeue(Q2, e);
    } else {
      dequeue(Q1, e);
    }
  } else if (!isEmptyQueue(*Q1)) {
    dequeue(Q1, e);
  } else if (!isEmptyQueue(*Q2)) {
    dequeue(Q2, e);
  } else {
    *e = '-';
  }
}