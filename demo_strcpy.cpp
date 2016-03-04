#include <stdio.h>
#include <string.h>
int main()
{
	char word[40];
	strcpy(word, (char *)"</s>");
	printf("%s\n", word);
	printf("sizeof(</s>):%ld\n",sizeof("</s>"));
	printf("0+'a'=%d\n",0+'a');
	long long train_words;
	while(1){
		if (train_words++ % 100000 == 0) {
    	  printf("%lldK%c", train_words / 1000, 13);
    	  fflush(stdout);
    	}
	}
	return 0;
}