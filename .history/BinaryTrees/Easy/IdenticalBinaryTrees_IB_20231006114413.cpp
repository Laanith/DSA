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
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

Return  0 / 1  ( 0 for false, 1 for true ) for this problem

Example :

Input : 

   1       1
  / \     / \
 2   3   2   3

Output : 
  1 

*/

typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
} treenode;



class Solution{
    public :
    bool isSameTree(treenode*A, treenode*B);
};

bool Solution::isSameTree(treenode*A,treenode*B){
    if(A ==NULL && B != NULL ) return false;
    else if(A !=NULL && B == NULL ) return false;
    else if(A ==NULL && B == NULL ) return true;
    else {
        if(A->val == B->val ) return true;
    }

    auto leftsubtreesame = isSameTree(A->left,B->left);
    auto rightsubtreesame = isSameTree(A->right, B->right);

    return leftsubtreesame && rightsubtreesame;

}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto a = new treenode(1);
auto a1= new treenode(1);
auto b = new treenode(2);
auto b1= new treenode(2);
auto c = new treenode(3);
auto c1 = new treenode(3);

a->left = b;
b->right = c;
a1->left = b1;
b1->right = c1;

cout<<S->isSameTree(a,a1)<<endl;
cout<<S->isSameTree(a,c1)<<endl;



return 0 ;
}