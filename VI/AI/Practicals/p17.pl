/*
delete at nth position in list

delete_nth(+N, ?L, -R)
    delete L[N] & assign new List to R.
*/
delete_nth(N, [_|L], L) :- 
    N =:= 1, !.

delete_nth(N, [H|L], [H|R]) :- 
    N > 1,
    N1 is N - 1,
    delete_nth(N1, L, R).