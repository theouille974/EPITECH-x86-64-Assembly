;;
;; EPITECH PROJECT, 2025
;; strcspn
;; File description:
;; returns the length of the initial segment of s that contains none of the characters in reject
;;

section .text
    global strcspn

strcspn:
    cmp rdi, 0
    je null

    cmp rsi, 0
    je null

    mov al, byte[rdi]  ; Check if s1 is an empty string
    test al, al
    jz null

    xor rcx, rcx ; count

loop_strcspn:
    mov al, byte[rdi + rcx] ; mov the current byte in al

    cmp al, 0 ; if byte is null
    je end_strcspn ; return len str 1

    xor rdx, rdx ; count str 2

loop_second_str:
    mov bl, byte[rsi + rdx]

    cmp bl, 0
    jz loop_continue ; If reached end of rsi, continue with rdi

    cmp al, bl
    je end_strcspn

    inc rdx
    jmp loop_second_str

loop_continue:
    inc rcx
    jmp loop_strcspn ; Move to next char in `s1`

null:
    xor rax, rax ; return null
    ret

end_strcspn:
    mov rax, rcx ; return count str 1
    ret
