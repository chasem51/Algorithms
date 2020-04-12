#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findKthSmallest(vector<int> A, vector<int> B, int k) {
   
    // Move elements from vector B to the end of vector A
    A.insert(A.end(), B.begin(), B.end());

    sort(A.begin(), A.end());

	return A[k-1]; // you will need to change this
}

/*
int main(){

    // find the kth smallest element in the concatenation of two arrays, where 1<=k<=arr1.size+arr2.size
    vector<int> A{7,5,-2};
    vector<int> B{4,3,2};
    int k = 1;

    cout << findKthSmallest(A,B,k) << endl;

    return 0;
}
*/