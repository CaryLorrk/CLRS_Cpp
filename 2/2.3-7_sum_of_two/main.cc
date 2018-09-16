#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

struct Input{
    int n;
    int x;
    vector<int> S;
};

Input read_data() {
    Input in;
    cin >> in.n >> in.x;
    in.S.resize(in.n);
    for (int i = 0; i < in.n; ++i) {
        cin >> in.S[i];
    }
    return in;
}

void solve() {
    Input in = read_data();

    sort(in.S.begin(), in.S.end());
    auto l = 0;
    auto r = in.n - 1;

    cout << boolalpha;
    while (l < r) {
        int sum = in.S[l] + in.S[r];
        if (sum == in.x) {
            cout << true << endl;
            return;
        } else if (sum < in.x){
            ++l;
        } else {
            --r;
        }
    }
    cout << false << endl;
}

int main()
{
    int n_input;
    cin >> n_input;

    while (n_input--) {
        solve();
    }
}
