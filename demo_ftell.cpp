/* ftell函数用于得到文件位置指针当前位置相对于文件首的偏移字节数*/
#include <iostream>
using namespace std;
int main()
{
	FILE *fp = fopen("myData.txt","w");
	cout << ftell(fp) <<endl;//0
	fprintf(fp,"123");
	cout <<ftell(fp)<<endl;//3
	fprintf(fp, "%d", 456);
	cout <<ftell(fp)<<endl;//6
	fclose(fp);
	

	int a;
	fp = fopen("myData.txt","r");
	cout<<ftell(fp)<<endl;//0
	fscanf(fp,"%d",&a);
	cout<<ftell(fp)<<endl;//6
	cout<<a<<endl;//123456
	fclose(fp);
	cout<<"*************"<<endl;

	int b[10];
	memset(b,0,sizeof(b));
	fp = fopen("yourData","wb");
	cout<<ftell(fp)<<endl;
	fwrite(b,sizeof(b),1,fp);
	cout<<ftell(fp)<<endl;
	fclose(fp);

	int c[10];
	fp=fopen("yourData","rb");
	cout<<ftell(fp)<<endl;
	fread(c,sizeof(c),1,fp);
	cout<<ftell(fp)<<endl;
	fclose(fp);

	return 0;
}