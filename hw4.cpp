// Chase Maivald
// U18719879

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include "hw4.h"

// (a)
int unsorted_mode(std::vector<int> v) { // counting sort technique

    std::unordered_map<int, int> hash;
    
    for(int i = 0;i < v.size(); i++){
        hash[v[i]]++; //++ the counter hash arr at index v[i] for every instance of a v[i]
    } 

    int max_count = 0, mode = -1;
    for(std::pair<int,int> element : hash){ //
        if(max_count < element.second){
            mode = element.first;
           // std::cout << "i first" << i.first << std::endl;
            
            //std::cout << "i second" << i.second << std::endl;
            max_count = element.second;
        }
    }

    return mode; // 5 bonus
    // time complexity: O(n), space: O(n)
}

// (b)
int sorted_mode(std::vector<int> v) {
int count = 1, total = 0, mode = v[0];

for (int i = 0; i < v.size() - 1; i++){
    if (v[i] == v[i + 1]) {
        count++;
        if (count > total) {
            mode = v[i];
            total = count;
        }
    }
    else{
        count = 1;
    }
}

    return mode;
}

// (c)
std::pair<int,int> unsorted_closest_integers(std::vector<int> v) {
    
    std::pair<int,int> foo;
    sort(v.begin(),v.end());

    int minDiff = v[1] - v[0]; // init  minDiff arbitrarily

    for(int i = 2;i<v.size();i++){ // for rest of vec..
        minDiff = std::min(minDiff,v[i]-v[i-1]); // O(n) runtime
    }

    for(int i =1;i<v.size()-1;i++){
        if((v[i+1] - v[i] == minDiff)){
            return std::make_pair(v[i],v[i+1]); // can't perf within the prev loop -- logic error, early init
        }
    }
}

// (d)
std::pair<std::pair<int,int>,std::pair<int,int>> unsorted_closest_coordinates(std::vector<std::pair<int,int>> v) {
    int size = v.size();
    std::pair<int,int> first,second,pairone,pairtwo;
    int dist,test;
    first = v[0];
    second = v[1];
    dist = sqrt(pow(second.first - first.first,2) + pow(second.second - first.second, 2));
    pairone = first;
    pairtwo = second;
    for(int i = 0;i < size;i++){
        first = v[i];
        for(int j = i+1;j < size; j++){
            second = v[j];
            test = sqrt(pow(second.first - first.first,2) + pow(second.second - first.second, 2));
            if(test != 0 && test < dist){
                dist = test;
                pairone = first;
                pairtwo = second;
            }
        }
    }
/*
float eucl_dist(std::pair<int, int> p1, std::pair<int, int> p2)
{
	return sqrt(pow((p1.first - p2.first), 2)
		+ pow((p1.second - p2.second), 2));
}

double bruteForce(vector<std::pair<int, int >> v, int n, std::pair<int, int > &p1, std::pair<int, int > &p2)
{
	double min = DBL_MAX;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (eucl_dist(v[i], v[j]) < min) {
				min = eucl_dist(v[i], v[j]);
				p1.first = v[i].first, p1.second = v[i].second;
				p2.first = v[j].first, p2.second = v[j].second;
			}
	return min;
}
    // ...
    // your code here
    // ...
    // 10 bonus
    */
   return std::make_pair(std::make_pair(pairone.first,pairone.second),std::make_pair(pairtwo.first,pairtwo.second));
}

// (e)
void flip_sort(std::vector<int> &v) {
    int i,j, length = v.size();
    for(j = length-1; j > 0; j --){ // decrement the index set to the "last" element
        i = distance(v.begin(), max_element(v.begin(), v.begin() + j +1));
        flip(v, i, j); // place the maximum value in the "shortening" array into the "last" index
        }
   /*
    for(int i = 0;i<v.size();i++){
        std::cout << v[i] << " ";
    }
    */
    
}

// (f)
void peak_valley_sort(std::vector<int>& v) {

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i += 2)
        if (i + 1 == v.size()){
            break;
        } 
        else{
            std::swap(v[i], v[i+1]);
        }

/*
    for(int i =0;i<v.size();i++){
        std::cout << v[i] << " ";
    }
    */
}

// (g)
void length_alpha_sort(std::vector<std::string> &v) {

    for(int i = 1;i<v.size();i++){
        for(int j= 0;j<v.size()-i;j++){
            if(v[j].length() > v[j+1].length()){
                swap(v[j],v[j+1]);
        }
        }
    }
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v.size();j++){
            if(v[j].length() == v[j+1].length()){
                int index = 0;
                std::string string1 = v[j];
                std::string string2 = v[j+1];

                while(string1[index] == string2[index]){
                    index++;
                }
                if(string1[index] > string2[index]){
                    swap(v[j],v[j+1]);
                    index = 0;
                }
            }
        }
    }
    /*
    for(int i =0;i<v.size();i++){
        std::cout << v[i] << " ";
    }
*/
}