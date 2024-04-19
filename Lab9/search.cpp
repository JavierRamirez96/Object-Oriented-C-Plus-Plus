#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
using namespace std;

/**
 * @brief returns the first index of elem if it exists, otherwise returns -1
 * iterativeSearch starts at the first index and iterates sequentially to the next until it either
 * finds the element or until it reaches the end (i.e. element does not exist)
 * 
 * @param v: vector of elemnts
 * @param elem: integer to look for
 * @return int
*/
int iterativeSearch(vector<int> v, int elem){
    for(int i = 0; i < v.size(); i++){
        if (v[i] == elem){
         return i;
         }
    }
    return -1;
}

/**
 * @brief returns the index of elem, if it exists in v. Otherwise it returns -1.
 * binarySearch is recursive (i.e. function calls itself).
 * It utilizes the fact that v is increasing order (e.g. values go up and
 * duplicates are not allowed).
 * 
 * It calculates the mid from the start and end index. It compares v[mid] (i.e. value
 * at mid) with elem and decides whether to search the left half (lower values)
 * or right half (upper values).
 * 
 * @param v: vector of elements
 * @param start: leftmost index (starting value is 0)
 * @param end: rightmost index ( starting value is v.size())
 * @param elem: integer to look for
 * @return int
*/
int binarySearch(vector<int> & v, int start, int end, int elem){
if (start > end){
    return -1;
}
int mid = (start + end) / 2; // intilizes mid
if (v[mid] > elem){
    end = mid -1;          // search left half
}
else if (v[mid] < elem){   
    start = mid + 1;      // search right half
}
else {
    return mid;          // found elem
}
return binarySearch(v, start, end, elem);
}

/**
 * @brief updates v to contain values from filename (leave as is)
 * 
 * It is expected that the files contain values ranging from one to
 * one hundred million in ascending order (no duplicates).
 * 
 * @param filename: string
 * @param v: vector
*/
void vecGen(string filename, vector<int> & v){
    ifstream file(filename);
    int num;
    v.clear();
    while(file.is_open() && file >> num){
        v.push_back(num);
    }
    file.close();
}

int main(){
    //populate v with 10000 sorted numbers (leave as is)
    vector <int> v;
    vecGen("10000_numbers.csv", v);

    // test elements to search for (leave as is)
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    // reads through all 10 of the test_elem values and calls iterative search
    // and records how long each search took (leave as is)
    for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock();                        // start time
        int index_if_found = iterativeSearch(v, elem); // call search
        clock_t end = clock();                         // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        
        //prints the index and how long it took to find it
        cout << "Iterative Search: " << index_if_found << " " << "Time: " << elapsed_time_in_sec << endl;

    }

    // records how long binarySearch took to do the same operation
     for(int i = 0; i < elem_to_find.size(); i++) {
        // gets the elem to search for
        int elem = elem_to_find[i];

        // stopwatches the time
        clock_t start = clock();                        // start time
        int index_if_found = binarySearch(v, 0, v.size(), elem); // call search
        clock_t end = clock();                         // end time

        // calculates the total time it took in seconds
        double elapsed_time_in_sec = (double(end - start)/CLOCKS_PER_SEC);
        
        //prints the index and how long it took to find it
        cout << "Binary Search: " << index_if_found << " " <<  "Time: " << elapsed_time_in_sec << endl;

    }
    return 0;
}
