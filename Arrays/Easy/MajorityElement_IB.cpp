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
Majority Element
Programming
Greedy Algorithm
Easy
52.6% Success

582

50

Bookmark
Asked In:
Problem Description
 
 

Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.



Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return the majority element.


*/


/*NOTE - Moore's Voting Algorithm */
 
 
class Solution{
public :
    int majorityElement(const vi &v ){
        int count  = 0;
        int ele ;
        int n = v.size();
        for(int i = 0 ; i < n ; i++){
            if(count == 0){
                ele = v[i];
                count = 1;
            }
            else {
                if(v[i]==ele) count++;
                else count--;
            }

        }


        int nCount = 0;
        for(auto x : v) if(x==ele) nCount++;
        if(nCount>n/2) return ele;
        return -1;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vi A = {1,2,3,4,5,6,7,7,7,7,7,7,7,7,7,7,7};
pint(S->majorityElement(A));
 
 
return 0 ;
}