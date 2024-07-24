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
Given an unsorted integer array, find a pair with the given sum in it.

• Each input can have multiple solutions. The output should match with either one of them.

Input : nums[] = [8, 7, 2, 5, 3, 1], target = 10
Output: (8, 2) or (7, 3)

• The solution can return pair in any order. If no pair with the given sum exists, the solution should return the pair (-1, -1).

Input : nums[] = [5, 2, 6, 8, 1, 9], target = 12
Output: (-1, -1)
*/
 
 
class Solution{
public :
    vpi printAllSubArray(vi const &nums){

        vpi ans;
        int n = nums.size();
        unordered_multimap<int,int> map;
        map.insert(make_pair(0,-1));

        int sum = 0;

        for(int i=0; i<n;i++){
            sum+=nums[i];
            if(map.find(sum)!=map.end()){
                auto it = map.find(sum);
                while(it !=map.end() && it->first == sum){
                    ans.push_back(make_pair(it->second+1, i));
                    it++;
                }
            }

            map.insert(pair<int,int>(sum,i));
        }


        return ans;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();

vi nums = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
vpi ans = S->printAllSubArray(nums);
    cout<<"START INDEX"<<"   "<<"END INDEX"<<endl;

for(auto it : ans){
    cout<<it.first<<"   "<<it.second<<endl;
}
 
 
return 0 ;
}