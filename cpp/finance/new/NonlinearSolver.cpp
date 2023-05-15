module;
export module NonlinearSolver;

using solver = double(*)(double);

export class NonlinearSolver {
public:
    double tolerance;
    solver func;
    NonlinearSolver(double(*function)(double)) {}
    virtual double solve() = 0;
};