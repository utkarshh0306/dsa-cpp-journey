#include <iostream>
#include <string>
using namespace std;

void subsetPrint(string str, string subset) {
    if (str.size() == 0) {
        cout << subset << endl;
        return;
    }

    char ch = str[0];

    // Include current character
    subsetPrint(str.substr(1), subset + ch);

    // Exclude current character
    subsetPrint(str.substr(1), subset);
}

int main() {
    string str = "abc";
    string subset = "";

    subsetPrint(str, subset);

    return 0;
}