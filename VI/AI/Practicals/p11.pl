/*
list is palindrome or not

palindrome(?L)
    L is palindrome or not
*/
palindrome([]) :- !.
palindrome([_]) :- !.
palindrome(L) :-
    append([H|T], [H], L),
    palindrome(T), !.