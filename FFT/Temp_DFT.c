#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979323846

int main(void){
  float time_buffer[4] = {1,2,3,4};
  int length;
  length = sizeof(time_buffer)/sizeof(time_buffer[0]);
  // printf("%d\n",length);
  float real_buffer[length];
  float imag_buffer[length];
  for(int i =0 ; i<length; i++){
    real_buffer[i] = 0;
    imag_buffer[i] = 0;
  }
  if(length == 1)
  real_buffer[0] = time_buffer[0];
  for (int i = 0; i < length; i++){
    for (int j = 0; j < length; j++){
      real_buffer[i] += time_buffer[j]*cos(2*pi*i*j/length);
      imag_buffer[i] += time_buffer[j]*sin(2*pi*i*j/length);
    }
  }
  for (int i = 0; i < length; i++) {
    printf("%lf\n",real_buffer[i]);
    // printf("%lf\n",imag_buffer[i]);
  }
  printf("##########################################\n");
  for (int i = 0; i < length; i++) {
    // printf("%lf\n",real_buffer[i]);
    printf("%lf\n",imag_buffer[i]);
  }
}
