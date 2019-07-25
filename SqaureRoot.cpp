#include<iostream>

// Finding sqaure root of a +ve integer using binary techniques and return floor value if not perfect sqaure root.

using namespace std;

int findSqaureRoot(int num)
{
    
    if(num < 2)                             // if num is 1 or 0, the sqrt is also 1 or 0
    {
        return num;
    }

    int *arr = new int[num/2];              // creating new array to store values from 2 to num/2;

    int count = 2;

    for(int i = 0 ; i < num/2; i++)            // inserting values in array
    {
        arr[i] = count++;
    }

    int left = arr[0];
    int right = arr[num/2 - 1];
    int mid;
    int floorValue;

    while( left <= right )                  // using Binary technique to find sqrt
    {
        mid = (left + right) / 2;

        if( mid * mid == num)
        {
            return mid;
        }

        else if( mid * mid > num)
        {
            right--;
        }

        else                                // if number is not perfect sqrt then we will return the floor value , i.e, smaller nearest perfect sqrt
        {
            floorValue = mid;               
            left++;
        }
    }

    return floorValue;

}

int main()
{
    int num;
    cin >> num;

    if (num < 0)                            // Negative integer 
    {
        cout << "Invalid number";
        return -1;
    }
    
    int k = findSqaureRoot(num);            // calling function

    cout << k;

    return 0;
}