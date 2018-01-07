#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>

long int calpow(long int num,long int exp,long int modn);

void miller(long int n){
	long int i,k,q,j,m;
    for(i=0;i<n;i++){
        for(j=1;j<n;j=j+2)
        {
                if((n-1)==(pow(2,i))*j)
                {
                        k=i;
                        q=j;
                        break;
                }
        }
    }
	long int a;
	printf("Values: k: %ld, q=%ld\n",k,q);
	int x;
	srand(time(NULL));
	a=1+((long int)rand()%(n-1));
    printf("\na is %ld",a);
    if(calpow(a,q,n)==1){
            printf("\nInconcusive1\n");
            return;
    }
    for(m=0;m<k;m++){
        if(calpow(a,(calpow(2,m,n)*q),n)==n-1){
                printf("\nInconclusive2\n");
                return;
        }
    }
    printf("\nComposite\n");
    return;
}

long int calpow(long int num, long int exp, long int modn){
    long int i,res=1;
    for(i = 0; i < exp; i++){
        res = res * num;
        res = res % modn;
    }
    return res;
}



bool gcd(long long int x,long long int y)
   {
      long long int n=1;
      while(n)
          {
           n=x%y;
           x=y;
           y=n;
          }
       if(x==1)
            return true;
       else return false;
   }



bool chkprime(long long int p)
  {
    long long int i;
   long long int j;
//   printf("\nchkprime\t%d\n",p);
   j = pow(p,0.5);
   for(i=2;i<j;i++)
         {
            if(p%i==0)
                 return false;
          }
     return true;
  }


void genran(long long int *p,long long int *q,long long int *s)
  {
    long long int num,n;

   srand(time(NULL));
   num = (rand()%1000);
   *p=num;
   // printf("\n\ngenran p = %d",*p);
   num = (rand()%1000);
   *q=num;
  // printf("\n\ngenran q = %d",*q);
   while(true){
   if(*p%4==3 && chkprime(*p))
         break;
   else (*p)++;
  }
  while(true)
   {
   if(*q%4==3 && chkprime(*q))
        break;
   else (*q)++;
  }
  n = (*p) * (*q);
  *s = rand()%1000;
 while(true)
    {
      if(gcd(n,*s))
            break;
      else
          (*s)++;
    }

}



int main()
{
    long long int p,q,s,n,seq,i,ar[1000],x;
    genran(&p,&q,&s);
    printf("p = %lld\nq = %lld\ns = %lld\n",p,q,s);
    n = p*q;
    printf("enter the sequence  ");
    scanf("%lld",&seq);
    i=0;
    x=s;
    printf("\n\n");
    while(i<seq)
        {

          x = (x*x);
          x=x%n;
          printf("%llu  ",x);
          ar[i] = x%2;
          i++;
        }
   i=0;
   printf("\n\n");
   while(i<seq)
         printf("%lld  ",ar[i++]);
   printf("\n\n");
   long long int no=0;
   int max = seq-1;
   i=0;
   while(max>=0){
        no+=(ar[i]*pow(2,max));
        max--;i++;
   }
   printf("\n%lld\n",no);

miller(no);
}