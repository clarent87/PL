	.file	"reorder1.cpp"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	_Z3foov
	.def	_Z3foov;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3foov
_Z3foov:
.LFB0:
	.seh_endprologue
	mov	eax, DWORD PTR b[rip] // b값 가져오고
	mov	DWORD PTR b[rip], 1  //  b에 1을 넣음 (순서가 코드랑 다르게 바뀌었음)
	add	eax, 1               // b+1한것
	mov	DWORD PTR a[rip], eax // a = 1
	ret
	.seh_endproc
	.p2align 4
	.globl	_Z3goov
	.def	_Z3goov;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3goov
_Z3goov:
.LFB1:
	.seh_endprologue
	ret
	.seh_endproc
	.globl	b
	.bss
	.align 4
b:
	.space 4
	.globl	a
	.align 4
a:
	.space 4
	.ident	"GCC: (MinGW-W64 x86_64-posix-seh, built by Brecht Sanders) 11.0.1 20210404 (experimental)"
