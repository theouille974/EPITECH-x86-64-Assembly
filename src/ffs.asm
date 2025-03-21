;;
;; EPITECH PROJECT, 2025
;; ffs
;; File description:
;; returns the position of the least significant bit set to 1 in the integer i
;;

section .text
    global ffs

ffs:
    cmp rdi, 0
    je return_zero ; if zero, return 0

    bsf rax, rdi ; bit scan : check for least significant bit
    add rax, 1
    ret

return_zero:
    xor rax, rax
    ret
