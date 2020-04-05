	.arch msp430g2553
	.p2align 1,0

	.text
	.global speed
	.global state
	.global states
state:
	.word 0

dim_flag:
	.word 0
JT:
	.word case0
	.word case1
	.word case2
	.word case3
	.word case4

states:
	mov &state, r12
	cmp #0, r12
	jeq #case0

	cmp #1, r12
	jeq #case1

	cmp #2, r12
	jeq #case2

	cmp #3, r12
	jeq #case3
	
	cmp #4, r12
	jeq #case4

case0:
	call #green_led_on
	mov #0, &state
	jmp #states
case1:
	mov #0, &dim_flag
	call count_to_3
	mov #1, &state
	jmp #states
case2:
	mov #1, &dim_flag
	call #count_to_3
	mov #1, &state
	jmp #states
case3:
	sub #1, &speed
	cmp #1, &speed
	jz case3
	call #count_to_3
	mov #3, &state
	jmp #states
case4:
	call #little_lamb
	mov #4, &state
	jmp #states

	
