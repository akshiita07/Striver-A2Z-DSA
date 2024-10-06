#include <bits/stdc++.h>
using namespace std;

bool areSentencesSimilar(string sentence1, string sentence2)
{
    // vector<string> word1=split(sentence1);
    // vector<string> word2=split(sentence2);

    if (sentence1.size() > sentence2.size())
    {
        swap(sentence1, sentence2);
    }

    // split sentence into words:
    istringstream iss1(sentence1);
    istringstream iss2(sentence2);
    vector<string> word1;
    vector<string> word2;
    string word;

    while (iss1 >> word)
    {
        word1.push_back(word);
    }
    while (iss2 >> word)
    {
        word2.push_back(word);
    }

    if (word1.size() > word2.size())
    {
        swap(word1, word2);
    }

    // 2 pointers
    int i = 0;
    int j = 0;

    int n1 = word1.size();
    int n2 = word2.size();

    // Compare from the beginning
    while (i < n1 && word1[i] == word2[i])
    {
        i++;
    }

    // Compare from the end
    while (j < n1 && word1[n1 - j - 1] == word2[n2 - j - 1])
    {
        j++;
    }

    // Check if there is an unmatched part that prevents similarity
    return i + j >= n1;
}

int main()
{
    string sentence1 = "My name is Haley";
    string sentence2 = "My Haley";
    cout << "\nIs sentence 1 and 2 similar: " << areSentencesSimilar(sentence1, sentence2);

    string sent1 = "of";
    string sent2 = "A lot of words";
    cout << "\nIs sent 1 and 2 similar: " << areSentencesSimilar(sent1, sent2);

    return 0;
}