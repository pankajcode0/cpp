#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int change(int n ,vector<int>vect)
{ int ans =0;
    for(int i=0;i<n;i++)
    {
        if(n==vect[i])
        {
            ans = 1;
            break;
        }
      
    }
   
    
    for(int i=1; i<=n/2; i++)
    {   
       int y = change(n-i,vect);
       int z = change(i,vect);

        if(y>0 && z>0){
            ans = ans + min(y,z);
        }
       else{
           ans = ans;
       }
            
       
        
    }
    

    return ans;
}




int main(){
    vector<int> vect;
    int n,m,a;
    cin>>n;
    cin>>m;

    for(int i=0; i<m;i++)
    {
        cin>>a;
        vect.push_back(a);
    }

   cout<< change(10,vect);
}