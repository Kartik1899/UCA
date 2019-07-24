#include<iostream>
#include<algorithm>

using namespace std;

int compareTo(const void* a, const void* b)            
{
    return (*(int*)a - *(int*)b);
}

int maxTwoDuplicate(int *arr,int size)
{
    int j = 0;

    for(int i = 0; i < size ; i++)
    {
        if(i < size - 2)
        {
            if(arr[i] == arr[i+1] && arr[i] == arr[i+2])    // checking for last 2 same elements
                continue;

            arr[j] = arr[i];
            j++;
        }
        else                                                // last 2 elements will always be in the array
        {
            arr[j] = arr[i];
            j++;
        }
        
    }
    return j;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for(int i = 0; i < size ;i++)
    {
        cin >> arr[i];
    }

    qsort(arr,size,sizeof(arr[0]),compareTo);             // sorting array 


    int k = maxTwoDuplicate(arr,size);                    // calling function() 


    for(int i = 0 ; i < k ; i++)
    {
        cout << arr[i] << " ";
    }


    delete arr;
    return 0;

}