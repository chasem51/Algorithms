// Chase Maivald
// U18719879

#include "sumProductDigit.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


int sumProductDigit(int a, int b)
{
    int ans = a*b;
    if(ans == 0)
    {
        return 0;
    }
    else if(ans % 9 == 0)
    {
        return 9;
    }
    else
    {
        return ans % 9; 
        // the digit sum of an integer = int % 9
    }
}