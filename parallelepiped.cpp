#include <stdio.h>
int area_xy,area_xz,area_yz;
int x,y,z;
int min(int x,int y){
	if (x>y)
		return y;
	else
		return x;
}
int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d%d%d",&area_xy,&area_xz,&area_yz)!=EOF)
	{
		for (x=1; x <=min(area_xy,area_xz); ++x)
		{
			y=area_xy/x;
			z=area_xz/x;
			if (y*x==area_xy&&z*x==area_xz)
			
				if (y*z==area_yz)
					printf("%d\n",4*(x+y+z));
		}
	}
	return 0;
}