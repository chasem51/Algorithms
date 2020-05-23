#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

void zigzagSort(vector<int> &nums) {

bool flip = true; 
  
    for (int i=0; i<=nums.size()-2; i++) 
    { 
        if (flip)  // allows the if else loop to flip, so the values alternate in a < > < ... pattern
        { 
            if (nums[i] > nums[i+1]) 
                swap(nums[i], nums[i+1]); 
        } 
        else
        { 
            if (nums[i] < nums[i+1]) 
                swap(nums[i], nums[i+1]); 
        } 
        flip = !flip; // flip the operation of the next if else loop
    } 
} 
/*
int main()
{
    vector<int> ar = { 1, 3, 2, 4, 200,20}; 
    zigzagSort(ar);

    return 0;
}
*/
