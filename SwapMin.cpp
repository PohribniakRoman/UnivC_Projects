#include <iostream>

using namespace std;


template<size_t r>
void swap_min(int (*m)[r], unsigned rows, unsigned cols){
    int min = m[0][0];
    int lowestNumRow = 0;
    for (int i = 0; i < rows; ++i) {
        int minCurrent = min;
        for (int j = 0; j < cols; ++j) {
            if(minCurrent > m[i][j]){
                minCurrent = m[i][j];
                lowestNumRow = i;
            }
        }
        if(minCurrent < min){
            min = minCurrent;
        }
    }
    swap(m[0],m[lowestNumRow]);
}


template<size_t a>
void visualise(int (*m)[a], unsigned rows, unsigned cols){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << m[i][j] << "\t";
        }
        cout << "|" << endl;
    }
}


int main(){
    const int rows = 5;
    const int cols = 4;
    int arr[rows][cols] = {
            {10,  22,   13,  15},
            {120, 130,  150, 160,},
            {1,   2,    3,   5},
            {14,  3000, -12, 16},
            {66,  73,84,92}
    };
    swap_min( arr,rows, cols);
    visualise(arr,rows, cols);
    return 0;
}