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

*/
 
 
class Solution{

private :
    void dfs(int src, vi adj[], vi & vis, si & st){
        vis[src] = 1;
        for(int neigh : adj[src]){
            if(!vis[neigh]) dfs(neigh, adj, vis, st);
        }
        st.push(src);
        return;
    }


public :
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        si st;
        vi ans;
        vi vis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, adj, vis, st);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
	}
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A[] = {{}, {0}, {0}, {0}};
pv(S->topoSort(4,A));
 
return 0 ;
}