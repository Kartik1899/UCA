#include<iostream>

// Rotating a sqaure matrix 90

using namespace std;

void swap(int *arr, int *arr1)                      // swap function()
{
    int temp = *arr;
    *arr = *arr1;
    *arr1 = temp;
}

void rotateArray(int **arr, int size)
{
    for(int i = 0 ; i < size ; i++)                         // taking transpose of matrix
    {
        for(int j = 0 ; j < size ; j++)
        {
            if( j > i)
            {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }


    int j = 0;

    for(int i = 0 ; i < size ; i++)                       // swapping elements in each row
    {
        j = 0;
        while(j < size/2)
        {
            swap(arr[i][j],arr[i][size-j-1]);
            j++;
        }
    }
}

int main()
{
    int size;
    cin >> size;
    
    int **arr = new int*[size];                     // initializing 2d array
    for(int i = 0 ; i < size ; i++)
    {
        arr[i] = new int[size];
    }


    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    rotateArray(arr,size);                          // calling function()


    for(int i = 0 ; i < size ; i++)                 // printing rotated array
    {
        for(int j = 0 ; j < size ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}