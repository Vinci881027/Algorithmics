#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> circuit;
vector<int> rCircuit;

void DFS(vector<int> adj[], bool visit[], int i)
{
    for(int j = 0; j < adj[i].size(); j++){
        if(!visit[adj[i][j]]){
            visit[adj[i][j]] = true;
            DFS(adj, visit, adj[i][j]);
        }
    }
}

void EulerianCircuit(vector<int> adj[], vector<int> visit[], int i)
{
    bool visitV;
    for(int j = 0; j < adj[i].size(); j++){
        visitV = false;
        for(int k = 0; k < visit[i].size(); k++){
            if(visit[i][k] == adj[i][j])
                visitV = true;
        }
        if(!visitV){
            visit[i].push_back(adj[i][j]);
            visit[adj[i][j]].push_back(i);
            circuit.push_back(i);
            EulerianCircuit(adj, visit, adj[i][j]);
            rCircuit.push_back(circuit.back());
            circuit.pop_back();
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    int v1, v2;
    bool evenDegree = true;
    bool connect = true;
    bool DFSvisit[V+1];
    vector<int> adj[V+1];
    vector<int> visit[V+1];
    for(int i = 0; i < E; i++){
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for(int i = 1; i <= V; i++){
        sort(adj[i].begin(), adj[i].end());
        if(adj[i].size() % 2)
            evenDegree = false;
        DFSvisit[i] = false;
    }
    if(evenDegree){
        DFS(adj, DFSvisit, 1);
        for(int i = 1; i <= V; i++){
            if(DFSvisit[i] == false)
                connect = false;
        }
        if(connect){
            EulerianCircuit(adj, visit, 1);
            while(circuit.size() > 0){
                rCircuit.push_back(circuit.back());
                circuit.pop_back();
            }
            while(rCircuit.size() > 0){
                cout << rCircuit.back() << " ";
                rCircuit.pop_back();
            }
            cout << "1 ";
            return 0;
        }
    }
    cout << "not exist" << endl;
    return 0;
}