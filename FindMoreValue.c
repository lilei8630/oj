#include <stdio.h>
#include <stdlib.h>

int FindMoreValue(int arr[],int n){
        int i;
        int curr_count = 1;
        int curr_value = arr[0];
        for(i=1;i<n;i++){
            if(arr[i]==curr_value){
                curr_count++;
            }else{
                curr_count--;
                if(curr_count<0){
                    curr_value = arr[i];
                    curr_count = 1;
                }
            }
        }
        if(curr_count > 0){
            return curr_value;
        }else{
            return -1;
        }
}

int main(int argc,char * argv[]){
    int arr[10] = {2,3,1,1,1,3,4,1,1,1};
    int value = FindMoreValue(arr,10);
    printf("Find Value:%d\n",value);
}
