#include<bits/stdc++.h>
#define ll long long
#include<algorithm>
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define PYES cout<<"YES"<<endl
#define PNO cout<<"NO"<<endl
#define vs vector<string>
#define si stack<int>
#define qi queue<int>
#define pi pair<int,int>
#define ima INT_MAX
#define imi INT_MIN
#define siz size()
#define pb push_back()
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}



/*!SECTION : Problem Description ::
    Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.

*/



class Solution{
    public :
        string solve(string A);
};

    string Solution::solve(string A)
    {
        vector<int> H(26, 0);
    string B = "";
        int index = 0;
        for (int i = 0; i < A.length(); i++)
        {
            H[A[i] - 97]++;

            if (H[A[index] - 97] <= 1)
            {
                B = B + A[index];
            }

            else if (index <= i)
            {
                index++;
                while (index <= i)
                {
                    if (H[A[index] - 97] <= 1)
                    {
                        B = B + A[index];
                        break;
                    }
                    else if (index == i)
                    {
                        B += '#';
                        break;
                    }
                    else{
                        index++;
                    }
                }
            }
        }
        return B;
    }



int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
cout<<S->solve("abadbc");

return 0 ;
}