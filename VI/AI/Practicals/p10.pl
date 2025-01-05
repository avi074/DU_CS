/*
Reverse of the list

reverse(?L, -R)
    R is reverse of L.
*/
reverse([], []).
reverse([H|L], R) :- 
    reverse(L,RevT), 
    append(RevT, [H], R).