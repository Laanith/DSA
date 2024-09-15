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
Sort a stack
Difficulty: MediumAccuracy: 69.19%Submissions: 124K+Points: 4
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/
 
 
class Solution{
public :
    void insert(si & st, int s){
        if(st.empty() || s>st.top()){ st.push(s); return;}
        while(st.top() > s){
            int t = st.top();
            st.pop();
            insert(st, t);
        }
        return;
    }

    void sort(si & st, int prev){
        int s1 = st.top();
        st.pop();
        sort(st,s1);
        insert(st,s1);
        
    }

    void Sort(si & st){
        sort(st, -1);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
si st;
st.push(3);
st.push(10);
st.push(4);
st.push(5);
S->Sort(st);
while(!st.empty()){cout<<st.top()<<" "; st.pop(); } cout<<endl;
 
return 0 ;
}