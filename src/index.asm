;;
;; EPITECH PROJECT, 2025
;; index
;; File description:
;; identical to strchr : eturns a pointer to the first occurrence of the character c in the string s
;;

section .text
    global index

index:
    cmp rdi, 0 ; check if str is NULL
    je return_null

    cmp rsi, 0
    je return_null

    xor rcx, rcx

loop_index:
    mov al, byte[rdi + rcx] ; load byte of str

    cmp al, 0 ; check if \0
    je return_null

    cmp al, sil ; if byte from str is equal to char
    je found

    inc rcx
    jmp loop_index

return_null:
    xor rax, rax
    ret

found:
    lea rax, [rdi + rcx]
    ret
