from typing import Tuple
import math

def normal_approximation_2_binomial(n: int, p: float) -> Tuple[float, float]:
    """returns mu and sigma corresponding to a Binomial(n, p)"""
    mu = p * n
    sigma = math.sqrt(p * (1 - p) * n)
    return mu, sigma

print(normal_approximation_2_binomial(10, 0.8))

from scratch.probability import normal_cdf
# The normal cdf _is_ the probability the variable is below a threshold
normal _probability_below = normal_cdf

# It's above the threshold if it's not below the threshold
def normal_probability_above(lo: float,
                             mu: float = 0,
                             sigma: float = 1) -> float:
    """The probability taht an N(mu, sigma) is greater than lo"""
    return 1 - normal_cdf(lo, mu, sigma)

# It's between if it's < hi, but >= lo