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
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
Expected Time Complexity: O(3*n)
Expected Space Complexity: O(3*n)

Constraint:
1 <=  arr.size <= 105
1 <=  arr[i] <= 100Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
Expected Time Complexity: O(3*n)
Expected Space Complexity: O(3*n)

Constraint:
1 <=  arr.size <= 105
1 <=  arr[i] <= 100Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
Output:11
Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
Expected Time Complexity: O(3*n)
Expected Space Complexity: O(3*n)

Constraint:
1 <=  arr.size <= 105
1 <=  arr[i] <= 100
*/
 




 
class Solution{
public :
   int maxPoint(vvi arr, int n){

    vvi dp(n, vector<int>(3,-1));

    // return solve(n, arr, dp);

   }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vvi x;
S->maxPoint(x, 4);

 
return 0 ;
}