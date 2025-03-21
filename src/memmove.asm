;;
;; EPITECH PROJECT, 2025
;; memmove
;; File description:
;; similar to memcpy, but handles overlapping memory regions safely
;;

section .text
    global memmove

memmove:
    cmp rdi, 0 ; check if dest is NULL
    je null

    cmp rsi, 0 ; check if src is NULL
    je end_memmove

    cmp rdi, rsi ; check if dest is higher or lower than src
    jge forward_cpy ; if destination is higher or same, copy forward

    mov r8, rdi ; store dest pointer
    mov r9, rsi ; store src pointer
    mov rcx, rdx ; cpy length

backward_copy:
    dec rcx ; reduce counter

    mov al, byte[r9 + rcx] ; load byte from source
    mov byte[r8 + rcx], al ; store byte in destination

    jnz backward_copy ; continue if counter is not zero

    mov rax, rdi ; return dest
    ret

forward_cpy:
    xor rcx, rcx ; reset counter

forward_copy_loop:
    cmp rcx, rdx ; check if counter has reached n
    je end_memmove

    mov al, byte[rsi + rcx] ; load byte from src
    mov byte[rdi + rcx], al ; store byte in dest

    inc rcx ; increment counter
    jmp forward_copy_loop ; repeat the loop

end_memmove:
    mov rax, rdi
    ret

null:
    xor rax, rax ; return NULL
    ret
