#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string name, title;
    cout<<name;
    cin>>name;
    cout<<title;
    cin>>title;
    char d[52];
    strcpy(d, name.c_str());
    strcat(d,title.c_str());
    cout<<d;


}
