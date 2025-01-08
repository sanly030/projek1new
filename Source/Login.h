
// void gotoxy(int x,int y);
// void fullscreen();
// void Username(char username[]);
// void Password(char password[]);
// void frame(int x, int y);
// void HalDashboard();
// void HalLogin();
int i, x, y;

void frame(int x, int y){
    SetColorBlock(1,7);
    for(i = y; i < 22 + y; i++){
        for(j = x; j < 127; j++){
            gotoprintchar(j,i,32);
        }
    }
    SetColorBlock(7,1);
    /*border frame atas bawah*/
    for(i = 23; i < 24; i++){
        for(j = x - 2; j < 137; j++){
            gotoprintchar(j,i,177);
        }
    }

    for(i = 44; i < 45; i++){
        for(j = x - 2; j < 137; j++){
            gotoprintchar(j,i,177);
        }
    }

    SetColorBlock(1,7);
    /*border frame tengah kanan kiri*/
    for(i = y + 1; i < y + 21; i++){
        gotoprintchar(x - 1,i,186);
    }

    for(i = y + 1; i < y + 21; i++){
        gotoprintchar(x+60,i,186);
    }
}

void HalLogin() {
    system("color 71");
    // PrintFile("..//Asset/ProCleanOrganizer.txt", 83, 15);
    PrintFile("..//Asset/ataskiri.txt", 2, 1);
    PrintFile("..//Asset/ataskanan.txt", 196, 1);
    PrintFile("..//Asset/bawahkiri.txt", 2, 47);
    PrintFile("..//Asset/bawahkanan.txt", 196, 47);

    frame(75,23);

    //kotak username
    gotoxy(95, 36);
    printf("%c", 192);      //kiri bawah
    gotoxy(95, 34);
    printf("%c", 218);      //kiri atas
    gotoxy(121, 34);
    printf("%c", 191);      //kanan atas
    gotoxy(121, 36);
    printf("%c", 217);      //kanan bawah
    gotoxy(95, 35);
    printf("%c", 179);  //kiri tengah
    gotoxy(121, 35);
    printf("%c", 179);  //kanan tengah
    for (x = 96;x <= 120; x++) {    //atas
        gotoxy(x,34);
        printf("%c", 196);
    }
    for (x = 96;x <= 120; x++) {    //bawah
        gotoxy(x,36);
        printf("%c", 196);
    }

    //kotak password
    gotoxy(95, 39);
    printf("%c", 192);      //kiri bawah
    gotoxy(95, 37);
    printf("%c", 218);      //kiri atas
    gotoxy(121, 37);
    printf("%c", 191);      //kanan atas
    gotoxy(121, 39);
    printf("%c", 217);      //kanan bawah
    gotoxy(95, 38);
    printf("%c", 179);  //kiri tengah
    gotoxy(121, 38);
    printf("%c", 179);  //kanan tengah
    for (x = 96;x <= 120; x++) {    //atas
        gotoxy(x,37);
        printf("%c", 196);
    }
    for (x = 96;x <= 120; x++) {    //bawah
        gotoxy(x,39);
        printf("%c", 196);
    }
    gotoxy(85, 35);
    printf("Username: ");
    gotoxy(85, 38);
    printf("Password: ");
    gotoxy(96, 35);
    Username(adm.username);
    gotoxy(96, 38);
    Password(adm.password);

    if((strcmp(adm.username, "Admin")== 0) && (strcmp(adm.password, "Admin") == 0)) {
        MessageBox(NULL, "Welcome To Admin", "Notification", MB_OK | MB_ICONINFORMATION | MB_DEFAULT_DESKTOP_ONLY);
        system("cls");
        DashboardAdmin();
    }else {
        MessageBox(NULL, "Masukan Username dan Password Dengan Benar!!!", "Notification", MB_OK | MB_ICONERROR | MB_DEFAULT_DESKTOP_ONLY);
         clearArea(96,35,8,1);
         clearArea(96,38,8,1);
        exit(0);

    }
}

    //Input username serta validasinya
    void Username(char username[]){
        fflush(stdin);
        int i = 0;
        char ch;
        while (1){
            ch = getch();
            if (ch == -32 || ch == 224) {
                getch();
                continue;
            }
            if (ch == BACKSPACE){
                if (i > 0){
                    printf("\b \b");
                    i--;
                }
            }
            else if (ch == ENTER){
                break;
            }
            else if (i < 8 && ch != SPACE && ch != TAB && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')){
                username[i] = ch;
                printf("%c", username[i]);
                i++;
            }
        }
        username[i] = '\0';
    }

    //Input password serta validasinya
    void Password(char password[]){
        fflush(stdin);
        int i = 0;
        char ch;
        while(1){
            ch = getch();
            if (ch == -32 || ch == 224) {
                getch();
                continue;
            }
            if(ch == BACKSPACE){
                if(i > 0){
                    printf("\b \b");
                    i--;
                }
            }
            else if(ch == ENTER){
                break;
            }
            else if(i < 8 && ch != SPACE && ch != TAB && (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')){
                password[i] = ch;
                printf("*");
                i++;
            }
        }
        password[i] = '\0';
    }