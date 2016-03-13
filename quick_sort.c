#include <stdio.h>
void quick_sort(int s[],int l,int r){
        if(l<r){
            /*初始化*/
            int i = l, j = r,x = s[l];
            while(i<j){
                /*从右边向左找第一个小于x的元素，如果不小于j就前移*/
                while(i<j&&s[j]>=x) j--;
                if(i<j) s[i++] = s[j];//填坑并将i后移一位
                while(i<j&&s[i]<x) i++;
                if(i<j) s[j--] = s[i];
            }
            s[i] = x;
            quick_sort(s,l,i-1);
            quick_sort(s,i+1,r);
        }

}

int main(){
    int s[] ={48,6,57,42,60,72,83,73,88,85};
    quick_sort(s,0,9);
    for(int i = 0;i<10;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
    return 0;
}
