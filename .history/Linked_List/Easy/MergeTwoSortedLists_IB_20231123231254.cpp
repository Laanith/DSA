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
Merge two sorted linked lists and return it as a new list.

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(NULL) {}
} node;

class Solution{
public :
    node *mergeTwoLists(node *A, node *B);
    void printList(node *A);
};
 
node * Solution::mergeTwoLists(node * A, node * B){
    node *dummy = &node(0);
    auto temp = dummy;
    while(A && B){
        if(A->val <= B->val ){
            temp->next = A;
            A = A->next;
        }
        else {
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }

    if (A)
    {
        temp->next = A;
    }
    if (B)
    {
        temp->next = B;
    }

    auto result = dummy->next;
    delete dummy;
    return result;
}


void printList(node * A){
    cout << "List : " << endl;
    while(A){
        cout << A->val << " -> ";
        A = A->next;
    }
    cout << endl;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
node a(1), b(0), c(1), d(1), e(0), f(1), g(0), h(0);
a.next = &b;
b.next = &c;
c.next = &d;
d.next = &e;
e.next = &f;
f.next = &g;
g.next = &h;
S->printList(a2);
auto result = S->mergeTwoLists(a1, a2);
S->printList(result);

return 0;
}