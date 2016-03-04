//查找数组中出现次数超过1/3的两个元素
#define NAN (0.0/0.0)
#include <stdio.h>
#include <stdlib.h>
int findMore(int arr[],int n,int cans[2]){
    int i;
    if(n<2){
        return -1;
    }
    int times[2];
    times[0] = times[1] = 0;
    cans[0] = cans[1] = NAN;
    for(i=0;i<n;i++){
        printf("the element of arr is %d.\n",arr[i]);
        if(arr[i] == cans[0]){
            times[0]++;
        }else if(arr[i] == cans[1]){
            times[1]++;
        }else{
            times[0]--;
            times[1]--;
            if(times[0]<0){
                cans[0] = arr[i];
                times[0] = 1;
            }else if(times[1]< 0){
                cans[1] = arr[i];
                times[1] = 1;
            }
        }
        printf("times:%d,%d\n",times[0],times[1]);
        printf("cans:%d,%d\n",cans[0],cans[1]);
    }
    return 0;
}


int main(int argc ,char * argv[]){
    int arr[10] = {1,1,1,1,2,2,2,2,4,5};
    int cans[2]={0,0};  
    int value = findMore(arr, 10,cans);  
    printf("Find Value:%d,%d\n", cans[0],cans[1]);  
}
