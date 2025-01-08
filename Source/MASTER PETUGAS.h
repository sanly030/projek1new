// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// #include "Dashboard.h"

void menuPetugas();

typedef char string[255];
typedef struct {
    int id_petugas[7];
    char nama[25];
    char alamat[25];
    char no_telp[25];
    char status[25];
    char username[20];
    char password[20];
} petugas;

petugas pgs;

void menuPetugas() {
    int pilihan;
    system("cls");
    system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderFullBlock(1,1,213,54);
    garisFullBlokVertical(49,1,53);
    garisFullBlokHorizontal(1,8,212);
    PrintFile("..//Asset//Menu Petugas.txt", 90, 1);

    do {
        gotoxy(10, 16);
        printf("Menu:");
        gotoxy(7, 18);
        printf("1. Tambah Data Petugas\n");
        gotoxy(7, 20);
        printf("2. Tampilkan Data Petugas\n");
        gotoxy(7, 22);
        printf("3. Ubah Data Petugas\n");
        gotoxy(7, 24);
        printf("4. Hapus Data Petugas\n");
        gotoxy(7, 26);
        printf("5. Keluar\n");
        gotoxy(7, 28);
        printf("Pilih opsi: ");
        gotoxy(19, 28);
        scanf("%d", &pilihan);
        getchar(); // Bersihkan buffer

        switch (pilihan) {
            case 1:
                tambahDatapetugas();
            break;
            case 2:
                tampilkanDatapetugas();
            break;
            case 3:
                ubahDatapetugas();
            break;
            case 4:
                hapusDatapetugas();
            break;
            case 5:
                printf("Keluar program.\n");
            system("cls");
            break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (pilihan != 5);
}

// Fungsi Tambah Data
void tambahDatapetugas() {
    FILE *PGS = fopen("MASTER PETUGAS.dat", "ab+"); // Gunakan "ab+" agar bisa membaca dan menulis
    if (PGS == NULL) {
        printf("File tidak dapat dibuka\n");
        return;
    }

    petugas pgs;
    int lastCustomerID = 0;

    // Baca ID terakhir dari file
    while (fread(&pgs, sizeof(petugas), 1, PGS) == 1) {
        lastCustomerID = atoi(pgs.id_petugas + 3); // Ambil angka dari "PGS00%d"
    }
    lastCustomerID++;
    sprintf(pgs.id_petugas, "PGS00%d", lastCustomerID + 1); // Format ID baru

    // Input data petugas
    gotoxy(60, 17);
    printf("-----------------------------------");
    gotoxy(60, 18);
    printf("T A M B A H  D A T A  P E T U G A S");
    gotoxy(60, 19);
    printf("-----------------------------------");
    gotoxy(60, 20);
    printf("Id Petugas                    : %s", pgs.id_petugas);
    gotoxy(60, 22);
    printf("Masukkan Nama Petugas         : ");
    scanf(" %[^\n]", pgs.nama);
    gotoxy(60, 24);
    printf("Masukkan Alamat Petugas       : ");
    scanf(" %[^\n]", pgs.alamat);
    gotoxy(60, 26);
    printf("Masukkan No. Telepon Petugas  : ");
    scanf(" %[^\n]", pgs.no_telp);
    gotoxy(60, 28);
    printf("Masukkan Status Petugas       : ");
    scanf(" %[^\n]", pgs.status);
    gotoxy(60, 30);
    printf("Masukkan Username Petugas     : ");
    scanf(" %[^\n]", pgs.username);
    gotoxy(60, 32);
    printf("Masukkan Password Petugas     : ");
    scanf(" %[^\n]", pgs.password);

    // Tulis data ke file
    fwrite(&pgs, sizeof(petugas), 1, PGS);
    fclose(PGS);

    gotoxy(60, 34);
    printf("Data petugas berhasil ditambahkan.\n");
    getch();
    menuPetugas();
}


// Fungsi Tampilkan Data
void tampilkanDatapetugas() {
    FILE *PGS = fopen("MASTER PETUGAS.dat", "rb");
    if (PGS == NULL) {
        printf("File could not be opened\n");
        return;
    }


    gotoxy(60,17);
    printf("-----------------------------------");
    gotoxy(60, 18);
    printf("D A T A  P E T U G A S");
    gotoxy(60, 19);
    printf("-----------------------------------\n");
    while (fread(&pgs, sizeof(petugas), 1, PGS)) {
        gotoxy(60, 20);
        printf("ID Petugas         : %s\n", pgs.id_petugas);
        gotoxy(60, 22);
        printf("Nama Petugas       : %s\n", pgs.nama);
        gotoxy(60, 24);
        printf("Alamat Petugas     : %s\n", pgs.alamat);
        gotoxy(60, 26);
        printf("No. Telepon        : %s\n", pgs.no_telp);
        gotoxy(60, 28);
        printf("Status Petugas     : %s\n", pgs.status);
        gotoxy(60, 30);
        printf("Username           : %s\n", pgs.username);
        gotoxy(60, 32);
        printf("Password           : %s\n", pgs.password);
        gotoxy(60, 33);
        printf("-------------------------------\n");
    }
    fclose(PGS);
    getch();
    menuPetugas();
}

// Fungsi Ubah Data
void ubahDatapetugas() {
    char id_petugas[6];
    int found = 0;

    printf("\n");
    printf("-----------------------------------");
    printf("\nU B A H  D A T A  P E T U G A S\n");
    printf("-----------------------------------\n");
    printf("Masukkan ID Petugas yang ingin diubah: ");
    scanf("%s", id_petugas);

    FILE *PGS = fopen("MASTER PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP PETUGAS.dat", "wb");

    if (PGS == NULL || temp == NULL) {
        printf("File could not be opened\n");
        return;
    }

    while (fread(&pgs, sizeof(petugas), 1, PGS)) {
        if (strcmp(pgs.id_petugas, id_petugas) == 0) {
            found = 1;
            printf("Masukkan Nama Petugas Baru      : ");
            scanf("%s", pgs.nama);
            printf("Masukkan Alamat Petugas Baru    : ");
            scanf("%s", pgs.alamat);
            printf("Masukkan No. Telepon Baru       : ");
            scanf("%s", pgs.no_telp);
            printf("Masukkan Status Baru            : ");
            scanf("%s", pgs.status);
            printf("Masukkan Username Baru          : ");
            scanf("%s", pgs.username);
            printf("Masukkan Password Baru          : ");
            scanf("%s", pgs.password);
        }
        fwrite(&pgs, sizeof(petugas), 1, temp);
    }

    fclose(PGS);
    fclose(temp);

    remove("MASTER PETUGAS.dat");
    rename("TEMP PETUGAS.dat", "MASTER PETUGAS.dat");

    if (found) {
        printf("Data petugas berhasil diubah.\n");
    } else {
        printf("Data dengan ID Petugas %s tidak ditemukan.\n", id_petugas);
    }
}

// Fungsi Hapus Data
void hapusDatapetugas() {
    char id_petugas[6];
    int found = 0;

    printf("\n");
    printf("-----------------------------------gr");
    printf("\nH A P U S  D A T A  P E T U G A S\n");
    printf("-----------------------------------\n");
    printf("Masukkan ID Petugas yang ingin dihapus: ");
    scanf("%s", id_petugas);

    FILE *PGS = fopen("MASTER PETUGAS.dat", "rb");
    FILE *temp = fopen("TEMP PETUGAS.dat", "wb");

    if (PGS == NULL || temp == NULL) {
        printf("File could not be opened\n");
        return;
    }

    while (fread(&pgs, sizeof(petugas), 1, PGS)) {
        if (strcmp(pgs.id_petugas, id_petugas) != 0) {
            fwrite(&pgs, sizeof(petugas), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(PGS);
    fclose(temp);

    remove("MASTER PETUGAS.dat");
    rename("TEMP PETUGAS.dat", "MASTER PETUGAS.dat");

    if (found) {
        printf("Data petugas berhasil dihapus.\n");
    } else {
        printf("Data dengan ID Petugas %s tidak ditemukan.\n", id_petugas);
    }
}

// Menu Utama
