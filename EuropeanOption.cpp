#include "EuropeanOption.h"
#include <math.h>

double EuropeanOption::callPrice() const {
    return 1;
}

double EuropeanOption::putPrice() const {
    return 1;
}

double EuropeanOption::callDelta() const {
    return 1;
}

double EuropeanOption::putDelta() const {
    return 1;
}

void EuropeanOption::init() {

}

void EuropeanOption::copy(const EuropeanOption& that) {

}

EuropeanOption::EuropeanOption() {
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& that) {
    copy(that);
}

EuropeanOption::EuropeanOption(const std::string& optionType) {

}

EuropeanOption::~EuropeanOption{}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& that) {

    return *this;
}


double EuropeanOption::delta() const {
    return 1;
}

void EuropeanOption::toggle() {
    return;
}
