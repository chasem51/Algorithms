// Chase Maivald
// U18719879

#include <iostream>
#include <string>
#include <vector>
#include "hw4.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "Welcome to Chase M's EC330 HW4." << endl << endl;
   
    vector<int> scrambled{-123324,300002,30,30,-400,5,5,10};
    vector<int> unscrambled{-2,-1,10,100,100,100};

    vector<string> alpha;
    alpha.push_back("EC330");
    alpha.push_back("homework4");
    alpha.push_back("EC327");
    alpha.push_back("033CE");

    pair<int,int> unsorted_closepair;

    unsorted_closepair = unsorted_closest_integers(scrambled);

    pair<int,int> point1;
    pair<int,int> point2;
    
    cout << "Problem a)" << endl;
    cout << "The most popular integer in my unsorted vector is: " << endl << unsorted_mode(scrambled) << endl;
    cout << endl;
    
    cout << "Problem b)" << endl;
    cout << "The most popular integer in my sorted vector is: " << endl << sorted_mode(unscrambled) << endl;
    cout << endl;
    
    cout << "Problem c)" << endl;
    cout << "The pair of integers closest in value in my unsorted vector are: " << endl << "(" << unsorted_closepair.first << ", " << unsorted_closepair.second << ")" << endl;
    cout << endl;
    
    cout << "Problem d)" << endl;
    cout << "The pair of points closest in my unsorted 2D plane are: " << endl << "(" << point1.first << ", " << point2.second << ") & (" << point2.first << ", " << point2.second << ")" << endl;
    cout << endl;

    cout << "Problem e)" << endl;
    flip_sort(scrambled);
    cout << endl;
    cout << "The vector has been sorted by the flip i,j operation." << endl;
    cout << endl;

    cout << "Problem f)" << endl;
    
    peak_valley_sort(scrambled);
    cout << endl;
    cout << "The vector has been peak valley sorted." << endl;
    cout << endl;

    cout << "Problem g)" << endl;
    length_alpha_sort(alpha);
    cout << endl;
    cout << "The list of alphanumeric strings has been sorted." << endl;
    cout << endl;       
}