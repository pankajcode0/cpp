#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int fiblookup(int n, auto &lookup)
{
    if(n<=1)
    {
        return n;
    }

    if(lookup.find(n) == lookup.end())
    {
        lookup[n] = fiblookup(n-1,lookup) + fiblookup(n-2,lookup);
    }

    return lookup[n];
}

int main()
{
    int n,y;
    unordered_map<int,int> lookup;
    cin>>n;

    cout<<fiblookup(n,lookup);
 

    return 0;
}