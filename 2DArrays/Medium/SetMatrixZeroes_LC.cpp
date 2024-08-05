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
void pvvi(vvi A){for(auto v : A){pv(v);}}



 
 
/*!SECTION : Problem Description ::
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
*/
 
 
class Solution{
public :
        void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> vpii;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]==0) vpii.push_back(pair<int,int>(i,j));
            }
        }

        for(pair<int,int> p : vpii){
            int row = p.first;
            int col = p.second;
            for(int i = 0 ; i < m; i++){
                matrix[row][i]=0;
            }
            for(int j = 0 ; j < n; j++){
                matrix[j][col]=0;
            }
        }

        return;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vvi matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
pvvi(matrix);
S->setZeroes(matrix);
cout << endl;
pvvi(matrix);

cout << endl;
cout << endl;
matrix = {{1,1,1},{1,0,1},{1,1,1}};
pvvi(matrix);
S->setZeroes(matrix);
cout << endl;
pvvi(matrix);





 
return 0 ;
}