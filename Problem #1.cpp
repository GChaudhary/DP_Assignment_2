// ZigZag Problem

#include <iostream>
#include <vector>

using namespace std;


// Function to return maximum of two numbers
// Complexity -> Theta{1}
int max(int a, int b){
    return (a > b) ? a : b; 
}
 
// Function to return 'length' of Longest Zig-Zag Subsequence
// Complexity -> Theta{ N^2 }
int longestZigZag(vector<int> &vec)
{
    int size = vec.size();

    int arrZigZag[size][2];

    // Initialize all values from 1
    for (int i = 0; i < size; i++)
        arrZigZag[i][0] = arrZigZag[i][1] = 1;
 
    int maxZigZag = 1; // Initialize result
 
    // Compute values in bottom up manner
    for (int i = 1; i < size; i++)
    {
        // Consider all elements as previous of vec[i]
        for (int j = 0; j < i; j++)
        {
            // If vec[i] is greater, then check with arrayZigZag[j][1]
            if (vec[j] < vec[i] && arrZigZag[i][0] < arrZigZag[j][1] + 1)
                arrZigZag[i][0] = arrZigZag[j][1] + 1;
 
            // If vec[i] is smaller, then check with arrZigZag[j][0]
            if( vec[j] > vec[i] && arrZigZag[i][1] < arrZigZag[j][0] + 1)
                arrZigZag[i][1] = arrZigZag[j][0] + 1;
        }
 
        // Pick maximum of both values at index i
        if (max(arrZigZag[i][0], arrZigZag[i][1]) > maxZigZag)
            maxZigZag = max(arrZigZag[i][0], arrZigZag[i][1]);
    }
 
    return maxZigZag;
}
 

int main()
{
    vector <int> vec_array;
    // Test_Cases
    // #1
    vec_array = { 1, 7, 4, 9, 2, 5 };
    // Output
    cout << "Input - { 1, 7, 4, 9, 2, 5 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    // #2
    vec_array = { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 };
    cout << "Input - { 1, 17, 5, 10, 13, 15, 10, 5, 16, 8 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    // #3
    vec_array = { 44 };
    cout << "Input - { 44 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    // #4
    vec_array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cout << "Input - { 1, 2, 3, 4, 5, 6, 7, 8, 9 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    // #5
    vec_array = { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
    cout << "Input - { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    // #6
    vec_array = { 374, 40, 854, 203, 203, 156, 362, 279, 812, 955, 600, 947, 978, 46, 100, 953, 670, 862, 568, 188, 67, 669, 810, 704, 52, 861, 49, 640, 370, 908, 477, 245, 413, 109, 659, 401, 483, 308, 609, 120, 249, 22, 176, 279, 23, 22, 617, 462, 459, 244 };
    cout << "Input - { 374, 40, 854, 203, 203, 156,...., 459, 244 }" << endl;
    cout << "Length of Longest Zig-Zag subsequence is " << longestZigZag(vec_array) << endl << endl;

    



    return 0;
}
