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
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/
 
 
class Solution{
public :
    int bruteForce(vi heights){
        int max_area = imi;
        int n = heights.size();
        for(int i= n; i>=1;i--){
            int window_size = i;
            for(int j=0; j<n-window_size+1;j++){
                int min_height=ima;
                for(int k=j; k<j+window_size;k++) if(min_height>heights[k]) min_height=heights[k];
                max_area = max(max_area, min_height*window_size);
            }
        }

        return max_area;

    }

    int optimal(vi h){
        if(h.size() == 1) return h[0];
        vi nextSmall, prevSmall;
        si st1, st2;

        int n = h.size();
        for(int i=0; i<n; i++){
            while (!st1.empty() && h[st1.top()] >= h[i]) st1.pop();
            prevSmall.push_back( st1.empty() ? -1 : st1.top());
            st1.push(i);
            
        }

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && h[st2.top()] >= h[i]) st2.pop();
            nextSmall.push_back(st2.empty() ? n : st2.top());
            st2.push(i);
        }

        reverse(nextSmall.begin() , nextSmall.end());

        int max_area = imi;
        for(int i=0;i<n;i++){
            int area = h[i]*(nextSmall[i] - prevSmall[i]-1);
            max_area = max(area, max_area);
        }
        return max_area;
    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->optimal({1,2,4,4});

return 0 ;
}