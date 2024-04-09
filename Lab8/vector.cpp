#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param arr - vector of integers
*/
void printMemVec(vector<int> v) { // void printMemArr(int arr[], int size)
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i = 0; i < v.size(); i++) {
        printf("Value :%i at Memory Location: %p\n", v[i], &v + i);
    }
}

/**
 * @brief increments all of the elements in arr by 10
 * 
 * @param arr - array of the integers
 * @param size - the numbers of elements in the array
*/
void incVecBy10(vector<int> & v) {
    for(int i = 0; i < v.size(); i++) {
        v[i] += 10;
    }
}

int main(){
    const int SIZE = 5;
    vector<int> vec(SIZE);
    for(int i = 0; i < SIZE; i ++){
        vec[i] = 100 + i;
    }
    printf("Before Increment ---------------\n");
    printMemVec(vec);
    incVecBy10(vec);
    printf("After Increment-----------------\n");
    printMemVec(vec);
    vec.pop_back();
    printf("After Pop---------------\n");
    printMemVec(vec);
    vec.push_back(101);
    vec.push_back(102);
    printf("After Push---------------\n");
    printMemVec(vec);
    return 0;
}