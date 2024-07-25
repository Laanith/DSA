#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define PMINUS cout<<-1<<endl
#define vi vector<int>
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
 
*/
 
 
class Solution{
public :
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vi A(k);
        copy(nums.begin()+(n-k), nums.end(), A.begin());
        

        for(int i=n-1; i>k-1;i--){
            nums[i] = nums[i-k];
        }

        for(int i=0; i<k;i++) nums[i] = A[i];

        return;
    }


    void rotateUsingReversals(vi &nums, int k){
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
        return;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5,6,7};
S->rotateUsingReversals(A,2);
pv(A);
 
 
return 0 ;
}