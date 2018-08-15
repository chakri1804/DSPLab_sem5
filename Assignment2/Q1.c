#include <stdio.h>
#include <math.h>

int main(void){
  int precision;
  double a;
  double b;
  printf("Give number of bits assigned for decimal part \n");
  scanf("%d",&precision);
  // printf("%d \n",precision);
  printf("Give numbers to be added \n");
  scanf("%lf %lf",&a,&b);
  // printf("%lf %lf \n",a,b);
  // printf("%lf,%lf",a,b);
  // int z = pow(2,precision);
  // printf("%d \n",z);
  int a1 = a * (1<<precision);
  int b1 = b * (1<<precision);
  // printf("%d,%d",a1,b1);
  int c1 = a1+b1;
  double c = (double)c1/(1<<precision);
  printf("%lf \n",c);
}
