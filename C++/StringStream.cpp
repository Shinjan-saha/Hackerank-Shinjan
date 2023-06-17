#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	stringstream sstream = stringstream(str);
    vector<int> vec;
    int temp;
    
    while( sstream >> temp)
    {
        char ch;
        vec.push_back(temp);
        if (!sstream.eof())
            sstream >> ch;
    }
    return vec;// Complete this function
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
