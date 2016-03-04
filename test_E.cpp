#include <stdio.h>
int main()
{
 	int n;
 	int factor[1000];
 	int size;
 	int a,b,c;
 	while(scanf("%d",&n)!=EOF)
 	{
 		size = 0;
 		int min = 100000000;
 		for (int i = 1; i*i<=n; i++)
 		{
 			
 			if (n%i==0)
 			{
 				factor[size++]=i;
 				factor[size++]=n/i;
 			}
 			
 		}
 		
 		//printf("%d\n",min);
 		for (int i = 0; i < size; ++i)
 		
 			for (int j = 0; j < size; ++j)
 			{
 				if (n%(factor[i]*factor[j]))
 					continue;	
 				for (int k = 0; k < size; ++k)
 				{
 				
 					if (factor[i]*factor[j]*factor[k]==n){


 						if (factor[i]*factor[j]+factor[i]*factor[k]+factor[k]*factor[j]<min)
 						{
 							min=factor[i]*factor[j]+factor[i]*factor[k]+factor[k]*factor[j];	
 							a=factor[i];
 							b=factor[j];
 							c=factor[k];
 							
 						}
 					
 					
 					}
 				}
 			}
 		printf("%d %d %d \n",a,b,c);
 	}
 	return 0;
}