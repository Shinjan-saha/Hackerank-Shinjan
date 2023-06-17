#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
     int n, q;
    cin >> n >> q;
    vector<vector<int>> data;
    for (int i = 0 ; i < n; i++) {
        int lenth; cin >> lenth;
        vector<int> actualData;
        for (int j = 0; j < lenth; j++) {
            int elements; cin >> elements;
            actualData.push_back(elements);   
        }
        data.push_back(actualData);
    }
    
    for (int i = 0; i < q; i++) {
        int row, coloumn; cin >> row >> coloumn;
        cout << data[row][coloumn] << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
