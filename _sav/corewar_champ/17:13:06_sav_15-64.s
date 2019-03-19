.name "goinfre"
.comment "I will erase you like a CryptoLocker"
	
clear:
	#if r16 = 0x69CACA69 alors go to skip
	#else:
	#peut etre remplacer les %0 par des long fork ?
	st		r1, 6
	live	%42
	ld		-4, r13
	ld %17563916, r1
	st r1, -22
	st r1, -21
	st r1, -20
	st r1, -19
	st r13, 6
    live %42
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

shit:
	ld %17563916, r1
	live %42
	st r13, 6
	st r1, -143
    st r1, -153
    st r1, -163
    st r1, -173
	
skip:
	live %42
	st r13, 6
	st r1, -100
    st r1, -200
	st r1, -300
    st r1, -400
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	ld %17563916, r1
	st r1, 100
	st r1, 150
	st r1, 250
    st r1, 300
	st r1, 350
	st r1, 400
	st r1, 450
    st r1, 500
	ld %0, r16
	zjmp %:skip
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	ld %17563916, r1
	ld %0, r16
	zjmp %:skip
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	st r13, 6
	live %42
	ld %17563916, r1
	ld %0, r16
	zjmp %:skip
	zjmp %:skip
	zjmp %:skip
	
