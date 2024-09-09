/* Program to print the continuous sum of elements in an array*/
#include<stdio.h>
void main(){
int array[5]= {1,2,3,4,5};
int sum=0;
for(int i=0; i<5; i++){
sum=sum+array[i];
printf("%d ", sum);
		}
}
