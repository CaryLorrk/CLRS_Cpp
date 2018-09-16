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

void solve() {
    Input in = read_data();

    for (int i = 0 ; i < in.n; ++i) {
        for (int j = in.n - 1 ; j > i; --j) {
            if (in.numbers[j] < in.numbers[j - 1]) 
                swap(in.numbers[j], in.numbers[j - 1]);
        }
    }

    for (auto x: in.numbers) {
        cout << x << ' ';
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
