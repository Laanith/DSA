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
103. Binary Tree Zigzag Level Order Traversal
Solved
Medium
Topics
Companies
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-100 <= Node.val <= 100

*/

typedef struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
} treenode;
 
 
class Solution{
public :
    vvi zigzagLevelOrder(TreeNode * root){
        vvi ans;
        if(!root) return ans;
        queue<treenode *> q;
        q.push(root);
        // rtl means right to left
        bool rtl = false;
        while(!q.empty()){
            int s = q.size();
            vi temp;
            for(int i = 0; i < s; i++){
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(rtl){
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            else ans.push_back(temp);
            rtl = !rtl;
        }
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto r = new treenode(3);
r->left = new treenode(9);
r->right = new treenode(20);
r->right->left = new treenode(15);
r->right->right = new treenode(7);
pvvi(S->zigzagLevelOrder(r));
 
return 0 ;
}