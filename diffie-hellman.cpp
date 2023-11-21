#include <bits/stdc++.h>
using namespace std;

long long generate_public_key(long long private_key, long long alpha, long long q) {
    return (long long)pow(alpha, private_key) % q;
}

long long generate_secret_key(long long public_key_receiver, long long private_key_sender, long long q) {
    return (long long)pow(public_key_receiver, private_key_sender) % q;
}

void print(long long private_key, long long public_key, long long secret_key) {
    cout<<"Private Key: "<<private_key<<"\nPublic Key: "<<public_key<<"\nSecret Key: "<<secret_key<<endl;
    cout<<"________________________________"<<endl;
}

void secure_communication(long long q, long long alpha) {
    long long private_key_A, private_key_B;
    cout<<"Enter private keys of A and B: ";
    cin>>private_key_A>>private_key_B;
   
    long long public_key_A = generate_public_key(private_key_A, alpha, q);
    long long public_key_B = generate_public_key(private_key_B, alpha, q);
   
    long long secret_key_A = generate_secret_key(public_key_B, private_key_A, q);
    long long secret_key_B = generate_secret_key(public_key_A, private_key_B, q);
   
   
    cout<<"For A:"<<endl;
    print(private_key_A, public_key_A, secret_key_A);
   
    cout<<"For B:"<<endl;
    print(private_key_B, public_key_B, secret_key_B);
   
}

void mitm(long long q, long long alpha) {
    long long private_key_E1, private_key_E2, private_key_A, private_key_B;
    cout<<"Enter private keys of Eve(two), Alice and Bob: ";
    cin>>private_key_E1>>private_key_E2>>private_key_A>>private_key_B;
   
    long long public_key_A = generate_public_key(private_key_A, alpha, q);
    long long public_key_B = generate_public_key(private_key_B, alpha, q);
   
    long long public_key_E1 = generate_public_key(private_key_E1, alpha, q);
    long long public_key_E2 = generate_public_key(private_key_E2, alpha, q);
   
    long long secret_key_E1 = generate_secret_key(public_key_A, private_key_E1, q);
    long long secret_key_E2 = generate_secret_key(public_key_B, private_key_E2, q);
   
    long long secret_key_A = generate_secret_key(public_key_E1, private_key_A, q);
    long long secret_key_B = generate_secret_key(public_key_E2, private_key_B, q);
   
   
    cout<<"For E1: "<<endl;
    print(private_key_E1, public_key_E1, secret_key_E1);
   
    cout<<"For A: "<<endl;
    print(private_key_A, public_key_A, secret_key_A);
    cout<<"________________________________"<<endl;
   
    cout<<"For E2: "<<endl;
    print(private_key_E2, public_key_E2, secret_key_E2);
   
    cout<<"For B: "<<endl;
    print(private_key_B, public_key_B, secret_key_B);
}

int main() {
    long long q, alpha;
    cout<<"Enter values of q and alpha: ";
    cin>>q>>alpha;
   
    int choice;
    A:
    cout<<"Select one of the following\n1. Secure Communication\n2. Man in the middle attack"<<endl;
    cin>>choice;
   
   
    if(choice == 1) {
        secure_communication(q, alpha);
        goto A;
    }
    else if(choice == 2) {
        mitm(q, alpha);\
        goto A;
    }
   

    return 0;
}