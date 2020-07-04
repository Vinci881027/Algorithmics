#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<int> adj[], vector<int> visit[], int V, int t)
{
    int edgeConnectivity = 0;
    queue<int> q;
    bool visited = false;
    int i = 0;
    q.push(1);
    while(!q.empty()){
        i = q.front();
        q.pop();
        if(i == t)
            continue;
        for(int j = 0; j < adj[i].size(); j++){
            visited = false;
            for(int k = 0; k < visit[i].size(); k++){
                if(visit[i][k] == adj[i][j])
                    visited = true;
            }
            if(!visited){
                cout << i << " " << adj[i][j] << endl;
                q.push(adj[i][j]);
                visit[i].push_back(adj[i][j]);
                visit[adj[i][j]].push_back(i);
                if(adj[i][j] == t)
                    edgeConnectivity++;
            }
        }
    }
    return edgeConnectivity;
}

int main()
{
    int V, E, v1, v2;
    cin >> V >> E;
    int minFlow, temp;
    vector<int> adj[V+1];
    vector<int> visit[V+1];
    for(int i = 0; i < E; i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    minFlow = BFS(adj, visit, V, 2);
    cout << minFlow;
    return 0;
}