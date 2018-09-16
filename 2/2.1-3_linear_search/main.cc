#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Input{
    int n;
    int v;
    vector<int> numbers;
};

Input read_data() {
    Input in;
    cin >> in.n >> in.v;
    in.numbers.resize(in.n);
    for (int i = 0; i < in.n; ++i) {
        cin >> in.numbers[i];
    }
    return in;
}

void solve() {
    Input in = read_data();

    int i;
    for (i = 0; i < in.n; ++i) {
        if (in.numbers[i] == in.v) break;
    }

    if (i < in.n) {
        cout << i;
    } else {
        cout << "NIL";
    }
    cout << endl;
}

int main()
{
    int n_input;
    cin >> n_input;

    while (n_input--) {
        solve();
    }
}
