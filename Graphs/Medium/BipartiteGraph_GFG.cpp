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
Bipartite Graph
Difficulty: MediumAccuracy: 31.25%Submissions: 177K+Points: 4
Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.

Know more about Bipartite Graph: - https://www.geeksforgeeks.org/what-is-bipartite-graph/

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105
*/
 
 
class Solution {
    
private:
    bool dfs(int node, int col, vi & color, vi adj[]){
        
        color[node] = col;
        for(int neigh : adj[node]){
            if(color[neigh]==-1){
                if(dfs(neigh, !col, color, adj)==false) return false;
            }
            else if(color[neigh]==col){
                 return false;
            }
        }
        
        return true;
        
    }
    
    
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vi color(V, -1);
	    
	    for(int i = 0; i < V; i++){
	        if(color[i]==-1){
	            if(dfs(i,0,color,adj)==false) return false;
	        }
	    }
	    
	    return true;
	    
	}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi adj[] = {{2,3}, {3}, {0,3}, {0,1,2}};
cout<<boolalpha<<S->isBipartite(4,adj)<<endl;
vi adj2[] = {{1}, {0,2}, {1}};
cout<<boolalpha<<S->isBipartite(3,adj2)<<endl;

 
return 0 ;
}