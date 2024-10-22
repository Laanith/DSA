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
21. Merge Two Sorted Lists
Solved
Easy
Topics
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

*/

typedef struct ListNode {
    int val;
    ListNode * next;

    ListNode(int x) : val(x), next(NULL) {};
} Node;

ListNode* vectorToList(const vector<int>& vec) {
    if (vec.empty()) return nullptr;
    ListNode* head = new ListNode(vec[0]);
    ListNode* current = head;
    for (int i = 1; i < vec.size(); i++) {
        current->next = new ListNode(vec[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
 
 
class Solution{
public :
    Node * merge(Node * list1, Node * list2){
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        Node * d = new Node(-1);
        Node * t = d;
        while(list1 && list2){
            if(list1->val < list2->val){
                auto it = new Node(list1->val);
                t->next = it;
                t = t->next;
                list1 = list1->next;
            }
            else {
                auto it = new Node(list2->val);
                t->next = it;
                t = t->next;
                list2 = list2->next;
            }
        }

        while(list1){
            auto it = new Node(list1->val);
            t->next = it;
            t = t->next;
            list1 = list1->next;
        }

        while(list2){
            auto it = new Node(list2->val);
            t->next = it;
            t = t->next;
            list2 = list2->next;
        }

        Node * head = d->next;
        delete d;
        return head;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,4,6,7,66,137,4536};
vi B = {2, 5,7,35,354,767,121119208};

Node * a = vectorToList(A);
Node * b = vectorToList(B);
printList(a);
printList(b);

Node * c = S->merge(a,b);
printList(c);


return 0 ;
}