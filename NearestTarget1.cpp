#include<iostream>
#include<algorithm>

// Finding a pair of triplets inside an array such that the sum of them is closest to the given number;

using namespace std;


int compareTo(const void* a, const void*b)
{
    return (*(int*)a - *(int*)b);
}

void findPair(int *arr, int size, int targetNumber)
{
    int i = 0;
    int j;
    int k = size - 1;
    int firstIndex, secondIndex, thirdIndex;
    int minDif = 2147483647;                                     //taking maximum possible value of int for min
    
    
    for( i = 0 ; i < size ; i++ )
    {
        int dif;
        j = i + 1;

        while( j < k) 
        {

            if( arr[i] + arr[j] + arr[k] == targetNumber )                  // if minDif = 0, we don't need to do any more iterations;
            {
                minDif = 0;
                firstIndex = i;
                secondIndex = j;
                thirdIndex = k;
                break;
            }


            else if( arr[i] + arr[j] + arr[k] < targetNumber )              // increasing j index when targetNumber > sum;
            {
                dif = targetNumber - ( arr[i] + arr[j] + arr[k]);
                if( dif < minDif)
                {
                    minDif = dif;
                    firstIndex = i;
                    secondIndex = j;
                    thirdIndex = k;
                }
                j++;
            }


            else                                                            // decreasing k index when targetNumber < sum;
            {
                dif = (arr[i] + arr[j] + arr[k]) - targetNumber;
                if( dif < minDif)
                {
                    minDif = dif;
                    firstIndex = i;
                    secondIndex = j;
                    thirdIndex = k;
                }
                k--;
            }

        }
        
        if(minDif == 0)                                         // breaking loop because sum of elements = target
        {
            break;
        }
    }

    cout << arr[firstIndex] << " " << arr[secondIndex] << " " << arr[thirdIndex] << endl;                     // printing the triplet;

}


int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];               // initializing array 
    
    for(int i = 0 ; i < size ;i++)
    {
        cin >> arr[i];
    }

    qsort(arr,size,sizeof(arr[0]),compareTo);    // sorting array

    int num;                                    // Target number
    cin >> num;


    findPair(arr,size,num);                     // calling function()
    
    delete arr;                                 // freeing memory
    
    return 0;

}