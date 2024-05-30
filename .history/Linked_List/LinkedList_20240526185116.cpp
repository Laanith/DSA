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
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}


typedef struct Node {
    int val;
    Node * next = NULL;

    Node(int x , Node  * nextptr){
        val = x;
        next = nextptr;
    }
} Node;


class LinkedList{



    public:
        Node * head;
        Node * lastNode;

        LinkedList(int head_node_val){
            head->val = head_node_val;
            head->next = NULL;
            lastNode = head;
        }

        void PrintList(){
            auto temp = head;
            while(temp !=NULL){
                cout<<temp->val<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }


        void AddNode(int x){
            cout<<lastNode->val<<endl;
            auto temp = Node(x,NULL);
            cout<<temp.val<<" "<temp.next<<endl;
            lastNode->next = &temp;
            lastNode = &temp;
        }
};



 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);

auto LL = LinkedList(3);
LL.AddNode(5);
LL.PrintList();
LL.AddNode(7);
LL.PrintList();
 
 
return 0 ;
}