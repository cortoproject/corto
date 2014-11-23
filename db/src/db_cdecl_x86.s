    .file   "db_cdecl_x86.s"
    .globl  db_call_cdecl_word
    .type   db_call_cdecl_word, @function
db_call_cdecl_word:
.LFB1:
    .cfi_startproc
    pushl   %ebp
    .cfi_def_cfa_offset 8
    .cfi_offset 5, -8
    movl    %esp, %ebp
    .cfi_def_cfa_register 5
    pushl   %ebx
    subl    $32, %esp
    .cfi_offset 3, -12
    movl    12(%ebp), %eax
    shrl    $2, %eax
    subl    $1, %eax
    sall    $2, %eax
    addl    %eax, 20(%ebp)
    movl    $0, -8(%ebp)
    jmp .L200
.L210:
    movl    20(%ebp), %eax
    movl    (%eax), %eax
    movl    %eax, -28(%ebp)
    movl    -28(%ebp), %eax
    pushl %eax
    subl    $4, 20(%ebp)
    movl    -8(%ebp), %eax
    addl    $4, %eax
    movl    %eax, -8(%ebp)
.L200:
    movl    -8(%ebp), %edx
    movl    12(%ebp), %eax
    cmpl    %eax, %edx
    jb  .L210
    call *8(%ebp);
    movl    %eax, -24(%ebp)
    addl 12(%ebp), %esp;
    cmpl    $0, 16(%ebp)
    je  .L190
    movl    -24(%ebp), %edx
    movl    16(%ebp), %eax
    movl    %edx, (%eax)
.L190:
    addl    $32, %esp
    popl    %ebx
    .cfi_restore 3
    popl    %ebp
    .cfi_restore 5
    .cfi_def_cfa 4, 4
    ret
    .cfi_endproc
.LFE1:
    .size   db_call_cdecl_word, .-db_call_cdecl_word

    .globl  db_call_cdecl_double
    .type   db_call_cdecl_double, @function
db_call_cdecl_double:
.LFB2:
    .cfi_startproc
    pushl   %ebp
    .cfi_def_cfa_offset 8
    .cfi_offset 5, -8
    movl    %esp, %ebp
    .cfi_def_cfa_register 5
    pushl   %ebx
    subl    $36, %esp
    .cfi_offset 3, -12
    movl    12(%ebp), %eax
    shrl    $2, %eax
    subl    $1, %eax
    sall    $2, %eax
    addl    %eax, 20(%ebp)
    movl    $0, -12(%ebp)
    jmp .L20
.L21:
    movl    20(%ebp), %eax
    movl    (%eax), %eax
    movl    %eax, -32(%ebp)
    movl    -32(%ebp), %eax
    pushl %eax
    subl    $4, 20(%ebp)
    movl    -12(%ebp), %eax
    addl    $4, %eax
    movl    %eax, -12(%ebp)
.L20:
    movl    -12(%ebp), %eax
    cmpl    12(%ebp), %eax
    jb  .L21
    call *8(%ebp);
    fstpl -24(%ebp);
    add 12(%ebp), %esp;
    cmpl    $0, 16(%ebp)
    je  .L19
    fldl    -24(%ebp)
    movl    16(%ebp), %eax
    fstpl   (%eax)
.L19:
    addl    $36, %esp
    popl    %ebx
    .cfi_restore 3
    popl    %ebp
    .cfi_restore 5
    .cfi_def_cfa 4, 4
    ret
    .cfi_endproc
.LFE2:
    .size   db_call_cdecl_double, .-db_call_cdecl_double

    .globl  db_call_cdecl_complex
    .type   db_call_cdecl_complex, @function
db_call_cdecl_complex:
.LFB3:
    .cfi_startproc
    pushl   %ebp
    .cfi_def_cfa_offset 8
    .cfi_offset 5, -8
    movl    %esp, %ebp
    .cfi_def_cfa_register 5
    pushl   %ebx
    subl    $32, %esp
    .cfi_offset 3, -12
    movl    16(%ebp), %eax
    movl    %eax, -12(%ebp)
    movl    12(%ebp), %eax
    shrl    $2, %eax
    subl    $1, %eax
    sall    $2, %eax
    addl    %eax, 20(%ebp)
    movl    $0, -8(%ebp)
    jmp .L24
.L25:
    movl    20(%ebp), %eax
    movl    (%eax), %eax
    movl    %eax, -28(%ebp)
    movl    -28(%ebp), %eax
    pushl %eax
    subl    $4, 20(%ebp)
    movl    -8(%ebp), %eax
    addl    $4, %eax
    movl    %eax, -8(%ebp)
.L24:
    movl    -8(%ebp), %eax
    cmpl    12(%ebp), %eax
    jb  .L25
    movl    -12(%ebp), %eax
    pushl %eax;
    call *8(%ebp);
    add 12(%ebp), %esp;
    addl    $32, %esp
    popl    %ebx
    .cfi_restore 3
    popl    %ebp
    .cfi_restore 5
    .cfi_def_cfa 4, 4
    ret
    .cfi_endproc
.LFE3:
    .size   db_call_cdecl_complex, .-db_call_cdecl_complex
