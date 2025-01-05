/*
concatenate two lists

conc(+L1, +L2, -L3)
    L3 is L1 + L2.
*/
conc(L1, [], L1).
conc([], L2, L2).
conc([X|L1], L2, [X|L3]) :- conc(L1, L2, L3).
