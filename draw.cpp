#include "global.h"
extern const int maxn = 105;
extern int sky[maxn][maxn];
static int show(int length,int width);
int draw(int length,int width){
	show(length,width);
	return 0;
}
static int show(int length,int width){
	int i,j;
	for(i=1;i<=width;i++){
		printf("                     %d ",width-i+1);
		for(j=1;j<=length;j++)
			switch(sky[i][j]){
				case -1:printf("        ");break;
				case 0:printf("\033[41m      \033[0m"); putchar(' ');putchar(' ');break;
				case 1:printf("\033[42m      \033[0m"); putchar(' ');putchar(' ');break;
				case 2:printf("\033[43m      \033[0m"); putchar(' ');putchar(' ');break;
				case 3:printf("\033[44m      \033[0m"); putchar(' ');putchar(' ');break;
				case 4:printf("\033[45m      \033[0m"); putchar(' ');putchar(' ');break;
			}
		putchar('\n');
		printf("                     %d ",width-i+1);
		for(j=1;j<=length;j++)
			switch(sky[i][j]){
				case -1:printf("        ");break;
				case 0:printf("\033[41m  沸  \033[0m"); putchar(' ');putchar(' ');break;
				case 1:printf("\033[42m  点  \033[0m"); putchar(' ');putchar(' ');break;
				case 2:printf("\033[43m  工  \033[0m"); putchar(' ');putchar(' ');break;
				case 3:printf("\033[44m  作  \033[0m"); putchar(' ');putchar(' ');break;
				case 4:printf("\033[45m  室  \033[0m"); putchar(' ');putchar(' ');break;
			}
		putchar('\n');
		printf("                     %d ",width-i+1);
		for(j=1;j<=length;j++)
			switch(sky[i][j]){
				case -1:printf("        ");break;
				case 0:printf("\033[41m      \033[0m"); putchar(' ');putchar(' ');break;
				case 1:printf("\033[42m      \033[0m");putchar(' ');putchar(' ');break;
				case 2:printf("\033[43m      \033[0m");putchar(' ');putchar(' ');break;
				case 3:printf("\033[44m      \033[0m");putchar(' ');putchar(' ');break;
				case 4:printf("\033[45m      \033[0m");putchar(' ');putchar(' ');break;
			}
		putchar('\n');
		putchar('\n');
	}
	printf("                   +   ");
	for(j=1;j<=length;j++){ 
		printf("%d %d %d ",j,j,j);printf("  ");
	}
	putchar('\n');
	printf("\033[36m                                        沸  点  工  作  室  制  作                   \033[0m \n");
	return 0;
}

