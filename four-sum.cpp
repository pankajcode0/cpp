#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;


int foursum(vector<int>vect,int n,int sum)
{
    unordered_map<int,pair<int,int>>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           mp[vect[i] + vect[j]] = {i, j}; 
  
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mp.find(sum-vect[i]-vect[j])!=mp.end())
            {
                pair<int,int> p = mp[sum-vect[i]-vect[j]];
                if(p.first!=i && p.second!=j && p.first!=j && p.second!=i && p.first!=p.second && i!=j)
                {
                    cout<<"four sum "<<vect[p.first]<<" " <<vect[p.second]<<" "<<vect[i]<<" "<<vect[j]<<endl;
                    cout<<"four sum "<<p.first<<" " <<p.second<<" "<<i<<" "<<j<<endl;


                }
            }
        }
    }
    return 0;
}

int main()
{
    int size,sum,input;
    vector<int>vect;
    cout<<"input array size";
    cin>>size;
    cout<<"\ninput array";
    for(int i=0;i<size;i++)
    {
        cin>>input;
        vect.push_back(input);
    }
    cout<<"\n input sum";
    cin>>sum;
    foursum(vect,size,sum);
    return 0;

}