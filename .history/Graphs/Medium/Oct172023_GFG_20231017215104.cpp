#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
Given a directed graph, determine whether a vertex j is reachable from another vertex i for all vertex pairs (i, j) in the given graph. Here, vertex j is reachable from another vertex i means that there is a path from vertex i to j. The reachability matrix is called the transitive closure of a graph. The directed graph is represented by an adjacency matrix where there are N vertices.


Input: N = 4
graph = {{1, 1, 0, 1},
         {0, 1, 1, 0},
         {0, 0, 1, 1},
         {0, 0, 0, 1}}
Output: {{1, 1, 1, 1},
         {0, 1, 1, 1},
         {0, 0, 1, 1},
         {0, 0, 0, 1}}
Explanation:
The output list shows the reachable indexes.
*/

class Solution
{
public:
    void dfs(int i, int j, vector<int> adj[],
             vector<vector<int>> &vec)
    {
        vec[i][j] = 1;
        for (auto it : adj[j])
        {
            if (!vec[i][it])
            {
                dfs(i, it, adj, vec);
            }
        }
    }
    vector<vector<int>>
    transitiveClosure(int n, vector<vector<int>> graph)
    {
        // code here
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[i][j] == 1 && i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<vector<int>> vec(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dfs(i, i, adj, vec);
        }
        return vec;
    }
};



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi graph = {{1, 1, 0, 1},
             {0, 1, 1, 0},
             {0, 0, 1, 1},
             {0, 0, 0, 1}};
pvvi(S->transitiveClosure(graph, 4));

return 0;
}