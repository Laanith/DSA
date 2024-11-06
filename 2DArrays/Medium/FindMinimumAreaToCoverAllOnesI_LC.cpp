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

Code


Testcase
Testcase
Test Result
3195. Find the Minimum Area to Cover All Ones I
Solved
Medium
Topics
Companies
Hint
You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

Return the minimum possible area of the rectangle.

 

Example 1:

Input: grid = [[0,1,0],[1,0,1]]

Output: 6

Explanation:



The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

Example 2:

Input: grid = [[1,0],[0,0]]

Output: 1

Explanation:



The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 0 or 1.
The input is generated such that there is at least one 1 in grid
*/
 
 
class Solution{
public :
    int minArea(vvi & grid){
        int n = grid.size(), m = grid[0].size();
        bool fl = false, ft = false, fr = false, fb =false;
        int t = 0, l = 0, r = m-1, b = n-1;
        while(!ft){
            for(int j = 0; j < m; j++) if(grid[t][j]){ ft = true; break;}
            t++;
        }
        while(!fb){
            for(int j = 0; j < m; j++) if(grid[b][j]){fb = true; break;}
            b--;
        }
        while(!fl){
            for(int i = 0; i < n; i++) if(grid[i][l]){fl=true; break;}
            l++;
        }
        while(!fr){
            for(int i = 0; i < n; i++) if(grid[i][b]){fr=true; break;}
            r--;
        }
        l--; r++; t--; b++;
        return (r-l+1)*(b-t+1);
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi grid = {{0,1,0},{1,0,1}};
pint(S->minArea(grid));
return 0 ;
}