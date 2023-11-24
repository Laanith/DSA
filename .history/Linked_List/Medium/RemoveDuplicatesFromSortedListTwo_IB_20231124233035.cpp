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
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,

Given 1->2->3->3->4->4->5, return 1->2->5.

Given 1->1->1->2->3, return 2->3.
*/

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x) , next(NULL) {}
} node;

class Solution{
public :
    void printList(node *a);
    node *removeDuplicates(node *A);
};
 
node * findit(node * a){
    if (a == NULL)
        return a;
    node *t = a->next;
    int flag = 0;
    while(t && t->val == a->val){
        t = t->next;
        flag = 1;
    }

    if (flag)
        a = findit(t);
    else
        a->next = findit(t);
    return a;

}

node *Solution::removeDuplicates(node * A){
    auto root = findit(A);
}

void Solution::printList(node * a){
    while(a){
        cout << a->val << " ";
        a = a->next;
    }
    cout << endl;
}

 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}