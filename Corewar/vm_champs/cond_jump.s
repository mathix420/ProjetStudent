#by zaz, it's not very good, but what did you expect, rainbowdash is way better
#2013

.name		"fluttershy"
.comment	"oh, my, what a scary project"

entry:
	fork	%:coregeni
	st		r1, 6
	live	%42
	fork	%:torpgeni
	st		r1, 6
	live	%42
	fork	%:avdefgeni

ardeftgt:

ardefgeni:
	st 		r1, 6

ardefgen:
	live 	%213904
	fork 	%:ardefgardefl1, %1
	st		r1, 6
	live	%43123
	sti		r1, %:ardefchk, %1
	ld		%-6, r2
	ld		%-6, r3
	ld		%150994953, r4
	ld		%-186, r5

ardefwrite:
ardefl1:
	live	%295423
	sti		r4, %:ardeftgt, r, r3, r2
	sti		r4, %:avdeftgt, r2
	add		r2, r3, r2
avdefchk:
	live	%3940641
	xor		r2, r5, r15
	zjmp	%:avdefinit
avdefloop:	
	ld		%0, r16
	zjmp	%:avdefwrite

torpgeni:
	st		r1, 6

torpgen:
	live	%96824
	fork	%:torpgen

torpinit:
	ld		%0, r2
	ld		%4, r3
	ld		%96, r5
	sti		r1, %:torpchk, %1
	st		r1, 6

torpwrite:
torpl1:
	live	%8008135
	ldi		%:torpinit, r2, r4
	sti		r4, %400, r2
	add		r2, r3, r2
	ldi		%:torpinit, r2, r4
	sti		r4, %383, r2
	add		r2, r3, r2
	ldi		%:torpinit, r2, r4
	sti		r4, %383, r2
	add		r2, r3, r2
torpchk:
	live	%89523
	xor		r2, r5, r15	
	zjmp	%362
torploop:
	ld		%0, r15
	zjmp	%:torpwrite

avdeftgt:
