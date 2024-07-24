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
pi firstAndLastOccurrence(vi nums, int target);
};

pi Solution::firstAndLastOccurrence(vi nums, int target){
    int left = 0, right =nums.size()-1;
    int mid;
    bool found = false;
    while(left<right){
        mid = left + (right-left)/2;
        if(nums[mid]==target){found=true; break;}
        else if(nums[mid]<target){ left = mid+1;}
        else {right = mid-1;}
    }

    if(found){
        int leftptr = mid, rightptr = mid;
        while(leftptr>0 && nums[leftptr-1]==target) leftptr--;
        while(rightptr<nums.size()-1 && nums[rightptr+1]==target) rightptr++;
        return pair<int,int>(leftptr,rightptr);
    }

    return pair<int,int>(-1,-1);
}
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
auto result = S->firstAndLastOccurrence({2, 5, 5, 5, 6, 6, 8, 9, 9, 9}, 5);
cout<<result.first<<" "<<result.second<<endl;
// Output should be (1, 3)
 
 
return 0 ;
}