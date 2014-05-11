#include "global.h"
#include "create_sky.h"
#include "draw.h"
#include "play.h"
#include "system_help.h"
extern int width,length;
int menu(){
	printf("               第一个输入为100则转换成系统帮你玩模式\n");
	printf("               HI 我们为您精心准备了以下功能，你准备好了吗？\n");
	printf("               1：我牛逼我自己玩      \n");
	printf("               2: 擦 不会，电脑您玩给我看看吧，求您了\n");
	printf("               快选吧:");
	return 0;
}
int main(){
	printf("HI，输入你的SKY SIZE:");
	while(1){
		scanf("%d %d",&length,&width);
		if(length >=10 || length <=0 || width >=10 || width <=0)
			printf("填空好像不能这样布局哦! 再输入一次吧\n SIZE:");
		else break;
	}
	create_sky(length,width);
	draw(length,width);
	int choice;
	menu();
	scanf("%d",&choice);
	switch(choice){
		case 2: system_play_now(length,width); break;
		case 1: play(length,width);            break;
	}
	return 0;
}
