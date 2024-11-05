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
3067. Count Pairs of Connectable Servers in a Weighted Tree Network
Solved
Medium
Topics
Companies
Hint
You are given an unrooted weighted tree with n vertices representing servers numbered from 0 to n - 1, an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional edge between vertices ai and bi of weight weighti. You are also given an integer signalSpeed.

Two servers a and b are connectable through a server c if:

a < b, a != c and b != c.
The distance from c to a is divisible by signalSpeed.
The distance from c to b is divisible by signalSpeed.
The path from c to b and the path from c to a do not share any edges.
Return an integer array count of length n where count[i] is the number of server pairs that are connectable through the server i.

 

Example 1:


Input: edges = [[0,1,1],[1,2,5],[2,3,13],[3,4,9],[4,5,2]], signalSpeed = 1
Output: [0,4,6,6,4,0]
Explanation: Since signalSpeed is 1, count[c] is equal to the number of pairs of paths that start at c and do not share any edges.
In the case of the given path graph, count[c] is equal to the number of servers to the left of c multiplied by the servers to the right of c.
Example 2:


Input: edges = [[0,6,3],[6,5,3],[0,3,1],[3,2,7],[3,1,6],[3,4,2]], signalSpeed = 3
Output: [2,0,0,0,0,0,2]
Explanation: Through server 0, there are 2 pairs of connectable servers: (4, 5) and (4, 6).
Through server 6, there are 2 pairs of connectable servers: (4, 5) and (0, 5).
It can be shown that no two servers are connectable through servers other than 0 and 6.
 

Constraints:

2 <= n <= 1000
edges.length == n - 1
edges[i].length == 3
0 <= ai, bi < n
edges[i] = [ai, bi, weighti]
1 <= weighti <= 106
1 <= signalSpeed <= 106
The input is generated such that edges represents a valid tree.

*/

void dfs(pi adjNode, int parent, int sum, int k, vi & count, vector<vector<pi>> & adj, int sig){
    int node = adjNode.first;
    int wt = adjNode.second;
    int newSum = sum + wt;
    if(newSum%sig==0) count[k]++;
    auto adjL = adj[node];
    if(adjL.size()<2) return;
    for(pi it : adjL){
        if(it.first==parent) continue;
        dfs(it,node,newSum,k,count,adj,sig);
    }
}
 
 
class Solution{
public :
    vi countPairsOfConnectableServers(vvi & edges, int sig){
        int V = edges.size()+1;
        vector<vector<pi>> adj(V);
        for(auto edge : edges){
            int a = edge[0], b = edge[1], wt = edge[2];
            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }
        vi ans(V, 0);
        for(int i = 0; i < V; i++){
            auto adjNodes = adj[i];
            if(adjNodes.size()<2) {cout<<"Skipping node : "<<i<<endl; continue;}
            vi count(adjNodes.size(), 0);
            for(int k = 0; k < adjNodes.size(); k++){
                dfs(adjNodes[k], i, 0, k, count, adj, sig);
            }
            cout<<i<<endl;
            pv(count);
            int s = count.size();
            for(int p = 0; p < s; p++){
                for(int q = p+1; q < s; q++){
                    if(count[p] && count[q]) ans[i]+=(count[p]*count[q]);
                }
            }
        }

        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vvi edges = {{0,6,3},{6,5,3},{0,3,1},{3,2,7},{3,1,6},{3,4,2}};
pv(S->countPairsOfConnectableServers(edges, 3));

return 0 ;
}