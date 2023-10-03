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
The first argument is the root node of the binary tree.
The second argument B is an integer equal to the value of k.
Example Input :
  2
 / \
1   3


and k = 2

Example Output:
2
*/


// Approach 1 : Use an empty vector, do inorder traversal and append each node to vector, finally return kth element of vector
// Approach 2 : Use a max priority queue, keep pushing node values, whenever nodes in priority queue exceed k, remove the larger value. Finally after whole tree is 
//traversed, pop the queue to get kth smallest element


typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;


class Solution{
    public :
        
};


int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int>pq;
    return solve(A, pq, B);
}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}