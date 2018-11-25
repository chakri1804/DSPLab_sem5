# include<stdio.h>
# include<stdlib.h>
# include<c6x.h>

#define q_fact 7
short int f = (1<<q_fact);

struct compl{
  float real;
  float img;
};

struct compls{
  short int real;
  short int img;
};

struct compl w1[32] =  {{1.000000,-0.000000},{0.995185,-0.098017},{0.980785,-0.195090},
                            {0.956940,-0.290285},{0.923880,-0.382683},{0.881921,-0.471397},
                            {0.831470,-0.555570},{0.773010,-0.634393},{0.707107,-0.707107},
                            {0.634393,-0.773010},{0.555570,-0.831470},{0.471397,-0.881921},
                            {0.382683,-0.923880},{0.290285,-0.956940},{0.195090,-0.980785},
                            {0.098017,-0.995185},{0.000000,-1.000000},{-0.098017,-0.995185},
                            {-0.195090,-0.980785},{-0.290285,-0.956940},{-0.382683,-0.923880},
                            {-0.471397,-0.881921},{-0.555570,-0.831470},{-0.634393,-0.773010},
                            {-0.707107,-0.707107},{-0.773010,-0.634393},{-0.831470,-0.555570},
                            {-0.881921,-0.471397},{-0.923880,-0.382683},{-0.956940,-0.290285},
                            {-0.980785,-0.195090},{-0.995185,-0.098017}};


struct compls *fft(struct compls x[],int N){
  struct compls *Y=(struct compls *)malloc(N*sizeof(struct compls));
  if(N==1){
    return x;
  }
  // short int temp1;
  // short int temp2;
  // struct compls wn;
  // wn.real=(short int)(cos(2*pi/N)*(1<<7) );
  // wn.img =(short int)(-sin(2*pi/N)*(1<<7));
  struct compls w;
  // w.real=1*(1<<7);
  // w.img=0;
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
      w.real = (short int)(w1[k*64/N].real*(1<<q_fact));
      w.img = (short int)(w1[k*64/N].img*(1<<q_fact));

      Y[k].real=_add2(Ye[k].real,    _addsub(((w.real)*(Yo[k].real)/(1<<q_fact)),((w.img)*(Yo[k].img)/(1<<q_fact))));
      Y[k].img=_add2(Ye[k].img,      _add2(((w.real)*(Yo[k].img)/(1<<q_fact)),((w.img)*(Yo[k].real)/(1<<q_fact))));
      Y[k+N/2].real=_add2(Ye[k].real,_addsub(((w.img)*(Yo[k].img)/(1<<q_fact)),((w.real)*(Yo[k].real)/(1<<q_fact))));
      Y[k+N/2].img=_addsub(Ye[k].img,_add2(((w.real)*(Yo[k].img)/(1<<q_fact)),((w.img)*(Yo[k].real)/(1<<q_fact))));
  }
  return Y;
}

void show(struct compls x[], int n){
  int i;
    for(i=0;i<n;i++){
    printf("(%f,%f)\n",x[i].real/(double)(1<<7),x[i].img/(double)(1<<7));
  }
}

int main(){
  struct compl x[64]={{0.749080237694725   ,0.561869019374761},
                      {1.9014286128198323  ,1.085392166316497},
                      {1.4639878836228102  ,0.281848449949525},
                      {1.1973169683940732  ,1.604393961508079},
                      {0.31203728088487304 ,0.149101287359541},
                      {0.3119890406724053  ,1.973773873201034},
                      {0.11616722433639892 ,1.544489538593314},
                      {1.7323522915498704  ,0.397431363068344},
                      {1.2022300234864176 ,0.011044234247204},
                      {1.416145155592091   ,1.630922856909668},
                      {0.04116898859160489,1.413714687695234},
                      {1.9398197043239886  ,1.458014336081974},
                      {1.6648852816008435 ,1.542540693371891},
                      {0.4246782213565523  ,0.148089303468180},
                      {0.36364993441420124,0.716931457088545},
                      {0.36680901970686763 ,0.231738119050259},
                      {0.6084844859190754 ,1.726206851751187},
                      {1.0495128632644757  ,1.246596253655115},
                      {0.8638900372842315 ,0.661796049705298},
                      {0.5824582803960838,0.127116700572047},
                      {1.223705789444759,0.621964643431324},
                      {0.27898772130408367,0.650366644053494},
                      {0.5842892970704363,1.459212356676128},
                      {0.7327236865873834 ,1.275114942710426},
                      {0.9121399684340719,1.774425485152653},
                      {1.5703519227860272,0.944429850323898},
                      {0.39934756431671947,0.239188491876603},
                      {1.0284688768272232,1.426489574445990},
                      {1.184829137724085 ,1.521570097233794},
                      {0.09290082543999545,1.122554395138992},
                      {1.2150897038028767,1.541934359909122},
                      {0.34104824737458306,0.987591192728781},
                      {0.13010318597055903,1.045465658763988},
                      {1.8977710745066665 ,0.855082036717099},
                      {1.9312640661491187 ,0.050838253488190},
                      {1.6167946962329223 ,0.215782853986608},
                      {0.6092275383467414 ,0.062858371373468},
                      {0.19534422801276774,1.272820822527560},
                      {1.3684660530243138 ,0.628711962152653},
                      {0.8803049874792026 ,1.017141382329405},
                      {0.24407646968955765,1.815132947852186},
                      {0.9903538202225404 ,0.498584458297749},
                      {0.06877704223043679,0.820765846071259},
                      {1.8186408041575641 ,1.511102277086097},
                      {0.5175599632000338 ,0.457596330983244},
                      {1.325044568707964  ,0.153959819657585},
                      {0.6234221521788219 ,0.579502905827536},
                      {1.0401360423556216 ,0.322442574508008},
                      {1.0934205586865593 ,1.859395304685146},
                      {0.3697089110510541 ,1.616240759128834},
                      {1.9391692555291171 ,1.266807513020847},
                      {1.550265646722229  ,1.742921180375435},
                      {1.8789978831283782 ,1.607344153798229},
                      {1.7896547008552977 ,0.373140117772071},
                      {1.1957999576221703 ,1.785117996979955},
                      {1.8437484700462337 ,1.078684483831301},
                      {0.176985004103839  ,1.614880310328125},
                      {0.3919657248382904 ,1.792182599846986},
                      {0.0904545778210761 ,0.636006949943727},
                      {0.6506606615265287 ,0.220103849055353},
                      {0.777354579378964  ,0.455870325083883},
                      {0.5426980635477918 ,0.854215577252512},
                      {1.6574750183038587 ,1.636029531844986},
                      {0.7135066533871786 ,1.721461166512686}};
  int n = 64;
  struct compls xs[64];
  int i;
  for(i=0;i<n;i++){
    xs[i].real = x[i].real*f;
    xs[i].img = x[i].img*f;
  }
  struct compls *X1;
  X1=fft(xs,64);
  show(X1,64);
}