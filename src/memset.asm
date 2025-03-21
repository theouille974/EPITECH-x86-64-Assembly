;;
;; EPITECH PROJECT, 2025
;; memset
;; File description:
;; fills the first n bytes of the memory area pointed to by s with the byte c
;;

section .text
    global memset

memset:
    cmp rdi, 0 ; check if dest is NULL
    je null

    cmp rsi, 0 ; check if value is NULL (optional)
    je null

    xor rcx, rcx ; counter
    mov al, sil ; load the value int to byte
    mov r8, rdi

loop_memset:
    cmp rcx, rdx ; check if we reach n bytes
    je end_memset

    mov byte[rdi + rcx], al ; set byte at dest
    inc rcx
    jmp loop_memset

end_memset:
    mov rax, r8 ; return dest pointer
    ret

null:
    xor rax, rax ; return NULL
    ret
