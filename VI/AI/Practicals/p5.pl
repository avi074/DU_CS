/*
GCD of two numbers

gcd(+X, +Y, -D)
    D is gcd(X,Y).
*/
gcd(0, 0, 0) :- !. % '!' is called cut & used for stopping more recursion & move process backwards. 
gcd(0, Y, Y) :- !.
gcd(X, 0, X) :- !.
gcd(X, Y, D) :- 
    X < 0, 
    gcd(-X, Y, D).
gcd(X, Y, D) :- 
    Y < 0, 
    gcd(X, -Y, D).
gcd(X, Y, D) :- 
    X > Y, 
    Z is mod(X, Y),
    gcd(Z, Y, D).
gcd(X, Y, D) :- 
    X =< Y, 
    Z is mod(Y, X),
    gcd(X, Z, D).