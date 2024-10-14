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
104. Maximum Depth of Binary Tree
Solved
Easy
Topics
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/
 
typedef struct TreeNode {
    int val;
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
} treenode;

 
class Solution{
public :
    int maxDepth(treenode * root){
        if(!root) return 0;
        int lh=0,rh=0;
        if(root->left) lh = maxDepth(root->left);
        if(root->right) rh = maxDepth(root->right);
        return max(lh,rh)+1;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto r = new treenode(0);
r->left = new treenode(1);
r->right = new treenode(2);
r->left->left = new treenode(3);
r->right->left = new treenode(4);
r->right->left->right = new treenode(5);
pint(S->maxDepth(r));
 
return 0 ;
}