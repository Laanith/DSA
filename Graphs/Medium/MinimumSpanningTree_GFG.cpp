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
Minimum Spanning Tree
Difficulty: MediumAccuracy: 47.82%Submissions: 137K+Points: 4
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Example 1:

Input:
3 3
0 1 5
1 2 3
0 2 1

Output:
4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Example 2:

Input:
2 1
0 1 5

Output:
5
Explanation:
Only one Spanning Tree is possible
which has a weight of 5.
 

Your task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function spanningTree() which takes a number of vertices V and an adjacency list adj as input parameters and returns an integer denoting the sum of weights of the edges of the Minimum Spanning Tree. Here adj[i] contains vectors of size 2, where the first integer in that vector denotes the end of the edge and the second integer denotes the edge weight.

Expected Time Complexity: O(ElogV).
Expected Auxiliary Space: O(V2).
 

Constraints:
2 ≤ V ≤ 1000
V-1 ≤ E ≤ (V*(V-1))/2
1 ≤ w ≤ 1000
The graph is connected and doesn't contain self-loops & multiple edges
*/



class DisjointSet{
    vi rank,size,parent;
    public :
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(size[ultimateParentOfu] < size[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
                size[ultimateParentOfv] += size[ultimateParentOfu];
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                size[ultimateParentOfu] += size[ultimateParentOfv];
            }
        }


        void unionByRank(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(ultimateParentOfu == ultimateParentOfv) return;
            if(rank[ultimateParentOfu] < rank[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
            }
            else if (rank[ultimateParentOfv] < rank[ultimateParentOfu]){
                parent[ultimateParentOfv] = ultimateParentOfu;
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                rank[ultimateParentOfu]++;
            }
        }

};


class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pi>> edges;
        for(int i = 0 ; i < V; i++){
            for(auto it : adj[i]){
                edges.push_back({it[1], {i, it[0]}});
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DisjointSet ds(V);
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findParent(u)!=ds.findParent(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
int V = 3;
vvi adj[V];
adj[0].pb({1, 5}); 
adj[0].pb({2, 1});
adj[1].pb({2, 3}); 
pint(S->spanningTree(3, adj));


 
return 0 ;
}