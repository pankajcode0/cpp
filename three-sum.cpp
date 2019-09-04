#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int main(){
    vector<int>vect;
    int n,a,sum,l,r;

    cout<<"size of array";
    cin>>n;

    cout<<"input array";

    for(int i=0;i<n;i++){
        cin>>a;
        vect.push_back(a);
    }

    cout<<"input sum";
    cin>>sum;
    /*for(int i=0;i<n;i++){
        cout<<vect[i]<<endl;
    }

    for (auto i = vect.begin(); i!=vect.end(); ++i){
        cout<<*i<<"";
    }

    for (auto i = vect.cbegin(); i!=vect.cend(); ++i){
        cout<<*i<<"";
    }
    int y = vect.size();
    //sort(vect.begin(),vect.end(),greater<int>());//sorting descending order
    */
    sort(vect.begin(),vect.end());
    for(auto i = vect.begin();i!=vect.end();++i)
    {
        cout <<*i<<" ";
    }
    cout<<endl;
    
    
    for(int i=0;i<vect.size()-1;i++){
        l=i+1;
        r=vect.size()-1;

        while(l<r){
            if(vect[i]+vect[r]+vect[l]==sum)
            {
                cout<<"triplet "<<vect[i]<<vect[r]<<vect[l];
                return true;
            }

            if(vect[i]+vect[r]+vect[l]<sum)
            {
                l++;
            }
            else{
                r--;
            }
        }
        
    }

    cout<<"no triplet";
    return 0;
}
