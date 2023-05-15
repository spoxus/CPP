module;
export module EuropeanOption;

import <cmath>;
import <iostream>;
import <stdexcept>;
import <numbers>;
/*
import <string>;

using std::string;
using std::cout;
using std::endl;
*/
export class EuropeanOption {
public:
    double call_price() const;
    double put_price()  const;
    double call_delta() const;
    double put_delta()  const;

    double r;       // risk-free interest rate
    double sig;     // volatility of the relative price change: Σ σ
    double K;       // strike price
    double T;       // time to expiration (in years)
    double U;       // current underlying price
    double b;       // cost-of-carry

    EuropeanOption() : r{0.08}, sig{0.3}, K{65.0}, T{0.25}, U{60.0}, b{r}, opt_type{'C'} {}
    EuropeanOption(const EuropeanOption& o2) {copy(o2);};
    //EuropeanOption(const string& T) {};

    virtual ~EuropeanOption() {};

    EuropeanOption& operator = (const EuropeanOption&);

    double  price() const;
    double  delta() const;
    void    toggle();
    void    set_type(char);

private:
    void init();
    void copy(const EuropeanOption&);
    inline double d0() const {return sig * sqrt(T);}
    inline double d1() const {return (log(U / K) + (b + (sig * sig) * 0.5) * T) / d0();}
    inline double d2() const {return d1() - d0();}
    double n(double)   const;  // Gaussian functions
    double N(double)   const;  // culmulative normal distribution

    char opt_type;    // call/put

};

double EuropeanOption::n(double x) const {
    //double A{1.0 / sqrt(2.0 * std::numbers::pi)};
    double A{1.0 / sqrt(2.0 * 3.1415)};
    return A * exp(-x * x * 0.5);
}

double EuropeanOption::N(double x) const {
    double a1{0.4361836};
    double a2{-0.1201676};
    double a3{0.9372980};
    double k{1.0/(1.0 + (0.33267 * x))};
    if (x >= 0) {
        return 1.0 - n(x)* (a1*k + (a2*k*k) + (a3*k*k*k));
    } else {
        return 1.0 - N(-x);
    }
}

double EuropeanOption::put_price() const {
    return (K * exp(-r * T) * N(-d2())) - (U * exp((b - r) * T) * N(-d1()));
}

double EuropeanOption::call_price() const {
    return (U * exp((b - r) * T) * N(d1())) - (K * exp(-r * T) * N(d2()));
}

double EuropeanOption::call_delta() const {
    return exp((b - r) * T) * N(d1());
}

double EuropeanOption::put_delta() const {
    return exp((b - r) * T) * (N(d1()) - 1.0);
}

void EuropeanOption::copy(const EuropeanOption& o2) {
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.K;
    U = o2.U;
    b = o2.b;
    opt_type = o2.opt_type;
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& o2) {
    if (this == &o2) return *this;
    copy(o2);
    return *this;
}

double EuropeanOption::price() const {
    if (opt_type == 'C') {
        return call_price();
    } else if (opt_type == 'P') {
        return put_price();
    } else {
        throw std::invalid_argument("type should be P or C");
    }
}

double EuropeanOption::delta() const  {
    if (opt_type == 'C') {
        return call_delta();
    } else {
        return put_delta();
    }
}

void EuropeanOption::set_type(char type) {
    if (type == 'P' || type == 'C') {
        opt_type = type;
    } else {
        throw std::invalid_argument("type should be P or C");
    }
}

void EuropeanOption::toggle() {
    if (opt_type == 'C') {
        opt_type = 'P'; 
    } else if (opt_type == 'P') {
        opt_type = 'C';
    } else {
        throw std::invalid_argument("type should be P or C");
    }
}