#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string mcs(string A, string B, int m, int n){
 int maxlen = 0;
 int ending_index =m;
 int lookup[m+1][n+1];
 memset(lookup,0,sizeof(lookup));
 for(int i=1;i<n;i++){
 for(int j=1;j<n;j++){
     if(A[i-1]==B[i-1]){
         lookup[i][j]=lookup[i-1][j-1]+1;
         cout<<lookup[i][j]<<" ";
     }
     if(maxlen<lookup[i][j]){
         maxlen = lookup[i][j];
         ending_index = i;
     }
 }
 cout<<"\n";
}


return A.substr(ending_index-maxlen,maxlen);
}

int main(){
    string A,B;
    cout<<"input string A";
    cin>>A;
    cout<<"input string B";
    cin>>B;
    cout<<mcs(A,B,A.length(),B.length());
}