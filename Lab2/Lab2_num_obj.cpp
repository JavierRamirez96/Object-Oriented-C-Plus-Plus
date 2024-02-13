//Lab2_num_obj.cpp
/*
This lab shows an example of each C++ data type and the amount of memory
each data type takes up.
*/

#include <iostream>
#include <ctsdlib>
using namespace std;

int main() {
    //numerical
    int int_example = 1;
    float float_example = 2.0;
    double double_example = 2.0;

    //non-numerical
    char char_example = 'a';
    bool bool_example = true;

    //sizeof returns the number of bytes (8 bits is equivalent to 1 byte)
    cout << "int_example: " << sizeof(int_example) << endl;
    cout << "float_example: " << sizeof(float_example) << endl;
    cout << "double_example: " << sizeof(double_example) << endl;

    cout << "char_example: " << sizeof(char_example) << endl;
    cout << "bool_example: " << sizeof(bool_example) << endl;
    }