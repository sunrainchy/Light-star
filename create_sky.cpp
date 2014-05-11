#include "data.h"
#include "global.h"
int create_sky(int length=6,int width=6){
	int i,j,k,t;
	memset(sky,0,sizeof(sky));
	srand(time(NULL));
	t=10000;/*Circle for 10000 times*/
	while(t--){
		j=rand()%length+1;
		i=rand()%width+1;
		for(k=0;k<5;k++){
			if(sky[i+dir[k][0]][j+dir[k][1]]==1)
				sky[i+dir[k][0]][j+dir[k][1]]=0;
			else 
				sky[i+dir[k][0]][j+dir[k][1]]=1;
		}
	}
	return 0;
}
