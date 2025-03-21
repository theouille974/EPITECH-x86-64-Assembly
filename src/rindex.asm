;;
;; EPITECH PROJECT, 2025
;; rindex
;; File description:
;; rindex
;;

section .text
    global rindex

rindex:
    cmp rsi, 0 ; check if str is NULL
    je return_null ; return NULL

    xor rcx, rcx
    xor r8, r8

loop_rindex:
    mov al, byte[rdi + rcx] ; load byte from rdi

    cmp al, 0
    je check_null

    cmp al, sil
    je save_occ ; save index of the last occ

    inc rcx
    jmp loop_rindex

save_occ:
    lea r8, [rdi + rcx]
    inc rcx ; increment counter
    jmp loop_rindex

check_null:
    cmp sil, 0 ; searching for '\0'
    jne end_rindex ; If not, return result
    lea r8, [rdi + rcx] ; Save position of null terminator

return_null:
    xor rax, rax
    ret

end_rindex:
    mov rax, r8
    ret
