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
1901. Find a Peak Element II
Solved
Medium

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 500
1 <= mat[i][j] <= 105
No two adjacent cells are equal.
*/
 
 
class Solution{
public :
    int maxIndex(vvi & mat, int col, int n, int m){
        int ind = imi, maxVal = imi;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                ind = i;
            }
        }
        return ind;
    }

    vi findPeakGrid(vvi & mat){
        int n = mat.size(), m = mat[0].size();
        int l = 0, h = m-1, mid;
        while(l<=h){
            mid = l + (h-l)/2;
            int max_ind = maxIndex(mat, mid, n, m);
            int ele = mat[max_ind][mid];
            int left = (mid > 0) ? mat[max_ind][mid-1] : -1;
            int right = (mid < m - 1) ? mat[max_ind][mid + 1] : -1;
            if(ele > left && ele > right) return {max_ind, mid};
            else if ( ele > left && ele < right) l = mid + 1;
            else h = mid - 1;
        }

        return {-1,-1};
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi mat  = {{10,20,15},{21,30,14},{7,16,32}};
vi res = S->findPeakGrid(mat);
pv(res);
pvvi(mat);
pint(mat[res[0]][res[1]]);

 
return 0 ;
}