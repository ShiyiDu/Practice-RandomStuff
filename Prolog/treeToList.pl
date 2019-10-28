t2l(nil, []).
t2l(t(L, Root, R), Result) :- t2l(L, L1), t2l(R, R1), conc(L1, [Root|R1], Result).
conc([], L2, L2).
conc(L1, [], L1).
conc([X|L], L1, [X|T]) :- conc(L, L1, T).