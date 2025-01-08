// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// #include "Dashboard.h"

void menuPetugas();

typedef char string[255];
typedef struct {
    char id_petugas[7];
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
    system("color 7");
    printf("\n");
    printf("-----------------------------------");
    printf("\nM E N U  P E T U G A S\n");
    printf("-----------------------------------\n");
    do {

        printf("\nMenu:\n");
        printf("1. Tambah Data Petugas\n");

        printf("2. Tampilkan Data Petugas\n");
        printf("3. Ubah Data Petugas\n");
        printf("4. Hapus Data Petugas\n");
        printf("5. Keluar\n");
        printf("Pilih opsi: ");
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
    FILE *PGS = fopen("MASTER PETUGAS.dat", "ab");
    if (PGS == NULL) {
        printf("File could not be opened\n");
        return;
    }

    petugas pgs;
    char last_id_petugas[7]= "PGS000";
    petugas temppgs;

    while(fread(&temppgs, sizeof(pgs), 1, PGS) == 1) {
        strcpy(last_id_petugas, temppgs.id_petugas);
    }

    int id_pgs;
    sscanf(last_id_petugas, "PGS-%d", &id_pgs);
    id_pgs++;
    snprintf(pgs.id_petugas, sizeof(pgs.id_petugas), "PGS%03d", id_pgs);

    printf("\n");
    printf("-----------------------------------");
    printf("\nT A M B A H  D A T A  P E T U G A S\n");
    printf("-----------------------------------\n");
    printf("Masukkan ID Petugas           : %s\n", pgs.id_petugas);

    printf("Masukkan Nama Petugas         : ");
    scanf("%s", pgs.nama);
    printf("Masukkan Alamat Petugas       : ");
    scanf("%s", pgs.alamat);
    printf("Masukkan No. Telepon Petugas  : ");
    scanf("%s", pgs.no_telp);
    printf("Masukkan Status Petugas       : ");
    scanf("%s", pgs.status);
    printf("Masukkan Username Petugas     : ");
    scanf("%s", pgs.username);
    printf("Masukkan Password Petugas     : ");
    scanf("%s", pgs.password);

    fwrite(&pgs, sizeof(petugas), 1, PGS);
    fclose(PGS);
    printf("Data petugas berhasil ditambahkan.\n");
}

// Fungsi Tampilkan Data
void tampilkanDatapetugas() {
    FILE *PGS = fopen("MASTER PETUGAS.dat", "rb");
    if (PGS == NULL) {
        printf("File could not be opened\n");
        return;
    }

    printf("\n");
    printf("-----------------------------------");
    printf("\nD A T A  P E T U G A S\n");
    printf("-----------------------------------\n");
    while (fread(&pgs, sizeof(petugas), 1, PGS)) {
        printf("ID Petugas         : %s\n", pgs.id_petugas);
        printf("Nama Petugas       : %s\n", pgs.nama);
        printf("Alamat Petugas     : %s\n", pgs.alamat);
        printf("No. Telepon        : %s\n", pgs.no_telp);
        printf("Status Petugas     : %s\n", pgs.status);
        printf("Username           : %s\n", pgs.username);
        printf("Password           : %s\n", pgs.password);
        printf("-------------------------------\n");
    }
    fclose(PGS);
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
