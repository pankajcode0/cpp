#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> world;
    freopen ("iland-input.txt", "r", stdin);
    pair<int,int> worldSize;
    cin>>worldSize.first;
    cin>>worldSize.second;
   
    world.resize(worldSize.first);
    for(int i=0; i<worldSize.first; i++){
        world[i].resize(worldSize.second);
    }

    for(int i=0; i<world.size(); i++){
        for( int j=0; j<world[i].size(); j++){
            cin>>world[i][j];
            cout<<world[i][j];
        }
        cout<<"\n";
    }
    
}
