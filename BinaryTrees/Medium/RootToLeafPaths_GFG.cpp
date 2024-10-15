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
Root to Leaf Paths
Difficulty: MediumAccuracy: 43.65%Submissions: 112K+Points: 4
Given a Binary Tree of nodes, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Example 1:

Input:
       1
    /     \
   2       3
Output: 
1 2 
1 3 
Explanation: 
All possible paths:
1->2
1->3
Example 2:

Input:
         10
       /    \
      20    30
     /  \
    40   60
Output: 
10 20 40 
10 20 60 
10 30 
Your Task:
Your task is to complete the function Paths() which takes the root node as an argument and returns all the possible paths. (All the paths are printed in new lines by the driver's code.)

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1<=n<=104

Seen this question in a real interview before ?
Yes
No
Company Tags
PaytmAmazon
*/
 
typedef struct Node {
    int data;
    Node * left;
    Node * right;

    Node(int x){ data=x; left=right=nullptr;}

} Node;
 
class Solution{
private:
    void traverse(Node * root, vi temp, vvi & ans){
        if(!root->left && !root->right){
            temp.push_back(root->data);
            ans.push_back(temp);
            return;
        }
        temp.push_back(root->data);
        if(root->left) traverse(root->left, temp, ans);
        if(root->right) traverse(root->right, temp, ans);
        return;
    }
public :
    vvi Paths(Node * root){
        vi temp;
        vvi ans;
        traverse(root, temp, ans);
        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto r = new Node(10);
r->left = new Node(20);
r->right = new Node(30);
r->left->left = new Node(40);
r->left->right= new Node(50);
pvvi(S->Paths(r));
 
return 0 ;
}