replace(X, Y, [X|L1], [Y|L]):-replace(X, Y, L1, L).
replace(X, Y, [Z|L1], [Z|L]):-replace(X, Y, L1, L).
replace(X, Y, [X], [Y]).
replace(X, Y, [Z], [Z]).
