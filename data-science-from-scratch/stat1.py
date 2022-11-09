from collections import Counter
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt

print("matplotlib version: " + matplotlib.__version__)
num_friends = [100.0,49,41,40,25,21,21,19,19,18,18,16,15,15,15,15,14,14,13,13,13,13,12,12,11,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,8,8,8,8,8,8,8,8,8,8,8,8,8,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]

friend_counts = Counter(num_friends)
xs = range(101)                         # largest value is 100
ys = [friend_counts[x] for x in xs]     # height is just # of friends

num_points = len(num_friends)
print(num_points)
largest_value = max(num_friends)
smallest_value = min(num_friends)
print(largest_value)
print(smallest_value)
sorted_values = sorted(num_friends)
print(sorted_values)
from typing import List
def mean(xs: List[float]) -> float:
    return sum(xs) / len(xs)

m = mean(num_friends)
print(m)

num_points = len(num_friends)               # 204
assert num_points == 204
print('asserted')
plt.bar(xs, ys)
plt.axis([0, 101, 0, 25])
plt.title("histogram of Friend Counts")
plt.xlabel("# of friends")
plt.ylabel("# of people")
plt.show()