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
Problem Description



Given a linked list A, remove the B-th node from the end of the list and return its head.

For example, Given linked list: 1->2->3->4->5, and B = 2. After removing the second node from the end, the linked list becomes 1->2->3->5.

NOTE: If B is greater than the size of the list, remove the first node of the list.

NOTE: Try doing it using constant additional space.



Problem Constraints
 1 <= |A| <= 106



Input Format
 The first argument of input contains a pointer to the head of the linked list.

 The second argument of input contains the integer B.



Output Format
 Return the head of the linked list after deleting the B-th element from the end.



Example Input
 Input 1:

A = [1, 2, 3, 4, 5]
B = 2
 Input 2:

A = [1]
B = 1


Example Output
 Output 1:

[1, 2, 3, 5]
 Output 2:

 []


Example Explanation
Explanation 1:

In the first example, 4 is the second last element.
Explanation 2:

In the second example, 1 is the first and the last element.


*/

/* LINK - Explanation by ChatGPT of below algorithm :

This C code aims to remove the nth node from the end of a singly-linked list. Let's break down how it accomplishes this:

The function `removeNthFromEnd` takes in the head pointer of a linked list `A` and an integer `B`, representing the position of the node to remove from the end.

- Two pointers, `slow` and `fast`, both initially pointing to the head of the list (`A`), are used to identify the node to be removed.
- Initially, the `fast` pointer moves `B + 1` steps forward. This creates a gap of `B` nodes between the `slow` and `fast` pointers.
- Then, both pointers move forward simultaneously until `fast` reaches the end of the list.
- At this point, the `slow` pointer is at the node just before the node to be removed.
- Finally, the node to be removed is detached by adjusting the `slow->next` pointer to skip the next node, effectively removing the nth node from the end.

However, there's a potential issue in the code: if the value of `B` equals the number of nodes in the list, it will return `head->next`, effectively removing the first node. A check could be added to handle this specific case more accurately.

Remember, this code assumes that `B` is a valid positive integer indicating the position of the node to remove from the end of the list.
*/
typedef struct node {
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
} node;

void printList(node *A)
{
    while (A)
    {
        cout << A->val << " ";
        A = A->next;
    }
    cout << endl;
}

class Solution{
public :
    node *remove(node *A, int B);
};

node * Solution::remove(node * A, int B){
    node *head = A;
    node *slow = A, *fast = A;
    B++;
    while(B && fast != NULL) {
        fast = fast->next;
        B--;
    }

    if(B)
        return head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
node a(1), b(2), c(3), d(4), e(5);
a.next = &b;
b.next = &c;
c.next = &d;
d.next = &e;
cout << "List before removal :" << endl;
printList(&a);
S->remove(&a, 2);
cout << "List after removal :" << endl;
printList(&a);

return 0 ;
}