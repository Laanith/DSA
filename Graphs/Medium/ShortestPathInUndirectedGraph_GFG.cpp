#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define unseti unordered_set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}cout << endl;}



 
 
/*!SECTION : Problem Description ::
Shortest path in Undirected Graph
Difficulty: MediumAccuracy: 49.98%Submissions: 104K+Points: 4
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input:
n = 9, m = 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4

Input:
n = 4, m = 2
edges=[[1,3],[3,0]] 
src=3
Output:
1 1 -1 0

Constraint:
1<=n,m<=104
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)


*/
 
 
class Solution{
public :
    vi shortestPath(vvi & edges, int V, int M, int src){
        vvi adj(V);
        for(vi & v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        vi dist(V, ima);
        queue<pi> q;
        q.push({src,0});
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().first;
            int nodeDist = q.front().second;
            q.pop();
            for(int neigh : adj[node]){
                if(dist[neigh] > nodeDist + 1){
                    dist[neigh] = nodeDist+1;
                    q.push({neigh, dist[neigh]});
                }
            }
        }

        for(int & it : dist) if(it==ima) it = -1;
        return dist;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
pv(S->shortestPath(edges,9,10,0));
edges = {{1,3},{3,0}};
pv(S->shortestPath(edges,4,2,3));
 
return 0 ;
}