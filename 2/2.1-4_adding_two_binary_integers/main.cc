#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct Input{
    int n;
    vector<int> A;
    vector<int> B;
};

Input read_data() {
    Input in;
    cin >> in.n;
    in.A.resize(in.n);
    in.B.resize(in.n);
    for (int i = 0; i < in.n; ++i) {
        char e;
        cin >> e;
        in.A[i] = static_cast<int>(e - '0');
    }

    for (int i = 0; i < in.n; ++i) {
        char e;
        cin >> e;
        in.B[i] = static_cast<int>(e - '0');
    }
    return in;
}

void solve() {
    Input in = read_data();

    vector<int> C(in.n + 1);
    int carry = 0;

    for (int i = in.n - 1; i >= 0; --i) {
        int sum = in.A[i] + in.B[i] + carry;
        carry = sum >> 1;
        C[i+1] = sum & 1;
    }
    C[0] = carry;

    for (auto x: C) {
        cout << x;
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
