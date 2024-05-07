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

/**
 * @brief write to file the time it took to search with respect to the
 * size of the vector, n
 * Number of Elements (n)           Time(sec)
   XXXX                             X.XXXXX
   XXXX                             X.XXXXX
* @param filename (string) : filename (e.g. output_10000_numbers.csv)
* @param times (vector<double>) : average times
* @param n (vector<int>) : sizes of vectors
*/
void writeTimes(string filename, const vector <double> times, const vector<int> n){
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec)" << endl;
    for(int i = 0; i < times.size(); i++){
        
        myFile << n[i] << "\t" << times[i] << "\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}
/**
 * @brief computes the average of the elements in vector, a
 * 
 * @param a vector of double
 * @return double
*/
double average(const vector <double> a){
    double averageVal = 0;
    double sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum = sum + a[i];
    }
    averageVal = sum / a.size();
    return averageVal;
    }
    
int main(){
    // test elements to search for
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);
    // size (n) of all tests
    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    // n list of numbers
    vector<int> v;

    // results of times
    vector<double> times;

    // averages
    vector<double> avg;

    // create a for loop to iterate through the file sizes
    for(int i = 0; i < file_sizes.size(); i++){
        // get the name/size of the file and assign it to string called filename
       string filename = to_string(file_sizes[i]) + "_numbers.csv";
       // call vecGen on filename an dv
       vecGen(filename, v);

       //call times.clear()
       times.clear();

       // create another for loop to iterate through all th elements from elem_to_find.
       // the code here should be nearly identical to the code from the previous lab.
        for(int i = 0; i < elem_to_find.size(); i++){
            // gets the elem to search for
            int elem = elem_to_find[i];

            // stopwatches the time
            auto start = chrono::high_resolution_clock::now();               // start
            int index_if_found = iterativeSearch(v, elem);                  // call search
            auto end = chrono::high_resolution_clock::now();

            // calculates the total time it took in seconds
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
            
            // append the elapsed_time_in_sec to the vector, times
            // this code should be within the for loop that iterates
            // through all the elements
            times.push_back(duration.count());
        }
        // call average on the vector, times, and save it as a double. This code should be
        // outside the for loop that iterates through all the elements from elem_to_find.
        // but within the for loop that iterates through the file sizes
        double v_avg = average(times);

        // append the double to avg.
        // This code should be outside the fo rloop that iterates through
        // all the elements from elem_to_find
        // but within the for loop that iterates through the file sizes
        avg.push_back(v_avg);
    }
    
    // outside both for loops call writeTimes with the appropriate parameters
    // the first parameter should be "iterativeSearch_times.csv"
    // read the function brief to complete the rest of the parameters
    writeTimes("iterativeSearch_times.csv", avg, file_sizes);

    // avg.clear() to reset avg, so we can use it for binarySearch
    avg.clear();

    // repeat the nested "for" loops used for iterativeSearch, but call binarySearch instead
    for(int i = 0; i < file_sizes.size(); i++){
        string filename = to_string(file_sizes[i]) + "_numbers.csv";

        vecGen(filename, v);

        times.clear();

        for(int i = 0; i < elem_to_find.size(); i++){
            int elem = elem_to_find[i];
            int start_v = 0;
            int end_v = v.size() - 1;

            auto start = chrono::high_resolution_clock::now();
            int index_if_found = binarySearch(v, start_v, end_v, elem);
            auto end = chrono::high_resolution_clock::now();
            
            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

            times.push_back(duration.count());
        }

        double v_avg = average(times);

        avg.push_back(v_avg);
    }

    writeTimes("binarySearch_times.csv", avg, file_sizes);

return 0;
}
   