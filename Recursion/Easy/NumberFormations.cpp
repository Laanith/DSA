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
Here is the extracted text from the image:

---

**Numbers Formation:**

Given three integers X, Y, and Z, your task is to find the sum of all the numbers formed having 4 at most X times, 5 at most Y times, and 6 at most Z times.

Output the sum modulo \(10^9 + 7\).

**Input**  
The first line of input contains three integers \(x, y, z\). \((1 \leq x, y, z \leq 60)\)

**Output**  
Output the sum of all the numbers formed.

**Examples**

| input | output |
|-------|--------|
| 1 1 1 | 3675   |
| 0 0 0 | 0      |

**Note**  
For test case 1:

Explanation:  
4 + 5 + 6 + 45 + 54 + 56 + 65 + 46 + 64 + 456 + 465 + 546 + 564 + 645 + 654 = 3675
*/


const int MOD = 1e9 + 7;

void generateNumbers(int x, int y, int z, int used4, int used5, int used6, long long current, long long &sum) {
    // Add current number to sum if it's not zero
    if(current != 0) {
        sum = (sum + current) % MOD;
    }
    
    // Try adding 4
    if(used4 < x) {
        generateNumbers(x, y, z, used4+1, used5, used6, current*10 + 4, sum);
    }
    
    // Try adding 5
    if(used5 < y) {
        generateNumbers(x, y, z, used4, used5+1, used6, current*10 + 5, sum);
    }
    
    // Try adding 6
    if(used6 < z) {
        generateNumbers(x, y, z, used4, used5, used6+1, current*10 + 6, sum);
    }
}

 
class Solution {
    int MOD = 1e9 + 7;

public:
    int solve(int x, int y, int z) {
    long long sum = 0;
    generateNumbers(x, y, z, 0, 0, 0, 0, sum);
    return sum;
}
};


 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
pint(S->solve(1,1,1));
 
return 0 ;
}