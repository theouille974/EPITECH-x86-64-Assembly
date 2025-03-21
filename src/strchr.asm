;;
;; EPITECH PROJECT, 2025
;; strchr
;; File description:
;; finds the first occurrence of character c in the string s
;;

section .text
    global strchr

strchr:
    cmp rdi, 0
    je null

    xor rcx, rcx ; initialize to 0

loop_strchr:
    mov al, byte[rdi + rcx] ; mov the current byte in al

    cmp al, sil ; compare the current byte with the byte we want
    je end_strchr

    cmp al, 0 ; if byte is null
    je null

    inc rcx
    jmp loop_strchr

check_null:
    cmp sil, 0 ; if we are at `\0` and searching for `\0`
    je end_strchr

null:
    mov rax, 0 ; return null
    ret

end_strchr:
    mov rax, rdi ; adress of the str in rax
    add rax, rcx ; adress of the byte in index rcx
    ret
