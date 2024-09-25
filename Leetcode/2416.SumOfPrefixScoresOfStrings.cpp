#include <bits/stdc++.h>
using namespace std;

vector<int> brute_force(vector<string> &words)
{
    int n = words.size();
    vector<int> ans(n, 0);
    // for each word:
    for (int i = 0; i < n; i++)
    {
        string prefix = "";
        for (auto it : words[i])
        {
            prefix += it;
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (words[j].substr(0, prefix.length()) == prefix)
                {
                    count++;
                }
            }
            ans[i] += count;
        }
    }
    return ans;
}

vector<int> sumPrefixScores(vector<string> &words)
{
    // copied from gpt:
    struct TrieNode
    {
        unordered_map<char, TrieNode *> children;
        int count;
        TrieNode() : count(0) {}
    };
    void buildTrie(TrieNode * root, const vector<string> &words)
    {
        for (const string &word : words)
        {
            TrieNode *node = root;
            for (char c : word)
            {
                if (!node->children.count(c))
                {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
                node->count++; // Increase count for each prefix in the Trie
            }
        }
    }

    // Function to calculate the sum of prefix scores for each word
    vector<int> sumPrefixScores(vector<string> & words)
    {
        TrieNode *root = new TrieNode();

        // Build the Trie
        buildTrie(root, words);

        vector<int> result;

        // Calculate the score for each word
        for (const string &word : words)
        {
            TrieNode *node = root;
            int score = 0;
            for (char c : word)
            {
                node = node->children[c];
                score += node->count; // Add the count of current prefix to score
            }
            result.push_back(score);
        }

        // Free memory used by Trie (optional but recommended)
        deleteTrie(root);

        return result;
    }

private:
    // Function to delete the dynamically allocated Trie
    void deleteTrie(TrieNode * node)
    {
        for (auto &pair : node->children)
        {
            deleteTrie(pair.second);
        }
        delete node;
    }
}

int main()
{
    vector<string> words = {"abc", "ab", "bc", "b"};
    vector<int> ans = brute_force(words);
    // vector<int> ans=sumPrefixScores(words);
    cout << "\nAns:";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}