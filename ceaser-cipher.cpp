#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ans;
    int key = 3;
    
    for (int i = 0; i < s.length(); i++)
    {   
        if (isupper(s[i]))
            ans = ans + char(int(s[i] + key - 65) % 26 + 65);
        else
        {
            ans = ans + char(int(s[i] + key - 97) % 26 + 97);
        }
    }
    cout<<"Encryption"<<endl;
    cout << ans;

    string temp;
    for (int i = 0; i < s.length(); i++)
    {   
        if (isupper(ans[i]))
            temp = temp + char(int(ans[i] - key - 65) % 26 + 65);
        else
        {
            temp = temp + char(int(ans[i] - key - 97) % 26 + 97);
        }
    }
    cout<<"EDecryption"<<endl;
    cout << temp;

    

    return 0;
}