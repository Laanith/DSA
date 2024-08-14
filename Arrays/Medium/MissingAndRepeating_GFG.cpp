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
Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 455K+Points: 4
Given an unsorted array arr of size n of positive integers. One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array. Find these two numbers.
Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer (The first index contains B and second index contains A)

Examples

Input: n = 2 arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: n = 3 arr[] = {1, 3, 3} 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n
*/
 
 
class Solution{
public :
        vector<int> findTwoElement(vector<int> arr, int n) {
        int xr = 0;
        for(int i = 0 ; i < n; i++){
            xr ^= arr[i];
            xr ^= (i+1);
    }
        
        int bitNo = 0;
        while(1){
            if((xr&(1<<bitNo)) != 0) break;
            bitNo++;
        }
        
        int zero = 0;
        int one = 0;
        for(int i = 0; i < n; i++){
            if( (arr[i]&(1<<bitNo)) != 0) one^=arr[i];
            else zero^=arr[i];
        }
        
        
        for(int i = 1; i <= n; i++){
            if( (i&(1<<bitNo)) != 0) one^=i;
            else zero^=i;
        }
        
        int count = 0;
        for(int i = 0 ; i < n; i++){
            if(arr[i]==zero) count++;
        }
        
        if(count==2) return {zero,one};
        return {one,zero};
        
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi arr = {2,3,4,5,5,6,7};
pv(S->findTwoElement(arr,7));

return 0 ;
}