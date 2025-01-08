void DashboardAdmin() {
    system("color 71");
    PrintFile("..//Tampilan//Admin.txt", 22, 1);
    gotoxy(0, 0);
    printf("%c", 177);      //kiri atas
    gotoxy(208, 0);
    printf("%c", 177);      //kanan atas
    gotoxy(208, 55);
    printf("%c", 177);      //kanan bawah
    gotoxy(0, 55);
    printf("%c", 177);      //kiri bawah

    for (x = 1;x <= 207; x++) {           //atas tengah
        gotoxy(x,0);
        printf("%c", 177);
    }
    for (x = 4;x <= 207; x++) {           //atas tengah bawah admin
        gotoxy(x,7);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kiri tengah
        gotoxy(0,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kiri tengah
        gotoxy(1,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kiri tengah
        gotoxy(2,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kiri tengah
        gotoxy(3,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kanan tengah
        gotoxy(208,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {            //kanan tengah
        gotoxy(207,y);
        printf("%c", 177);
    }
    for (x = 1;x <= 207; x++) {           //bawah tengah
        gotoxy(x,55);
        printf("%c", 177);
    }

    for (y = 1;y <= 54; y++) {            //pembatas
        gotoxy(75,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(76,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(77,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(78,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(79,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(80,y);
        printf("%c", 177);
    }
    for (y = 1;y <= 54; y++) {
        gotoxy(81,y);
        printf("%c", 177);
    }
}