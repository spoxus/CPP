module;
export module SteffensensSolver;
import NonlinearSolver;


using solver = double(*)(double);

export class SteffensensSolver : public NonlinearSolver {
public:
    SteffensensSolver(double guess, solver s) : x0 {guess}, func {s} {}
/*    
    double solve() {
        double tmp;
        double hn;
        n = 1;
        x_previous = x0;
L1:
        tmp = func(x_previous);
        hn = (func(x_previous + tmp) - tmp) / tmp;
        hn = tmp / hn;
        ++n;
        if(::fabs(hn) <= tolerance) {
            return x_current;
        }
        goto L1;
    };
*/    
private:
    double x0;
    double x_previous;
    double x_current;
    long n;
};