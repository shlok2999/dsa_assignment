	.file	"2021201046_Q3.cpp"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN4nodeC2Ev,"axG",@progbits,_ZN4nodeC5Ev,comdat
	.align 2
	.weak	_ZN4nodeC2Ev
	.type	_ZN4nodeC2Ev, @function
_ZN4nodeC2Ev:
.LFB1523:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
.L3:
	cmpl	$1, -4(%rbp)
	jg	.L2
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	$0, (%rax,%rdx,8)
	addl	$1, -4(%rbp)
	jmp	.L3
.L2:
	movq	-24(%rbp), %rax
	movb	$0, 16(%rax)
	movq	-24(%rbp), %rax
	movq	$0, 24(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1523:
	.size	_ZN4nodeC2Ev, .-_ZN4nodeC2Ev
	.weak	_ZN4nodeC1Ev
	.set	_ZN4nodeC1Ev,_ZN4nodeC2Ev
	.section	.text._ZN4nodeD2Ev,"axG",@progbits,_ZN4nodeD5Ev,comdat
	.align 2
	.weak	_ZN4nodeD2Ev
	.type	_ZN4nodeD2Ev, @function
_ZN4nodeD2Ev:
.LFB1526:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	$0, -20(%rbp)
.L7:
	cmpl	$1, -20(%rbp)
	jg	.L8
	movq	-40(%rbp), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rbx
	testq	%rbx, %rbx
	je	.L6
	movq	%rbx, %rdi
	call	_ZN4nodeD1Ev
	movl	$32, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm@PLT
.L6:
	addl	$1, -20(%rbp)
	jmp	.L7
.L8:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1526:
	.size	_ZN4nodeD2Ev, .-_ZN4nodeD2Ev
	.weak	_ZN4nodeD1Ev
	.set	_ZN4nodeD1Ev,_ZN4nodeD2Ev
	.section	.text._ZN4trieC2Ev,"axG",@progbits,_ZN4trieC5Ev,comdat
	.align 2
	.weak	_ZN4trieC2Ev
	.type	_ZN4trieC2Ev, @function
_ZN4trieC2Ev:
.LFB1529:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movl	$32, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN4nodeC1Ev
	movq	-24(%rbp), %rax
	movq	%rbx, (%rax)
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1529:
	.size	_ZN4trieC2Ev, .-_ZN4trieC2Ev
	.weak	_ZN4trieC1Ev
	.set	_ZN4trieC1Ev,_ZN4trieC2Ev
	.section	.text._ZN4trie6insertEx,"axG",@progbits,_ZN4trie6insertEx,comdat
	.align 2
	.weak	_ZN4trie6insertEx
	.type	_ZN4trie6insertEx, @function
_ZN4trie6insertEx:
.LFB1531:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -24(%rbp)
	movl	$63, -28(%rbp)
.L15:
	cmpl	$0, -28(%rbp)
	js	.L11
	movl	-28(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	cltq
	andq	-48(%rbp), %rax
	testq	%rax, %rax
	je	.L12
	movl	$1, -32(%rbp)
	jmp	.L13
.L12:
	movl	$0, -32(%rbp)
.L13:
	movq	-24(%rbp), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	testq	%rax, %rax
	jne	.L14
	movl	$32, %edi
	call	_Znwm@PLT
	movq	%rax, %rbx
	movq	%rbx, %rdi
	call	_ZN4nodeC1Ev
	movq	-24(%rbp), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	movq	%rbx, (%rax,%rdx,8)
.L14:
	movq	-24(%rbp), %rax
	movl	-32(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	movq	%rax, -24(%rbp)
	subl	$1, -28(%rbp)
	jmp	.L15
.L11:
	movq	-24(%rbp), %rax
	movb	$1, 16(%rax)
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, 24(%rax)
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1531:
	.size	_ZN4trie6insertEx, .-_ZN4trie6insertEx
	.section	.text._ZN4trie6searchEx,"axG",@progbits,_ZN4trie6searchEx,comdat
	.align 2
	.weak	_ZN4trie6searchEx
	.type	_ZN4trie6searchEx, @function
_ZN4trie6searchEx:
.LFB1532:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	$0, -8(%rbp)
	movl	$63, -20(%rbp)
.L22:
	cmpl	$0, -20(%rbp)
	js	.L17
	movl	-20(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	cltq
	andq	-48(%rbp), %rax
	testq	%rax, %rax
	je	.L18
	movl	$0, -24(%rbp)
	jmp	.L19
.L18:
	movl	$1, -24(%rbp)
.L19:
	movq	-16(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	testq	%rax, %rax
	jne	.L20
	movl	$1, %eax
	subl	-24(%rbp), %eax
	movl	%eax, %edx
	movq	-16(%rbp), %rax
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	movq	%rax, -16(%rbp)
	jmp	.L21
.L20:
	movq	-16(%rbp), %rax
	movl	-24(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	movq	%rax, -16(%rbp)
	movl	-20(%rbp), %eax
	movl	$1, %edx
	movl	%eax, %ecx
	sall	%cl, %edx
	movl	%edx, %eax
	cltq
	addq	%rax, -8(%rbp)
.L21:
	subl	$1, -20(%rbp)
	jmp	.L22
.L17:
	movq	-8(%rbp), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rdx, %rax
	sarq	%rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1532:
	.size	_ZN4trie6searchEx, .-_ZN4trie6searchEx
	.section	.text._ZN4trieD2Ev,"axG",@progbits,_ZN4trieD5Ev,comdat
	.align 2
	.weak	_ZN4trieD2Ev
	.type	_ZN4trieD2Ev, @function
_ZN4trieD2Ev:
.LFB1534:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rbx
	testq	%rbx, %rbx
	je	.L26
	movq	%rbx, %rdi
	call	_ZN4nodeD1Ev
	movl	$32, %esi
	movq	%rbx, %rdi
	call	_ZdlPvm@PLT
.L26:
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1534:
	.size	_ZN4trieD2Ev, .-_ZN4trieD2Ev
	.weak	_ZN4trieD1Ev
	.set	_ZN4trieD1Ev,_ZN4trieD2Ev
	.text
	.globl	main
	.type	main, @function
main:
.LFB1536:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1536
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZN4trieC1Ev
.LEHE0:
	leaq	-52(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
.LEHB1:
	call	_ZNSirsERi@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movl	$0, -40(%rbp)
.L29:
	movl	-52(%rbp), %eax
	cmpl	%eax, -40(%rbp)
	jge	.L28
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movl	-44(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4trie6insertEx
	addl	$1, -40(%rbp)
	jmp	.L29
.L28:
	movl	$0, -36(%rbp)
.L31:
	movl	-48(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jge	.L30
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rdi
	call	_ZNSirsERi@PLT
	movl	-44(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-32(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN4trie6searchEx
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSolsEx@PLT
	movq	%rax, %rdx
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE1:
	addl	$1, -36(%rbp)
	jmp	.L31
.L30:
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4trieD1Ev
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L34
	jmp	.L36
.L35:
	endbr64
	movq	%rax, %rbx
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4trieD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L36:
	call	__stack_chk_fail@PLT
.L34:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1536:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1536:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1536-.LLSDACSB1536
.LLSDACSB1536:
	.uleb128 .LEHB0-.LFB1536
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1536
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L35-.LFB1536
	.uleb128 0
	.uleb128 .LEHB2-.LFB1536
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1536:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2023:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L39
	cmpl	$65535, -8(%rbp)
	jne	.L39
	leaq	_ZStL8__ioinit(%rip), %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L39:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2023:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2024:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2024:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
