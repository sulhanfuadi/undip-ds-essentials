#ifndef titik_H
#define titik_H 
/***********************************/
/* Program   : titik.h */
/* Deskripsi : header file modul Titik */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 29 Agustus 2024*/
/***********************************/
//#include <stdio.h>

typedef enum {false, true} boolean;

/*NOTASI ALGORITMIK : */
/* type Titik=<absis:integer, ordinat:integer>*/
/*DITERJEMAHKAN KE BAHASA C : */
typedef struct {int absis; int ordinat;} Titik;
/* cara akses T:Titik, T.absis, T.ordinat */

/*KONSTRUKTOR*/
/* procedure makeTitik(output T:Titik)*/
/*{I.S.: -}*/
/*{F.S.: T terdefinisi}*/
/*{proses: mengisi nilai komponen absis dan ordinat T dengan 0}*/
void makeTitik(Titik *T);

/*DESTRUKTOR*/

/**********SELEKTOR*/
/*function getAbsis(T:Titik)->integer*/
/*{mengembalikan nilai komponen absis T}*/
int getAbsis(Titik T);

/*function getOrdinat(T:Titik)->integer*/
/*{mengembalikan nilai komponen ordinat T}*/
int getOrdinat(Titik T);

/*********MUTATOR*/
/*procedure setAbsis(input/output T, input xx)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.absis=xx}*/
/*{proses: mengisi nilai komponen absis T}*/
void setAbsis(Titik *T, int xx);

/*procedure setOrdinat(input/output T, input yy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T.ordinat=yy}*/
/*{proses: mengisi nilai komponen ordinat T}*/
void setOrdinat(Titik *T, int yy);

/*********PREDIKAT*/
/*function isOrigin(T:Titik)->boolean*/
/*{mengembalikan true jika Titik T ada di persilangan sumbu X dan Y}*/
boolean isOrigin(Titik T);

/*********SUBRUTIN LAIN*/
/*procedure geserXY(input/output T:Titik, input dx, input dy)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T bergeser sejauh (dx,dy)}*/
/*{proses: mengubah nilai komponen absis dan ordinat T}*/
void geserXY(Titik *T, int dx, int dy);

/*procedure refleksiSumbuX(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu X }*/
/*{proses: mengubah nilai komponen ordinat T}*/
void refleksiSumbuX(Titik *T);

/*procedure refleksiSumbuY(input/output T:Titik)*/
/*{I.S.: T terdefinisi}*/
/*{F.S.: T dicerminkan ke sumbu Y }*/
/*{proses: mengubah nilai komponen absis T}*/
void refleksiSumbuY(Titik *T);

/*function Kuadran(T:Titik)->integer*/
/*{mengembalikan posisi Titik T pada kuadran 1,2,3 atau 4}*/
/*{asumsi: bila titik memotong sumbu, maka nilai 0 dianggap positif}*/
int Kuadran(Titik T);

/*function Jarak(T1:Titik, T2:Titik)->real*/
/*{mengembalikan jarak euclidian titik T1 dan T2}*/
/*{asumsi: aplikasikan rumus Pitagoras dan fungsi akar sqrt}*/
float Jarak(Titik T1, Titik T2);

#endif