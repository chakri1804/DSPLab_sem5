# include<stdio.h>
# include<stdlib.h>
# include <math.h>

#define pi 3.141592653

struct compl{
  short int Re;
  short int Img;
};

struct compl *fft(struct compl x[],int N){
  struct compl *X=(struct compl *)malloc(N*sizeof(struct compl));
  if(N==1){
    return x;
  }
  struct compl wn;
  short int temp1;
  short int temp2;
  wn.Re=(short int)(cos(2*pi/N)*(1<<7));
  wn.Img=(short int)(-sin(2*pi/N)*(1<<7));
  struct compl w;
  w.Re=(short int)(1*(1<<7));;
  w.Img=0;
  struct compl *ye=(struct compl *)malloc((N/2)*sizeof(struct compl));
  struct compl *yo=(struct compl *)malloc((N/2)*sizeof(struct compl));
  int i,k;
  for(i=0;i<N/2;i++){
    ye[i]=x[2*i];
    yo[i]=x[2*i+1];
  }
  ye=fft(ye,N/2);
  yo=fft(yo,N/2);
  for(k=0;k<N/2;k++){
    X[k].Re=ye[k].Re+((w.Re)*(yo[k].Re)/(1<<7))-((w.Img)*(yo[k].Img)/(1<<7));
    X[k].Img=ye[k].Img+((w.Re)*(yo[k].Img)/(1<<7))+((w.Img)*(yo[k].Re)/(1<<7));
    X[k+N/2].Re=ye[k].Re-((w.Re)*(yo[k].Re)/(1<<7))+((w.Img)*(yo[k].Img)/(1<<7));
    X[k+N/2].Img=ye[k].Img-((w.Re)*(yo[k].Img)/(1<<7))-((w.Img)*(yo[k].Re)/(1<<7));
    temp1=((w.Re)*(wn.Re)/(1<<7))-((w.Img)*(wn.Img)/(1<<7));
    temp2=((w.Re)*(wn.Img)/(1<<7))+((w.Img)*(wn.Re)/(1<<7));
    w.Re=temp1;
    w.Img=temp2;
  }
  return X;
}

int main(){
  struct compl x[8]={{1.1*(1<<7),0},{8.1*(1<<7),0},{4.1*(1<<7),0},{1.1*(1<<7),0},{2.1*(1<<7),0},{3.1*(1<<7),0},{1.1*(1<<7),0},{5.1*(1<<7),0}};
  struct compl *X1;
  X1=fft(x,8);
  for(int i=0;i<8;i++){
    printf("(%f,%f)\n",X1[i].Re/(float)(1<<7),X1[i].Img/(float)(1<<7));
  }
}
