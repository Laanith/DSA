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
Dijkstra Algorithm
Difficulty: MediumAccuracy: 50.83%Submissions: 180K+Points: 4
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S. You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 

Note: The Graph doesn't contain any negative weight cycle.

The structure of adjacency list is as follows :-

For Example : adj = {  {{1, 1}, {2, 6}}  , {{2, 3}, {0, 1}}  , {{1, 3}, {0, 6}}  }

Here adj[i] contains a list which contains all the nodes which are connected to the ith vertex. Here adj[0] = {{1, 1}, {2, 6}} means there are two nodes conneced to the 0th node, node 1 with an edge weight of 1 and node 2 with an edge weight of 6 and similarly for other vertices.

Example 1:

Input:
V = 2
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9
Explanation:

The source vertex is 0. Hence, the shortest 
distance of node 0 is 0 and the shortest 
distance from node 1 is 9.
 

Example 2:

Input:
V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
Explanation:

For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function dijkstra()  which takes the number of vertices V and an adjacency list adj as input parameters and Source vertex S returns a list of integers, where ith integer denotes the shortest distance of the ith node from the Source node. Here adj[i] contains a list of lists containing two integers where the first integer j denotes that there is an edge between i and j and the second integer w denotes that the weight between edge i and j is w.

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V2).

Constraints:
1 ≤ V ≤ 1000
0 ≤ adj[i][j] ≤ 1000
1 ≤ adj.size() ≤ [ (V*(V - 1)) / 2 ]
0 ≤ S < V
*/
 
 
//NOTE - Djikstra Algorithm using Priority Queue

class Solution{
public :
    vi djikstra(int V, vvi adj[], int S){
        vi dist(V, ima);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[S]=0;
        pq.push({0,S});
        while(!pq.empty()){
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            for(vi & neigh : adj[node]){
                int neighNode = neigh[0];
                int neighDist = neigh[1];
                int newDist = nodeDist + neighDist;
                if(dist[neighNode] > newDist){
                    dist[neighNode] = newDist;
                    pq.push({newDist, neighNode});
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

 
return 0 ;
}