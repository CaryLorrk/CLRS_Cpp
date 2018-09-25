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

Result max_cross(Input& in, int begin, int mid, int end) {
    int l_value = in.numbers[mid - 1];
    int l_max = mid - 1;
    int l_max_value = l_value;

    for (int i = mid - 2; i >= begin; --i) {
        l_value += in.numbers[i];
        if (l_value > l_max_value) {
            l_max = i;
            l_max_value = l_value;
        }
    }

    int r_value = in.numbers[mid];
    int r_max = mid;
    int r_max_value = r_value;
    for (int i = mid + 1; i < end; ++i) {
        r_value += in.numbers[i];
        if (r_value > r_max_value) {
            r_max = i;
            r_max_value = r_value;
        }
    }

    return {l_max, r_max + 1, l_max_value + r_max_value};
}

Result max_subarray(Input& in, int begin, int end) {
    if (end - begin <= 1) return {begin, end, in.numbers[begin]};

    int mid = (begin + end) / 2;
    return max({max_subarray(in, begin, mid),
                max_subarray(in, mid, end), 
                max_cross(in, begin, mid, end)},
                [](const Result& rhs, const Result& lhs) {
                    return rhs.value < lhs.value;
                });
}

void solve() {
    Input in = read_data();
    
    Result res = max_subarray(in, 0, in.n);

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
