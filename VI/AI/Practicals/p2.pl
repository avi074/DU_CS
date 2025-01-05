% max(+X, +Y, -M)
%   M is max(X,Y).
% condition -> expr on true ; expr on false.
max(X, Y, M) :- X > Y -> M is X ; M is Y.