/* File : pohon2.c */
/* Deskripsi : realisasi body ADT bintree2 berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 29 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
  //kamus lokal
  int i;

  //algoritma
  if (IsEmptyTree(P)){ // jika pohon P kosong
    printf("()");
  } else{ // jika pohon P tidak kosong
    printf("%c", GetAkar(P));
    printf("\n");
    for (i = 1; i < H; i++){ // memajukan "posisi anak" dari pohon P
      printf("-");
    }
    PrintTreeInden(GetLeft(P), 2*H);
    printf("\n");
    for (i = 1; i < H; i++){ // memajukan "posisi anak" dari pohon P
      printf("-");
    }
    PrintTreeInden(GetRight(P), 2*H);
  }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N) {
  /*kamus lokal*/


  /*algoritma*/
  if (!IsEmptyTree(P)) { /*jika pohon tidak kosong*/
    if (N == 1) { /*jika level yang dicari adalah 1*/
      printf("%c ", akar(P));
    } else { /*jika level yang dicari bukan 1*/
      PrintLevel(GetLeft(P), N - 1);
      PrintLevel(GetRight(P), N - 1);
    }
  }
}

/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
  /*kamus lokal*/
  infotype X;

  /*algoritma*/
  if (n == 0) { /*jika n = 0*/
    return NIL;
  } else { /*jika n > 0*/
    if(n == 1){ /*jika n = 1*/
      printf("\nMasukkan elemen X: ");
      scanf(" %c", &X);
      return Tree(X, NIL, NIL);
    } else{ /*jika n > 1*/
      printf("\nMasukkan elemen X: ");
      scanf(" %c", &X);
      return Tree(X, BuildBalanceTree((n-1)/2), BuildBalanceTree(n-1-((n-1)/2))); //membuat pohon dari rekursif ke anak kiri dan anak kanan
    }
  }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
  /*kamus lokal*/
  int nL, nR;

  /*algoritma*/
  if (IsEmptyTree(P)) { /*jika pohon kosong (kita anggap balance)*/
    return true;
  } else { /*jika pohon tidak kosong*/
    nL = NbElm(GetLeft(P));
    nR = NbElm(GetRight(P));
    return (abs(nL - nR) <= 1);
    /*cek apakah jumlah elemen anak kiri dan kanan tidak terlalu jauh berbeda*/
    /*rekursif untuk anak kiri dan kanan*/
  }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree P, infotype X) {
  /*kamus lokal*/

  /*algoritma*/
  if (IsEmptyTree(P)) { /*jika pohon kosong*/
    P = Tree(X, NIL, NIL);
  } else { /*jika pohon tidak kosong*/
    if(IsEmptyTree(GetLeft(P))){ /*jika anak pohon P sebelah kiri kosong*/
      left(P) = Tree(X, NIL, NIL);
    } else{ /*jika anak pohon P sebelah kiri tidak kosong*/
      AddDaunTerkiri(GetLeft(P), X);
    }
  }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree P, infotype X, infotype Y, boolean Kiri){
  /*kamus lokal*/

  /*algoritma*/
  if(IsEmptyTree(P)) { /*jika pohon kosong*/
    P = Tree(Y, NIL, NIL);
  } else { /*jika pohon tidak kosong*/
    if(Kiri == true) { /*jika kiri bernilai true*/
      if (GetAkar(P) == X && IsDaun(P)){ /*jika akar P adalah X sekaligus merupakan daun*/
        left(P) = Tree(Y, NIL, NIL);
      } else{ /*jika akar P bukan X atau bukan merupakan daun*/
        AddDaun(GetLeft(P), X, Y, true);
        AddDaun(GetRight(P), X, Y, true);
      }
    } else { /*jika kiri bernilai false*/
      if (GetAkar(P) == X && IsDaun(P)){ /*jika akar P adalah X sekaligus merupakan daun*/
        right(P) = Tree(Y, NIL, NIL);
      } else { /*jika akar P bukan X atau bukan merupakan daun*/
        AddDaun(GetLeft(P), X, Y, false);
        AddDaun(GetRight(P), X, Y, false);
      }
    }
  }
}
/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
/*asumsi: jika kiri kosong, prosedur akan menambahkan ke kiri terlebih dahulu,
tetapi, jika kiri tidak kosong, akan coba cek terlebih dahulu apakah kanan kosong,
dan apabila keduanya tidak kosong, akan dicoba ke anak dari anak kiri P (insert ke kiri didahulukan)*/
void InsertX(bintree P, infotype X){
  //kamus lokal

  //algoritma
  if (IsEmptyTree(P)) { /*jika pohon kosong*/
    P = Tree(X, NIL, NIL);
  } else { /*jika pohon tidak kosong*/
    if (SearchX(P, X)) { /*jika X sudah ada*/
      printf("\nSudah ada simpul %c", X);
    } else { /*jika pohon tidak kosong dan X belum ada*/
      if (IsEmptyTree(GetLeft(P))) { /*jika anak pohon P sebelah kiri kosong*/
        left(P) = Tree(X, NIL, NIL);
      } else { /*jika anak pohon P sebelah kiri tidak kosong*/
        if (IsEmptyTree(GetRight(P))) { /*jika anak pohon P sebelah kanan kosong*/
          right(P) = Tree(X, NIL, NIL);
        } else { /*jika anak pohon P sebelah kanan tidak kosong*/
          InsertX(GetLeft(P), X);
        }
      }
    }
  }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
/*asumsi: prosedur dapat juga menghapus daun terkiri dari anak kanan apabila anak kiri kosong*/
void DelDaunTerkiri(bintree *P, infotype *X){
  /*kamus lokal*/

  /*algoritma*/
  if (IsDaun(*P)) { /*jika pohon merupakan daun*/
    *X = GetAkar(*P);
    *P = NIL;
    Dealokasi(P);
  } else { /*jika pohon bukan daun*/
      if (GetLeft(*P) == NIL) { /*jika anak pohon P sebelah kiri kosong*/
        DelDaunTerkiri(&(right(*P)), &(*X));
      } else { /*jika anak pohon P sebelah kiri tidak kosong*/
        DelDaunTerkiri(&(left(*P)), &(*X));
      }
  }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
  /*kamus lokal*/

  /*algoritma*/
  if (!IsEmptyTree(*P)) { /*jika pohon bukan kosong*/
    if (IsDaun(*P) && GetAkar(*P) == X) { /*jika pohon adalah daun dan akar sama dengan X*/
      Dealokasi(&(*P));
      *P = NIL;
    } else { /*jika pohon bukan daun atau akar tidak sama dengan X*/
      DelDaun(&left((*P)), X);
      DelDaun(&right((*P)), X);
    }
  }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X){
  /*kamus lokal*/
  bintree temp, *prec;

  /*algoritma*/
  if (!IsEmptyTree(*P)) { /*jika pohon P tidak kosong*/
    if (GetAkar(*P) == X) { /*jika akar pohon P sama dengan X*/
      if (IsDaun(*P)) { /*jika pohon P merupakan daun*/
        Dealokasi(P);
        *P = NIL; 
      } else if (IsEmptyTree(left(*P)) || IsEmptyTree(right(*P))) { /*jika anak pohon P sebelah kiri kosong atau anak pohon P sebelah kanan kosong*/
        if (!IsEmptyTree(left(*P))) { /*jika anak pohon P sebelah kiri tidak kosong*/
          temp = GetLeft(*P);
        } else { /*jika anak pohon P sebelah kiri kosong*/
          temp = GetRight(*P);
        }
        Dealokasi(P);
        *P = temp;
      } else { /*jika anak pohon P sebelah kiri dan kanan tidak kosong*/
        prec = &left(*P);
        while (!IsEmptyTree(GetRight(*prec))){
          prec = &(right(*prec));
        }
        /*end while: prec menunjuk ke node dengan subtree kanan kosong*/
        akar(*P) = GetAkar(*prec);
        DeleteX(prec, GetAkar(*prec));
      }
    } else { /*jika akar pohon P tidak sama dengan X*/
      DeleteX(&(left(*P)), X);
      DeleteX(&(right(*P)), X);
    }
  }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y){
  /*kamus lokasl*/

  /*algoritma*/
  if(!IsEmptyTree(*P)){ /*jika pohon tidak kosong*/
    if(akar(*P) == X){ /*jika akar pohon P sama dengan X*/
      akar(*P) = Y;
    }
    UpdateAllX(&left(*P), X, Y);
    UpdateAllX(&right(*P), X, Y);
  }
}
/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
char maxTree(bintree P){
  //kamus lokal
  char max;

  //algoritma
  max = GetAkar(P);
  if (!IsEmptyTree(GetLeft(P))) { /*jika anak pohon P sebelah kiri tidak kosong*/
    max = max2(max, maxTree(GetLeft(P)));
  }
  if (!IsEmptyTree(GetRight(P))) { /*jika anak pohon P sebelah kanan tidak kosong*/
    max = max2(max, maxTree(GetRight(P)));
  }
  return max;
}

/* function min2(int a, int b)->integer
{mengembalikan nilai minimal dari a atau b}*/
int min2(int a, int b){
  /*kamus lokal*/

  /*algoritma*/
  if(a >= b){ /*jika bilangan pertama lebih dari bilangan kedua*/
    return b;
  } else{ /*sebaliknya*/
    return a;
  }
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
char minTree(bintree P){
  /*kamus lokal*/
  char min, temp;

  /*algoritma*/
  min = GetAkar(P);
  if(!IsEmptyTree(GetLeft(P))){ /*jika anak pohon P sebelah kiri tidak kosong*/
    min = min2(min, minTree(GetLeft(P)));
  }
  if(!IsEmptyTree(GetRight(P))){ /*jika anak pohon P sebelah kanan tidak kosong*/
    min = min2(min, minTree(GetRight(P)));
  }
  return min;
}

/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X){
  /*kamus lokal*/
  
  /*algoritma*/
  if (GetAkar(P) == X) { /*jika akar pohon P sama dengan X*/
    return true;
  } else { /*jika akar pohon P tidak sama dengan X*/
    if(GetAkar(GetLeft(P)) < X){ /*jika akar dari anak pohon P sebelah kiri kurang dari X*/
      BSearch(GetRight(P), X);
    } else { /*jika akar dari anak pohon P sebelah kiri tidak kurang dari X*/
      BSearch(GetLeft(P), X);
    }
  }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X){
  /*kamus lokal*/

  /*algoritma*/
  if (IsEmptyTree(P)) { /*jika pohon BST kosong*/
    return Tree(X, NIL, NIL);
  } else { /*jika pohon BST tidak kosong*/
    if(GetAkar(P) > X){ /*jika akar pohon P lebih besar dari X*/
      left(P) = InsSearch(GetLeft(P), X);
    } else if(GetAkar(P) < X){ /*jika akar pohon P lebih kecil dari X*/
      right(P) = InsSearch(GetRight(P), X);
    }
  }
  return P;
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X){
  /*kamus lokal*/
  bintree temp;
  bintree *prec;

  /*algoritma*/
  if (!IsEmptyTree(*P)) { /*jika pohon P tidak kosong*/
    if (GetAkar(*P) > X) { /*jika akar dari pohon P lebih besar dari X*/
      DelBtree(&left(*P), X);
    } else if (GetAkar(*P) < X) { /*jika akar dari pohon P lebih kecil dari X*/
      DelBtree(&right(*P), X);
    } else { /*jika akar dari pohon P sama dengan X*/
      if (GetAkar(*P) == X) { /*jika akar dari pohon P sama dengan X*/
        if (IsDaun(*P)) { /*jika pohon P merupakan daun*/
          Dealokasi(P);
          *P = NIL; 
        } else if (IsEmptyTree(left(*P)) || IsEmptyTree(right(*P))) { /*jika anak pohon P sebelah kiri kosong atau anak pohon P sebelah kanan kosong*/
          if (!IsEmptyTree(left(*P))) { /*jika anak pohon P sebelah kiri tidak kosong*/
            temp = GetLeft(*P);
          } else { /*jika anak pohon P sebelah kiri kosong*/
            temp = GetRight(*P);
          }
          Dealokasi(P);
          *P = temp;
        } else { /*jika anak pohon P sebelah kiri dan kanan tidak kosong*/
          prec = &left(*P);
          while (!IsEmptyTree(GetRight(*prec))) {
            prec = &(right(*prec));
          }
          /*end while: prec menunjuk ke node dengan subtree kanan kosong*/
          akar(*P) = GetAkar(*prec);
          DelBtree(prec, GetAkar(*prec));
        }
      }
    }
  }
}
