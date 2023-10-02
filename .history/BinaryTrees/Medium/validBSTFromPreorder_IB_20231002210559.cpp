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
You are given a preorder traversal A, of a Binary Search Tree.

Find if it is a valid preorder traversal of a BST.

Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.

Input 1:

A = [7, 7, 10, 10, 9, 5, 2, 8]

Output 1:

 0

*/



class Solution{
    public :
        int solve(vi &A);
};


void makeBST(vector<int>& A, int &index, int low, int high){

    if(index >= A.size()) return; 

    if(A[index] <= low || A[index] >= high) return; 

    int root = A[index]; // value of root for limits

    index++;

    makeBST(A, index, low, root); //left call, higher limit will be root's data

    makeBST(A, index, root, high); //right call, lower limit will be root's data

}



int Solution::solve(vi &A) {

    int index = 0;

    int low = INT_MIN; //for root node lower limit is

    int high = INT_MAX; // upper limit

    

    makeBST(A, index, low, high);

    if(index < A.size()) return false; // makeBST function returned in between, it was not possible to make a BST

    return true;

}



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}