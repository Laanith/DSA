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
74. Search a 2D Matrix
Solved
Medium
Topics
Companies
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/
 
 
class Solution{
public :
    bool searchMatrix(vvi & matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int lrow = 0, rrow = n-1, mid;
        bool foundRow = false;
        while(lrow<=rrow){
            mid = lrow + (rrow-lrow)/2;
            int s = matrix[mid][0], e = matrix[mid][m-1];
            if(s<=target && target<=e){foundRow=true; break;}
            else if(s<target && e<target) lrow = mid +1 ;
            else rrow = mid - 1;
        }

        if(!foundRow) return false;
        vi & ans = matrix[mid];
        int s = 0, e= m-1;
        while (s<=e)
        {   
            int mid = s + (e-s)/2;
            if(ans[mid]==target) return true;
            else if(ans[mid]<target) s = mid + 1;
            else e = mid - 1;
        }

        return false;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi A ={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
cout<<boolalpha<<S->searchMatrix(A,16)<<endl;
cout<<boolalpha<<S->searchMatrix(A,46)<<endl;
 
return 0 ;
}