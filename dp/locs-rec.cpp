#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int longestsub(string A, string B, int m, int n){
    if(m==0 || n==0) 
    {
        return 0;
    }

    if(A[m-1] == B[n-1])
    {
        return longestsub(A,B,m-1,n-1) + 1;
    }
    

    return max(longestsub(A,B,m-1,n),longestsub(A,B,m,n-1));
}

int main(){
    string  A,B;
    cout<<"string A:";
    cin>>A;
    cout<<"\nstring B:";
    cin>>B;
    cout<<"\nlength of longest common subsequence:"<<longestsub(A,B,A.length(),B.length());

    return 0;

}