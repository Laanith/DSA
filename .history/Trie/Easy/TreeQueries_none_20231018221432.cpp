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
#define umapii unordered_map<int,int>
#define vvi vector<vector<int>>
using namespace std;
void pv(vi A){cout << endl;for(auto x : A) cout << x <<' ';cout << endl;}
void pint(int A){cout<<endl<<A<<endl;}
void pp(pair<int,int> p){cout<<p.first<<' '<<p.second<<endl;}
void pvs(vs A){cout<<endl;for(auto x : A) cout<<x<<" ";cout<<endl;}
void ps(string A){cout<<A<<endl;}
void pvvi(vvi A){for(auto v : A){pv(v);}}

/*!SECTION : Problem Description ::
You love strings a lot, so you decided to play the following game.

You have a tree T of A nodes. The tree is represented by a matrix B of dimensions (A - 1) * 2 such that there exist an edge between node B[i][1] and BEach node is assigned a lowercase english character, which is represented by a string C of length A. Node i is assigned character at position I of strin

You are given Q queries in the form of a matrix D of dimensions Q * 2 For each you query you will perform the following steps.

1. You will move from node D[i][1] to node D[i][2] using the shortest possible path.2. Let V[1], V[2]... V[K] be the nodes visited in the corresponding order. Create a string S such that length of S is equal to K and S[i] = C[v[i]]

3. Store string S in your bag.

Return the number of unique strings you would create
*/

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool is_end_of_word;

    TrieNode() : is_end_of_word(false) {}
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
        count = 0;
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        if (!node->is_end_of_word)
        {
            node->is_end_of_word = true;
            count++;
        }
    }

    int getCount()
    {
        return count;
    }

private:
    TrieNode *root;
    int count;
};

int uniqueStringsCount(int A, vector<vector<int>> &B, string C, vector<vector<int>> &D)
{
    unordered_map<int, vector<int>> tree;

    for (vector<int> &edge : B)
    {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    unordered_set<string> uniqueStrings;

    function<void(int, int, string)> dfs = [&](int node, int parent, string currentString)
    {
        currentString += C[node - 1];
        if (node == destinationNode)
        {
            uniqueStrings.insert(currentString);
        }
        for (int child : tree[node])
        {
            if (child != parent)
            {
                dfs(child, node, currentString);
            }
        }
    };

    Trie trie;

    for (vector<int> &query : D)
    {
        int sourceNode = query[0];
        destinationNode = query[1];
        dfs(sourceNode, 0, "");
    }

    for (const string &str : uniqueStrings)
    {
        trie.insert(str);
    }

    return trie.getCount();
}

int main(){
ios::sync_with_stdio(0);
cin.tie(0);
auto S = new Solution();


return 0 ;
}