/* Program   : tqueue3.c */
/* Deskripsi : file BODY modul ADT Queue III representasi kontigu dengan array, 
               model III: head memutar searah jarum jam */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 07 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue3.h"

/*function isEmptyQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue3(tqueue3 Q) {
  /*Kamus Lokal*/

  /*ALgoritma*/
  return head3(Q) == 0;
}

/*function isFullQueue3(Q:tQueue3) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue3(tqueue3 Q) {
  /*Kamus Lokal*/

  /*ALgoritma*/  
  return sizeQueue3(Q) == 5;
}

/*function isOneElement3(Q:tQueue3) -> boolean
{mengembalikan true jika Q 1 elemen}*/
boolean isOneElement3(tqueue3 Q) {
  /*Kamus Lokal*/

  /*ALgoritma*/
  if (!isEmptyQueue3(Q)) {
    return tail3(Q) == head3(Q);
  } else {
    return false;
  }  
}

/*procedure createQueue3 ( output Q:tQueue3)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='#'}*/ 
void createQueue3(tqueue3 *Q) {
  /*Kamus Lokal*/
  int i;

  /*ALgoritma*/
  for (i = 1; i <= 5; i++) {
    (*Q).wadah[i] = '#';
  }
  (*Q).head = 0;
  (*Q).tail = 0;
}

/*Function Head3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terdepan} */
int head3(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Q.head;
}

/*Function Tail3(Q:tqueue3) -> integer
{mengembalikan posisi elemen terakhir} */
int tail3(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return Q.tail;
}

/*Function InfoHead3(Q:tqueue3) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead3(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isEmptyQueue3(Q)) {
    return Q.wadah[head3(Q)];
  } else {
    return '#';
  }
}

/*Function InfoTail3(Q:tqueue3) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail3(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isEmptyQueue3(Q)) {
    return Q.wadah[tail3(Q)];
  } else {
    return '#';
  }   
}

/*function sizeQueue3(Q:tQueue3)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue3(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  if (isEmptyQueue3(Q)) {
    return 0;
  } else {
    if (isTailOverHead(Q)) {
      return 5 - head3(Q) + tail3(Q) + 1;
    } else {
      return tail3(Q) - head3(Q) + 1;
    }
  }
}

/*procedure printQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak isi wadah ke layar, berisi atau kosong}*/
void printQueue3(tqueue3 Q) {
  /* Kamus Lokal */
  int i, count;

  /* Algoritma */
  if (isEmptyQueue3(Q)) {
    printf("#, #, #, #, #");
  } else {
    i = head3(Q);
    count = 0;

    while (i != tail3(Q)) {
      printf("%c, ", Q.wadah[i]);
      count++;
      i = (i % 5) + 1;
    }

    // print elemen tail
    printf("%c", Q.wadah[tail3(Q)]);
    count++;

    // print '#' untuk sisa tempat kosong
    for (i = count; i < 5; i++) {
      printf(", #");
    }
  }
  printf("\n");
}

/*procedure viewQueue3(input Q:tQueue3)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue3(tqueue3 Q) {
  /* Kamus Lokal */
  int i;

  /* Algoritma */
  if (!isEmptyQueue3(Q)) {
    if (!isTailOverHead(Q)) {
      for (i = head3(Q); i <= tail3(Q); i++) {
        printf("%c%s", Q.wadah[i], i == tail3(Q) ? "" : ", ");
      }
    } else {
      for (i = head3(Q); i <= 5; i++) {
        printf("%c%s", Q.wadah[i], i == 5 ? "" : ", ");
      }
      for (i = 1; i <= tail3(Q); i++) {
        printf(", %c", Q.wadah[i]);
      }
    }
  }
}

/*procedure enQueue3( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 } */
void enqueue3(tqueue3 *Q, char E) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isFullQueue3(*Q)) {
    if (isEmptyQueue3(*Q)) {
      (*Q).head = 1;
      (*Q).tail = 1;
    } else {
      (*Q).tail = (tail3(*Q) % 5) + 1; 
    }
    (*Q).wadah[tail3(*Q)] = E;
  } else {
    printf("\nQueue penuh, tidak bisa menambah elemen %c\n", E);
  }
}


/*procedure deQueue3( input/output Q:tQueue3,output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q), bila kosong E=' '}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue3(tqueue3 *Q, char *E) {
  /* Kamus Lokal */

  /* Algoritma */
  if (isEmptyQueue3(*Q)) {
    *E = ' ';
  } else {
    *E = (*Q).wadah[head3(*Q)];
    (*Q).wadah[head3(*Q)] = '#';
    if (isOneElement3(*Q)) {
      (*Q).head = 0;
      (*Q).tail = 0;
    } else {
      (*Q).head = (head3(*Q) % 5) + 1;
    }
  }
}

/*EKSTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*function isTailOverHead(Q:tQueue3) -> boolean
{mengembalikan true jika tail berada di depan head}*/
boolean isTailOverHead(tqueue3 Q) {
  /* Kamus Lokal */

  /* Algoritma */
  return tail3(Q) < head3(Q);
}

/*function countMember(Q:tQueue3, E:character) -> integer
{mengembalikan banyaknya nilai E dalam antrian Q}*/
int countMember(tqueue3 Q, char E) {
  /* Kamus Lokal */
  int i, count;

  /* Algoritma */
  count = 0;
  if (!isEmptyQueue3(Q)) {
    if (!isTailOverHead(Q)) {
      for (i = head3(Q); i <= tail3(Q); i++) {
        if (Q.wadah[i] == E) {
          count++;
        }
      }
    } else {
      for (i = head3(Q); i <= 5; i++) {
        if (Q.wadah[i] == E) {
          count++;
        }
      }
      for (i = 1; i <= tail3(Q); i++) {
        if (Q.wadah[i] == E) {
          count++;
        }
      }
    }
  }
  return count;
}

/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
/*procedure enQueue3E( input/output Q:tQueue3, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q sebagai tail, mungkin memutar ke 1 dengan syarat nilai E belum ada di Q} */
void enqueue3E(tqueue3 *Q, char E) {
  /* Kamus Lokal */

  /* Algoritma */
  if (!isFullQueue3(*Q)) {
    if (countMember((*Q), E) == 0) {
      enqueue3(Q, E);
    } else {
      printf("\nNilai %c sudah ada di dalam Queue, tidak bisa menambah elemen.\n", E);
    }
  } else {
    printf("\nQueue penuh, tidak bisa menambah elemen %c.\n", E);
  }
}
