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
19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?


*/

typedef struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {};
} Node;
 
 
class Solution{
public :
    Node * removeNthFromEnd(Node * head, int n){
        Node * dummy = new Node(0);
        dummy->next = head;
        Node * fast = dummy, * slow = dummy;
        while(n--) fast = fast->next;
        while(fast->next){fast = fast->next; slow = slow->next;}
        Node * nodeTodel = slow->next;
        slow->next = slow->next->next;
        delete nodeTodel;

        Node * newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5};
Node * t = new Node(A[0]);
Node * head = t;
for(int i = 1; i < A.size(); i++){
    auto temp = new Node(A[i]);
    t->next = temp;
    t = t->next;
}

auto temp = head;
while(temp){cout<<temp->val<<" "; temp=temp->next;}
cout<<endl;
head = S->removeNthFromEnd(head, 2);

temp = head;
while(temp){cout<<temp->val<<" "; temp=temp->next;}
cout<<endl;


 
return 0 ;
}