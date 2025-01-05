/*
X is member of list or not
            ? -> preinitialized but bounded

memb(+X, ?L)
    X is member of list L.
*/
% memb(X, [X|_]) :- write(X), write(' is member of given list.').
memb(X, [X|_]) :- !.
memb(X, [_|L]) :- memb(X, L).