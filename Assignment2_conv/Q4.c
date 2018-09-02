// x-(f(x)/f'(x))
#include <stdio.h>

int main(void){
double x=10;
for(int i=0;i<100;i++){
  x = x-(((x*x*x)-x-1)/(3*x*x-1));
}
printf("%lf\n",x);
}
