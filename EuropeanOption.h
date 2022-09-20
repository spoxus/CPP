#include <string>

class EuropeanOption {
    private:
    void   init();
    void   copy(const EuropeanOption& other);
    double callPrice() const;
    double putPrice() const;
    double callDelta() const;
    double putDelta() const;

    public:
    double r;                   // interest rate
    double sig;                 // volatility
    double K;                   // strike price
    double T;                   // expiry date
    double U;                   // current underlying price
    double b;                   // cost of carry
    std::string optType;        // call/put

    EuropeanOption();
    EuropeanOption(const EuropeanOption& other);
    EuropeanOption(const std::string& optionType);

    //virtual 
    ~EuropeanOption();

    EuropeanOption& operator = (const EuropeanOption& other);
    
    double price() const;
    double delta() const;
    void toggle();
};