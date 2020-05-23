#include <iostream>
#include <vector>

using namespace std;

int kthDigit(int k){
    int ctr = 1;
    int places = 1;
    vector <int> values{0};
    
    while(1){        
        int value = values[places];
        //leave ctr to 1,
        cout << "places: " << places << endl;
        
        for(int i = 0;i<places;i++){
            ctr = 1;
            if(values.size() == 1){
                break;
            }
            cout << "values ith index: " << values[i] << endl;
            
            cout << "values ith + 1 index " << values[i+1] << endl;

            while(values[i] == values[i+1]){ // check how many instances of the same #
                i++;
                ctr++;
                cout << "hey";
            }

            values.push_back (ctr);
            cout << "ctr: " << ctr << endl; // append the count of the value to the loop
        
            values.push_back (values[i]);               // append the counted value to the loop
            cout << "value: " << value << endl;
                cout << "he2y";
            i+2;
        
        }
        values.push_back (ctr);
        places++;

        values.push_back (value);
        places++;
        
        cout << "contents" << endl;
        for(int j = 0;j<values.size();j++){
            cout << values[j] << endl;
        }
        
        if(k <= values.size()){ // break when the kth index is discovered
            cout << "places: " << places << endl;
            break;
        }
    }
    
    return values[k-1];
}


int main(){
    int ans = kthDigit(10);

    cout << "kth digit is: " << ans << endl;
    return 0;
}

