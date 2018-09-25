#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

using namespace std;

class Matrix {
public:
    Matrix(int n): n_(n), data_(n*n) {}

    int& at(int r, int c) {
        return data_[r*n_ + c];
    }

    int size() const {
        return n_;
    }

    Matrix operator*(Matrix& rhs) {
        Matrix ret(n_);
        for (int r = 0; r < n_; ++r) {
            for (int c = 0; c < n_; ++c) {
                for (int k = 0; k < n_; ++k) {
                    ret.at(r, c) += at(r, k) * rhs.at(k, c);
                }
            }
        }
        return ret;
    }
private:
    int n_;
    vector<int> data_;
    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);
};

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int r = 0; r < m.n_; ++r) {
        for (int c = 0; c < m.n_; ++c) {
            os << m.data_[r*m.n_ + c] << ' ';
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& m) {
    for (int& x: m.data_) {
        is >> x;
    }
    return is;
}

struct Input{
    Matrix m1;
    Matrix m2;
};

Input read_data() {
    int n;
    cin >> n;
    Input in{n, n};
    cin >> in.m1 >> in.m2;
    return in;
}

void solve() {
    Input in = read_data();
    cout << in.m1 * in.m2;
}

int main()
{
    int n_input;
    cin >> n_input;

    while (n_input--) {
        solve();
    }
}
