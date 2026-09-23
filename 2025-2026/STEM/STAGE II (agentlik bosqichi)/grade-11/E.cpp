#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
int p,q,r,s,P,Q,R,S,i,cnt,M=16;
int main()
{
    scanf("%d",&M);
    for(p=0;;p++)
    {
        P=6*p*p;
        if(P>M)break;
        for(q=0;;q++)
        {
            Q=2*q*q+8*p*q;
            if(P+Q>M)break;
            for(r=M&1;;r+=2)
            {
               R=M-(P+Q+r*r+6*p*r+4*r*q);
                if(R<=0)
                {
                    if(!R)cnt++;

                    break;
                }
                S=4*p+2*q+2*r;
                if(S&&(R%S==0))cnt++;
            }
        }

    }
    printf("%d",cnt);
    return 0;
}