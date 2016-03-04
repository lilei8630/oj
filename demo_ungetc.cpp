#include <stdio.h>
#include <ctype.h>
int main()
{
	char ch;
	int result = 0;
printf( "Enter an integer: " );
while( ((ch = getchar()) != EOF) && isdigit( ch ) )
	result = result * 10 + ch - '0';
if( ch != EOF )
	ungetc( ch, stdin );
printf("Number = %d\nNextcharacter in stream = %c\n",result,getchar());
  return 0;
}