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
Given a binary tree, return the preorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,2,3].

Using recursion is not allowed.

*/

///// First I try to code things out using recursion
  
  typedef struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  } treenode;
 




 
 
void solve(treenode*A, vector<int>&v){
    if(A == NULL) return;
    else {
        v.push_back(A->val);
        solve(A->left, v);
        solve(A->right, v);
    }
}



class Solution{
    public :
        vi preorderTraversalUsingRecursion(treenode*A);
        vi preorderTraversalWithoutRecursion(treenode*A);
};


vector<int> Solution::preorderTraversalUsingRecursion(treenode* A) {
    vector<int> v;
    solve(A, v);
    return v;
}


vector<int> Solution::preorderTraversalWithoutRecursion(TreeNode* root)
{
   
    vector<int>v;
    if(root==NULL)
        return v;
    stack<TreeNode*>s;
    s.push(root);
    while(s.empty()==false)
    {
        TreeNode* curr=s.top();
        v.push_back(curr->val);
        s.pop();
       
        if(curr->right!=NULL)
        {
            s.push(curr->right);
        }
        if(curr->left!=NULL)
        {
            s.push(curr->left);
        }
    }
return v;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}