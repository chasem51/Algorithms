// Chase Maivald
// U18719879

#include "findSingle.h"
#include <iostream>
using namespace std;

int findSingle(int arr[], int arr_size)
{
    int found;
    int current;
    int temp;

    for(int i = 0; i<arr_size;i++)
    {
        int count = 0;
        for(int j = 0;j<arr_size;j++)
        {
            if(i == j) // prevents the nested loop from checking the index against itself
            {
                j++;
            }
            current = arr[i]; 
            //cout << "here" << current << endl;
            temp = arr[j];  
            //cout << "there" << temp << endl;    
            if(current == temp)
            {
               count++;
               j = arr_size;
            }
            else if(j == (arr_size-1) && count<1)
            {
                found = current;
                return found; // returns the element that doesnt repeat
            }
        }
    }  
}