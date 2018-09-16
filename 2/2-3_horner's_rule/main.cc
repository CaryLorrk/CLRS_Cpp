#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Input{
    int n;
    int x;
    vector<int> a;
};

Input read_data() {
    Input in;
    cin >> in.n >> in.x;
    in.a.resize(in.n);
    for (int i = 0; i < in.n; ++i) {
        cin >> in.a[i];
    }
    return in;
}

void solve() {
    Input in = read_data();
    int y = 0;
    for (int i = in.n - 1; i >= 0; --i) {
        y = in.a[i] + in.x * y;
    }

    cout << y << endl;
}

int main()
{
    int n_input;
    cin >> n_input;

    while (n_input--) {
        solve();
    }
}
