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


typedef struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {};
} treenode;


/*!SECTION : Problem Description ::
Given a binary tree A, invert the binary tree and return it. 

Inverting refers to making left child as the right child and vice versa.

Input 1:

 
     1
   /   \
  2     3

Output 1:

 
     1
   /   \
  3     2

*/



class Solution{
    public :
        treenode * invert(treenode * A);
};

void swapper(treenode*A){
    if(A==NULL) return;
    else {
        auto l = A->left;
        auto r = A->right;
        swapper(l);
        swapper(r);
        A->left = r;
        A->right = l;
    }
}

treenode * Solution::invert(treenode * A){
    swapper(A);
    return A;
}




int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}