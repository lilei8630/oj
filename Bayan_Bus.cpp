#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char bus[6][27];
void init(){
	//初始第一行
	bus[0][0]='+';
	bus[0][25]='+';
	for (int i = 1; i <= 24; ++i)
		bus[0][i] = '-';
	//初始化第2行
	bus[1][0] =bus[1][25]=bus[1][23]='|';
	bus[1][24]='D',bus[1][26]=')';
	for (int i = 1; i <= 22; ++i)
	{
		if (i%2==1)
			bus[1][i] = '#';
		else
			bus[1][i] = '.';
	}
	//初始化第3行
	bus[2][0] =bus[2][25]=bus[2][23]='|';
	bus[2][24]='.';
	for (int i = 1; i <= 22; ++i)
	{
		if (i%2==1)
			bus[2][i] = '#';
		else
			bus[2][i] = '.';
	}
	//初始化第4行
	bus[3][0] =bus[3][25]='|';
	bus[3][1]='#';
	for (int i = 2; i <= 24; ++i)
		bus[3][i]='.';
	//初始化第5行
	bus[4][0] =bus[4][25]=bus[4][23]='|';
	bus[4][24]='.',bus[4][26]=')';
	for (int i = 1; i <= 22; ++i)
	{
		if (i%2==1)
			bus[4][i] = '#';
		else
			bus[4][i] = '.';
	}
	//初始化第6行
	bus[5][0]='+';
	bus[5][25]='+';
	for (int i = 1; i <= 24; ++i)
		bus[5][i] = '-';

}
void print(){
	for (int i = 0; i < 6; ++i)
	{
		if(i==1||i==4){
			for (int j = 0; j < 27; ++j)
				printf("%c",bus[i][j]);
			printf("\n");

		}
		else{
			for (int j = 0; j < 26; ++j)
				printf("%c",bus[i][j]);
			printf("\n");
			
		}

	}

}
int main(){
	int n,m,lef;//m为3个人的座位坐几排,lef为剩几个人
	freopen("0input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		memset(bus,0,sizeof(bus));
		init();
		if (n==0)
			print();
		else if(n>=1&&n<=4){
			for (int i = 0; i < n; ++i)
				bus[i+1][1]='O';
			print();

		}else{
			//n>4
			for (int i = 0; i < 4; ++i)//坐满最后一排
				bus[i+1][1]='O';
			m = (n-4)/3;
			lef = n-4-3*m;
			//printf("m:%dlef:%d\n",m,lef);
			for (int i = 3; i < 3+2*m; i+=2)//坐满m个3排
			{
				for (int j = 0; j < 3; ++j)
					if (j!=2)
						bus[j+1][i]='O';
					else
						bus[4][i]='O';
			}
			for (int i = 0; i < lef; ++i)
			{
				bus[i+1][3+2*m]='O';
			}

			print();
		}
		




	}
}