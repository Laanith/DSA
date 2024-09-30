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
721. Accounts Merge
Solved
Medium
Topics
Companies
Hint
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/
 
 

class DisjointSet{
    vector<unsigned long long> rank,size,parent;
    public :
        DisjointSet(int n){
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i = 0; i <= n; i++) parent[i] = i;
        }

        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(size[ultimateParentOfu] < size[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
                size[ultimateParentOfv] += size[ultimateParentOfu];
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                size[ultimateParentOfu] += size[ultimateParentOfv];
            }
        }


        void unionByRank(int u, int v){
            int ultimateParentOfu = findParent(u);
            int ultimateParentOfv = findParent(v);
            if(ultimateParentOfu == ultimateParentOfv) return;
            if(rank[ultimateParentOfu] < rank[ultimateParentOfv]){
                parent[ultimateParentOfu] = ultimateParentOfv;
            }
            else if (rank[ultimateParentOfv] < rank[ultimateParentOfu]){
                parent[ultimateParentOfv] = ultimateParentOfu;
            }
            else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                rank[ultimateParentOfu]++;
            }
        }

};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> m;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if(m.find(mail)==m.end()) m[mail] = i;
                else ds.unionBySize(i, m[mail]);
            }
        }


        vector<vector<string>> mailThreads(n);
        for(auto it : m){
            string mail = it.first;
            int node = ds.findParent(it.second);
            mailThreads[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(mailThreads[i].size()==0) continue;
            vector<string> temp = {accounts[i][0]};
            sort(mailThreads[i].begin(), mailThreads[i].end());
            for(auto it : mailThreads[i] ) temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;

    }
};
 
 
int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();
vector<vector<string>> accounts  = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},
                                    {"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},
                                    {"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},
                                    {"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},
                                    {"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};

vector<vector<string>> ans = S->accountsMerge(accounts);

for(auto it : ans){
    for(int i = 0; i < it.size(); i++){
        if(i==0){cout<<"Account name : "<<it[i]<<endl<<"Mails :";}
        else cout<<it[i]<<" ";
    }
    cout<<endl<<endl;
}

return 0 ;
}