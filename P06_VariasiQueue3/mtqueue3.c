/* Program   : mtqueue3.c */
/* Deskripsi : file DRIVER modul queue karakter model III */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 07 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue3.c"
#include "tqueue3.h"

int main(){
    /* Kamus Main */
    tqueue3 A, B;
    char X;
    
    /* Algoritma */
    createQueue3(&A);
    createQueue3(&B);

    printf("========================================\n");
    printf("Queue A saat ini:\n");
    printQueue3(A);
    printf("Head queue A berada di posisi ke-%d\n", head3(A));
    printf("Tail queue A berada di posisi ke-%d\n", tail3(A));
    printf("Elemen terakhir di queue A: %c\n", infoTail3(A));
    printf("Apakah queue A kosong? %s\n", isEmptyQueue3(A) ? "Ya" : "Tidak");
    printf("Apakah queue A penuh? %s\n", isFullQueue3(A) ? "Ya" : "Tidak");
    printf("========================================\n");

    // Tambahkan elemen ke queue A
    enqueue3(&A, 'A');
    printf("Queue A setelah menambahkan elemen 'A':\n");
    printQueue3(A);
    printf("Tail queue A sekarang di posisi ke-%d\n", tail3(A));
    printf("Head queue A sekarang di posisi ke-%d\n", head3(A));
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("Apakah queue A hanya memiliki satu elemen? %s\n", isOneElement3(A) ? "Ya" : "Tidak");
    printf("========================================\n");

    // Tambahkan beberapa elemen ke queue A
    enqueue3(&A, 'K');
    enqueue3(&A, 'U');
    enqueue3(&A, 'N');
    printf("Queue A setelah menambahkan beberapa elemen:\n");
    printQueue3(A);
    printf("Head queue A berada di posisi ke-%d\n", head3(A));
    printf("Tail queue A berada di posisi ke-%d\n", tail3(A));
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("========================================\n");

    // Hapus elemen dari queue A
    dequeue3(&A, &X);
    printf("Queue A setelah menghapus satu elemen:\n");
    printQueue3(A);
    printf("Head queue A sekarang di posisi ke-%d\n", head3(A));
    printf("Tail queue A sekarang di posisi ke-%d\n", tail3(A));
    printf("Elemen pertama di queue A: %c\n", infoHead3(A));
    printf("Elemen terakhir di queue A: %c\n", infoTail3(A));
    printf("Karakter yang dihapus dari queue A: %c\n", X);
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("========================================\n");

    // Tambahkan elemen tambahan ke queue A
    enqueue3(&A, 'Q');
    printf("Queue A setelah menambahkan elemen 'Q':\n");
    printQueue3(A);
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("Head queue A sekarang di posisi ke-%d\n", head3(A));
    printf("Tail queue A sekarang di posisi ke-%d\n", tail3(A));
    printf("========================================\n");

    // Tambahkan elemen tambahan ke queue A dan tampilkan dengan view
    enqueue3(&A, 'W');
    printf("Queue A setelah menambahkan elemen 'W':\n");
    viewQueue3(A);
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("Head queue A sekarang di posisi ke-%d\n", head3(A));
    printf("Tail queue A sekarang di posisi ke-%d\n", tail3(A));
    printf("Elemen pertama di queue A: %c\n", infoHead3(A));
    printf("Elemen terakhir di queue A: %c\n", infoTail3(A));
    printf("========================================");

    // Tambahkan elemen ke queue A hingga penuh
    enqueue3(&A, 'P');
    printf("Queue A setelah menambahkan elemen 'P' (queue penuh):\n");
    printQueue3(A);
    printf("Panjang queue A saat ini: %d\n", sizeQueue3(A));
    printf("Head queue A sekarang di posisi ke-%d\n", head3(A));
    printf("Tail queue A sekarang di posisi ke-%d\n", tail3(A));
    printf("Elemen pertama di queue A: %c\n", infoHead3(A));
    printf("Elemen terakhir di queue A: %c\n", infoTail3(A));
    printf("========================================\n");

    // Tambahkan elemen ke queue B
    enqueue3(&B, 'K');
    enqueue3(&B, 'U');
    enqueue3(&B, 'N');
    printf("Queue B setelah menambahkan beberapa elemen:\n");
    viewQueue3(B);
    printf("Panjang queue B saat ini: %d\n", sizeQueue3(B));
    printf("Head queue B berada di posisi ke-%d\n", head3(B));
    printf("Tail queue B berada di posisi ke-%d\n", tail3(B));
    printf("Elemen pertama di queue B: %c\n", infoHead3(B));
    printf("Elemen terakhir di queue B: %c\n", infoTail3(B));
    printf("========================================\n");

    // Tambahkan elemen tambahan ke queue B
    enqueue3E(&B, 'Q');
    printf("Queue B setelah menambahkan elemen 'Q':\n");
    printQueue3(B);
    printf("Panjang queue B saat ini: %d\n", sizeQueue3(B));
    printf("Head queue B berada di posisi ke-%d\n", head3(B));
    printf("Tail queue B berada di posisi ke-%d\n", tail3(B));
    printf("Elemen pertama di queue B: %c\n", infoHead3(B));
    printf("Elemen terakhir di queue B: %c\n", infoTail3(B));
    printf("Jumlah elemen 'K' di queue B: %d\n", countMember(B, 'K'));
    printf("========================================\n");

    // Tampilkan isi Queue3 A dan B
    printf("Isi Queue A: ");
    printQueue3(A);
    printf("Isi Queue B: ");
    printQueue3(B);

    // Tambahkan elemen tambahan ke queue B
    enqueue3(&B, 'W');
    printf("Queue B setelah menambahkan elemen 'W':\n");
    printQueue3(B);
    printf("Panjang queue B saat ini: %d\n", sizeQueue3(B));
    printf("Head queue B berada di posisi ke-%d\n", head3(B));
    printf("Tail queue B berada di posisi ke-%d\n", tail3(B));
    printf("========================================\n");

    // Tampilkan isi Queue3 A dan B serta posisi head dan tail
    printf("Isi Queue A: ");
    printQueue3(A);
    printf("Head queue A berada di posisi ke-%d\n", head3(A));
    printf("Tail queue A berada di posisi ke-%d\n", tail3(A));
    printf("Apakah Tail di depan Head? %s\n", isTailOverHead(A) ? "Ya" : "Tidak");
    printf("========================================\n");

    printf("Isi Queue B: ");
    printQueue3(B);
    printf("Head queue B berada di posisi ke-%d\n", head3(B));
    printf("Tail queue B berada di posisi ke-%d\n", tail3(B));
    printf("Apakah Tail di depan Head? %s\n", isTailOverHead(B) ? "Ya" : "Tidak");
    printf("========================================\n");

    return 0;
}
