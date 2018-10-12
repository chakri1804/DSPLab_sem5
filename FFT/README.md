### Usage

The complex.h has a way to define imaginary numbers

for example
~~~
1+3i  ===  1 + 3*I
~~~

and the input must be change accordingly in the main() of the code

The FFT_cooley_tukey.c is the Float point implimentation of FFT

and fixed_FFT.c is the pure short int implimentation

The input for the fixed_point is generated in python with uniform random
variable between 0 and 2 for better results and preventing overflow

The Q factor has been fixed to Q7.7 for equal weightage.

While running the FFT_cooley_tukey.c code, use the following command to skip errors while compiling
math.h and complex.h
~~~
gcc FFT_cooley_tukey.c -lm
~~~
