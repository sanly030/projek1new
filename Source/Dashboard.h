#ifndef DASHBOARD_H
#define DASHBOARD_H
void DashboardAdmin() {
    system("color 71");

    PrintFile("..//Asset//Admin.txt", 7, 2);
    borderFullBlock(1,1,213,54);
    garisFullBlokVertical(49,1,53);
    garisFullBlokHorizontal(1,8,212);


    int opsi;
    gotoxy(7, 12);
    printf("1. C R U D  P E T U G A S");
    gotoxy(7, 14);
    printf("2. C R U D  J E N I S  P E T U G A S");
    gotoxy(7, 16);
    printf("3. C R U D  P E L A N G G A N");
    gotoxy(7, 18);
    printf("P I L I H  M E N U : ");
    gotoxy(29,18);
    scanf("%d",&opsi);
    switch (opsi) {
        case 1:
            clearArea(3,9,46,43);
        menuPetugas();
        break;

    }
}


//     gotoxy(0, 0);
//     printf("%c", 177);      //kiri atas
//     gotoxy(208, 0);
//     printf("%c", 177);      //kanan atas
//     gotoxy(208, 55);
//     printf("%c", 177);      //kanan bawah
//     gotoxy(0, 55);
//     printf("%c", 177);      //kiri bawah
//
//
//     for (x = 1;x <= 213; x++) {           //atas tengah
//         gotoxy(x,1);
//         printf("%c", 177);
//     }
//     for (x = 4;x <= 213; x++) {           //atas tengah bawah admin
//         gotoxy(x,9);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kiri tengah
//         gotoxy(0,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kiri tengah
//         gotoxy(1,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kiri tengah
//         gotoxy(2,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kiri tengah
//         gotoxy(3,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kanan tengah
//         gotoxy(213,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {            //kanan tengah
//         gotoxy(212,y);
//         printf("%c", 177);
//     }
//     for (x = 1;x <= 215; x++) {           //bawah tengah
//         gotoxy(x,54);
//         printf("%c", 177);
//     }
//
//     for (y = 1;y <= 54; y++) {            //pembatas
//         gotoxy(51,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(52,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(53,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(54,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(55,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(56,y);
//         printf("%c", 177);
//     }
//     for (y = 1;y <= 54; y++) {
//         gotoxy(57,y);
//         printf("%c", 177);
//     }
// }
// void menuPetugas();

#endif