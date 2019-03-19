.name "Redcode 0xC01055E"
.comment "Redcode colosse pour les intimes"

recover:
	st		r2, -10
	zjmp    %:start
	st		r2, 12
	st		r1, 18
	xor		%420, r1, r16
	zjmp    %:start
	ld		%1, r2
	and		%0, r1, r1
start:
	fork %100
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	st		r2, 6
	live    %0
	ld		%0, r16
	st		r16, 500
	zjmp	%:start

