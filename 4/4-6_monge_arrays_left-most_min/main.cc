#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <tuple>
#include <cmath>

using namespace std;

class Matrix {
public:
    Matrix(int m, int n): m_(m), n_(n), data_(m*n) {}

    int at(int r, int c) const {
        return data_[r*n_ + c];
    }

    int& at(int r, int c) {
        return data_[r*n_ + c];
    }

    vector<int> leftmost_min() {
        vector<int> ret(m_);
        if (m_ == 1) {
            ret[0] = distance(data_.begin(),
                              min_element(data_.begin(), data_.end()));
            return ret;
        }
        
        auto sub_min = submatrix().leftmost_min();
        for (int r = 0; r < m_; ++r) {
            if (r % 2 == 0) {
                ret[r] = sub_min[r/2];
                continue;
            }
            int upper = sub_min[(r-1)/2];
            int lower = (r == m_ - 1) ? (n_ - 1) : sub_min[(r+1)/2];
            int min_index = upper;
            int min_value = at(r, upper);
            for (int c = upper+1; c <= lower; ++c) {
                if (min_value > at(r, c)) {
                    min_index = c;
                    min_value = at(r, c);
                }
            }
            ret[r] = min_index;
        }
        
        return ret;
    }

    int m() { return m_; }
    int n() { return n_; }

private:
    int m_;
    int n_;
    vector<int> data_;

    Matrix submatrix() {
        Matrix subm(ceil(m_/2.0), n_);
        for (int r = 0; r < subm.m(); ++r) {
            for (int c = 0; c < subm.n(); ++c) {
                subm.at(r, c) = at(r*2, c);
            }
        }
        return subm;
    }

    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);
};

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int r = 0; r < m.m_; ++r) {
        for (int c = 0; c < m.n_; ++c) {
            os << m.at(r, c) << ' ';
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
    Matrix monge;
};

Input read_data() {
    int m;
    int n;
    cin >> m >> n;
    Input in{{ m, n }};
    cin >> in.monge;
    return in;
}

void solve() {
    Input in = read_data();

    auto leftmost_min = in.monge.leftmost_min();
    for (int r = 0; r < in.monge.m(); ++r) {
        cout << in.monge.at(r, leftmost_min[r]) << ' ';
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
