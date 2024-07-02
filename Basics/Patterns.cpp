#include <bits/stdc++.h>
using namespace std;

// PATTERN 1:
/*  ****
 ****
 ****
 ****
 */
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// PATTERN 2:
/*
 *
 **
 ***
 ****
 *****
 */
void pattern2()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

// PATTERN 3:
/*
1
1 2
1 2 3
*/
void pattern3()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

// PATTERN 4:
/*
1
2 2
3 3 3
*/
void pattern4()
{
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

// PATTERN 5:
/*
****
***
**
*
*/
void pattern5()
{
    for (int i = 5; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// PATTERN 6:
/*
12345
1234
123
12
1
*/
void pattern6()
{
    for (int i = 5; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << "";
        }
        cout << endl;
    }
}

// PATTERN 7:       IMP
/*
 *
 ***
 *****
 *******
 */
void pattern7()
{
    for (int i = 0; i < 5; i++) // rows
    {
        for (int j = 0; j < 5 - i - 1; j++) // spaces print in reverse manner
        {
            cout << " ";
        }
        for (int k = 0; k < (2 * i + 1); k++) // to print stars
        {
            cout << "*";
        }
        for (int j = 0; j < 5 - i - 1; j++) // spaces print in reverse manner
        {
            cout << " ";
        }

        cout << endl;
    }
}

// PATTERN 10:       IMP
/*
 *
 **
 ***
 **
 *
 */
void pattern10()
{
    for (int i = 0; i < 5; i++)
    {
        // star
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 5 - 2; i > 0; i--)
    {
        // star
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// PATTERN 11:       IMP
/*
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
 */
void pattern11()
{
    int start = 1;
    for (int i = 0; i < 5; i++)
    {
        if (i % 2 == 0)
        {
            // print 1
            start = 1;
        }
        else
        {
            start = 0;
        }
        for (int j = 0; j <= i; j++)
        {
            cout << start << " ";
            start = 1 - start;
        }
        cout << endl;
    }
}

// PATTERN 12:       IMP
/*
 1         1
1 2     2 1
1 2 3 3 2 1
 */
void pattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // spaces
        for (int j = 1; j <= space; j++)
        {
            cout << " ";
        }
        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space = space - 2;
    }
}

// PATTERN 17:       IMP
/*
    A
  A B A
A B C B A
 */
void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A';
        int breakpt = ((2 * i) + 1) / 2;
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // alphabets
        for (int j = 0; j < ((2 * i) + 1); j++)
        {
            cout << ch;
            if (j < breakpt)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        // space
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

// PATTERN 13:       IMP
/*
    A
  A B A
A B C B A
 */
void pattern13(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - 1); // ch=3='c'
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}

// PATTERN 18:       IMP
/*
E
DE
CDE
BCDE
ABCDE
 */
void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char j = 'E' - i; j <= 'E'; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
}

// PATTERN 19:       IMP
/*
 * * * * * *
 * *     * *
 *         *
 *         *
 * *     * *
 * * * * * *
 */
void pattern19(int n)
{
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    int space = (2 * n) - 2;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        space -= 2;
    }
}

// PATTERN 14:       IMP
/*
 *        *
 **      **
 ***    ***
 ****  ****
 **********
 **********
 ****  ****
 ***    ***
 **      **
 *        *
 */
void pattern14(int n)
{
    int space = 2 * n - 2;
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
        space -= 2;
    }
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        // space
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// PATTERN 20:       IMP
/*
 *         *
 * *     * *
 * * * * * *
 * *     * *
 *         *
 */
void pattern20(int n)
{
    // int space = 2 * n - 2;

    // for (int i = 1; i <= 2 * n - 1; i++)
    // {
    //     int stars = i;
    //     if (i > n)
    //     {
    //         stars = 2 * n - i;
    //     }

    //     // stars
    //     for (int j = 0; j < stars; j++)
    //     {
    //         cout << "*";
    //     }
    //     // space
    //     for (int j = 0; j < space; j++)
    //     {
    //         cout << " ";
    //     }
    //     // stars
    //     for (int j = 0; j < stars; j++)
    //     {
    //         cout << "*";
    //     }
    //     if (i >= n)
    //     {
    //         space += 2;
    //     }
    //     else
    //     {
    //         space -= 2;
    //     }
    //     cout << endl;
    // }
    int space = 2 * n + 2; // 8

    for (int i = 0; i < 2 * n - 1; i++)
    { // i:0 to 5
        int stars;

        if (i >= n)
        {
            stars = ((2 * n - 2) - i); // 4>3: stars=2*3-4=2
        }
        else
        {
            stars = i;
        }

        // stars
        for (int j = 0; j <= stars; j++)
        {
            cout << "* ";
        }
        // space
        for (int j = 0; j < space; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j <= stars; j++)
        {
            cout << "* ";
        }
        cout << endl;

        if (i >= n - 1)
        {
            space += 4;
        }
        else
        {
            space -= 4;
        }
    }
}

// PATTERN 21:       IMP
/*

****
*  *
*  *
****

 */
void pattern21(int n)
{
    int space = 0;
    for (int i = 1; i <= n; i++)
    {
        // star
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1 || i == n || j == n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// PATTERN 22:       IMP
/*

i    7-4    4444444
            4333334
            4322234
            4321234
            4322234
            4333334
            4444444

 */
void pattern22(int n)
{
    int count = n; // count=4;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        // boundary->n
        for (int j = 0; j < 2 * n - 1; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i == k || j == k || i == (2 * n - 2 - k) || j == (2 * n - 2 - k))
                {
                    cout << count - k;
                    break;
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    // PATTERN 1
    // test cases-t
    // int t;
    // cout << "Enter how many times u want this fnc to run? ";
    // cin >> t;
    // for (int i = 0; i < t; i++)
    // {
    //     int n;
    //     cout << "Enter no of stars: ";
    //     cin >> n;
    //     pattern1(n);
    // }

    // PATTERN 2
    // pattern2();

    // PATTERN 3
    // pattern3();

    // PATTERN 4
    // pattern4();

    // PATTERN 5
    // pattern5();

    // PATTERN 6
    // pattern6();

    // PATTERN 7
    // pattern7();

    // PATTERN 10
    // pattern10();

    // PATTERN 11
    // pattern11();

    // PATTERN 12
    // pattern12(5);

    // PATTERN 17
    // pattern17(5);

    // PATTERN 18
    // pattern18(5);

    // PATTERN 19
    // pattern19(5);

    // PATTERN 20
    // pattern20(3);

    // PATTERN 21
    pattern21(5);

    // PATTERN 22
    pattern22(4);
}