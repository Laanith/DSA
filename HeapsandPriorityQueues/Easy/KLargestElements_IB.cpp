#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<deque>
#define ll long long
#define vi vector<int>
#include<utility>
#include<assert.h>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
 
 
using namespace std;

class Solution{
    public :
    vi Solve(vector<int> &A, int B);
};

vi Solution::Solve(vi &A,int B){
    priority_queue<int> pq;
    vi C;
    for(auto a : A){
        pq.push(a);
    }

    for (int i = 0; i < B; i++){
        C.push_back(pq.top());
        pq.pop();
    }

    sort(C.begin(), C.end());
    return C;
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

vi A = {11, 3, 4, 6};
auto B = 3;
auto S = new Solution();
for(int k : S->Solve(A,B)){
        cout << k << " ";
}

return 0 ;
}