import EuropeanOption;
import NonlinearSolver;

import <iostream>;
import <numbers>;

using namespace std::numbers;
using namespace std;


int main() {
    EuropeanOption call_option;
    cout << "call option on a stock: " << call_option.price() << endl;
cout << "Pi = " << numbers::pi << endl;
    EuropeanOption index_option;
    index_option.set_type('P');
    index_option.U = 100.0;
    index_option.K = 95.0;
    index_option.T = 0.5;
    index_option.r = 0.1;
    index_option.sig = 0.2;
    double q = 0.05;
    index_option.b = index_option.r - q;
    cout << "put option on index: " << index_option.price() << endl;

    EuropeanOption future_option;
    future_option.set_type('P');
    future_option.U = 19.0;
    future_option.K = 19.0;
    future_option.T = 0.75;
    future_option.r = 0.1;
    future_option.sig = 0.28;
    future_option.b = 0.0;

    cout << "put option on the future: " << future_option.price() << endl;

    future_option.toggle();
    cout << "call optoin on the future: " << future_option.price() << endl;
}