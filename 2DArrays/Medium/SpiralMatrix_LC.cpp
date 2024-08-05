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
Given an m x n matrix, return all elements of the matrix in spiral order.
*/
 
 
class Solution{
public :
    vi spiralOrder(vvi & matrix){

        int n = matrix.size(), m = matrix[0].size();
        int top = 0, left = 0, right = m - 1, bottom = n - 1;
        vi ans;

        while(left<=right && top<=bottom){
            for(int i = left; i <= right ; i++) ans.pb(matrix[top][i]);
            top++;
            for(int i = top ; i <= bottom ; i++ ) ans.pb(matrix[i][right]);
            right--;
            if(top<=bottom){
                for(int i = right; i >= left; i--) ans.pb(matrix[bottom][i]);
                bottom--;
            }
            if(left<=right){
                for(int i = bottom ; i >= top; i--) ans.pb(matrix[i][left]);
                left++;
            }
        }

        return ans;
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vvi matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
pvvi(matrix);
pv(S->spiralOrder(matrix));

 
return 0 ;
}