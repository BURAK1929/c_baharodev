# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *head = NULL;

void yazdir();

void basaEkle(int veri);

void arayaEkle(int veri, int sira);

void sonaEkle(int veri);

void dugumSil(int sira);

int main() {
    int secim, veri, sira;

    while (1) {
        printf("\n**** menu****\n");
        printf("1. Listeyi goruntule\n");
        printf("2. Basa eleman ekle \n");
        printf("3. Araya eleman ekle \n");
        printf("4. Sona eleman ekle \n");
        printf("5. Sil \n");
        printf("6. Cikis yap \n");
        printf(" Secim yapiniz \n");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                yazdir();
                break;
            case 2:
                printf("Eleman girin\n");
                scanf("%d", &veri);
                basaEkle(veri);
                break;
            case 3:
                printf("Eleman girin: \n");
                scanf("%d", &veri);
                printf("Hangi indekse ekleme yapilsin: \n");
                scanf("%d", &sira);
                arayaEkle(veri, sira);
                break;
            case 4:
                printf("Eleman girin: \n");
                scanf("%d", &veri);
                sonaEkle(veri);
                break;
            case 5:
               dugumSil(sira);
            case 6:
                 printf("Cikis yapiliyor\n");
                exit(0);
            default:
                printf("Gecersiz secim yaptiniz \n");
                break;
        }
    }
}

void yazdir() {
    Node *temp = head;

    printf("Liste: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void basaEkle(int veri) {
    Node *yeni = (Node *) malloc(sizeof(Node));

    yeni->data = veri;
    yeni->next = head;

    head = yeni;
}

void arayaEkle(int veri, int sira) {
    Node *yeni = (Node *) malloc(sizeof(Node));

    yeni->data = veri;
    yeni->next = NULL;

    if (sira == 0) {
        basaEkle(veri);
        return;
    }

    Node *temp = head;
    for (int i = 0; i < sira - 1; i++) {
        if (temp == NULL) {
            printf("Girilen deger liste boyutundan buyuktur! \n Ekleme yapilamadi\n");
            // free(yeni);
        }

        temp = temp->next;
    }
    yeni->next = temp->next;
    temp->next = yeni;

    printf("%d. indekse %d degeri eklendi", sira, veri);
}

void sonaEkle(int veri) {
    Node *yeni = (Node *) malloc(sizeof(Node));

    yeni->data = veri;
    yeni->next = NULL;

    if (head == NULL) {
        head = yeni;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = yeni;
    printf("%d. degeri listenin sonuna  eklendi", veri);
}

void dugumSil(int sira) {
    if (head == NULL || sira < 0) {
        printf("Liste bos veya yanlis indeks girdiniz");
        return;
    }
    Node *temp = head;

    if (sira == 0) {
        head = temp->next;
        free(temp);
        printf("%d. indeks silindi\n", sira);
        return;
    }

    for (int i = 0; temp != NULL && i < sira - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Sira listeden uzun.Silme basarisiz\n");
        return;
    }

    Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    printf(" %d. indeks silindi.\n", sira);
}


