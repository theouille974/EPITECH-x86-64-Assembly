;;
;; EPITECH PROJECT, 2025
;; strpbrl
;; File description:
;; searches for the first character in s that matches any character from accept
;;

section .text
    global strpbrk

strpbrk:
    cmp rdi, 0
    je null

    cmp rsi, 0
    je null

    xor rcx, rcx ; initialize to 0

loop_strpbrk:
    mov al, byte[rdi + rcx] ; mov the current byte in al

    cmp al, 0 ; if byte is null
    je null

    mov r8, rsi

save_rest:
    mov bl, byte[r8 + rcx] ; load the byte in al

    cmp bl, 0
    je next_char

    cmp al, bl
    je end_strpbrk

    inc r8
    jmp save_rest

next_char:
    inc rdi
    jmp loop_strpbrk

null:
    mov rax, 0 ; return null
    ret

end_strpbrk:
    mov rax, rdi ; index of the occ
    ret
