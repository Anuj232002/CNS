#include<bits/stdc++.h>
using namespace std;
void secure(int q,int alpha)
{
    int xA,yA,xB,yB;
    cout<<"Enter private key of Alice: ";
    cin>>xA;

    cout<<"Enter private key of Bob: ";
    cin>>xB;
    
    int temp1;
    temp1=pow(alpha,xA);
    yA=fmod(temp1,q);
    cout<<"Public key of Alice: "<<yA<<endl;


    int temp2;
    temp2=pow(alpha,xB);
    yB=fmod(temp2,q);
    cout<<"Public key of Bob: "<<yB<<endl;

    int k1,k2;

    int temp3=pow(yB,xA);
    k1=fmod(temp3,q);
    cout<<"K1: "<<k1<<endl;

    int temp4=pow(yA,xB);
    k1=fmod(temp4,q);
    cout<<"K2: "<<k1<<endl;
    
    
    if(k1==k2)
    {
        cout<<"Key exachange successfull!"<<endl;
    }


}
void MITM(int q,int alpha)
{
   
    long long xA,xB,xE1,xE2;
    long long yA,yB,yE1,yE2;


    cout<<"Enter private key of A: ";
    cin>>xA;

    cout<<"Enter private key of B: ";
    cin>>xB;

    cout<<"Enter two private key of Eve: ";
    cin>>xE1>>xE2;


     yA=(long long)pow(alpha,xA)%q;
     yB=(long long)pow(alpha,xB)%q;
     yE1=(long long)pow(alpha,xE1)%q;
     yE2=(long long)pow(alpha,xE2)%q;

     long long k1,k2,kE1,kE2;

     k1=(long long)pow(yE1,xA)%q;
     kE1=(long long)pow(yA,xE1)%q;

     cout<<"Secret key of Alice and Eve: "<<k1<<" "<<kE1<<endl;



     k2=(long long)pow(yE2,xB)%q;
     kE2=(long long)pow(yB,xE2)%q;

     cout<<"Secret key of Bob and Eve: "<<k2<<" "<<kE2<<endl;

     



}
int main()
{   
    int q;
    cout<<"Enter prime number q: ";
    cin>>q;
    
    int alpha;
    cout<<"Enter primitive root alpha: ";
    cin>>alpha;
    
    int ch;
    A:
    cout<<"Enter choice: "<<endl<<"1.Secure communication"<<endl<<"2.MIMT"<<endl;
    cin>>ch;
    
    
    if(ch==1)
    {
        secure(q,alpha);
        goto A;
    }
    else if(ch==2)
    {
        MITM(q,alpha);
        goto A;
    }
    else if(ch==3)
    {
        
    }
    return 0;
}