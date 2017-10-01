#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> test;
    test.push_back(5);
    test.push_back(10);
    test.push_back(100);
    test.insert(test.begin(), 1);
    cout << test.back() << " " << test.front() << " " << test[0] << endl;
    return 0;
}

void disp(vector<con> items) {
    for(int i = 0; i < items.size(); i++) {
        cout << items[1] << " ";
    }
}
