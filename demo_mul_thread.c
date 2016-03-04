#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char filename[20][15]={ "output1.txt","output2.txt","output3.txt","output4.txt",
						"output5.txt","output6.txt","output7.txt","output8.txt",
						"output9.txt","output10.txt","output11.txt","output12.txt",
						"output13.txt","output14.txt","output15.txt","output16.txt",
						"output17.txt","output18.txt","output19.txt","output20.txt"};
int userNum = 8231;
int num_threads = 20;


void * CalUserSim(void * a){
	

	FILE * fout = fopen(filename[(int)a],"w");

	float p;
	int left = userNum / num_threads * (int)a;
	int right  = userNum / num_threads *((int)a+1)-1;
	if ((int)a==num_threads-1)
		right=userNum-1;
	for (int i = left; i <= right; ++i){
		fprintf(fout,"%d\n",i);
	}
	pthread_exit(NULL);


}


int main(){
		pthread_t *pt = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
	for (long long a = 0; a < num_threads; a++) pthread_create(&pt[a], NULL, CalUserSim, (void *)a);
  	for (long long a = 0; a < num_threads; a++) pthread_join(pt[a], NULL);
	return 0;

}