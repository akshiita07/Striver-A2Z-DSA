#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    unordered_map<int, set<int>> hashMap;  // number->{set of indices in sorted order} //do not use unordered_ set here as it does not sorts elements
    unordered_map<int, int> indexToNumber; // index to number
    NumberContainers()
    {
        // initialise
    }

    void change(int index, int number)
    {
        // Fills container at index with the number
        // if already a number at that index, replace it

        // first check if that index is already in a set or not
        if (indexToNumber.find(index) != indexToNumber.end())
        {
            // already present index so replace it:
            int numberAssociated = indexToNumber[index];
            hashMap[numberAssociated].erase(index); // remove it from index to number mapping
            // if it becomes empty then remove it:
            if (hashMap[numberAssociated].empty() == true)
            {
                hashMap.erase(numberAssociated); // remove this whole if set gets empty
            }
        }
        hashMap[number].insert(index);
        indexToNumber[index] = number;
    }

    int find(int number)
    {
        // Returns smallest index for the given number, or -1
        if (hashMap.find(number) == hashMap.end() || hashMap[number].empty() == true)
        {
            // not found:
            return -1;
        }
        return *(hashMap[number].begin()); // dereference the pointer
    }
};

int main()
{

    return 0;
}