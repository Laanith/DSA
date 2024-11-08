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
98. Validate Binary Search Tree
Solved
Medium
Topics
Companies
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

typedef struct TreeNode {
    int val;
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){};
} TreeNode;

TreeNode * tree(vi & arr, int l, int r){
        if(l>r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode * root = new TreeNode(arr[mid]);
        root->left = tree(arr, l, mid-1);
        root->right = tree(arr, mid+1,r);
        return root;

    }
TreeNode* build(vi & arr){
    int l = 0, r = arr.size();
    return tree(arr, 0, r-1);
}
 

 
class Solution{
private:
    bool help(TreeNode * root, TreeNode * min, TreeNode * max){
        if(!root) return true;
        if((min && root->val <= min->val) || (max && root->val >= max->val)) return false;
        return help(root->left, min, root) && help(root->right, root, max);
    }

public :
    bool validate(TreeNode * root){
        return help(root, nullptr, nullptr);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi  arr = {1,2,3,4,5,6};
auto tree = build(arr);
cout<<boolalpha<<S->validate(tree)<<endl;
 
return 0 ;
}