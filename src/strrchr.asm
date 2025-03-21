;;
;; EPITECH PROJECT, 2025
;; strrchr
;; File description:
;; finds the last occurrence of character c in the string s
;;

section .text
    global strrchr

strrchr:
    cmp rdi, 0 ; check if rdi (string) is NULL
    je null ; if NULL, return NULL

    xor rcx, rcx ; initialize to 0
    xor r8, r8

loop_strrchr:
    mov al, byte[rdi + rcx] ; mov the current byte in al

    cmp al, 0 ; if byte is null (\0)
    je check_null ; If null, check if `c == '\0'

    cmp al, sil ; compare the current byte with the byte we want
    je save_occ ; save the index of the last occ

    inc rcx ; increment counter
    jmp loop_strrchr

save_occ:
    lea r8, [rdi + rcx]
    inc rcx ; increment counter
    jmp loop_strrchr ; continue the loop

check_null:
    cmp sil, 0 ; If searching for `'\0'`
    jne end_strrchr ; If not, return result
    lea r8, [rdi + rcx] ; Save position of null terminator

end_strrchr:
    mov rax, r8 ; return last occ
    ret

null:
    xor rax, rax ; return NULL
    ret
