#include <bits/stdc++.h>
#define ll long long
#include <algorithm>
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define PYES cout << "YES" << endl
#define PNO cout << "NO" << endl
#define vs vector<string>
#define qi queue<int>
#define si stack<int>
#define pi pair<int, int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A)
{
    cout << endl;
    for (auto x : A)
        cout << x << ' ';
    cout << endl;
}
void pint(int A) { cout << endl
                        << A << endl; }
void pp(pair<int, int> p) { cout << p.first << ' ' << p.second << endl; }

/*!SECTION : Problem Description ::
Given a singly linked list and an integer K, reverses the nodes of the

list K at a time and returns modified linked list.

NOTE : The length of the list is divisible by K

Example :

Given linked list 1 -> 2 -> 3 -> 4 -> 5 -> 6 and K=2,

You should return 2 -> 1 -> 4 -> 3 -> 6 -> 5

Try to solve the problem using constant extra space.
*/

typedef struct node
{
    int val;
    node *next;
    node(int x) : val(x), next(NULL) {}
} node;

class Solution
{
public:
    node * reverse(node *A, int B);
};

void printList(node *A)
{
    while (A)
    {
        cout << A->val << " ";
        A = A->next;
    }
    cout << endl;
}

node * Solution::reverse(node *A, int B)
{

    if (A == NULL || B == 1)
        return A;

    node *dummy = new node(0);

    dummy->next = A;

    node *prev = dummy;

    node *curr = dummy;

    node *nex = dummy;

    int count = 0;

    while (curr)
    {

        curr = curr->next;

        count++;
    }

    while (count >= B)
    {

        curr = prev->next;

        nex = curr->next;

        for (int i = 1; i < B; i++)
        {

            curr->next = nex->next;

            nex->next = prev->next;

            prev->next = nex;

            nex = curr->next;
        }

        prev = curr;

        count -= B;
    }

    return dummy;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto S = new Solution();
    node a(1), b(2), c(3), d(4), e(5), f(6);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    cout << "List before reversal :" << endl;
    printList(&a);
    S->reverse(&a, 2);
    cout << "List after reversal :" << endl;
    printList(&a);

    return 0;
}