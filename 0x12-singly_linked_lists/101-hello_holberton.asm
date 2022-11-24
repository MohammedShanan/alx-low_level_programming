globl _Start
section .text:
_Start
    mov eax, 0x4
    mov ebx, 1
    mov ecx, massage
    mov edx, massage_len
    syscall

    mov eax, 0x1 
    mov ebx, 0 
    syscall
section .data:
    massage: db "Hello, Holberton", 0xA
    massage_len equ $-massage
