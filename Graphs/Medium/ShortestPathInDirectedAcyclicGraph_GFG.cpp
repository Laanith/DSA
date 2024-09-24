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
Shortest path in Directed Acyclic Graph
Difficulty: MediumAccuracy: 48.48%Submissions: 130K+Points: 4
Given a Directed Acyclic Graph of n vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length m, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :

Input: n = 4, m = 2, edge = [[0,1,2],[0,2,1]]
Output: 0 2 1 -1
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
Input: n = 6, n = 7, edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output: 0 2 3 6 1 5
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
Your Task:You don't need to print or input anything. Complete the function shortest path() which takes an integer N as number of vertices, an integer M as number of edges and a 2D Integer array(or vector) edges as the input parameters and returns an integer array(or vector), denoting the list of distance from src to all nodes.

Expected Time Complexity: O(n+m), where n is the number of nodes and m is edges
Expected Space Complexity: O(n)

Constraint:
1 <= n <= 100
1 <= m <= min((N*(N-1))/2,4000)
0 <= edgei,0,edgei,1 < n
0 <= edgei,2 <=105
*/
 
 
class Solution{
public :
    vi shortestPath(int V, int M, vvi & edges){
        vi dist(V, ima);
        queue<pi> q;
        vector<vector<pair<int,int>>> adj(V);
        for(vi & v : edges){ adj[v[0]].push_back({v[1], v[2]}); }
        dist[0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            int nodeDist = q.front().second;
            q.pop();
            for(pi neigh : adj[node]){
                int neighNode = neigh.first;
                int neighDist = neigh.second;
                if(dist[neighNode] > nodeDist + neighDist){
                    dist[neighNode] = neighDist + nodeDist;
                    q.push({neighNode, dist[neighNode]});
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
vvi edge = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
pv(S->shortestPath(6,7,edge));
edge = {{0,1,2},{0,2,1}};
pv(S->shortestPath(4,2,edge));


 
return 0 ;
}