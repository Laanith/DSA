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
#define vvi vector<vector<int>>
#define pb push_back
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
void pvvi(vvi A)
{
    for (auto v : A)
    {
        pv(v);
    }
}

typedef struct Node
{
    int val;
    Node *next;

    Node(int x, Node *nextPtr = nullptr)
    {
        val = x;
        next = nextPtr;
    }
} Node;

class LinkedList
{

public:
    Node *head = nullptr;
    Node *lastNode = head;
    int size = 0;

    LinkedList(int head_node_val)
    {

        head = new Node(head_node_val);
        lastNode = head;
        size = 1;
    }

    LinkedList(vi A)
    {
        if (A.empty())
            return;
        head = new Node(A[0]);
        size = A.size();
        auto temp = head;
        for (int i = 1; i < A.size(); i++)
        {
            auto tempNode = new Node(A[i]);
            temp->next = tempNode;
            temp = temp->next;
        }
        lastNode = temp;
    }

    void PrintList()
    {
        cout << endl;
        auto temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
        cout << "Size : " << size << endl
             << endl;
    }

    void AddNode(int x)
    {
        Node *temp = new Node(x);
        if (lastNode)
        {
            lastNode->next = temp;
        }
        else
        {
            head = temp;
        }
        lastNode = temp;
        size++;
    }

    void AddNodeAtBeginning(int x)
    {
        Node *tempNode = new Node(x);
        tempNode->next = head;
        head = tempNode;
        if (size == 0)
        {
            lastNode = tempNode;
        }
        size++;
    }

    void DeleteNodeAtBeginning()
    {
        if (head == nullptr)
        {
            lastNode = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        size--;
        delete temp;
    }

    void AddNodesAtBeginning(vi A )
    {
        for (int i = A.size() - 1; i >= 0; i--) {
            AddNodeAtBeginning(A[i]);
        }
    }

    void DeleteNodesAtBeginning(const int numNodes)
    {
        for (int i = 0; i < numNodes && head != nullptr; i++)
        {
            DeleteNodeAtBeginning();
        }
    }


    void DeleteNodeAtEnd(){
        if(size<1) return;
        auto temp = head;
        while(temp->next->next != nullptr){
            temp  = temp->next;
        }

        auto delNode = temp->next;
        lastNode = temp;
        temp->next = nullptr;
        delete delNode;
        size--;

    }


    void Concatenate(LinkedList * other){
        if(head==nullptr && other->head) return;
        lastNode->next = other->head;
        lastNode = other->lastNode;
        size += other->size;
        return;
    }

    void DeleteNodeInMiddle(int index){
        if(size<1 && index>0) return;
        if(index>=size) return;
        int tempIndex = index;
        auto temp = head;
        while(tempIndex--){
            temp = temp->next;
        }
        auto tempHeader = temp->next->next;

    }

    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    LinkedList linkedList(1);
    linkedList.AddNode(3);
    linkedList.AddNode(5);
    linkedList.AddNode(7);
    linkedList.PrintList();

    LinkedList LL = LinkedList({2, 3, 4, 5});

    LL.PrintList();

    LL.AddNodeAtBeginning(1);

    LL.PrintList();

    LL.AddNodeAtBeginning(69);

    LL.PrintList();

    LL.DeleteNodeAtBeginning();

    LL.PrintList();

    LL.AddNodesAtBeginning({68, 69, 70});

    LL.PrintList();

    LL.DeleteNodesAtBeginning(3);

    LL.PrintList();

    LL.DeleteNodeAtEnd();

    LL.PrintList();

    auto x = new LinkedList({134,135,136});

    x->PrintList();

    LL.Concatenate(x);

    LL.PrintList();

    return 0;
}