#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<math.h>



long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}
bool Miller(long long p){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    int i;
    for(i=0;i<100;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}
    //else it is probably a prime







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

   if(Miller(no))
        printf("\n%lld is probably a prime number\n",no);
    else
          printf("\n%lld is not probably a prime number\n",no);
return main();
}
