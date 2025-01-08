
// void logo();
// void loading();
// void PrintFile(char file[], int x, int y);

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

// Deklarasi prosedur untuk menampilkan kursor
void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
//--------------------------------------untuk mengatur posisi--------------------------------/
void gotoxy(int x, int y) {
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//--------------------------------------Fullscreen Layar---------------------------------------/
void fullscreen(){
    keybd_event(VK_MENU,0x39,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x39,KEYEVENTF_KEYUP,0);

    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
}

//--------------------------------------Gotoprint Character------------------------------------/
void gotoprintchar(int x, int y, int dec){
    gotoxy(x,y);
    printf("%c",dec);
}

//--------------------------------------Gotoprint Text------------------------------------/
void gotoprinttext(int x, int y, char text[255]){
    gotoxy(x,y);
    printf("%s",text);
}

//---------------------------------------Untuk mewarnai huruf dan background---------------------/
void SetColorBlock(int foreground, int background) {
    int color = foreground + (background << 4);
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//----------------------------------------Menghapus semua block-----------------------------------/
void clearArea(int x, int y, int width, int height) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = {(SHORT) x, (SHORT) y};
    DWORD written;

    for (int row = 0; row < height; ++row) {
        FillConsoleOutputCharacterA(console, ' ', width, topLeft, &written);
        topLeft.Y++;
    }
}

//-------------------------------------Mematikan scrollbar CMD----------------------------------------/
void disableScrollBar() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    // Mendapatkan informasi tentang jendela console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hOut, &csbi);

    // Menyusun atribut baru untuk mengunci scrollbar
    csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;

    // Menyetel ukuran jendela console
    SetConsoleScreenBufferSize(hOut, csbi.dwSize);

    // Menonaktifkan scrollbar
    SetConsoleMode(hOut, ENABLE_EXTENDED_FLAGS);
}

//--------------------------------------untuk mencetak file txt----------------------------------------/
void CetakFile(int x, int y, char filename[255]) {
    FILE *fp;
    char str[MAXCHAR];
    int i;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s", filename);
    }
    i = 0;
    while (fgets(str, MAXCHAR, fp) != NULL) {
        gotoxy(x, y + i);
        printf("%s", str);
        i++;
    }
    fclose(fp);
}

void BorderScreen(){
    int i;

    SetColorBlock(1,7);

    //pojok kanan atas/
    gotoprintchar(2,1,206);

    //atas tengah/
    for(i = 3; i < 174; i++){
        gotoprintchar(i,1,205);
    }

    //pojok kiri atas/
    gotoprintchar(173,1,206);

    //border samping kiri/
    for(i = 2; i < 43; i++){
        gotoprintchar(2,i,186);
    }

    //border samping kanan
    for(i = 2; i < 43; i++){
        gotoprintchar(173,i,186);
    }

    //pojok kiri bawah/
    gotoprintchar(2,43,206);

    //bawah tengah/
    for(i = 3; i < 174; i++){
        gotoprintchar(i,43,205);
    }
    //pojok kanan bawah/
    gotoprintchar(173,43,206);
}

// FONT
void setConsoleFont(int fontSizeX, int fontSizeY, const wchar_t* fontName) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

    // Mendapatkan informasi font saat ini
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    // Mengganti ukuran font
    fontInfo.dwFontSize.X = fontSizeX;
    fontInfo.dwFontSize.Y = fontSizeY;

    // Mengganti nama font
    wcscpy(fontInfo.FaceName, fontName);

    // Mengganti bentuk font
    SetCurrentConsoleFontEx(hConsole, FALSE,&fontInfo);
}

//UNTUK DESAIN TXT
void PrintFile(char file[], int x, int y){
    FILE *Text;
    char Data[200];
    if((Text=fopen(file, "r")) == NULL){
        system("cls");
    }
    while(fgets(Data, 200, Text))
    {
        gotoxy(x, y);
        printf("%s", Data);
        y++;
    }
    fclose(Text);
}

//LOADING
 void loading() {
    int x;
     gotoxy(97, 40);
     printf("L O A D I N G . . . ");         //Loading

     for (x = 93; x <= 118; x++) {           //atas
         gotoxy(x, 40);
         printf("%c", 196);
     }
     for (x = 93; x <= 118; x++) {           //bawah
         gotoxy(x, 42);

         printf("%c", 196);
     }
     for (x = 93; x <= 120; x++) {           //isi
         _sleep(20);
         gotoxy(x, 41);
         printf("%c", 219);
     }
     gotoxy(90, 41);
     system("pause");
     system("cls");
 }

//TAMPILAN AWAL
void logo()
{
    PrintFile("..//Asset/LogoProClean.txt", 66, 6);
    PrintFile("..//Asset/ProCleanOrganizer.txt", 83, 25);
    PrintFile("..//Asset/LogoBubbleKiri.txt", 17, 3);
    PrintFile("..//Asset/LogoBubbleKanan.txt", 165, 6);
    PrintFile("..//Asset/AnimasiOrangKiri.txt", 35, 25);
    PrintFile("..//Asset/AnimasiOrangKanan.txt", 135, 25);
    PrintFile("..//Asset/ataskiri.txt", 2, 1);
    PrintFile("..//Asset/ataskanan.txt", 196, 1);
    PrintFile("..//Asset/bawahkiri.txt", 2, 47);
    PrintFile("..//Asset/bawahkanan.txt", 196, 47);
    loading();
}



void BoxBlock(int x, int y, int width, int height) {
    int i, j;
    for(i = 0; i <= height; i++) {
        for(j = 0; j < width; j++) {
            gotoxy(x + j, y + i);
            printf("%c", 219);
        }
    }
}


void textBox2(int x, int y, int width, int height) {
    int i, j;

    /* first Line */
    gotoxy(x, y);
    printf("%c", 201);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 187);

    /* looping for height */
    for(i = 1; i <= height; i++) {
        gotoxy(x, y + i);
        printf("%c", 186);
        for(j = 1; j <= width; j++) {
            printf(" ");
        }
        gotoxy(x + width + 1, y + i);
        printf("%c", 186);
    }

    /* last line */
    printf("\n");
    gotoxy(x, y + height);
    printf("%c", 200);
    for(i = 1; i <= width; i++) {
        printf("%c", 205);
    }
    printf("%c", 188);
}

void blankScreen(i,j){
    SetColorBlock(7,7);
    for(i = 2; i < 43; i++){
        for(j = 3; j < 173; j++){
            gotoprintchar(j,i,32);
        }
    }
}

//====== Garis kotak (Border) dengan karakter full blok ========
void borderFullBlock(int x, int y, int lebar, int tinggi) {
    // ========= garis atas
    for (int i = x; i < x + lebar; ++i) {
        gotoprintchar(i, y, 219);
    }

    // ========= Menggambar garis samping
    for (int j = y + 1; j < y + tinggi; ++j) {
        gotoprintchar(x, j, 219);
        gotoprintchar(x + lebar - 1, j, 219);
    }

    // ========= Menggambar garis bawah
    for (int i = x; i < x + lebar; ++i) {
        gotoprintchar(i, y + tinggi - 1,219);
    }
}

void garisFullBlokVertical(int x, int y, int tinggi) {
    for (int i = 0; i < tinggi; ++i) {
        gotoprintchar(x, y + i ,219);
    }
}

void garisFullBlokHorizontal(int x, int y, int lebar) {
    for (int i = 0; i < lebar; ++i) {
        gotoprintchar(x + i, y ,219);
    }
}
