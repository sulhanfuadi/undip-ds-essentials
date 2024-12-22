/************************************/
/* Program   : titik.c */
/* Deskripsi : realisasi body modul Titik */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 29 Agustus 2024*/
/***********************************/
/* petunjuk:
1.Unduh file-file tugas
2.Pelajari file header *.h
3.Buatlah file body *.c sesuai template
4.Salin (copy) SATU buah prosedur/fungsi dari file header lalu tempel (paste) di file body, gantilah tanda titik koma ( ; ) menjadi kurung kurawal buka dan tutup ( { } )
5.Isikan body di DALAM tanda kurawal.
6.Tuliskan aplikasi pemanggilan fungsi/presedur di file driver main.c
7.Uji kebenaran prosedur/fungsi yang sudah dibuat
8.Lakukan berulang hingga semua subrutin dites */

#include <stdio.h>
#include "titik.h"
#include "math.h"

/*KONSTRUKTOR*/
/* procedure makeTitik(output T:Titik)*/
/*{I.S.: -}*/
/*{F.S.: T terdefinisi}*/
/*{proses: mengisi nilai komponen absis dan ordinat T dengan 0}*/
void makeTitik(Titik *T) {
  (*T).absis = 0;
  (*T).ordinat = 0;
};

/*DESTRUKTOR*/

/**********SELEKTOR*/
/*function getAbsis(T:Titik)->integer*/
/*{mengembalikan nilai komponen absis T}*/
int getAbsis(Titik T) {
  return T.absis;
};

/*function getOrdinat(T:Titik)->integer*/
/*{mengembalikan nilai komponen ordinat T}*/
int getOrdinat(Titik T) {
  return T.ordinat;
};

/*********MUTATOR*/
/*procedure setAbsis(input/output T, input xx)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.absis=xx}*/
/*{proses: mengisi nilai komponen absis T}*/
void setAbsis(Titik *T, int xx) {
  (*T).absis = xx;
};

/*procedure setOrdinat(input/output T, input yy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.ordinat=yy}*/
/*{proses: mengisi nilai komponen ordinat T}*/
void setOrdinat(Titik *T, int yy) {
  (*T).ordinat = yy;
};

/*********PREDIKAT*/
/*function isOrigin(T:Titik)->boolean*/
/*{mengembalikan true jika Titik T ada di persilangan sumbu X dan Y}*/
boolean isOrigin(Titik T) {
  return (T.absis == 0 && T.ordinat == 0);
};

/*********SUBRUTIN LAIN*/
/*procedure geserXY(input/output T:Titik, input dx, input dy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T bergeser sejauh (dx,dy)}*/
/*{proses: mengubah nilai komponen absis dan ordinat T}*/
void geserXY(Titik *T, int dx, int dy) {
  (*T).absis += dx;
  (*T).ordinat += dy;
};

/*procedure refleksiSumbuX(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu X }*/
/*{proses: mengubah nilai komponen ordinat T}*/
void refleksiSumbuX(Titik *T) {
  (*T).ordinat *= -1;
};

/*procedure refleksiSumbuY(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu Y }*/
/*{proses: mengubah nilai komponen absis T}*/
void refleksiSumbuY(Titik *T) {
  (*T).absis *= -1;
};

/*function Kuadran(T:Titik)->integer*/
/*{mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4}*/
/*{asumsi: bila titik memotong sumbu, maka nilai 0 dianggap positif}*/
int Kuadran(Titik T) {
  if (T.absis > 0 && T.ordinat > 0) {
    return 1;
  } else if (T.absis < 0 && T.ordinat > 0) {
    return 2;
  } else if (T.absis < 0 && T.ordinat < 0) {
    return 3;
  } else if (T.absis > 0 && T.ordinat < 0) {
    return 4;
  }
};

/*function Jarak(T1:Titik, T2:Titik)->real*/
/*{mengembalikan jarak euclidian titik T1 dan T2}*/
/*{asumsi: aplikasikan rumus Pitagoras dan fungsi akar sqrt}*/
float Jarak(Titik T1, Titik T2) {
  return sqrt(pow(T1.absis - T2.absis, 2) + pow(T1.ordinat - T2.ordinat, 2));
};
