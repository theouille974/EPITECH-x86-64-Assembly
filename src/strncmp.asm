;;
;; EPITECH PROJECT, 2025
;; strncmp
;; File description:
;; compares n characters of two strings
;;

section .text
    global strncmp

strncmp:
    xor rcx, rcx ; initialize rcx to 0 (counter)

loop_strncmp:
    cmp rcx, rdx ; compare current index (rcx) with the number of characters (n)
    jge equal ; if counter >= count, jump to equal (strings are equal)

    mov al, byte[rdi + rcx] ; mov one letter in al (str1)
    mov bl, byte[rsi + rcx] ; mov one letter in bl (str2)

    cmp al, bl ; compare the two letter
    jne not_equal

    cmp al, 0 ; Is AL (character) 0? If yes, we reached the null terminator
    je equal

    inc rcx ; increment counter
    jmp loop_strncmp

not_equal:
    movzx eax, al
    movzx ebx, bl
    sub eax, ebx ; Return difference
    ret

equal:
    xor rax, rax ; Return 0 (strings are equal)
    ret
