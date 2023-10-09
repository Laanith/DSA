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
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}

typedef struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
} treenode ;


/*!SECTION : Problem Description ::
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor: the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Note:
You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn't exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, and helper functions, and can modify the node struct but, you can't add a parent pointer.

Example input ::
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4


B = 6
C = 7


Example output : 
5




*/



class Solution{
    public :
        int LeastCommonAncestor(treenode * A, int B, int C); 
};

bool checkDescendant(treenode * A, int B){
    if(!A) return false;
    else if (A->val == B ) return true;
    else return checkDescendant(A->left, B)||checkDescendant(A->right,B);
}

treenode * solve(treenode * A, int B, int C){
    if(!A) return NULL;   
    if(A->val == B) return A;
    if(A->val == C) return A;
    auto l = solve(A->left, B,C);
    auto r = solve(A->right ,B,C);
    if (l && r) return A;
    if(l) return l;
    if(r) return r;
    return NULL;
}

int Solution::LeastCommonAncestor(treenode * A, int B,int C){
    bool bothexist  = false;
    bothexist = checkDescendant(A,B)&&checkDescendant(A,C);
    auto ans = solve(A,B,C);
    if(ans && bothexist) return ans->val;
    return -1;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto a = new treenode(3);
auto b = new treenode(5);
auto c = new treenode(1);
auto d = new treenode(6);
auto e = new treenode(2);
auto f = new treenode(0);
auto g = new treenode(8);
auto h = new treenode(7);
auto i = new treenode(4);

a->left = b;
a->right = c;
b->left=d ;
b->right = e;
c->left = f;
c->right = g;
e->left = h;
e->right = i;
pint(S->LeastCommonAncestor(a,6,7));

return 0 ;
}