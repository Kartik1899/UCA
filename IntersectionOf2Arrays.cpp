#include<iostream>
#include<algorithm>

using namespace std;

int compareTo(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void findIntersection(int *arr, int size, int *arr2, int size2)
{
    int i = 0;
    int j = 0;
    bool flag = true;
    while(i < size && j < size2)
    {
        if(arr[i] < arr2[j])
        {
            i++;
        }
        else if(arr2[j] < arr[i])
        {
            j++;
        }
        else                                    // printing common elements
        {
            cout << arr[i] << " ";
            i++;
            j++;
            flag = false;
        }
    }
    if( flag )
    {
        cout << "No Common Elements" << endl;
    }
}

int main()
{
    int size,size2;

    cin >> size;                     // Taking size of both arrays as inputs
    cin >> size2;


    int *arr = new int[size];
    int *arr1 = new int[size2];


    for(int i = 0 ; i < size ; i++)  // Adding elements in 1st Array
    {
        cin >> arr[i];
    }


    for(int i = 0 ; i < size2; i++)   // Adding elements in 2nd Array
    {
        cin >> arr1[i];
    }

    qsort(arr,size,sizeof(arr[0]),compareTo);    // sorting array 1

    qsort(arr1,size2,sizeof(arr1[0]),compareTo); // sorting array 2

    findIntersection(arr,size,arr1,size2);


    delete arr;
    delete arr1;
    return 0;
}