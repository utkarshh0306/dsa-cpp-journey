#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert elements
    dq.push_back(10);   // Insert at rear
    dq.push_back(20);
    dq.push_front(5);  // Insert at front
    dq.push_front(1);

    // Display deque
    cout << "Deque: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // Delete elements
    dq.pop_front();    // Delete from front
    dq.pop_back();     // Delete from rear

    cout << "After deletion: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // Access elements
    cout << "Front element: " << dq.front() << endl;
    cout << "Rear element: " << dq.back() << endl;

    return 0;
}