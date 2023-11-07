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
A conveyor belt has packages that must be shipped from one port to another within B days.

The ith package on the conveyor belt has a weight of A[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within B days.



Problem Constraints
1 <= B <= |A| <= 5 * 105
1 <= A[i] <= 105


Input Format
First argument is array of integers A denoting the weights.

Second argument is the integer B denoting the number of days.



Output Format
Return the least weight capacity of the ship.


Example Input
Input 1:
A = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
B = 5
Input 2:

A = [3, 2, 2, 4, 1, 4]
B = 3


Example Output
Ouput 1:
15
Ouput 2:

6


Example Explanation
Explanation 1:
A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and
splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Explanation 2:

A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
*/

class Solution{
public :
    int solve(vi A, int B);
};
 

 bool check(vi weights, int x, int days){
    int cnt = 0;
    int day = 0;
    for(auto i : weights){
        if(cnt + i <= x)
            cnt += i;
            else {
            day++;
            cnt = i;
            }
    }
    return day < days;
 }

 int Solution::solve(vi weights, int days){
    
 }
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
 
 
return 0 ;
}