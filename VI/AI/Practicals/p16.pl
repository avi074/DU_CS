/*
insert at nth position in list

insert_nth(?I, +N, ?L, -R)
    insert I to L[N] & assign new List to R.
*/
insert_nth(I, N, L, [I | L]) :- 
    N =:= 1, !.

insert_nth(I, N, [H|L], [H|R]) :- 
    N > 1,
    N1 is N - 1,
    insert_nth(I, N1, L, R).