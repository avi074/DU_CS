/*
merge two list in sorted order.

merge(?L1, ?L2, -L3)
    L3 is sort(L1+L2).
*/
merge([], L2, L2) :- !.
merge(L1, [], L1) :- !.
merge([H1|L1], [H2|L2], [H1|L3]) :- 
    H1 =< H2, merge(L1, [H2|L2], L3), !.
merge([H1|L1], [H2|L2], [H2|L3]) :- 
    H2 < H1, merge([H1|L1], L2, L3).