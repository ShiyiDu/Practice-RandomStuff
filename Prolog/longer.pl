longer([], X, X).
longer(X, [], X).
longer([X|L1], [Y|L2], [Y|L2]):-longer(L1, L2, L2).
longer([X|L1], [Y|L2], [X|L1]):-longer(L1, L2, L1).
