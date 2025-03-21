;;
;; EPITECH PROJECT, 2025
;; strcmp
;; File description:
;; compares two strings (based on ASCII values)
;;

section .text
    global strcmp

strcmp:
    xor rcx, rcx

loop_strcmp:
    mov al, byte[rdi + rcx] ; mov one letter in al
    mov bl, byte[rsi + rcx] ; mov one letter in bl

    cmp al, bl ; compare the two letter
    jne not_equal

    cmp al, 0 ; Is AL (character) 0? If yes, we reached the null terminator
    je equal

    inc rcx
    jmp loop_strcmp

not_equal:
    movzx eax, al
    movzx ebx, bl
    sub eax, ebx ; Return difference
    ret

equal:
    xor eax, eax ; Return 0 (strings are equal)
    ret
