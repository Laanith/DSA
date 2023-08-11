#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
using namespace std;

/*!SECTION : Problem Description ::

Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.
*/

class Solution{
public :
    int Solve(vi &A, int B);
};

int Solution::Solve(vi &A, int B){
    priority_queue<int> pq;
    for(auto x : A){
        pq.push(x);
    }
    int profits = 0;
    while(B--){
        int pr = pq.top();
        pq.pop();
        pq.push(pr - 1);
        profits += pr;
    }

    return profits;
}
 



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1, 4};
auto B = 2;
cout << S->Solve(A, B);

return 0 ;
}