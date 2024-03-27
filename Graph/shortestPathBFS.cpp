#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void bfsShortestPath(vector<vector<ll>> graph, ll source, ll destination){
    ll vertices=graph.size();
    vector<bool> visited(vertices,false);
    vector<ll> distances(vertices, 0);
    vector<ll> parent(vertices,-1);
    queue<ll>bfsQueue;

    bfsQueue.push(source);
    visited[source]=true;

    parent[source]=source;
    distances[source]=0;

    while(!bfsQueue.empty()){
        ll current=bfsQueue.front();
        bfsQueue.pop();

        for(ll i=0;i<vertices;i++){
            if(graph[current][i]==1 && !visited[i]){
                bfsQueue.push(i);
                visited[i]=true;
                parent[i]=current;
                distances[i] = distances[current] + 1;
            }
        }
    }

    cout<<endl<<"Shortest Distances from Node "<<source<<":"<<endl;
    for (ll i=0;i<vertices;i++)cout<<"Node "<<i<<": "<<distances[i]<<endl;

    cout<<"Shortest path from source node "<<source<<" to destination node "<<destination<<":";
    int tmp=destination;
    while(tmp!=source){
        cout<<" "<<tmp;
        tmp=parent[tmp];
    }
    cout<<source<<endl;
}

int main(){
  ll vertices, edges, source, destination;

  cout<<"Enter Number of Vertices and Edges: ";
  cin>>vertices>>edges;

  vector<vector<ll>> graph(vertices, vector<ll>(vertices, 0));

  // GETTING INPUT
  for(ll i=0;i<edges;i++){
    ll from, to;
    cout<<"Enter "<<i+1<<"th Start and End Node: ";
    cin>>from>>to;
    graph[from][to]=1;
    graph[to][from]=1;
  }

  cout<<"Enter Source Node: ";cin>>source;
  cout<<"Enter Destination Node: ";cin>>destination;

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(ll i=0;i<vertices;i++){
    for(ll j=0;j<vertices;j++)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  bfsShortestPath(graph,source,destination);

  return 0;
}