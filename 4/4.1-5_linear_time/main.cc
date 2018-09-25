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
    int begin = 0;
    int sum = in.numbers[0];
    if (in.numbers[0] > 0) {
        ++begin;

    }
    for (int i = 1; i < in.n; ++i) {
        if (sum <= 0 ) {
            begin = i;
            sum = 0;
        }
        sum += in.numbers[i];
        if (sum > res.value) {
            res.begin = begin;
            res.end = i + 1;
            res.value = sum;
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
