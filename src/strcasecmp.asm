;;
;; EPITECH PROJECT, 2025
;; strcasecmp
;; File description:
;; compares two strings case-insensitively
;;

section .text
    global strcasecmp

strcasecmp:
    xor rcx, rcx

loop_strcasecmp:
    mov al, byte[rdi + rcx] ; mov one letter in al (str1)
    mov bl, byte[rsi + rcx] ; mov one letter in bl (str2)

    cmp al, 'A'
    jl no_lower_al ; if less

    cmp al, 'Z'
    jg no_lower_al ; if greater

    add al, 32 ; convert to lowercase

no_lower_al:
    cmp bl, 'A'
    jl no_lower_bl ; if less

    cmp bl, 'Z'
    jg no_lower_bl ; if greater

    add bl, 32 ; convert to lowercase

no_lower_bl:
    cmp al, bl ; compare both lowercase characters
    jne return_diff ; if different, return difference

    cmp al, 0 ; if null terminator, end comparison
    je return_zero

    inc rcx ; move to the next character
    jmp loop_strcasecmp ; continue the loop

return_diff:
    sub al, bl
    movsx rax, al
    ret

return_zero:
    xor rax, rax
    ret
