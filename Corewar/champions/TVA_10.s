.name "TVA 10%"
.comment "Faux passer a la caisse maintenant"

recover:
	st		r13, -10
	st		r1, 18
	xor		%420, r1, r16
	zjmp    %:clear
	ld		%1, r13
	and		%0, r1, r1
	zjmp    %:skip
clear:
	#if r16 = 0x69CACA69 alors go to skip
	#else:
	#peut etre remplacer les %0 par des long fork ?
	st		r1, 6
	live	%42
	ld		-4, r13
	ld %0, r1
	st r1, -22
	st r1, -21
	st r1, -20
	st r1, -19
	ld %0, r2
	ld %0, r3	
	ld %0, r4
	ld %0, r5
	ld %0, r6
	ld %0, r7
	ld %0, r8
	ld %0, r9
	ld %0, r10
	ld %0, r11
	ld %0, r12
#	ld %0, r13 #less use in heuristics
	ld %0, r14
	ld %0, r15
	ld %0, r16

skip:
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	ld %0, r1
	zjmp %:skip
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	ld %0, r1
	zjmp %:skip
