#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define seti set<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 
*/


typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
} treenode;
 
 
class Solution {
public:
    void dfs(TreeNode * node, string s, vector<string> & v_string){
        string n_string = (s + "->" + to_string(node->val));
        if(!node->left && !node->right){
            v_string.push_back(n_string);
            return;
        }
        if(node->left) dfs(node->left, n_string, v_string);

        if(node->right) dfs(node->right, n_string, v_string);

        return;
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v_string;
        string str = to_string(root->val);
        if(root->left) dfs(root->left, str, v_string);
        if(root->right) dfs(root->right, str, v_string);
        return v_string;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
treenode * node_1 = new treenode(1);
treenode * node_2 = new treenode(2);
treenode * node_3 = new treenode(3);
treenode * node_4 = new treenode(4);
treenode * node_5 = new treenode(5);
treenode * node_6 = new treenode(6);
treenode * node_7 = new treenode(7);
treenode * node_8 = new treenode(8);

node_1->left = node_2;
node_1->right = node_3;
node_2->left = node_4;
node_2->right = node_5;
node_3->left = node_6;
node_3->right = node_7;
node_4->left = node_8;

vs ans = S->binaryTreePaths(node_1);
for (auto x : ans) cout<<x<<endl;
 
return 0 ;
}