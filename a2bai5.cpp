#include <iostream>
#include <vector>

using namespace std;

bool findFixedPoint(vector<int> a, int left, int right) {
    if (right < left) {
        return false;
    }
    
    int mid = (left + right) / 2;
    
    if (a[mid] == mid) {
        return true;
    } else if (a[mid] > mid) {
        return findFixedPoint(a, left, mid - 1);
    } else {
        return findFixedPoint(a, mid + 1, right);
    }
}

int main() {
    vector<int> a;
    a.push_back(-10);
    a.push_back(-5);
    a.push_back(0);
    a.push_back(3);
    a.push_back(7);
    int n = a.size();
    
    if (findFixedPoint(a, 0, n - 1)) {
        cout << "There exists an integer i such that ai = i" << endl;
    } else {
        cout << "There does not exist an integer i such that ai = i" << endl;
    }
    
    return 0;
}

