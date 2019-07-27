#include<iostream>

// find the number of students b/w the marks range given
using namespace std;


int compareTo(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}


int countStudents(int *marks,int size, int low, int high)                  
{

    int storeLow;
    int storeHigh;
    int left = 0;
    int right = size;
    int mid;


    if( low < marks[left])              // if the first element of the array is greater than lower range then we store it as lower bound.
    {
        storeLow = left;
    }


    else                                // searching for lower bound
    {
    
        while( left < right )
        {
            mid = (left + right) / 2;

            if( low <= marks[mid] )       // if mid element is greater or eqaul to lower range we delete the right side of the array and search inside left to mid
            {
                right = mid;
            }
            else
            {
                left = mid + 1;         // deleting left side of the array if lower range is greater than mid
            }
        }

        storeLow = left;
    }

    left = 0;
    right = size;


    if( high > marks[right - 1])       // if higher range is greater than last element of the array, we take it as higher range
    {
        storeHigh = right;
    }   

    else                                // finding upper bound
    {

        while( left < right)
        {
           mid = (left + right) / 2;

            if(high >= marks[mid] )             // if higher range is greater than middle element, delete left side of array
            {
                left = mid + 1;
            }
            else                                // else delete right side of the array;
            {
                right = mid;
            }
        }

        storeHigh = left;
    }
    
    

    return storeHigh - storeLow;
}
int main()
{
    int size;
    cin >> size;
    
    int *marks = new int[size];

    for(int i = 0 ; i < size ; i++)                         // inserting marks
    {
        cin >> marks[i];
    }

    qsort(marks,size,sizeof(marks[0]),compareTo);          // sorting array

    for(int i = 0 ; i < size ; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;

    int lowerRange;
    int higherRange;
    cin >> lowerRange;                                  // getting ranges
    cin >> higherRange;

    int k = countStudents(marks,size,lowerRange,higherRange);       // calling function()
    
    cout << "Number of students in range : " << k << endl;

    return 0;
}