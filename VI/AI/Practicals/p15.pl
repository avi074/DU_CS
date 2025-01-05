/*
max element of the List

maxlist(?L, -M)
    M is max(L).
*/
maxlist([X], X) :- !.
maxlist([H|T], M) :-
    maxlist(T, M1),
    M is max(H, M1).