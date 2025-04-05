
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrisA[2][3];
int matrisB[3][2];

void matrisOlustur(int satir, int sutun, int matris[satir][sutun]);
void matrisYazdir(int satir, int sutun, int matris[satir][sutun]);
void matrisTopla(int matrisA[2][3], int matrisB[2][3]);
void matrisCarp(int matrisA[2][3], int matrisB[3][2]);

int main() {
    srand(time(NULL));

    printf("\n** A Matrisi **\n");
    matrisOlustur(2, 3, matrisA);

    printf("\n** B Matrisi **\n");
    matrisOlustur(3, 2, matrisB);

    printf("\n** Matris Toplama **\n");
    printf("Boyutlari esit olmadigi icin tanimsizdir.\n");

    printf("\n** Matris Carpma **\n");
    matrisCarp(matrisA, matrisB);

    return 0;
}

void matrisOlustur(int satir, int sutun, int matris[satir][sutun]) {
    for (size_t i = 0; i < satir; i++) {
        for (size_t j = 0; j < sutun; j++) {
            matris[i][j] = rand() % 100 + 1;
        }
    }
    matrisYazdir(satir, sutun, matris);
}

void matrisYazdir(int satir, int sutun, int matris[satir][sutun]) {
    for (size_t i = 0; i < satir; i++) {
        for (size_t j = 0; j < sutun; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void matrisTopla(int matrisA[2][3], int matrisB[2][3]) {
    int sonuc[2][3];
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            sonuc[i][j] = matrisA[i][j] + matrisB[i][j];
        }
    }
    matrisYazdir(2, 3, sonuc);
}

void matrisCarp(int matrisA[2][3], int matrisB[3][2]) {
    int sonuc[2][2] = {0};
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 2; j++) {
            for (size_t k = 0; k < 3; k++) {
                sonuc[i][j] += matrisA[i][k] * matrisB[k][j];
            }
        }
    }
    matrisYazdir(2, 2, sonuc);
}


