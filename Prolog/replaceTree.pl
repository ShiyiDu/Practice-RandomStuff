rt(X, Y, t(L, X, R), t(L1, Y, R1)) :- rt(X, Y, L, L1), rt(X, Y, R, R1).
rt(X, Y, t(L, Root, R), t(L1, Root, R1)) :- rt(X, Y, L, L1), rt(X, Y, R, R1).
rt(X, Y, X, Y).
rt(X, Y, Z, Z).