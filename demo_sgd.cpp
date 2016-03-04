/* 
 * 随机梯度下降实验： 
 * 训练集输入为矩阵： 
 * 1,4 
 * 2,5 
 * 5,1 
 * 4,2 
 * 输出结果为： 
 * 19 
 * 26 
 * 19 
 * 20 
 * 需要参数为theta： 
 * theta0
 * theta1 
 *
 * 目标函数:
 * y=theta0*x0+theta1*x1; 
 * */  
#include <stdio.h>
int main(void)
{
        float matrix[4][2]={{1,4},{2,5},{5,1},{4,2}};
        float result[4]={19,26,19,20};
        float theta[2]={2,5};
        float loss = 10.0;
        for(int i =0 ;i<1000&&loss>0.00001;++i)
        {
                float error_sum=0.0;
                int j=i%4;
                
                        float h = 0.0;
                        for(int k=0;k<2;++k)
                        {
                                h += matrix[j][k]*theta[k];

                        }
                        error_sum = result[j]-h;
                        for(int k=0;k<2;++k)
                        {
                                theta[k] = theta[k]+0.01*(error_sum)*matrix[j][k];
                        }
                
                printf("i=%d,%f,%f\n",i,theta[0],theta[1]);
                loss = 0.0;
                for(int j = 0;j<4;++j)
                {
                        float sum=0.0;
                        for(int k = 0;k<2;++k)
                        {

                                sum += matrix[j][k]*theta[k];
                        }
                        loss += (sum-result[j])*(sum-result[j]);
                }
                printf("%f\n",loss);
        }
        return 0;
}