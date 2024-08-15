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
Problem statement
You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.



You are also given an integer ‘k’.



You have to place 'k' new gas stations on the X-axis.



You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.



Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

Find the minimum value of dist.


Example:
Input: ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}.

Answer: 0.5

Explanation:
We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 

Thus the value of 'dist' will be 0.5. It can be shown that we can't get a lower value of 'dist' by placing 6 gas stations.


Note:
You will only see 1 or 0 in the output where:
  1 represents your answer is correct.
  0 represents your answer is wrong. 
Answers within 10^-6 of the actual answer will be accepted.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
5 4
1 2 3 4 5


Expected Answer:
0.5


Output Printed On Console:
1


Explanation of sample output 1:
k = 4, arr = {1,2,3,4,5} 

One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}

Thus the maximum difference between adjacent gas stations is 0.5. 

Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. (Note: 1 will be printed in the output for the correct answer). 


Sample Input 2:
10 1
1 2 3 4 5 6 7 8 9 10


Expected Answer:
1


Output Printed On Console:
1


Explanation of sample output 2:
k = 1, arr = {1,2,3,4,5,6,7,8,9,10} 

One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10} 

Thus the maximum difference between adjacent gas stations is still 1. 

Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this. (Note: 1 will be printed in the output for the correct answer). 


Expected Time Complexity
Try solving this in O(n*log(A)), where A is the maximum value in array 'arr'.


Constraints:
2 <= n <= 10^5
1 <= k <= 10^6 
1 <= arr[i] <= 10^9

Time Limit: 1 sec
*/
 
 
class Solution{
public :
    int placeAbleGasStations(vector<int> & arr, long double dist){
        int cnt = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            int nearDist = (arr[i+1]-arr[i])/dist;
            if(((arr[i+1]-arr[i])/dist)==nearDist*dist) nearDist--;
            cnt+=nearDist;
        }
        return cnt;
    }


    double minimiseMaxDistance(vector<int> &arr, int k){
        long double high = 0;
        long double low = 0;
        int n = arr.size();
        for(int i = 0; i < n-1; i++){
            high = max(high, (long double)(arr[i+1]-arr[i]));
        }

        long double diff = 1e-6, mid;
        while((high-low)>diff){
            mid = low + (high-low)/2.0;
            int k_dash = placeAbleGasStations(arr, mid);
            if(k_dash > k) low = mid;
            else high = mid;
        }

        return high;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5};
cout<<S->minimiseMaxDistance(A,4)<<endl;

 
return 0 ;
}