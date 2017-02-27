#include <iostream>
#include <vector>

using namespace std;
 
// Binary Search        
// Complexity -> Theta{ log(N) }
int BSearch(vector<int> &vec, int l, int r, int key) {
    while (r-l > 1) { // While there are alteast 'three' elements
    int m = l + (r-l)/2;
    if (vec[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}

// Function to find LIS in given vector 'v'
// Complexity -> Theta{ N*log(N) }
int Length_LIS(vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming grater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            tail[BSearch(tail, -1, length-1, v[i])] = v[i];
    }
 
    return length;
}
 

// Complexity -> Theta{ N*N*log(N) }
int main() {
    int test_cases;
    cin >> test_cases;
    
    while(test_cases--){
        // Take input the 'number' of elements
        int N;
        cin >> N;
        
        // Take input the 'value' of those elements
        int arr[2*N - 1];
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < N-1; i++)
            arr[i+N] = arr[i];
        
        // Find the 'LIS' from given sub-array
        int LIS_i;
        int max = 0;
        for (int i = 0; i < N; i++){
            vector <int> vec(arr+i, arr+i+N);
            LIS_i = Length_LIS(vec);
            
            if (LIS_i > max)
                max = LIS_i;
        }
        
        // Output
        cout << max << endl;  
        
    }
    
   return 0;
}