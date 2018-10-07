# include<stdio.h>
# include<stdlib.h>
# include<math.h>

#define pi 3.141592653589793238462643383279502884

struct compl{
  float real;
  float img;
};

struct compls{
  short int real;
  short int img;
};

struct compls *fft(struct compls x[],int N){
  struct compls *Y=(struct compls *)malloc(N*sizeof(struct compls));
  if(N==1){
    return x;
  }
  short int temp1;
  short int temp2;
  struct compls wn;
  wn.real=(short int)(cos(2*pi/N)*(1<<7) );
  wn.img =(short int)(-sin(2*pi/N)*(1<<7));
  struct compls w;
  w.real=1*(1<<7);
  w.img=0;
  struct compls *Ye=(struct compls *)malloc((N/2)*sizeof(struct compls));
  struct compls *Yo=(struct compls *)malloc((N/2)*sizeof(struct compls));
  int i,k;
  for(i=0;i<N/2;i++){
    Ye[i]=x[2*i];
    Yo[i]=x[2*i+1];
  }
  Ye=fft(Ye,N/2);
  Yo=fft(Yo,N/2);
  for(k=0;k<N/2;k++){
        Y[k].real = Ye[k].real+((w.real)*(Yo[k].real)/(1<<7)) -((w.img)*(Yo[k].img )/(1<<7));
         Y[k].img = Ye[k].img +((w.real)*(Yo[k].img) /(1<<7)) +((w.img)*(Yo[k].real)/(1<<7));
    Y[k+N/2].real = Ye[k].real-((w.real)*(Yo[k].real)/(1<<7)) +((w.img)*(Yo[k].img )/(1<<7));
     Y[k+N/2].img = Ye[k].img -((w.real)*(Yo[k].img) /(1<<7)) -((w.img)*(Yo[k].real)/(1<<7));
            temp1 = (w.real)*(wn.real)/(1<<7) - (w.img)*(wn.img) /(1<<7);
            temp2 = (w.real)*(wn.img) /(1<<7) + (w.img)*(wn.real)/(1<<7);
    w.real=temp1;
    w.img=temp2;
  }
  return Y;
}

void show(struct compls x[], int n){
  for(int i=0;i<n;i++){
    printf("(%f,%f)\n",x[i].real/(double)(1<<7),x[i].img/(double)(1<<7));
  }
}

int main(){
  struct compl x[8]={{1,0},{8,0},{4,0},{1,0},{2,0},{3,0},{1,0},{5,0}};
  int n = 8;
  struct compls xs[n];
  int i;
  for(i=0;i<n;i++){
    xs[i].real = x[i].real*(1<<7);
     xs[i].img = x[i].img*(1<<7);
  }
  struct compls *X1;
  X1=fft(xs,8);
  show(X1,8);
}
