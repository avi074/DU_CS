/* 
(+) for pre-initialised vars before call
(-) for var to store computed result in procedure after call

Summation of two variables

    sum(+X, +Y, -A)    
        A = X+Y
*/
sum(X, Y, A) :- A is X + Y.
