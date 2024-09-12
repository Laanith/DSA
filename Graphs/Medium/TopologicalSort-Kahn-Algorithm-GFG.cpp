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
Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 234K+Points: 4
Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

 

In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.

 

Example 1:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
Example 2:

Input:

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 5, 4, 2, 1, 3, 0.
Your Task:
You don't need to read input or print anything. Your task is to complete the function topoSort()  which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns an array consisting of the vertices in Topological order. As there are multiple Topological orders possible, you may return any of them. If your returned topo sort is correct then the console output will be 1 else 0.

Expected Time Complexity: O(V + E).
Expected Auxiliary Space: O(V).

Constraints:
2 ≤ V ≤ 104
1 ≤ E ≤ (N*(N-1))/2


*/
 
 
class Solution{
public :
    vi topoSort(int V, vi adj[]){
        queue<int> q;
        int indegree[V] = {0};
        for(int i = 0 ; i < V; i++){
            for(int it : adj[i]) indegree[it]++;
        }

        for(int i = 0; i < V; i++) if(!indegree[i]) q.push(i);

        vi ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neigh : adj[node]){
                indegree[neigh]--;
                if(!indegree[neigh]) q.push(neigh);
            }
        }

        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi adj[] = {{}, {0}, {0}, {0}};
pv(S->topoSort(4, adj));

 
return 0 ;
}