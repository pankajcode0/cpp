#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int topologicalsort(int v, vector<vector<int>> &tmatrix,vector<int> &visited, stack<int>&topological)
{
    visited[v] = 1;
    
    for(auto i=tmatrix[v].begin();i<tmatrix[v].end();++i)
    {
        if(visited[*i]==0)
        {
            topologicalsort(*i,tmatrix,visited,topological);
        }
    }
    topological.push(v);
}

int main()
{
   
    int edge,vertex,a,b;
    cout<<"edge";
    cin>>edge;
    cout<<"vertex";
    cin>>vertex;
    vector< vector<int> > tmatrix(vertex);
    vector<int>visited(vertex);
    stack<int>topological;
    for (int i=0; i<vertex; i++)
    {
        cin>>a;
        cin>>b;
        tmatrix[a].push_back(b);
    }
    for(int i=0;i<vertex;i++)
    {
        visited[i]=0;
    }

    for(int i=0; i<vertex; i++)
    {
        for(auto j = tmatrix[i].begin(); j < tmatrix[i].end(); j++)
        {
            cout<<"edge "<<i<<"-"<<*j;
        }
    }
    for(int j=0; j<vertex; j++)
        {
            if(visited[j]==0){
                    topologicalsort(j,tmatrix,visited,topological);
            }
        }
    
    while (topological.empty() == false) 
    { 
        cout << topological.top() << " "; 
        topological.pop(); 
    } 
}

