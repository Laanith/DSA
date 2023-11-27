#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}

/*!SECTION : Problem Description ::
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

typedef struct node{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
} node;

class Solution{
public :
    node * reverse(node *A, int B);
};

node * Solution::reverse(node * A, int B ){
    if (B == 1 || !A) return NULL;
    node *dummy = new node(0);
    dummy->next = A;
    node *prev = dummy, *curr = dummy;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}