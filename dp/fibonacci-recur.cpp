#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fib(int n)
{
    int j;
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    else{
        j = fib(n-1) + fib (n-2);
    }
    return j;
}

int main()
{
    int n;
    cin>>n;
    int y= fib(n);
    cout<<y;
}