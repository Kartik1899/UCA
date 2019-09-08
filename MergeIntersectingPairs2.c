// In this question we are given a seperate Interval, which we have to consider while merging the the pairs.

#include<stdio.h>
#include<stdlib.h>

typedef struct pairs{                           // Structure 
    int low;
    int high;
}Pairs;

int compareTo(const void* a, const void* b)                  // qSort comparator 
{
    return ((Pairs *)a)->low - ((Pairs *)b)->low;
}

Pairs* getMergedPairs(Pairs *givenArr, int size,Pairs newPair, int *value)
{
    int i;
    Pairs *allPairs = (Pairs *)malloc((size + 1)*sizeof(Pairs));
    for(i = 0 ; i < size ; i++)
    {
        allPairs[i] = givenArr[i];
    }
    allPairs[i] = newPair;

    qsort(allPairs,size+1,sizeof(allPairs),compareTo);

    Pairs *mergedPairs = (Pairs *)malloc(sizeof(Pairs));
    mergedPairs[0] = allPairs[0];
    

    int index = 0;
    
    for(i = 0 ; i < size + 1; i++)
    {
        if(mergedPairs[index].high >= allPairs[i].low)
        {
            if(mergedPairs[index].high < allPairs[i].high)
            {
                mergedPairs[index].high = allPairs[i].high;
            }
        }
        else
        {
            index++;
            mergedPairs = (Pairs *)realloc(mergedPairs,(index+1)*sizeof(Pairs));
            mergedPairs[index].low = allPairs[i].low;
            mergedPairs[index].high = allPairs[i].high;
        } 
    }

    *value = (index + 1);                                         // we take this index + 1 because index starts from 0;

    return mergedPairs;
    

}







int main()
{
    int size;
    scanf("%d",&size);
    Pairs givenPairs[size];
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d%d",&givenPairs[i].low,&givenPairs[i].high);
    }

    Pairs newPair;
    scanf("%d%d",&newPair.low,&newPair.high);
    
    
    int *value;
    Pairs *finalArr = getMergedPairs(givenPairs,size,newPair,value);
    for(int i = 0 ; i < *value ; i++)
    {
        printf("{%d, %d} ",finalArr[i].low,finalArr[i].high);
    }

    return 0;
}


