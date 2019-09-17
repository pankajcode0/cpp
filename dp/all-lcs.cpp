#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define Max 20

int lookup[Max][Max];

string lcs(string x, string y, int m , int n){

    if(m==0|n==0){
        return "";
    }

    if(x[m-1]==y[n-1]){
    return  lcs(x,y,m-1,n-1) + x[m-1];
    }

    if(lookup[m][n-1]>lookup[m-1][n]){
        return lcs(x,y,m,n-1);
    }
    else{
        return lcs(x,y,m-1,n);
    }
    

}

void lcslength(string x,string y, int m, int n){
  
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){

            if(x[i-1]==y[j-1])
            {
            lookup[i][j] = lookup[i-1][j-1]+1;
            }
            else
            {
                
             lookup[i][j] = max(lookup[i-1][j],lookup[i][j-1]);
                
            }
            
        }
    }
}

int main()
{
    string x,y;
    cout<<"output string1: ";
    cin>>x;
    cout<<"output string2: ";
    cin>>y;
    lcslength(x,y,x.length(),y.length());
    for(int i=0; i<=x.length(); i++)
    {
        for ( int j=0; j<=y.length(); j++)
        {
            cout<<lookup[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<lcs(x,y,x.length(),y.length());
return 0;

}