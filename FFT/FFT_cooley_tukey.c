#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

double pi = 3.141592653589793238462643383279502884;
typedef double complex clx;

clx* fft(clx buf[],int n){
  if(n == 1)
  return buf;
  clx wn = cexp(-I*2*pi/n);
  clx w  = 1.0000000;
  clx *Ye=(clx*)malloc((n/2)*sizeof(clx));
  clx *Yo=(clx*)malloc((n/2)*sizeof(clx));
  int i=0;
  for (i = 0; i<n/2; i++){
    Ye[i] = buf[2*i];
    Yo[i]  = buf[2*i+1];
  }
  clx *y=(clx*)malloc((n)*sizeof(clx));
  Yo = fft(Yo,n/2);
  Ye = fft(Ye,n/2);
  for(i=0; i<n/2; i++){
    y[i] = Ye[i] + (w*Yo[i]);
    y[i+(n/2)] = Ye[i] - (w*Yo[i]);
    w = w*wn;
  }
  return y;
}

void show(clx buf[], int n) {
  int i;
	for (i = 0; i < n; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
}

int main(void){
  clx input[] = {1,8,0,4,1,2,3,1};
  int lenght_input = 8;
  clx *ans = (clx*)malloc((lenght_input)*sizeof(clx));
  ans = fft(input,lenght_input);
  show(ans,lenght_input);
}
