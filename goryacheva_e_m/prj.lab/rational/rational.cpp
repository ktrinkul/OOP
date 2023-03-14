#include <rational/rational.hpp>

int32_t gcd(int32_t a, int32_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

Rational::Rational(int32_t num) noexcept : num_(num), den_(1) {};

Rational::Rational(int32_t num, int32_t denom) : num_(num), den_(denom) {};


Rational Rational::operator-() const noexcept {
    return Rational(-num_, denom());
};
Rational::operator bool() const noexcept {
    if (num_ == 0) return false;
    return true;
};

bool Rational::operator==(const Rational& rhs) const noexcept {
    return num_ * rhs.denom() - rhs.num() * den_ == 0;
}
bool Rational::operator!=(const Rational& rhs) const noexcept {
    return !(num_ * rhs.denom() - rhs.num() * den_ == 0);
};
bool Rational::operator>(const Rational& rhs) const noexcept {
    return num_ * rhs.denom() - rhs.num() * den_ > 0;
};
bool Rational::operator<(const Rational& rhs) const noexcept {
    return num_ * rhs.denom() - rhs.num() * den_ < 0;
};
bool Rational::operator>=(const Rational& rhs) const noexcept {
    return num_ * rhs.denom() - rhs.num() * den_ >= 0;
};
bool Rational::operator<=(const Rational& rhs) const noexcept {
    return num_ * rhs.denom() - rhs.num() * den_ <= 0;
};

Rational& Rational::operator*=(const Rational& rhs) noexcept {
    num_ *= rhs.num();
    den_ *= rhs.denom();
    normalize();
    return *this;
};
Rational& Rational::operator+=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom() + rhs.num() * den_;
    den_ *= rhs.denom();
    normalize();
    return *this;
};
Rational& Rational::operator-=(const Rational& rhs) noexcept {
    num_ = num_ * rhs.denom() - rhs.num() * den_;
    den_ *= rhs.denom();
    normalize();
    return *this;
};

Rational& Rational::operator/=(const Rational& rhs) {
    num_ *= rhs.denom();
    den_ *= rhs.num();
    normalize();
    return *this;
};

void Rational::normalize() noexcept {
    int32_t g = gcd(abs(num_), den_);
    num_ /= g;
    den_ /= g;
    if (num_ < 0 && den_ < 0) {
        num_ = -num_;
        den_ = -den_;
    }
};


std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
    return rhs.write_to(ostrm);
}
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
    return rhs.read_from(istrm);
}


std::ostream& Rational::write_to(std::ostream& ostrm) const noexcept {
    ostrm << num_ << delimiter_ << den_;
    return ostrm;
};
std::istream& Rational::read_from(std::istream& istrm) noexcept {
    double num;
    char delimiter;
    double den;
    istrm >> num >> delimiter >> den;
    if (istrm.good()) {
        if (Rational::delimiter_ == '/' && den != 0) {
            num_ = num;
            den_ = den;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;

};