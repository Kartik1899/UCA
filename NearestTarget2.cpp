#include<iostream>

// finding triplet inside an array such that its sum is equal to target number

using namespace std;

void findTriplet(int *arr, int size, int target)
{                                                // In BruteForce method we do not sort the array and hence have to compare all possible elements
    
    int minDif = 2147483647;
    int first, second, third;
    int dif;
    
    for(int i = 0 ; i < size; i++)
    {
        for(int j = i+1 ; j < size ; j++)
        {
            for(int k = j+1 ; k < size ; k++)
            {
                int sum = arr[i] + arr[j] + arr[k];
                
                if(sum == target)                                       // We don't need any more iterations if sum = target
                {
                    minDif = 0;
                    first = i;
                    second = j;
                    third = k;
                    break;
                }

                else if( sum < target)
                {
                    dif = target - sum;
                    if(dif < minDif)                                    // keeping indexs of elements saved when difference is min
                    {
                        minDif = dif;
                        first =  i;
                        second = j;
                        third = k;
                    }
                }
                else
                {
                    dif = sum - target;
                    if( dif < minDif )                                  // keeping indexs of elements saved when difference is min
                    {
                        minDif = dif;
                        first  = i;
                        second = j;
                        third = k;
                    }
                }
            }
            if(minDif == 0)
                break;
        }
        if(minDif == 0)
            break;
    }

    cout << arr[first] << " " << arr[second] << " " << arr[third] << endl;

}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];           // initializing array

    for(int i = 0 ; i < size; i++)
    {
        cin >> arr[i];
    }

    int num;                            // target number
    cin >> num;


    findTriplet(arr,size,num);          // calling function()

    delete arr;

    return 0;

}