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
ected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 448K+Points: 4
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

Example 1:

Input:  
V = 5, E = 5
adj = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Example 2:

Input: 
V = 4, E = 2
adj = {{}, {2}, {1, 3}, {2}}
Output: 0
Explanation: 

No cycle in the graph.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isCycle() which takes V denoting the number of vertices and adjacency list as input parameters and returns a boolean value denoting if the undirected graph contains any cycle or not, return 1 if a cycle is present else return 0.

NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)


 

Constraints:
1 ≤ V, E ≤ 105
*/
 
 
class Solution{
public :
    bool detect(int src, vi adj[], vector<bool> & vis){
        vis[src]=true;
        queue<pair<int,int>> q;
        q.push({src, -1});

        while (!q.empty())
        {
            pi p = q.front();
            int node = p.first;
            int parent = p.second;
            q.pop();
            for(int neigh : adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = true;
                    q.push({neigh,node});
                }
                else {
                    if(neigh!=parent) return true;
                 }
            }
        }
        




        return false;
    }

    bool isCycle(int V, vi adj[]){
        vector<bool> vis(V, false);
        for(int i = 0 ; i < V; i++) if(!vis[i]) if(detect(i,adj,vis)) return true;
        return false;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi adj[] = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}} ;
cout<<boolalpha<<S->isCycle(5,adj)<<endl;
vi adj2[] = {{}, {2}, {1, 3}, {2}};
cout<<boolalpha<<S->isCycle(4,adj2)<<endl;


 
return 0 ;
}