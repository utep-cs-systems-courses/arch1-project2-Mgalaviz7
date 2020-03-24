	.arch msp430g2553

	.p2align 1,0
	
	.data

state:	.byte 0

	.text

	.global state_1

state_1:
	cmp.b #1 , r12
	jne out
	mov #1 , &state

out:
	mov #0 , &state
	ret state
