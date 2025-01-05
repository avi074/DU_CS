/*
sum of the list.

sumlist(?L, -S)
    S is sum(L).
*/
sumlist([], 0).
sumlist([H|L], S) :-
    sumlist(L, S2),
    S is H + S2.