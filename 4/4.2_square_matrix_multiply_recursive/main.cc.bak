#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
#include <tuple>

using namespace std;

class Matrix {
public:
    Matrix(int n): n_(n), data_(n*n) {}

    int at(int r, int c) const {
        return data_[r*n_ + c];
    }

    int& at(int r, int c) {
        return data_[r*n_ + c];
    }

    Matrix operator*(const Matrix& rhs) {
        if (n_ == 1) {
            Matrix ret(1);
            ret.data_[0] = data_[0] * rhs.data_[0];
            return ret;
        }
        auto [a00, a01, a10, a11] = split();
        auto [b00, b01, b10, b11] = rhs.split();
        return {a00*b00 + a01*b10, a00*b01 + a01*b11,
                a10*b00 + a11*b10, a10*b01 + a11*b11};
    }

    Matrix operator+(const Matrix& rhs) {
        Matrix ret(n_);
        for (int i = 0; i < n_*n_; ++i) {
            ret.data_[i] = data_[i] + rhs.data_[i];
        }
        return ret;
    }

    Matrix operator-(const Matrix& rhs) {
        Matrix ret(n_);
        for (int i = 0; i < n_*n_; ++i) {
            ret.data_[i] = data_[i] - rhs.data_[i];
        }
        return ret;
    }
private:
    int n_;
    vector<int> data_;

    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend istream& operator>>(istream& is, Matrix& m);

    Matrix(const Matrix& c00, const Matrix& c01,
            const Matrix& c10, const Matrix& c11): n_(c00.n_*2), data_(n_*n_){
        int mid = n_/2;
        for (int r = 0; r < mid; ++r) {
            for (int c = 0; c < mid; ++c) {
                at(r, c) = c00.at(r, c);
                at(r, c+mid) = c01.at(r, c);
                at(r+mid, c) = c10.at(r, c);
                at(r+mid, c+mid) = c11.at(r, c);
            }
        }
    }

    tuple<Matrix, Matrix, Matrix, Matrix> split() const {
        int mid = n_/2;
        Matrix m00(mid), m01(mid), m10(mid), m11(mid);
        for (int r = 0; r < mid; ++r) {
            for (int c = 0; c < mid; ++c) {
                m00.at(r, c) = at(r, c);
                m01.at(r, c) = at(r, c+mid);
                m10.at(r, c) = at(r+mid, c);
                m11.at(r, c) = at(r+mid, c+mid);
            }
        }
        return make_tuple( m00, m01, m10, m11 );
    }
};

ostream& operator<<(ostream& os, const Matrix& m) {
    for (int r = 0; r < m.n_; ++r) {
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
