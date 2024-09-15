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
Directed Graph Cycle
Difficulty: MediumAccuracy: 27.88%Submissions: 407K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices and adjacency list adj as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.
In the adjacency list adj, element adj[i][j] represents an edge from i to j.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105


*/
 
//NOTE - the objective is to detect a cycle in a DAG using Kahn's algorithm
 
class Solution{
public :
    bool isCyclic(int V, vi adj[]){
        vi indegree(V, 0);
        vi vis(V, 0);
        qi q;

        for(int i=0; i < V; i++){
            for(int it : adj[i]) indegree[it]++;
        }

        for(int i  = 0; i < V; i++) if(!indegree[i]) q.push(i);

        int cnt=0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(int it : adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }

        return cnt < V;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi adj[4] = {{1}, {2}, {3}, {3}};
cout<<boolalpha<<S->isCyclic(4, adj)<<endl;

 
return 0 ;
}