#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 15

int amountMoreAvg(const double* arr, int num);
double sumAfterMinus(const double* arr, int num);
 
int main(){
    int i;
    double a[N];
    srand((unsigned int)time(NULL));
    printf("Array\n");
    for(i = 0; i < N; ++i){
        a[i] = (double)(-51 + rand() % 101);
        printf("%lg ", a[i]);
    }
    
    printf("Number of elements, large elements array averages : %d\n", amountMoreAvg(a, N));
    printf("The sum of the modules of the array elements located after the first negative element: %lg\n", sumAfterMinus(a, N));
 
    return 0;
}
 

int amountMoreAvg(const double* arr, int num){
    double avg=0;
    int amount=0, i;
    for(i = 0; i < num; ++i){
        avg+=arr[i];
    }
    avg/=num;
    printf("Avg: %lg\n",avg);
    for(i = 0; i < num; ++i){
        if(arr[i]>avg)
            ++amount;
    }
    return amount;
}

double sumAfterMinus(const double* arr, int num){
    double sum=0, minus;
    int i, minus_i;
    for(i = 0; i < num; ++i){
        if(arr[i]<0){
            minus = arr[i];
            minus_i = i;
            printf("First negative number: %lg\n", minus);
            break;
        }
    }
    for(i = minus_i+1; i < num; ++i){
        sum+=fabs(arr[i]);
    }
    return sum;
}
