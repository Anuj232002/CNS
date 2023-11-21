#include<bits/stdc++.h>
using namespace std;
int main()
{   int p,q;
    cout<<"Enter two prime numbers: ";
    cin>>p>>q;
    string m;
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
    string s1="";
    for(int i=0;i<m.length();i++)
    {
    encry=pow(int(m[i]),e);
    int en=fmod(encry,n);
    }
    
    cout<<"Encrytion: "<<s1<<endl;

    int decry;
    string s2="";
    for(int i=0;i<s1.length();i++)
    {
    decry=pow(int(s1[i]),d);
    s2=s2+char(fmod(decry,n));
    }
    cout<<"Decrytion: "<<s2<<endl;

    return 0;
}