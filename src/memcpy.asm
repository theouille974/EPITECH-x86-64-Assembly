;;
;; EPITECH PROJECT, 2025
;; memcpy
;; File description:
;; copies n bytes from src to dest
;;

section .text
    global memcpy

memcpy:
    cmp rdi, 0 ; check if dest is NULL
    je null

    cmp rsi, 0 ; check if src is NULL ==> renvoyer premier arg
    je return_dest

    cmp rdx, 0 ; check if n == 0
    je return_dest ; if n == 0, return dest immediatly

    xor rcx, rcx ; counter
    mov r8, rdi ; save the original pointer of dest

loop_memcpy:
    cmp rcx, rdx ; check if counter as reach n
    je end_memcpy

    mov al, byte[rsi] ; load a byte from src in al
    mov byte[rdi], al ; store in dest

    inc rcx
    inc rsi ; mov to the next byte in src
    inc rdi ; mov to the next byte in dest

    jmp loop_memcpy

end_memcpy:
    mov rax, r8
    ret

return_dest:
    mov rax, rdi
    ret

null:
    xor rax, rax ; return NULL
    ret
