replace(X, Y, [L1|L2], [L3|L4]):-replace(X, Y, L1, L3), replace(X, Y, L2, L4).
replace(X, Y, X, Y).
replace(X, Y, Z, Z). 