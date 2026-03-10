/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;
    int n;
    cin >> n;

    while (n--) {
        string op;
        cin >> op;

        if (op == "push_front") {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (op == "push_back") {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (op == "pop_front") {
            if (!dq.empty())
                dq.pop_front();
            else
                cout << "Deque is empty\n";
        }
        else if (op == "pop_back") {
            if (!dq.empty())
                dq.pop_back();
            else
                cout << "Deque is empty\n";
        }
        else if (op == "front") {
            if (!dq.empty())
                cout << dq.front() << endl;
            else
                cout << "Deque is empty\n";
        }
        else if (op == "back") {
            if (!dq.empty())
                cout << dq.back() << endl;
            else
                cout << "Deque is empty\n";
        }
        else if (op == "empty") {
            if (dq.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if (op == "size") {
            cout << dq.size() << endl;
        }
        else if (op == "clear") {
            dq.clear();
        }
    }

    cout << "Final Deque: ";
    if (dq.empty()) {
        cout << "Empty";
    } else {
        for (int x : dq)
            cout << x << " ";
    }
    cout << endl;

    return 0;
}