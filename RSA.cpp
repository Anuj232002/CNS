#include<bits/stdc++.h>
using namespace std;
int main()
{   int p,q,m;
    cout<<"Enter two prime numbers: ";
    cin>>p>>q;

    cout<<"Enter plaintext: ";
    cin>>m;

    int n=p*q;

    int phi=(p-1)*(q-1);

    int e;
    cout<<"Enter public key: ";
    cin>>e;

    int d,k;

    for(int i=1;i<phi;i++)
    {
        if(((1+(i*phi)) % e)==0)
        {
            k=i;
            break;
        }
    }
    d=(1+(k*phi))/e;

    cout<<"Private key: "<<d<<endl;

    int encry;
    encry=pow(m,e);
    int en=fmod(encry,n);
    cout<<"Encrytion: "<<en<<endl;

    int decry;
    decry=pow(encry,d);
    int dn=fmod(decry,n);
    cout<<"Decrytion: "<<dn<<endl;

    return 0;
}