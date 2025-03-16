#include <bits/stdc++.h>
using namespace std;

long long canRepairCars(vector<int> &ranks, int cars, long long time)
{
    long long noOfCars = 0;
    for (auto it : ranks)
    {
        // count how many cars can each mechanic repair in this time
        // mechanic with a rank r can repair n cars in r * (n^2) minutes so N^2=TIME/RANK SO N=SQRT(TIME/RANK)
        long long maxCars = sqrt(time / it);
        noOfCars += maxCars;
        if (noOfCars >= cars)
        {
            return true;
        }
    }
    return false;
}

long long repairCars(vector<int> &ranks, int cars)
{
    // ranksi is the rank of the ith mechanic
    // mechanic with a rank r can repair n cars in r * n^2 minutes
    // cars representing the total number of cars waiting in the garage to be repaired
    // Return the minimum time taken to repair all the cars.

    // min possible time taken by 1 mechanic:
    long long left = 1;
    // max possible time when all cars are repaired by 1 mechanic only:
    long long right = (long long)(*min_element(ranks.begin(), ranks.end())) * (long long)cars * cars;
    long long ans = right;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (canRepairCars(ranks, cars, mid))
        {
            // sufficient time so try lower time
            ans = mid;
            right = mid - 1;
        }
        else
        {
            // not sufficient so try higher values
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> ranks = {4, 2, 3, 1};
    int cars = 10;
    cout << "\nminimum time taken to repair all the cars= " << repairCars(ranks, cars);

    return 0;
}