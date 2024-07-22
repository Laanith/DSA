#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v. Find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the input graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.


Example 1:

Input:
V = 5, E = 4
adj = {{1,2,3},{},{4},{},{}}

*/
 
 
class Solution {

    public :

    vi bfs(int V, vi adj[]);
};


vi Solution::bfs(int V, vi adj[]){

    vi ans;
    vector<bool> visited(V);
    qi q;
    q.push(0);
    ans.push_back(0);
    visited[0]=true;


    while(!q.empty()){
        int currNode = q.front();
        q.pop();

        for(auto node : adj[currNode]){
            if(!visited[node]){
                visited[node]=true;
                ans.push_back(node);
                q.push(node);
            }
        }
    }

    return ans;

}

 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);

int V,E;
cin>>V>>E;
vi adj[V];
for(int i=0; i < E; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}

auto S = new Solution();


pv(S->bfs(V, adj));
 
 
return 0 ;
}