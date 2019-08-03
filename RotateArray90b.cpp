#include<iostream>

// rotating array 90 degree without taking transpose

using namespace std;


void rotateArray(int **arr, int size)                               //rotate function
{
    for(int i = 0 ; i < size / 2 ; i++)
    {
        for(int j = i ; j < size - 1 - i; j++)
        {
            int temp = arr[ i ][ j ];
            
            arr[ i ][ j ] = arr[ size - 1 - j][ i ];

            arr[ size - 1 - j ][ i ] = arr[ size - 1 - i ][ size - 1 - j ];

            arr[ size - 1 - i ][ size - 1 - j ] = arr[ j ][ size-1-i ];

            arr[ j ][ size-1-i ] = temp;

        }
    }
}
int main()
{
    int size;
    cin >> size;


    int **arr = new int*[size];                 // initializing 2d array
              
    for(int i = 0 ; i < size ;i++)
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


    rotateArray(arr,size);                      // calling function()


    for(int i = 0 ; i < size ; i++)
    {
        for(int j = 0 ; j < size ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
