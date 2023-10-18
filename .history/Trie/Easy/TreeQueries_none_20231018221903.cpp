#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

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
    int destinationNode; // Declare destinationNode here

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
I've added the declaration of destinationNode within the uniqueStringsCount function. This should resolve the issue, and the code should now work as intended.

    int
    main()
{
    int A = 5;
    vector<vector<int>> B = {{1, 4}, {5, 1}, {2, 4}, {3, 4}};
    string C = "baaba";
    vector<vector<int>> D = {{5, 2}, {3, 5}};

    int result = uniqueStringsCount(A, B, C, D);
    cout << result << endl;

    return 0;
}
