#include<iostream>
#include<algorithm>

using namespace std;

int compareTo(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int removeDuplicate(int arr[],int size)
{
    int j = 0;

    for(int i = 0 ; i < size; i++)
    {
        if(arr[i] != arr[i+1])
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
    
    for(int i = 0 ;i < size; i++)
    {
        cin >> arr[i];
    }
    
    qsort(arr,size,sizeof(arr[0]),compareTo);           //sorting array
    
    int k = removeDuplicate(arr,size);                  //calling function()

    for(int i = 0 ; i < k; i++)
    {
        cout << arr[i] << " ";
    }

    
    delete arr;
    return 0;
}