section .text
    default rel
    extern printf
    global main
main:
    mov	rdi, fmt
    mov	rsi, message
    mov	rax, 0
    call printf wrt ..plt
    mov	rax,0	; Exit code 0
    ret			; Return
section .data
    message:  db        "Hello, Holberton", 10, 0
    fmt:    db "%s", 10, 0