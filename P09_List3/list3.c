/* File : list3.c */
/* Deskripsi : realisasi body ADT list lanjar kait ganda dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 14 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.h"

/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E bila berhasil, Nil bila gagal} */
address Alokasi(infotype E) { //representasi fisik fungsi
  //kamus lokal
  address P;

  //algoritma
  P = (address) malloc(sizeof(Elm));
  if (P != NIL) { //ruang memori tersedia
    info(P) = E;
    next(P) = NIL;
    prev(P) = NIL;
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
  if(P != NIL){
    prev(*P) = NIL; //alamat element sebelum P adalah NIL
    next(*P) = NIL; //alamat element setelah P adalah NIL
  }
  *P = NIL; //membuat isi P menjadi NIL/kosong
  free(*P); //mengosongkan memori
}

/* PROTOTYPE */
/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List3)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List3 *L) {
  //kamus lokal
  
  //algoritma
  First(*L) = NIL;
}

/****************** TEST LIST KOSONG ******************/
/* function IsEmptyList(L:List3) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List3 L) {
  //kamus lokal
  
  //algoritma
  return (First(L) == NIL);
}

/*PENELUSURAN*/
/*procedure PrintList(input L:List3)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan semua elemen list L} */
void PrintList(List3 L) {
  //kamus lokal
  address P;
  
  //algoritma
  if (!IsEmptyList(L)) { //jika list tidk kosong
    P = First(L);
    do {
      printf("%c ", info(P));
      P = next(P);
    } while (P != NIL);
    //end while: P = NIL (sudah sampai elemen terakhir)
  }
}

/*function NbElm(L:List3) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List3 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return 0;
  }
  //list tidak kosong
  P = First(L);
  count = 0;
  do {
    count++;
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List3 *L, infotype V ) {
  //kamus lokal
  address P;
  
  //algoritma
  P = Alokasi(V);
  if (P != NIL) { //alokasi berhasil
    if (IsEmptyList(*L)) { //kosong
      First(*L) = P;
      next(P) = NIL;
      prev(P) = NIL;
    } else { //tidak kosong
      next(P) = First(*L);
      prev(P) = NIL;
      prev(First(*L)) = P;
      First(*L) = P;
    }
  }
}

/*Procedure InsertVLast(input/output L:List3, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V}
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List3 *L, infotype V ) {
  //kamus lokal
  address P, Last;
  
  //algoritma
  P = Alokasi(V);
  if (P != NIL) { //alokasi berhasil
    if (IsEmptyList(*L)) { //kosong
      First(*L) = P;
      next(P) = NIL;
      prev(P) = NIL;
    } else { //tidak kosong
      Last = First(*L);
      while (next(Last) != NIL) {
        Last = next(Last);
      }
      //endwhile: Last = elemen terakhir
      next(P) = NIL;
      prev(P) = Last;
      next(Last) = P;
    }
  }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List3, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen pertama list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List3 *L, infotype *V) {
  //kamus lokal
  address P;
  
  //algoritma
  if (!IsEmptyList(*L)) {
    P = First(*L);
    *V = info(P);
    if (next(P) == NIL) { //hanya satu elemen
      First(*L) = NIL;
    } else { //lebih dari satu elemen
      First(*L) = next(P);
      prev(First(*L)) = NIL;
    }
    Dealokasi(&P);
  } else { //kosong
    *V = '#';
  }
}

/*Procedure DeleteVLast(input/output L:List3, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List3 *L, infotype *V) {
  //kamus lokal
  address Last;

  //algoritma
  if (!IsEmptyList(*L)) { //tiidak kosong
    Last = First(*L);
    while (next(Last) != NIL) {
      Last = next(Last);
    }
    //endwhile: Last = elemen terakhir
    *V = info(Last);
    if (prev(Last) == NIL) { //satu elemen
      Last = NIL;
    } else { //lebih dari satu elemen
      next(prev(Last)) = NIL; //elemen Last dihapus
    }
    Dealokasi(&Last);
  } else { //kosong
    *V = '#';
  }
}

/*Procedure DeleteX(input/output L:List3, input X:infotype)
{ I.S. List L terdefinisi }
{ F.S. List mungkin menjadi kosong, atau berkurang 1 elemen. }
{ Proses: Elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteX(List3 *L, infotype X) {
  // Kamus lokal
  address P;

  // Algoritma
  if (!IsEmptyList(*L)) {
    P = First(*L);
    while (P != NIL) { //selama belum mencapai elemen terakhir
      if (info(P) == X) {
        if (P == First(*L)) { //elemen pertama
          DeleteVFirst(L, &X);
        } else if (next(P) == NIL) { //elemen terakhir
          DeleteVLast(L, &X);
        } else { //elemen di tengah
          next(prev(P)) = next(P);
          prev(next(P)) = prev(P);
          Dealokasi(&P);
        }
        break; // Keluar setelah menghapus elemen
      }
      P = next(P);
    }
  }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List3, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X. }
{ Proses : Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List3 L, infotype X, address *A) {
  //kamus lokal
  address P;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    *A = NIL;
  } else { //jika list tidak kosong
    *A = NIL;
    P = First(L);
    do {
      if (info(P) == X) {
        *A = P;
        break;
      }
      P = next(P);
    } while (P != NIL && *A == NIL);
    //end while: P = NIL atau A != NIL
  }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List3, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.}
{ Proses : Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List3 *L, infotype X, infotype Y) {
  //kamus lokal
  address P;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    P = First(*L);
    do {
      if (info(P) == X) {
        info(P) = Y;
      }
      P = next(P);
    } while (P != NIL);
    //end while: P = NIL (sampai elemen terakhir)
  }
}

/*Procedure Invers(input/output L:List3)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, misal {3,5,6} menjadi {6,5,3} }*/
void Invers(List3 *L) {
  //kamus lokal
  address P, temp;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    P = First(*L);
    while (next(P) != NIL) { //selama belum sampai elemen terakhir
      temp = next(P);
      next(P) = prev(P); //menukar next dan prev
      prev(P) = temp;
      P = temp; //pindah ke elemen selanjutnya
    }
    //end while: next(P) = NIL (sudah sampai elemen terakhir)
    next(P) = prev(P);
    prev(P) = NIL;
    First(*L) = P;
  }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*Procedure InsertVAfterX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List3 *L, infotype X, infotype V) {
  //kamus lokal
  address P, NodeX;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    NodeX = First(*L);
    while (next(NodeX) != NIL && info(NodeX) != X) {
      NodeX = next(NodeX);
    }
    //endwhile: next(NodeX) = NIL atau info(NodeX) = X
    if (info(NodeX) == X) { //jika X ditemukan
      P = Alokasi(V);
      if (P != NIL) { //jika alokasi berhasil
        if (next(NodeX) == NIL) { //jika X adalah elemen terakhir
          InsertVLast(L, V);
        } else { //jika X bukan elemen terakhir
          next(P) = next(NodeX);
          prev(P) = NodeX;
          prev(next(NodeX)) = P;
          next(NodeX) = P;
        }
      }
    }
  }
}

/*Procedure InsertVBeforeX(input/output L:List3, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List3 *L, infotype X, infotype V) {
  //kamus lokal
  address P, NodeX;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    NodeX = First(*L);
    while (next(NodeX) != NIL && info(NodeX) != X) {
      NodeX = next(NodeX);
    }
    //endwhile: next(NodeX) = NIL atau info(NodeX) = X
    if (info(NodeX) == X) { //jika X ditemukan
      P = Alokasi(V);
      if (P != NIL) { //jika alokasi berhasil
        if (NodeX == First(*L)) { //jika X adalah elemen pertama
          InsertVFirst(L, V);
        } else { //jika X bukan elemen pertama
          next(P) = NodeX;
          prev(P) = prev(NodeX);
          next(prev(NodeX)) = P;
          prev(NodeX) = P;
        }
      }
    }
  }
}

/*Procedure DeleteVAfterX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List3 *L, infotype X, infotype *V) {
  //kamus lokal
  address NodeX, P;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    NodeX = First(*L);
    while (next(NodeX) != NIL && info(NodeX) != X) {
      NodeX = next(NodeX);
    }
    //endwhile: next(NodeX) = NIL atau info(NodeX) = X
    if (info(NodeX) == X && next(NodeX) != NIL) { //jika X ditemukan dan bukan elemen terakhir
      P = next(NodeX);
      *V = info(P);
      next(NodeX) = next(P);
      prev(next(P)) = NodeX;
      Dealokasi(&P);
    } else { //jika X tidak ditemukan atau elemen terakhir
      *V = '#';
    }
  } else { //kosong
    *V = '#';
  }
}

/*Procedure DeleteVBeforeX(input/output L:List3, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List3 *L, infotype X, infotype *V) {
  //kamus lokal
  address NodeX, P;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    NodeX = First(*L);
    while (next(NodeX) != NIL && info(NodeX) != X) {
      NodeX = next(NodeX);
    }
    //endwhile: next(NodeX) = NIL atau info(NodeX) = X
    if (info(NodeX) == X && NodeX != First(*L)) { //jika X ditemukan dan bukan elemen pertama
      P = prev(NodeX);
      *V = info(P);
      if (P == First(*L)) { //jika X adalah elemen kedua
        DeleteVFirst(L, V);
      } else { //jika X bukan elemen kedua
        prev(NodeX) = prev(P);
        next(prev(P)) = NodeX;
        Dealokasi(&P);
      }
    } else { //jika X tidak ditemukan atau elemen pertama
      *V = '#';
    }
  } else { //kosong
    *V = '#';
  }
}

/*function CountX(L:List3, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List3 L, infotype X) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return 0;
  }
  //list tidak kosong
  P = First(L);
  count = 0;
  do {
    if (info(P) == X) {
      count++;
    }
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return count;
}

/*function FrekuensiX(L:List3, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
/*{ asumsi tambahan: jika list kosong, mengembalikan 0.0 } */
float FrekuensiX(List3 L, infotype X) {
  //kamus lokal
  int count, total;
  
  //algoritma
  count = CountX(L, X);
  total = NbElm(L);
  if (total != 0) { //jika list tidak kosong
    return (float) count / NbElm(L);
  } else { //meanangani kasus divide by zero
    return 0.0;
  }
}

/*function MaxMember(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List3 L) {
  //kamus lokal
  address P;
  int count, max;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return 0;
  }
  //list tidak kosong
  P = First(L);
  max = 0;
  do {
    count = CountX(L, info(P));
    if (count > max) {
      max = count;
    }
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return max;
}

/*function Modus(L:List3) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
/*{ asumsi tambahan: '#' akan dikembalikan apabila list L kosong}*/
char Modus(List3 L) {
  //kamus lokal
  address P;
  int count, max;
  infotype mod;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return '#'; //'#' merupakan karakter default
  }
  //list tidak kosong
  P = First(L);
  max = 0;
  do {
    count = CountX(L, info(P));
    if (count > max) {
      max = count;
      mod = info(P);
    }
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return mod;
}

/*function CountVocal(L:List3) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List3 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return 0;
  }
  //list tidak kosong
  P = First(L);
  count = 0;
  do {
    if (info(P) == 'A' || info(P) == 'a' || info(P) == 'I' || info(P) == 'i' || info(P) == 'U' || info(P) == 'u' || info(P) == 'E' || info(P) == 'e' || info(P) == 'O' || info(P) == 'o') { //jika terdapat huruf vokal
      count++;
    }
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return count;
}

/*function CountNG(L:List3) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List3 L) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    return 0;
  }
  //list tidak kosong
  P = First(L);
  count = 0;
  do {
    if ((info(P) == 'G' && info(prev(P)) == 'N') || (info(P) == 'g' && info(prev(P)) == 'n')) { //jika terdapat kombinasi GN
      count++;
    }
    P = next(P);
  } while (P != NIL);
  //end while: P = NIL (sudah sampai elemen terakhir)
  return count;
}

/*Procedure SearchAllX(input L:List3, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. - }
{ Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List3 L, infotype X) {
  //kamus lokal
  address P;
  int count;
  
  //algoritma
  if (IsEmptyList(L)) { //jika list kosong
    printf("0\n");
  } else { //jika list tidak kosong
    P = First(L);
    count = 0;
    do {
      count++;
      if (info(P) == X) {
        printf("%d ", count);
      }
      P = next(P);
    } while (P != NIL);
    //end while: P = NIL (sudah sampai elemen terakhir)
  }
}

/*Procedure DeleteAllX(input/output L:List3, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. List mungkin menjadi kosong. }
{ Proses: Semua elemen bernilai X dihapus, dan didealokasi. }*/
void DeleteAllX(List3 *L, infotype X) {
  //kamus lokal
  address P, NodeX;
  
  //algoritma
  if (!IsEmptyList(*L)) { //tidak kosong
    do {
      SearchX(*L, X, &NodeX);
      if (NodeX != NIL) { //jika X ditemukan
        if (NodeX == First(*L)) { //jika X adalah elemen pertama
          DeleteVFirst(L, &X);
        } else { //jika X bukan elemen pertama
          P = NodeX;
          next(prev(P)) = next(P);
          if (next(P) != NIL) { //jika X bukan elemen terakhir
            prev(next(P)) = prev(P);
          }
          Dealokasi(&P);
        }
      }
    } while (NodeX != NIL); //selagi X ditemukan
  }
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List3, input L2:List3, output L:List3)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List3 L1, List3 L2, List3 *L) {
  //kamus lokal
  address P1, P2;
  
  //algoritma
  CopyList(L1, L);
  if (!IsEmptyList(L2)) { //jika L2 tidak kosong
    P1 = First(*L);
    while (next(P1) != NIL) {
      P1 = next(P1);
    }
    //endwhile: next(P1) = NIL (P1 adalah elemen terakhir)
    P2 = First(L2);
    next(P1) = P2; //sambungkan elemen terakhir L1 ke elemen pertama L2
    prev(P2) = P1; //sambungkan elemen pertama L2 ke elemen terakhir L1
  }
}

/*Procedure SplitList(input L:List3, output L1:List3, output L2:List3)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List3 L, List3 *L1, List3 *L2) {
  //kamus lokal
  address P, Q;
  int mid, count, i;
  
  //algoritma
  CreateList(L1);
  CreateList(L2);
  count = NbElm(L);
  i = 1;
  if (count > 0) { //jika list tidak kosong
    mid = count / 2;
    P = First(L);
    do {
      if (i <= mid) {
        InsertVLast(L1, info(P));
      } else {
        InsertVLast(L2, info(P));
      }
      P = next(P);
      i++;
    } while (P != NIL);
    //end while: P = NIL (sudah sampai elemen terakhir)
  }
}

/*Procedure CopyList(input L1:List3, output L2:List3)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List3 L1, List3 *L2) {
  //kamus lokal
  address P;
  
  //algoritma
  CreateList(L2);
  if (!IsEmptyList(L1)) { //jika L1 tidak kosong
    P = First(L1);
    do {
      InsertVLast(L2, info(P));
      P = next(P);
    } while (P != NIL);
    //end while: P = NIL (sudah sampai elemen terakhir)
  }
}
