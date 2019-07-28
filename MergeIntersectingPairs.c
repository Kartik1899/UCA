#include<stdio.h>
#include<stdlib.h>


typedef struct pairs {                                              // defining structure
    int low;
    int high;
} Pairs;



int compareTo(const void* a, const void* b)
{
        return (((Pairs *)a)->low - ((Pairs *)b)->low);
}

int mergePairs(Pairs *arr, int size,Pairs *mergedPairs)
{
    int count = 0;
    mergedPairs[0] = arr[0];

    for(int i = 0 ; i < size; i++)
    {
        if(mergedPairs[count].high >= arr[i+1].low)                             // checking if pairs can be merged
        {

            if(mergedPairs[count].high <= arr[i+1].high)
            {
                mergedPairs[count].high = arr[i+1].high;
            }

        }
        else
        {

            count++;
            mergedPairs = (Pairs *)realloc(mergedPairs,(count+1)*sizeof(Pairs));            // allocating more space to array if pairs don't merge
            mergedPairs[count].low = arr[i+1].low;
            mergedPairs[count].high = arr[i+1].high;
        
        }        
    }

    return count;                                                       // returning size of mergedPairs
}


int main()
{
    int size;
    scanf("%d",&size);

    Pairs *arr = (Pairs*)malloc(size*sizeof(Pairs));                    // initializing structure array

    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d",&arr[i].low);
        scanf("%d",&arr[i].high);
    }

    qsort(arr,size,sizeof(Pairs),compareTo);                           // sorting 

    Pairs *mergedPairs = (Pairs *)malloc(1*sizeof(Pairs));             // initializing another array to store merged pairs


    int s = mergePairs(arr,size,mergedPairs);                          // calling function()

    for(int i = 0 ; i < s ; i++)
    {
        printf("{ %d, %d}     ",mergedPairs[i].low,mergedPairs[i].high);
    }

    return 0;

}