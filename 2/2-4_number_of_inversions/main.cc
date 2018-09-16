#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

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

int merge_sort(Input &in, int begin, int end) {
    if (end - begin <= 1) return 0;
    int mid = (begin + end)/2;
    int count = 0;
    count += merge_sort(in, begin, mid);
    count += merge_sort(in, mid, end);

    vector<int> L(in.numbers.begin() + begin, in.numbers.begin() + mid);
    vector<int> R(in.numbers.begin() + mid, in.numbers.begin() + end);
    auto li = L.begin();
    auto ri = R.begin();
    auto it = in.numbers.begin() + begin;
    while (li != L.end() && ri != R.end()) {
        if (*li < *ri) {
            *it = *li;
            ++li;
        } else {
            *it = *ri;
            ++ri;
            count += distance(li, L.end());
        }
        ++it;
    }

    copy(li, L.end(), it);
    copy(ri, R.end(), it);
    return count;
}

void solve() {
    Input in = read_data();

    cout << merge_sort(in, 0, in.n);

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
