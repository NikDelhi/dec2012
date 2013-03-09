% AI Assignment-2 
% Implement Goal Stack method
%

%General functions: 
member(X,[X | T]).
member(X,[_ | T]) :- member(X,T).
insert_start(X,L1,[X|L1]).
insert_end(X,[],[X]).
insert_end(X,[H|T1],[H|T2]) :- insert_end(X,T1,T2).
remove(X,[],[]).
remove(X,[X|T],T).
remove(X,[H|T1],[H|T2]) :- remove(X,T1,T2).
remove_list([],L1,L1).
%remove_list([X],L1,L2) :- remove()
remove_list([X|T1],L1,L2) :- remove(X,L1,L2), remove_list(T1,L1,L2).

%skip_similar(X,L1,L2) :- skip_similar(X,L1,Hd,L2), Hd=[].
%%skip_similar(X,[X],[X],[]).
%%skip_similar(X,[Y],[],[Y]).
%skip_similar(X,[],[],[]).
%skip_similar(X,[Y|T],[],[Y|T]) :- \+(X=Y).
%skip_similar(X,[X|T],[X|Hd],Tl) :- skip_similar(X,T,Hd,Tl).
%insert_random(X,[],[X]).
%insert_random(X,[Y|T],[X|[Y|T]]) :- \+(X=Y).
%insert_random(X,[Y|T],[Y|L]) :- \+(X=Y),  insert_random(X,T,L).
%insert_random(X,T,L) :- skip_similar(X,T,Hd,Tl), \+(Hd=[]),  insert_random(X,Tl,L1), append(Hd,L1,L).
%insert_random(X,[H|T1],[H|T2]) :- skip_similar(X,T1,Hd,T3), insert_random(X,T3,T4), append(Hd,T4,T2).
insert(X,L1,L2) :- insert_start(X,L1,L2).
%perm([],[]).
%perm([],[]).
%perm([X|T], L) :- perm(T,L2), insert_random(X,L2,L).
perm(L1,L2) :- permutation(L1,L2).
%union_single(X, [], [X]).
%union_single(X, L1, L2) :- member(X,L1), perm(L1,L2).
%union_single(X, L1, L2) :- \+member(X,L1), insert_random(X,L1,L3), perm(L3,L2).
%union([], [], []).
%union(L, [], L).
%union([], L, L).
%union([X|T1], L1, L2) :- union_single(X,L1,L3), union(T1,L1,L4), union(L3,L4,L2).
union([],L,L).
union([X|L1], L2, L3) :- member(X,L2), union(L1,L2,L3).
union([X|L1], L2, [X|L3]) :- \+(member(X,L2)), union(L1,L2,L3).

intersection([],_,[]).
intersection([X|L1], L2, [X|L3]) :- member(X,L2), intersection(L1,L2,L3).
intersection([X|L1], L2, L3) :- \+(member(X,L2)), intersection(L1,L2,L3).

diff([],_,[]).
diff([X|L1], L2, [X|L3]) :- \+(member(X,L2)), !, diff(L1,L2,L3).
diff([_|L1], L2, L3) :- diff(L1,L2,L3).
%insert_list([X|T],L1,L2) :- insert(X,L1,L2), insert_list(T,L1,L2).

% Predicates used: 
% posrobo(r,l).
% box(b,r,l).
% switch(r,s).
% landmark(l,r).
% door(d,r).
%
% Initial State: 
landmark(x1,r1).
landmark(x2,r2).
landmark(y1,r1).
landmark(y2,r1).
landmark(x3,r3).
landmark(l,c).
switch(r1,1).
switch(r2,0).
switch(r3,1). 
door(d1,r1).
door(d2,r2).
door(d3,r3).
door(d1,c).
door(d2,c).
door(d3,c).
posrobo(r2,x2).
box(b1,r1,y1).
box(b2,r1,y2).

% Check whether initial state is valid..
initial_valid([landmark(X,Y) | T]) :- landmark(X,Y), initial_valid(T).
initial_valid([switch(X,Y) | T]) :- switch(X,Y), initial_valid(T).
initial_valid([door(X,Y) | T]) :- door(X,Y), initial_valid(T).
initial_valid([posrobo(X,Y) | T]) :- posrobo(X,Y), landmark(Y,X), initial_valid(T).
initial_valid([box(X,Y,Z) | T]) :- box(X,Y,Z), landmark(Z,Y), initial_valid(T).

% landmark(X,R,[landmark(X,R) | T]).
% landmark(X,R,[_ | T]) :- landmark(X,R,T).

% Check predicate in a state
% P(X,Y,[P(X,Y) | T]).
% P(X,Y,[_ | T]) :- P(X,Y,T).
% P(X,Y,Z,[P(X,Y,Z) | T]).
% P(X,Y,Z,[_ | T]) :- P(X,Y,Z,T).

% Add-lists of actions: 
add(go(R,X,Y), S1, S2) :- insert(posrobo(R,Y), S1, S2). 
add(push(B,X,Y), S1, S2) :- box(B,R,X), insert(box(B,R,Y), S1, S2).
add(turnon(R), S1, S2) :- insert(switch(R,1), S1, S2).
add(turnoff(R), S1, S2) :- insert(switch(R,0), S1, S2).
add(roboCtoR(R,D), S1, S2) :- insert(posrobo(R,D), S1, S2).
add(roboRtoC(R,D), S1, S2) :- insert(posrobo(c,D), S1, S2).
add(boxRtoC(B,R,D), S1, S2) :- insert_list([box(B,c,D),posrobo(C,D)], S1, S2).
add(boxCtoR(B,R,D), S1, S2) :- insert_list([box(B,R,D),posrobo(R,D)], S1, S2).

% Delete-lists of actions: 
delete(go(R,X,Y), S1, S2) :- remove_list([posrobo(R,X)], S1, S2).
delete(push(B,X,Y), S1, S2) :- box(B,R,X), remove_list([box(B,R,X),posrobo(R,X)], S1, S2).
delete(turnon(R), S1, S2) :- remove_list([switch(R,0)], S1, S2).
delete(turnoff(R), S1, S2) :- remove_list([switch(R,1)], S1, S2).
delete(roboCtoR(R,D), S1, S2) :- remove_list([posrobo(c,_)], S1, S2).
delete(roboRtoC(R,D), S1, S2) :- remove_list([posrobo(R,_)], S1, S2).
delete(boxRtoC(B,R,D), S1, S2) :- remove_list([box(B,R,_),posrobo(R,_)], S1, S2).
delete(boxCtoR(B,R,D), S1, S2) :- remove_list([box(B,c,_),posrobo(c,_)], S1, S2).

% modify the present state: 
modify(A, S1, S2) :-  add(A,S1,S2).

% Actions: 
go(R,X,Y,S) :- landmark(X,R,S), landmark(Y,R,S), posrobo(X,R,S), modify(S, go(R,X,Y)).


