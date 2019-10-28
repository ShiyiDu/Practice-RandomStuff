build_tree([], nil).
build_tree([X|L], T):- build_tree(L, T1), insert(X, T1, T).
insert(X, nil, t(nil, X, nil)).
insert(X, t(L, X, R), t(L, X, R)).
insert(X, t(L, Root, R), t(L1, Root, R)) :- X < Root, insert(X, L, L1).
insert(X, t(L, Root, R), t(L, Root, R1)) :- X > Root, insert(X, R, R1).