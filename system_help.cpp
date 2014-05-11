#include "global.h"
#include "draw.h"
extern int sky[105][105];
extern int dir[5][2];
static int my_sky[105][105];
struct point{
	int x,y;
};
static point po[200];
static int pos=0;
static int system_play(int length,int width,int num);
static int change(int i,int j){
	int k;
	for(k=0;k<5;k++){
		if(my_sky[i+dir[k][0]][j+dir[k][1]]==1)
			my_sky[i+dir[k][0]][j+dir[k][1]]=0;
		else 
			my_sky[i+dir[k][0]][j+dir[k][1]]=1;
	}
	return 0;
}
static int find_ans(int length,int width){
	int k=(1<<(length+1)),i,j,p,q;
	for(i=0;i<k;i++){
		memcpy(my_sky,sky,sizeof(my_sky));
		for(j=0;j<length;j++){
			if(i&(1<<j)) change(1,j+1);
		}
		for(p=1;p<width;p++)
		for(q=1;q<=length;q++){
			if(my_sky[p][q]==0)
				change(p+1,q);
		}
		bool flag=true;
		for(p=1;p<=length;p++)
			if(my_sky[width][p]==0){
				flag=false;
				break;
			}
		if(flag){
			system_play(length,width,i);
			break;
		}
	}
	return 0;
}

static int new_change(int i,int j){
	int k;
	for(k=0;k<5;k++){
		if(sky[i+dir[k][0]][j+dir[k][1]]==1)
			sky[i+dir[k][0]][j+dir[k][1]]=0;
		else 
			sky[i+dir[k][0]][j+dir[k][1]]=1;
	}
	return 0;
}
static int my_rand(){
	srand(time(NULL));
	int i,j,k=1000;
	while(k--){
		i=rand()%pos;
		j=rand()%pos;
		swap(po[i],po[j]);
	}
	return 0;
}
static int system_play(int length,int width,int num){
	int i,j,k;
	memcpy(my_sky,sky,sizeof(sky));
	for(i=0;i<length;i++){
		if(num&(1<<i)){
			change(1,i+1);
			//sleep(1);
			//draw(length,width);
			po[pos].x=1;
			po[pos++].y=i+1;
		}
	}
	for(i=1;i<width;i++)
	for(j=1;j<=length;j++){
		if(my_sky[i][j]==0){
			change(i+1,j);
			//sleep(1);
			//draw(length,width);
			po[pos].x=i+1;
			po[pos++].y=j;
		}
	}
	my_rand();
	for(i=0;i<pos;i++){
		new_change(po[i].x,po[i].y);
		sleep(1);
		draw(length,width);
	}
	return 0;
}
int system_play_now(int length,int width){
	find_ans(length,width);
	return 0;
}
