#include <stdio.h>
#include <math.h>

int main(void){
  int precision;
  double a;
  double b;
  printf("Give precision \n");
  scanf("%d",&precision);
  // printf("%d \n",precision);
  printf("Give numbers to be added \n");
  scanf("%lf %lf",&a,&b);
  // printf("%lf %lf \n",a,b);
  // printf("%lf,%lf",a,b);
  int z = pow(2,precision);
  printf("%d \n",z);
  int a1 = a * pow(2,precision);
  int b1 = b * pow(2,precision);
  // printf("%d,%d",a1,b1);
  int c1 = a1+b1;
  double c = c1/pow(2,precision);
  printf("%lf \n",c);
}
