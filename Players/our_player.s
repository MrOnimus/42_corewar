.name "It's my best player"
.comment "It's like a small fluffy nightmare"


 # gap between code = abs0

beg:
    ld %-508, r7 
    ld %-62, r15
    ld %0, r8
first_jmp:
    zjmp %:start

launch:
	sti r1, r7, r12
	sti r2, r7, r6
    sti r8, r7, r11
    zjmp %-506    ## synchronize with size of the jump 0

live %253954135
zjmp %-65 # value of the little jump  here to change the size of the loop size loop - trois
live %252621135
zjmp %-511 # value of the big jump  here to  change the size of the jump size jump -trois
start:
	fork %:p2

p1:
	st r1, -10
    st r8, -4
	ld -21, r8
	ld -53, r3
	ld %16, r11
	ld %15, r12
	ld %43, r6
	ld %252400644, r1
	ld %84347915, r2
	ld %25240065, r4
	ld %235342859, r5
	ld %252400573, r13
	ld %235867147, r14
	ld %0, r16
	zjmp %:launch

p2:
    st r1, -57
    st r8, -4
    ld -118, r3
    ld -115, r8
	ld %20, r11
	ld %23, r12
	ld %36, r6
	ld %118164308, r1
	ld %1441098122, r2
	ld %118164308, r4
	ld %14094550, r5
	ld %252402036, r13
	ld %1409486598, r14
	ld %0, r16
	zjmp %:launch
