// all libraries:
// #include<iostream>
// #include<math.h>
// #include<string>

// packed all libs into 1:
#include <bits/stdc++.h>
using namespace std;

void name()
{
    cout << "My name is Akshita Pathak" << endl;
}
void greet(string nameInp)
{
    cout << "My name is " << nameInp << endl;
}
int sum(int a, int b)
{
    // cout<<"Sum is: "<<a+b<<endl;
    return a + b;
}

int maxx(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void doSmthg(int n){
    cout<<n<<endl;      //10
    n+=5;
    cout<<n<<endl;      //15
    n+=5;
    cout<<n<<endl;      //20

}

void doSmthgElse(int &n){
    cout<<n<<endl;      //10
    n+=5;
    cout<<n<<endl;      //15
    n+=5;
    cout<<n<<endl;      //20

}

void changeArr(int arr[],int n){
    arr[0]+=100;
    cout<<"In fnc changed value of arr[0] is: "<<arr[0]<<endl;
}

int main()
{
    // outputs:
    // cout<<"Hello Aki!"<<endl;
    // cout<<"Hello Aki!";

    // inputs:
    // int age,dob;
    // cout<<"Enter age: ";
    // cin>>age;
    // cout<<"Enter dob: ";
    // cin>>dob;
    // cout<<"your age is: "<<age<<"\nYour dob is: "<<dob;

    // DATA TYPES:
    // INTEGERS: int,long,long long

    //  int 10^9
    //  long 10^13
    //  long long 10^18

    // FRACTIONS: float,double
    // CHARACTER: char                                  ''
    // STRING: string (use getline(cin,string_name))    ""

    // string s;
    // getline(cin,s);
    // cout<<"String is- "<<s;

    // CONDITIONALS

    // int age;
    // cout<<"Enter ur age: ";
    // cin>>age;
    // if(age>=18){
    //     cout<<"u r an adult";
    // }
    // else{
    //     cout<<"still a baby";
    // }

    /*int marks;
    cout<<"Enter your marks: ";
    cin>>marks;

    if(marks<25){
        cout<<"F";
    }
    else if(marks>=25 && marks<=44){
        cout<<"E";
    }
    else if(marks>=45 && marks<=49){
        cout<<"D";
    }
    else if(marks>=50 && marks<=59){
        cout<<"C";
    }
    else if(marks>=60 && marks<=79){
        cout<<"B";
    }
    else if(marks>=80 && marks<=100){
        cout<<"A";
    } */

    /*int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age < 18)
    {
        cout << "Not eligible for job";
    }
    else if (age >= 18 && age<=57)
    {
        cout << "Eligible for job";

        if (age >= 55 && age <= 57)
        {
            cout << ", but retirement soon";
        }
    }
    else if (age > 57)
    {
        cout << "retirement time";
    }*/

    //  SWITCH STATEMENT
    /*int dayNo;
    cout<<"Enter the day no: ";
    cin>>dayNo;

    switch(dayNo){
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Tuesday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"Enter a valid day no! ";
    }
    */

    //    ARRAYS
    /*int arr[] = {3, 4, 5, 7};
    cout<<arr[3];
    arr[2]+=10;
    cout<<arr[2];*/

    // 2D array
    /*int arr[3][5];
    // row colm
    arr[1][3]=27;       //initialise
    cout<<arr[1][3];*/
    // print

    // STRING
    /*string s = "Akshita";
    // cout<<s[2];
    int l=s.size();
    // cout<<s[l-1];
    s[l-1]='s';
    cout<<s;*/

    // LOOPS
    /*for(int i=0;i<5;i++){
        cout<<"Aki "<<i<<endl;
    }*/

    //    for(int i=5;i>0;i--){
    //         cout<<"Aki "<<i<<endl;
    //     }

    // int i = 0;
    /*while(i<5){
        cout<<"Aki "<<i<<endl;
        i++;
    }*/

    //    EXECUTES ATLEAST ONCE EVEN IF CND IS FALSE
    /*do
    {
        cout << "Aki " << i << endl;
        i++;
    } while (i < 0);*/

    // FUNCTIONS:
    // name();
    // greet("Saanvi");
    // greet("Shaktee");

    // cout<<"Sum fnc:"<<sum(2,10);

    // USING MATH.H FUNCTIONS
    // cout<<min(2,19)<<endl;
    // cout<<max(2,19);

    // cout << "Maximum value is: " << maxx(4, 9);

    // PASS BY VALUE-> a copy goes
    // int num=10;
    // doSmthg(num);        //the copy is modified
    // cout<<"in main num is: "<<num<<endl;

    // PASS BY REFERENCE
    // int num=10;
    // doSmthgElse(num);       //add & in fnc
    // cout<<"in main num is: "<<num<<endl;
    
    // int arr[5];
    // for(int i=0;i<5;i++){
    //     cin>>arr[i];
    // }
    // for(int i=0;i<5;i++){
    //     cout<<arr[i]<<" ";
    // }


    int n=5;
    int arr[n];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    changeArr(arr,n);
    cout<<"Value of arr[0] in main: "<<arr[0]<<endl;
    // IN ARRAY ALWAYS PASS BY REFERNCE!! NO NEED TO ADD &

    return 0;
}