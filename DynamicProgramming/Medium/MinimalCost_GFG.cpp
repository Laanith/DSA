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
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size
#define vvi vector<vector<int>>
#define pb push_back
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
1<= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104


*/
 
 
class Solution{
public :
int minimizeCost(vector<int>& arr, int& k) {
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = 0;
        for(int i = 1; i < n ; i++){
            int minEnergy = INT_MAX;
            for(int r = 1 ; r <= k ; r++){
                if(i-r>=0){
                    int energy = dp[i-r] + abs(arr[i]-arr[i-r]);
                    minEnergy = min(minEnergy, energy);
                }
            }
            
            dp[i]=minEnergy;
        }

        
        return dp[n-1];
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {10,30,40,50,20};
int k = 3;
pint(S->minimizeCost(A,k));
vi B = {10,20,10};
int k_n = 1;
pint(S->minimizeCost(B,k_n));

 
return 0 ;
}