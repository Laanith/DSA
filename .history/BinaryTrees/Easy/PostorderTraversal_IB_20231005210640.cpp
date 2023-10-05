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



/*!SECTION : Problem Description ::
Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.

Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the Postorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [3, 2, 1]
Output 2:

 [6, 3, 2, 1]


*/
typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL) ,right(NULL){};

} treenode;

void solve(treenode*A, vi &v){
    if(A==NULL) return;
    else {
        solve(A->left,v);
        solve(A->right,v);
        v.push_back(A->val);
    }
}

class Solution{
    public :
        vi PostorderWithRecursion(treenode *A);
};

vi Solution::PostorderWithRecursion(treenode * A){
    vi x;
    solve(A,x);
    return x;
}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto A = new treenode(1);
auto B = new treenode(2);
auto C = new treenode(3);
auto D = new treenode(6);
B->left = C;
A->left = D;
A->right = B;
pv(S->PostorderWithRecursion(A));

return 0 ;
}