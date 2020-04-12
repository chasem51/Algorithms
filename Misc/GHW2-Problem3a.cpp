#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<int> func(vector<int> &g1, int k, vector<int> step)
{
	int curr, count;
    int n = step.size();
	vector<int> intermed;
    for(int i = 0; i < n; i++)
    {
        count = 1;
        for(int j = i + 1; j < n; j++)
        {
            if(step[i] == step[j])
            {
                curr = step[i];
                count ++;
			}
            if(step[i] != step[j])
            {
				curr = step[i];
                intermed.push_back(count);
                intermed.push_back(curr);
                i = j;
                curr = step[j];
                count = 1;
            }
        }
        if(i = n-1)
        {
            intermed.push_back(count);
            intermed.push_back(curr);
        }
    }
	g1.insert(g1.end(), intermed.begin(), intermed.end());
	return intermed;
}

void retry(int k, vector<int> &g1, vector<int> step) {
    try
	{
		g1.at(k);
		
    } catch (const out_of_range& oor)
	{
		step = func(g1, k, step);
		retry(k, g1, step);
    }
}

int kthDigit(int k)
{
	vector<int> step = {1,0};
	vector<int> g1 = {0,1,0};
	retry(k, g1, step);
	return g1.at(k-1);
}


int main(){
    int ans = kthDigit(8);

    cout << "kth digit is: " << ans << endl;
    return 0;
}
