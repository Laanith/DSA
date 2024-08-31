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
Linked List Insertion At End
Difficulty: BasicAccuracy: 43.96%Submissions: 241K+Points: 1
Given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList and return the modified Linked List.

Examples :

Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 1->2->3->4->5->6
Explanation: 

We can see that 6 is inserted at the end of the linkedlist.
Input: LinkedList: 5->4 , x = 1
Output: 5->4->1
Explanation: 

We can see that 1 is inserted at the end of the linkedlist.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
0 <= number of nodes <= 105
1 <= node->data , x <= 103
*/

typedef struct Node {
    int data;
    Node * next = NULL;
    Node(int x ){ data=x; next = nullptr; }
} Node;

Node * viToLL(vi arr){
    if(arr.empty()) return nullptr;
    Node * head = new Node(arr[0]);
    Node * temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}
 
class Solution{
public :
    Node * insertAtEnd(Node * head, int x){
        if(!head) return new Node(x);
        Node * temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new Node(x);
        return head;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
Node * head = viToLL({1,2,3,4,5,6});
auto t1 = head;
while(t1){cout<<t1->data<<"->"; t1=t1->next;} cout<<"NULL"<<endl;
head = S->insertAtEnd(head, 7);
auto t2 = head;
while(t2){cout<<t2->data<<"->"; t2=t2->next;} cout<<"NULL"<<endl;



 
return 0 ;
}