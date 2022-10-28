Vectors
A vector is a one-dimensinal list of numbers. When used in mathematical expressions, vectors are usually assumed to be written vertically.
In deep learning, we typically use vectors to represent one sample: one set of features that we we'll input to a model.
But mathematically, vectors are used to represent points in space.

Matrices
A matrix is a two-dimensinal array of numbers.

Multiplying Vectors and Matrices
in NumPy, [1, 2, 3] x [4, 5, 6] = [4, 10, 18]
Mathematically, if A = (a, b, c) and B = (d, e, f) are assumed to be column vectors.
outer products:
      a              ad ae af
ABT = b  [d, e, f] = bd be bf
      c              cd ce cf
and inner product (dot product)
              d
ATB = [a b c] e = ad + be +ef
              f

When pultiplying a matrix and a vector, the vector is typically on the right side of the matrix.
Arrays that have three or more dimensions are referred to as tensors.
We can use fist index to refer to low-level tensor.
