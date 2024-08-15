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
1011. Capacity To Ship Packages Within D Days
Medium
Topics
Companies
Hint
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

 

Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1
 

Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
*/
 
 
class Solution{
public :
    int check(vi & packages, int capacity, int days){
        
        int n = packages.size();
        int dayCnt = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(sum + packages[i] <= capacity){
                sum+=packages[i];
            }
            else {
                dayCnt++;
                sum = packages[i];
            }
        }

        return dayCnt;

    }

    int shipWithinDays(vi & weights, int days){
       
        int sum = 0;
        int n = weights.size();
        int maxi = imi;
        for(int i = 0 ; i < n; i++){
            maxi = max(maxi, weights[i]);
            sum+=weights[i];
        }

        int l =maxi, r = sum, mid, ans = -1;
        while (l<=r)
        {
            mid = l + (r-l)/2;
            if(check(weights, mid, days) <= days){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi A = {1,2,3,4,5,6,7,8,9,10};
pint(S->shipWithinDays(A,5));
A = {3,2,2,4,1,4};
pint(S->shipWithinDays(A,3));
A = {1,2,3,1,1};
pint(S->shipWithinDays(A,4)); 

 
return 0 ;
}