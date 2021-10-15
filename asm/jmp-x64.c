
#ifdef mini_setjmp

typedef unsigned long long jmp_buf[8];

int setjmp(jmp_buf env);
int _setjmp(jmp_buf env);
void __attribute__((noreturn))longjmp(jmp_buf env, int val);
void __attribute__((noreturn))_longjmp(jmp_buf env, int val);

asm(".globl	longjmp,_longjmp\n\
_longjmp:\n\
longjmp:\n\t\
	mov	%rsi,%rax\n\t\
	test	%rax,%rax\n\t\
	jnz	1f\n\t\
	inc	%rax\n\
1:\n\t\
	mov	(%rdi),%rbx\n\t\
	mov	8(%rdi),%rbp\n\t\
	mov	16(%rdi),%r12\n\t\
	mov	24(%rdi),%r13\n\t\
	mov	32(%rdi),%r14\n\t\
	mov	40(%rdi),%r15\n\t\
	mov	48(%rdi),%rdx\n\t\
	mov	%rdx,%rsp\n\t\
	mov	56(%rdi),%rdx\n\t\
	jmp	*%rdx\n\t\
\n\t\
	.globl	setjmp,_setjmp\n\
_setjmp:\n\
setjmp:\n\t\
	mov	%rbx,(%rdi)\n\t\
	mov	%rbp,8(%rdi)\n\t\
	mov	%r12,16(%rdi)\n\t\
	mov	%r13,24(%rdi)\n\t\
	mov	%r14,32(%rdi)\n\t\
	mov	%r15,40(%rdi)\n\t\
	lea	8(%rsp),%rdx\n\t\
	mov	%rdx,48(%rdi)\n\t\
	mov	(%rsp),%rdx\n\t\
	mov	%rdx,56(%rdi)\n\t\
	xor	%rax,%rax\n\t\
	ret\n\t ");

#endif

