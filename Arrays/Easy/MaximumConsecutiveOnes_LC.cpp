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
 Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/
 
 
class Solution{
public :
    int findMaxOnes(vi nums){
        int n = nums.size();
        int maxCount =0, count = 0;
        for(int i=0; i < n; i++){
            if(nums[i]==1) count++;
            maxCount = max(count, maxCount);
            if(!nums[i]) count=0;
        }

        return maxCount;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,1,0,1,1,1};
cout<<S->findMaxOnes(A);
 
return 0 ;
}