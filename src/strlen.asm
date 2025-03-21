;;
;; EPITECH PROJECT, 2025
;; strlen
;; File description:
;; returns the length of the string s
;;

section .text
    global strlen

strlen:
    cmp rdi, 0
    je return_null

    xor rcx, rcx ; initialize registers rcx to 0 (clear register)

loop_strlen:
    mov al, byte[rdi + rcx]

    cmp al, 0 ; compare byte : while str[i] != '\0'
    je end_loop ; if yes jump to end_loop

    inc rcx ; increment the loop counter
    jmp loop_strlen ; continue the loop, count next char

return_null:
    xor rax, rax
    ret

end_loop:
    mov rax, rcx ; rax stock the return value
    ret ; return value
