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
Given a singly linked list A, determine if it's a palindrome. Return 1 or 0, denoting if it's a palindrome or not, respectively.



Problem Constraints
 1 <= |A| <= 105



Input Format
The first and the only argument of input contains a pointer to the head of the given linked list.



Output Format
 Return 0, if the linked list is not a palindrome.

 Return 1, if the linked list is a palindrome.



Example Input
 Input 1:

A = [1, 2, 2, 1]
Input 2:

A = [1, 3, 2]


Example Output
 Output 1:

 1
 Output 2:

 0


Example Explanation
Explanation 1:

 The first linked list is a palindrome as [1, 2, 2, 1] is equal to its reversed form.
Explanation 2:

 The second linked list is not a palindrom as [1, 3, 2] is not equal to [2, 3, 1].
*/
typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} node;


class Solution{
public :
    bool isPalindrome(node * A);
    void printList(node *A)
    {
        while (A)
        {
            cout << A->val << " ";
            A = A->next;
        }
        cout << endl;
    }
};


bool isPalindrome(node * A){
    vi Ac;
    auto head = A;
    while(head){
        Ac.push_back(head->val);
        head = head->next;
    }
    auto B = Ac;
    reverse(Ac.begin(), Ac.end());
    return B == Ac;
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
node a(3), b(4), c(5), d(4), e(3);
a.next = &b;
b.next = &c;
c.next = &d;
d.next = &e;
cout << "The sequence :" << endl;
S->printList(&a);
cout << S->isPalindrome(&a) << endl;

return 0 ;
}