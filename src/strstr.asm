;;
;; EPITECH PROJECT, 2025
;; strstr
;; File description:
;; finds the first occurrence of the substring needle in the string haystack
;;

section .text
    global strstr

strstr:
    cmp rdi, 0        ; Check if haystack (rdi) is NULL
    je null

    cmp rsi, 0        ; Check if needle (rsi) is NULL
    je  null

    cmp byte[rsi], 0
    je return_rax

search_loop:
    mov rbx, rdi         ; Set haystack pointer
    mov rcx, rsi         ; Set needle pointer

compare_loop:
    mov al, byte[rbx]
    mov dl, byte[rcx]

    cmp dl, 0 ; Check if needle reached null terminator
    je found_match ; we found a match

    cmp al, dl
    jne next_haystack ; If different, move to the next position

    inc rbx ; Move haystack pointer
    inc rcx ; Move needle pointer
    jmp compare_loop ; Continue checking

next_haystack:
    mov al, byte[rdi] ; Load next haystack character

    cmp al, 0 ; Check if haystack reached null terminator
    je null ; not found

    inc rdi ; Move haystack pointer
    jmp search_loop ; Restart comparison from the next position

found_match:
    mov rax, rdi ; Return pointer to the first match
    ret

null:
    xor rax, rax ; Return NULL
    ret

return_rax:
    mov rax, rdi ; If needle is empty (""), return haystack
    ret ; Return haystack (rax already set)
