#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

struct Input{
    int n;
    vector<int> numbers;
};

Input read_data() {
    Input in;
    cin >> in.n;
    in.numbers.resize(in.n);
    for (int i = 0; i < in.n; ++i) {
        cin >> in.numbers[i];
    }
    return in;
}

struct Result {
    int begin;
    int end;
    int value;
};

void solve() {
    Input in = read_data();

    Result res = {0, 1, in.numbers[0]};

    for (int begin = 0; begin < in.n; ++begin) {
        int sum = 0;
        for (int end = begin + 1; end <= in.n; ++end) {
            sum += in.numbers[end - 1];
            if (sum > res.value) res = {begin, end, sum};
        }
    }

    cout << res.begin << ' ' << res.end << ' ' << res.value << endl;
}

int main()
{
    int n_input;
    cin >> n_input;

    while (n_input--) {
        solve();
    }
}
