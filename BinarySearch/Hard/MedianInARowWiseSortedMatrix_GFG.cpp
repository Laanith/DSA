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
Median in a row-wise sorted Matrix
Difficulty: HardAccuracy: 55.05%Submissions: 113K+Points: 8
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives 
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives 
us {1,2,3}. Hence, 2 is median.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1 <= R, C <= 400
1 <= matrix[i][j] <= 2000
*/
 
 
class Solution{   
public:

    int upperBound(vector<int> & arr, int target, int n){
        int l = 0, r = n - 1, mid, ans = n;
        while(l <= r){
            mid = l + (r-l)/2;
            if(arr[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }



    int count(vector<vector<int>> & matrix, int mid, int R, int C){
        int cnt = 0;
        for(int i = 0; i < R; i++) cnt += upperBound(matrix[i], mid, C);
        return cnt;
    }
    
    
    int median(vector<vector<int>> &matrix, int R, int C){
        int l = INT_MAX, r = INT_MIN;
        for(int i = 0; i < R; i++){
            l = min(l , matrix[i][0]);
            r = max(r, matrix[i][C-1]);
        }
        
        int target = (R*C)/2;
        
        int mid;
        while(l<=r){
            mid = l + (r-l)/2;
            int smallOrEqual = count(matrix, mid, R, C);
            if(smallOrEqual <= target) l = mid + 1;
            else r = mid -1 ;
        }
        
        return l;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi matrix = {{1,3,5}, {3,6,9}, {2,6,9}};
pint(S->median(matrix, 3, 3));


return 0 ;
}