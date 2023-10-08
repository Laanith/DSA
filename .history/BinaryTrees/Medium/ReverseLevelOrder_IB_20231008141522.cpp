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
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
} treenode;



/*!SECTION : Problem 
Given a binary tree, return the reverse level order traversal of its nodes values.
 (i.e, from left to right and from last level to starting level).

Input 1:

    3
   / \
  9  20
    /  \
   15   7
   
Output 1:
[15, 7, 9, 20, 3] 
*/



class Solution{
    public :
        vi ReverseLevelOrder(treenode * A);
};


vi Solution::ReverseLevelOrder(treenode *A){
    vi ans;
    auto head = A;
    queue<treenode *> q;
    q.push(head);
    while(!q.empty()){
        auto temp = q.front();
        ans.push_back(temp->val);
        q.pop();
        if(temp->right == NULL ) q.push(temp->right);
        if(temp->left == NULL ) q.push(temp->left); 
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto a = new treenode(3);
auto b = new treenode(9);
auto c = new treenode(20);
auto d = new treenode(15);
auto e = new treenode(7);
a->left = b;
a->right = c;
c->left = d;
d->right = e;
pv(S->ReverseLevelOrder(a));



return 0 ;
}