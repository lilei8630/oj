#include <stdio.h>
#include <string.h>
char filename[20][15]={ "output1.txt","output2.txt","output3.txt","output4.txt",
						"output5.txt","output6.txt","output7.txt","output8.txt",
						"output9.txt","output10.txt","output11.txt","output12.txt",
						"output13.txt","output14.txt","output15.txt","output16.txt",
						"output17.txt","output18.txt","output19.txt","output20.txt"};


int main(){
	/*int a =5;
	char filename[15]="output.txt";
	int len = strlen(filename);
	for (int i = len; i >6 ; i--)
	{
		filename[i]=filename[i-1];
	}
	filename[6]=(char)48+a;
	printf("%s\n",filename);
	*/
	printf("%s\n",filename[5]);

}