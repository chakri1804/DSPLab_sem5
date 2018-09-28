#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

double PI = 3.1415926535;
typedef double complex clx;

void split(clx buf[], clx odd[], clx even[], int n){
	for(int i=0; i<n; i++){
		if(i%2 == 0)
		even[i/2] = buf[i];
		else
		odd[i/2]  = buf[i];
	}
}

void show(clx buf[], int n) {
	for (int i = 0; i < n; i++)
		if (!cimag(buf[i]))
			printf("%g ", creal(buf[i]));
		else
			printf("(%g, %g) ", creal(buf[i]), cimag(buf[i]));
}

clx *fft(clx buf[],clx y[],int n){
	if(n==1){
		return buf;
	}

	clx wn = cexp(2*PI*I/n);
	clx w = 1;
	clx even[n/2];
	clx odd[n/2];
	clx *y1=(clx*)malloc((n/2)*sizeof(clx));
	clx *y0=(clx*)malloc((n/2)*sizeof(clx));

	printf("%p\n",y0);
	split(buf,odd,even,n);
	  y1 = fft(odd,y,n/2);
		y0 = fft(even,y,n/2);
	for (int i=0;i<n/2;i++){
		y[i] = y0[i] + w*y1[i];
		y[i+ n/2] = y0[i] - w*y1[i];
		w = w*wn;
	return y;
}
}

int main(void){
  clx buf[] = {1,2,3,4};
	int n = 4;
	clx *ans = (clx*)malloc((n)*sizeof(clx));
	ans = fft(buf,ans,n);
	show(ans,n);
}
