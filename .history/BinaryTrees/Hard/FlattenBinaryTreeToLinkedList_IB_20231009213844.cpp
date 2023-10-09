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
void print(string x){cout<<x<<endl;}
typedef struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
} treenode;



/*!SECTION : Problem Description ::
Given a binary tree A, flatten it to a linked list in-place.

The left child of all nodes should be NULL.

Input 2:

         1
        / \
       2   5
      / \   \
     3   4   6
     

Output 2:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/



class Solution{
    public :
       treenode * flattenTree(treenode * A); 
};


treenode * Solution::flattenTree(treenode * A){
    
    treenode *dummy=new treenode(-1);
    treenode *curr=dummy;
    stack<treenode *> st;
    st.push(A);
    while(!st.empty())
    {
        treenode *l=st.top()->left;
        treenode *r=st.top()->right;
        curr->right=st.top();
        st.pop();
        curr->left=NULL;
        curr=curr->right;
        if(r)
        st.push(r);
        if(l)
        st.push(l);
    }
    return(dummy->right);
}


void printflattenedtree(treenode * A){
    if(!A) return;
    if(!A->left) print("You made a stupid tree !");
    else {
        
    }

}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto a = new treenode(1);
auto b = new treenode(2);
auto c = new treenode(3);
auto d = new treenode(4);
auto e = new treenode(5);
auto f = new treenode(6);
a->left = b;
a->right = e;
b->left = c;
b->right = d;
e->right = f;


return 0 ;
}