#include<bits/stdc++.h>
#include <iostream>

using namespace std;

class Dikstra{
    public:
    void sol(vector<pair<int,int>> adj[],int n,int source)
    {
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push(make_pair(0,source));
        vector<int>finaldist(n+1,9999);
        finaldist[source]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            vector<pair<int,int>>::iterator it;
		    for( it = adj[node].begin() ; it != adj[node].end() ; it++){
                int next=it->first;
                int nextDist=it->second;
                if(finaldist[next]>finaldist[node]+nextDist){
                    finaldist[next]=finaldist[node]+nextDist;
                    pq.push(make_pair(finaldist[next],next));
                }
            }
        }
        cout<<"Distance from source "<<source<<" is:";
        for(int i=1;i<=n;i++)
        cout<<finaldist[i]<<" ";
    }
    
};
int main()
{
    int n,m;
    int source;
    cout<<"Enter the number of nodes:";
    cin>>n;
    cout<<"Enter the number of edges:";
    cin>>m;
    cout<<"Enter the source:";
    cin>>source;
    
    vector<pair<int,int>> adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    Dikstra d;
    d.sol(adj,n,source);
    return 0;
}
