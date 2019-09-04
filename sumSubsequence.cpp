#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> vect;
    int size,incl,excl=0,excl_new=0,a,i;
    cout<<"size";
    cin>>size;
    cout<<"input array";
    for(i=0;i<size;i++)
    {
        cin>>a;
        vect.push_back(a);
    }
    incl = vect[0];

    for(i=1;i<size;i++)
    {   
        excl_new = (incl > excl)? incl: excl; 
        incl = excl + vect[i];
        excl = excl_new;

    }

    cout<<((incl > excl)? incl : excl);

}