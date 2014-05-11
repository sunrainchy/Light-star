#include "global.h"
#include "play.h"
#include "draw.h"
#include "system_help.h"
extern int sky[105][105];
/*extern const int maxn = 105;
extern int sky[maxn][maxn];*/
extern int dir[5][2];
int play(int length,int width){
	int le,wi,i,j,k;
	int step_num=0;
	printf("亲，请输入位置：");
	while(scanf("%d%d",&le,&wi)!=EOF){
		if(le>length || le<1 || wi >width || wi<1){
			if(le==100) {
				system_play_now(length,width);
				return 0;
			}
			printf("亲，好像位置输错了哦！！！\nAgain:");
			continue;
		}
		i=wi,j=le;
		i=width-i+1;
		for(k=0;k<5;k++){
			if(sky[i+dir[k][0]][j+dir[k][1]]==1)
				sky[i+dir[k][0]][j+dir[k][1]]=0;
			else 
				sky[i+dir[k][0]][j+dir[k][1]]=1;
		}
		step_num++;
		draw(length,width);
		if(check_is_success(length,width)){
			printf("您一共用了%d步完成 恭喜过关 \n",step_num);
			return step_num;
		}
		printf("亲，请输入位置：");
	}
	return 0;
}
/*检查是否结束游戏，就是检查暗的星星个数是否为0*/
bool check_is_success(int length,int width){
	int i,j,k;
	for(i=1;i<=width;i++)
	for(j=1;j<=length;j++){
		if(sky[i][j]==0)
			return false;
	}
	return true;
}
