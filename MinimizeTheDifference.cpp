#include<iostream>

// minimize the difference b/w max and min in 3 arrays, given all 3 arrays are sorted.


using namespace std;

int find_Max(int a, int b, int c)                   // returns max element
{
    if (a > b && a > c)
    {
        return a;
    }
    else if (b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
}

int find_Min(int a, int b,int c)                // returns min element
{
    if(a < b && a < c)
    {
        return a;
    }
    else if(b < c)
    {
        return b;
    }
    else
    {
        return c;
    }
    
}
void findMinDifference(int *arr1, int size1, int *arr2, int size2, int *arr3, int size3)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int firstIndex, secondIndex, thirdIndex;
    
    int minDifference =	2147483647;                 // taking maximum possible int value for min;

    int minValue, maxValue;
    while(i < size1 && j < size2 && k < size3)
    {
        minValue = find_Min(arr1[i], arr2[j], arr3[k]);     // finding min value amongst 3 values
        maxValue = find_Max(arr1[i], arr2[j], arr3[k]);     // finding max value amongst 3 values

        if( minDifference > maxValue - minValue)            // comapring minDiff with new difference;
        {
            minDifference = maxValue - minValue;
            firstIndex = i;
            secondIndex = j;
            thirdIndex = k;
        }
        if(minValue == arr1[i])
        {
            i++;
        }
        else if(minValue == arr2[j])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    cout << arr1[firstIndex] << " " << arr2[secondIndex] << " " << arr3[thirdIndex] << endl; // printing the pair
}

int main()
{
    int size1, size2, size3;
    cin >> size1 >> size2 >> size3;                          // Taking the sizes of the arrays

    int *arr1 = new int[size1];
    int *arr2 = new int[size2];
    int *arr3 = new int[size3];

    for(int i = 0 ; i < size1 ; i++)                        // inserting elements in the arrays 
    {
        cin >> arr1[i];
    }
    for(int i = 0 ; i < size2; i++)
    {
        cin >> arr2[i];
    }
    for(int i = 0 ; i < size3; i++)
    {
        cin >> arr3[i];
    }

    findMinDifference(arr1,size1,arr2,size2,arr3,size3);        // calling function

    return 0;
}