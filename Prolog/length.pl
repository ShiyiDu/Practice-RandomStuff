len([], 0).
len([X|L], N):-len(L, M), N is M + 1.
