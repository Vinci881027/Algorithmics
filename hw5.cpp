#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<int> adj[], bool visit[], int i, bool connected)
{
    for(int j = 0; j < adj[i].size(); j++){
        if(!visit[adj[i][j]-1]){
            visit[adj[i][j]-1] = true;
            if(connected)
                cout << adj[i][j] << " ";
            DFS(adj, visit, adj[i][j]-1, connected);
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    int v1, v2;
    int oddDegree = 0;
    bool visit[V];
    bool connected = true;
    vector<int> adj[V];
    for(int i = 0; i < E; i++){
        cin >> v1 >> v2;
        adj[v1-1].push_back(v2);
        adj[v2-1].push_back(v1);
    }
    //count degree of every vertex
    for(int i = 0; i < V; i++){
        if(adj[i].size() % 2)
            oddDegree++;
    }
    if(oddDegree == 0 || oddDegree == 2){
        for(int i = 0; i < V; i++)
            visit[i] = false;
        for(int i = 0; i < V; i++){
            if(!visit[i]){
                visit[i] = true;
                DFS(adj, visit, i, false);
            }
        }
        for(int i = 0; i < V; i++){
            if(!visit[i])
                connected = false;
        }
        for(int i = 0; i < V; i++)
            visit[i] = false;
        for(int i = 0; i < V; i++){
            if(!visit[i]){
                visit[i] = true;
                DFS(adj, visit, i, connected);
            }
        }
    }
    else
        cout << "not exist" << endl;
    return 0;
}