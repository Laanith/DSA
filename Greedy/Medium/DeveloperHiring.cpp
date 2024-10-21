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


You are tasked with hiring developers for a project that requires exactly **N** front-end developers and exactly **M** back-end developers. There are **N + M** candidates, and each candidate can work in either role, but not both.

You are given the cost of hiring each candidate for front-end and back-end development. Your goal is to minimize the total cost of hiring exactly **N** front-end developers and **M** back-end developers.

### Input:
- **N**: An integer representing the number of front-end developers required.
- **M**: An integer representing the number of back-end developers required.
- **F**: A list of size **N + M** where the i-th element represents the cost of hiring the i-th developer as a front-end developer.
- **B**: A list of size **N + M** where the i-th element represents the cost of hiring the i-th developer as a back-end developer.

### Output:
- Return an integer representing the minimum total cost to hire exactly **N** front-end developers and **M** back-end developers.

### Constraints:
- 1 ≤ N, M ≤ 1000
- 1 ≤ F[i], B[i] ≤ 10^6

### Example:

**Example 1:**

```
Input:
N = 2
M = 2
F = [4, 5, 6, 3]
B = [7, 3, 4, 2]

Output:
9
```

**Explanation:**
- You need 2 front-end developers and 2 back-end developers.
- Assign developer 1 (cost for front-end: 4, back-end: 7) as a front-end developer.
- Assign developer 2 (cost for front-end: 5, back-end: 3) as a back-end developer.
- Assign developer 3 (cost for front-end: 6, back-end: 4) as a front-end developer.
- Assign developer 4 (cost for front-end: 3, back-end: 2) as a back-end developer.
- The minimum total cost is 4 + 5 + 3 + 2 = 9.



*/

bool compare(const pi & a, const pi & b){
    if(a.second==b.second) return a.first < b.first;
    return a.second < b.second;
}
 
 
class Solution{
public :
    int solve(int N, int M, vi & F, vi & B){
        vector<pi> costD;
        for(int i = 0 ; i < N+M;i++) costD.push_back({i, abs(F[i]-B[i])});
        sort(costD.begin(), costD.end(), compare);
        int cost =0, fh = 0, bh = 0;
        for(auto & p : costD){
            int idx = p.first;
            int gain = p.second;
            if((fh < N && (F[idx] <= B[idx])) || bh==M){cost+=F[idx]; fh++;}
            else if(bh<M) {cost+=B[idx]; bh++;}
        }
        return cost;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

 
return 0 ;
}