#include <iostream>
#include <vector>
#include <algorithm>

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

int binary_search(Input &in, int begin, int end) {
    if (end - begin == 1) {
        return in.numbers[begin] == in.v ? begin : -1;
    }
    int mid = (begin + end) / 2;
    int ret = binary_search(in, begin, mid);
    if (ret != -1) {
        return ret;
    }

    ret = binary_search(in, mid, end);
    return ret;
}

void solve() {
    Input in = read_data();

    int ret = binary_search(in, 0, in.n);
    if (ret < 0) {
        cout << "NIL";
    } else {
        cout << ret;
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
