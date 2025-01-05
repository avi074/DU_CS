/*
nth element of the List

nth_element(+N, ?L, -X)
    X = L[N].
*/
nth_element(N, [X|_], X) :- 
    N =:= 1, !.

nth_element(N,[_|L], X) :- 
    N > 1,
    N1 is N - 1,
    nth_element(N1, L, X).