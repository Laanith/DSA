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
Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 297K+Points: 4
You are given a 2D array consisting of only 1's and 0's, where each row is sorted in non-decreasing order. You need to find and return the index of the first row that has the most number of 1s. If no such row exists, return -1.
Note: 0-based indexing is followed.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's.
Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's.
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1 


*/
 
 
class Solution{
public :

    int lBound( vi & arr, int n, int x){
        int l =0, h = n - 1, ans = n,mid;
        while(l<=h){
            mid = l + (h-l)/2;
            if(arr[mid] >= x){
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }    
        return ans;
    }

    int rowWithMax1s(vvi & matrix){
        int cntMax = 0, index = -1;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            int cntOnes = m - lBound(matrix[i], m, 1);
            if(cntOnes > cntMax){
                cntMax = cntOnes;
                index = i;
            }
        }

        return index;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi A = {{0, 1, 1, 1},
         {0, 0, 1, 1},
         {1, 1, 1, 1},
         {0, 0, 0, 0}};
pint(S->rowWithMax1s(A));
 
return 0 ;
}