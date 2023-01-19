#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double stdev(int *ptr,int n);
double average(int *ptr,int n);

int main() {
    FILE * fp;
    fp = fopen("isafile.txt","w");

    char c1 = 241;
    int N,*ptr,avrg;
    double s;
    printf("Give number of cells :\n");
    scanf("%d",&N);
    ptr = (int*) malloc(N *sizeof(int));

    srand(time(NULL));
    for(int i = 0;i < N; i++){
        ptr[i] = rand() % 50 +  25;
    }
    s = stdev(ptr,N);
    double s2 = s * (double)2;
    fprintf(fp,"average %c stdev : %lf  | average %c 2 * stdev : %lf",c1,s,c1,s2);



}

double stdev(int *ptr,int n){
    double s =0;
    double temp;
    double avrg = average(ptr,n);
    double sum = 0;
    for(int i = 1;i < n;i++){
        sum = sum  + pow(ptr[i] - avrg , 2);
    }
    s  = sqrt(sum/n-1);
    return s;
}
double average(int *ptr,int n){
    double  sum = 0;
    for(int i = 0;i < n;i++){
        sum  = sum + ptr[i];
    }
    sum  = sum / (double)n;

    return sum;
}