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

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){};
} treenode;

/*!SECTION : Problem Description ::

Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

Input :
               1
             /   \
           2       3
         /   \       \
        4     5       2
                     /  \
                    4    5


Output : 1
Explanation :
    2
  /   \
 4     5
is the duplicate sub-tree.
*/

class Solution{
    public :
        int dupSub(treenode *A);
};

string helper(treenode *A, set<string> &s){
    if(A == NULL)
        return "$";

    auto lstr = helper(A->left, s);
    auto rstr = helper(A->right, s);
    if(lstr == "#" || rstr == "#")
        return "#";


    string k =  to_string(A->val) + lstr + rstr;
    if( k.size() > 3  && s.find(k) != s.end()){
        return "#";
    }

    s.insert(k);
    return k;
}

int Solution::dupSub(treenode * A){
        set<string> s;
        return helper(A, s) == "#" ? 1 : 0;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto a = new treenode(1);
auto b = new treenode(2);
auto c = new treenode(4);
auto d = new treenode(5);
auto e = new treenode(3);
auto f = new treenode(2);
auto g = new treenode(4);
auto h = new treenode(5);
a->left = b;
a->right = e;
b->left = c;
b->right = d;
e->left = f;
f->left = g;
f->right = h;
pint(S->dupSub(a));

return 0 ;
}