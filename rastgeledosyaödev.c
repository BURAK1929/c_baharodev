#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "product.dat"

struct product {
    int id;
    char name[20];
    float price;
    int stock;
};

void menu();
void addProducts();
void updateProducts();
void showProducts();
void deleteProduct();


int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    while (1) {
        printf("\n**** Urun Yonetimi ****\n");
        printf("1. Urun ekleme\n");
        printf("2. Stok guncelleme\n");
        printf("3. Urunleri gosterme\n");
        printf("4. Urun silme\n");
        printf("5. Cikis\n");
        printf("Secim yapiniz: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProducts();
                break;
            case 2:
                updateProducts();
                break;
            case 3:
                showProducts();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                exit(0);
            default:
                printf("Hatali secim!\n");
        }
    }
}

void addProducts() {
    struct product p;
    FILE *file = fopen(FILE_NAME, "ab");

    if (file == NULL) {
        printf("Dosya acilamadi\n");
        return;
    }

    printf("Urun ID: ");
    scanf("%d", &p.id);



    printf("Urun adi: ");
    scanf("%s", p.name);
    printf("Urun fiyati: ");
    scanf("%f", &p.price);
    printf("Urun miktari: ");
    scanf("%d", &p.stock);

    fwrite(&p, sizeof(struct product), 1, file);
    fclose(file);
    printf("Urun basariyla eklendi.\n");
}

void updateProducts() {
    struct product p;
    int id, new_stock;
    FILE *file = fopen(FILE_NAME, "rb+");

    if (file == NULL) {
        printf("Dosya acilamadi\n");
        return;
    }

    printf("Guncellemek istediginiz urunun ID'sini girin: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&p, sizeof(struct product), 1, file) == 1) {
        if (p.id == id) {
            printf("Yeni stok miktari: ");
            scanf("%d", &new_stock);
            p.stock = new_stock;

            fseek(file, -sizeof(struct product), SEEK_CUR);
            fwrite(&p, sizeof(struct product), 1, file);
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found)
        printf("Stok basariyla guncellendi.\n");
    else
        printf("Urun bulunamadi.\n");
}

void showProducts() {
    struct product p;
    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        printf("Dosya acilamadi\n");
        return;
    }

    printf("\nUrun Listesi:\n");
    printf("--------------------------\n");

    int found = 0;
    while (fread(&p, sizeof(struct product), 1, file) == 1) {
        printf("ID    : %d\n", p.id);
        printf("Ad    : %s\n", p.name);
        printf("Fiyat : %.2f\n", p.price);
        printf("Stok  : %d\n", p.stock);
        printf("--------------------------\n");
        found = 1;
    }

    if (!found)
        printf("Hic urun bulunamadi.\n");

    fclose(file);
}

void deleteProduct() {
    struct product p;
    int id;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL) {
        printf("Dosya acilamadi\n");
        return;
    }

    printf("Silmek istediginiz urunun ID'sini girin: ");
    scanf("%d", &id);

    int found = 0;
    while (fread(&p, sizeof(struct product), 1, file) == 1) {
        if (p.id != id) {
            fwrite(&p, sizeof(struct product), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        printf("Urun basariyla silindi.\n");
    else
        printf("Urun bulunamadi.\n");
}

int checkIfIdExists(int id) {
    struct product p;
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) return 0;

    while (fread(&p, sizeof(struct product), 1, file) == 1) {
        if (p.id == id) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}
