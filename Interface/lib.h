//#ifndef LIB_H
//#define LIB_H
//
//#endif //LIB_H
//
//
//void getinputmin(char input[], int min, int max, int type){
//	char strcurrent;
//	int i,n,x,m;
//	n = 0;
//	x=0;
//	do
//	{
//		strcurrent = getch();
//
//		if(strcurrent == '\b' && n != 0) //backspace
//		{
//			printf("\b \b");
//			n--;
//			input[n]='\0';
//		}
//		//else if(current >= 32 && current <= 122){
//		else if(isprint(strcurrent)){ //karakter yang bisa di print
//			if(n == max) {
//				continue;
//			}
//			else{
//				if(type == 3){ //isdigit = hanya angka
//					if(isdigit(strcurrent)) {
//						printf("%c", strcurrent);
//						input[n]=strcurrent;
//						n++;
//					}
//					else printf("\a");
//				}
//				else if(type == 2){ //isalpha = alpabet dan spasi co : nama
//					if(isalpha(strcurrent) || strcurrent == ' ') {
//						printf("%c", strcurrent);
//						input[n]=strcurrent;
//						n++;
//					}
//					else printf("\a");
//				}
//				else {
//					if(type == 1) // password //0= bebas
//					{
//						if(strcurrent==35||x>0)
//						{
//							if(strcurrent==35)
//							{
//								x=x+1;
//								for(m=0;m<n;m++)
//								{
//									printf("\b \b");
//								}
//								for(m=0;m<n;m++)
//								{
//									printf("%c",input[m]);
//								}
//
//							}
//							else if(strcurrent==64)
//							{
//								x=0;
//								for(m=0;m<n;m++)
//								{
//									printf("\b \b");
//								}
//								for(m=0;m<n;m++)
//								{
//									printf("*");
//								}
//							}
//							else
//							{
//								printf("%c", strcurrent);
//								input[n]=strcurrent;
//								n++;
//							}
//						}
//						else
//						{
//							printf("*");
//							input[n]=strcurrent;
//							n++;
//						}
//
//					}
//					else
//					{
//						printf("%c", strcurrent);
//						input[n]=strcurrent;
//						n++;
//					}
//				}
//			}
//		}
//		else if(strcurrent == 13)
//		{
//			if(n < min) {
//				printf("\a");
//				strcurrent = 0;
//			}
//			else input[n]='\0';
//		}
//		//else if(current == 27) end();
//	}
//	while(strcurrent != 13);
//}
//
//void getRp(int *nilai, int min, int max, int x, int y)
//{
//    char input[225];
//    char inpkey;
//    int i, n, m;
//    n = 0;
//
//    do
//    {
//        inpkey = getch();
//        if(inpkey == '\b' && n != 0)
//        {
//            n--;
//            input[n] = '\0';
//
//            m = n % 3;
//            if((n - m) % 3 == 0 || n == m){
//                printf("\b \b");
//                printf("\b \b");
//            }else{
//                printf("\b \b");
//            }
//            gotoxy(x,y);
//            for(i = 0; i < n; i++){
//                if((i + 1) == m || (i + 1 - m) % 3 == 0){
//                    printf("%c", input[i]);
//                    if(i != (n - 1)){
//                        printf(".");
//                    }
//                }else {
//                    printf("%c", input[i]);
//                }
//            }
//        }else if (isprint(inpkey)){
//            if(n == max){
//                continue;
//            }else {
//                if (isdigit(inpkey)){
//                    gotoxy(x,y);
//                    input[n]=inpkey;
//                    n++;
//                    m = n % 3;
//                    for(i = 0; i < n; i++){
//                        if((i+1) == m || (i+1-m) % 3 == 0){
//                            printf("%c", input[i]);
//                            if(i != (n-1)){
//                                printf(".");
//                            }
//                        }else {
//                            printf("%c", input[i]);
//                        }
//                    }
//                }
//                else printf("\a");
//            }
//        }
//        else if(inpkey == 13)
//        {
//            if(n < min){
//                printf("\a");
//                inpkey = 0;
//            }
//            else input[n]='\0';
//        }
//    }
//    while(inpkey != 13);
//
//    *nilai = atoi(input);
//}
//
//void getinput(char input[], int max, int type){
//	getinputmin(input, 1, max, type);
//}
//
//void getteks(char input[], int max){
//	getinput(input, max, 0);
//}
//
//void getnum(int *dest, int max){
//	char input[max];
//	getinput(input, max, 3);
//	*dest = atoi(input);
//}
//
//void getnummin(int *dest, int min, int max){
//	char input[max];
//	getinputmin(input, min, max, 3);
//	*dest = atoi(input);
//}
//
//void getteksnum(char input[], int max){
//	getinput(input, max, 3);
//}
//
//void getteksnummin(char input[], int min, int max){
//	getinputmin(input, min, max, 1);
//}
//
//void getpass(char input[], int max){
//	getinput(input, max, 1);
//}
//
//void getletter(char input[], int max){
//	getinput(input, max, 2);
//}
//
//void rupiah(int number, char output[])
//{
//	// menampilkan Bentuk Rupiah
//	if(number < 1000) sprintf(output, "%d", number);
//    else if(number < 1000000) sprintf(output, "%d.%03d", number/1000, number%1000);
//    else if(number < 1000000000) sprintf(output, "%d.%03d.%03d", number/1000000, (number%1000000)/1000, number%1000);
//    else sprintf(output, "%d.%03d.%03d.%03d", number/1000000000, (number%1000000000)/1000, (number%1000000)/1000, number%1000);
//}
//
//void formatID(char tipe[4], int id, char newID[]) {
//
//	if(id < 10) {
//		sprintf(newID, "%s00%d", tipe, id);
//	} else if(id < 100) {
//		sprintf(newID, "%s0%d", tipe, id);
//	} else {
//		sprintf(newID, "%s%d", tipe, id);
//	}
//}
