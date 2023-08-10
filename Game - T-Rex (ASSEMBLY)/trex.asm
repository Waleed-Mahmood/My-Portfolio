[org 0x0100]
jmp start
					;Variables
					
					;OldIsr Variables(To store offset and segment of Original ISR's)
oldisr: dd 0
oldisr1: dd 0
					;Prints Following Messages when Called in Subroutines
num :db 'Ω'
message:db 'SCORE:'	
message2: db '   {: *T-REX RUNNER* :}   '
message3:db 'Press SPACEBAR to Play T-REX GAME'
msg4: db 'Press ESC to EXIT  the T-REX GAME'
msg5: db '   {: *T-REX RUNNER* :}   '   
msg51: db 'PROJECT: T-REX GAME'
msg6: db 'MADE BY: '
msg7: db 'WALEED(19L-2256)'
msg71:db '-------------------'
msg8: db 'INTRUCTIONS:'
msg9: db '1-Press SPACE-BAR to JUMP'
msg10: db '2-Press ARROW-UP to JUMP'
msg11: db '3-SCORE = Current Player Score'
gOver: db 'GAME OVER :('
msg12: db '---------- LOAD-ING -----------' 
msg13: db '|'
msg14: db '------------ PROJECT ------------'
msg15: db '--------- T-REX RUNNER ----------'


					;T-REX Variables
TrexHead: db '*'
TrexBody: db '|'					
TrexLeftLeg: db '/'
TrexRightLeg: db '\'

num1: dw 0
num2:dw 0
					;Counter Variables
counter1: dw 0
counter: dw 0
					;printBorder Subroutine Variables
borderLB: db 'Ω'
borderRB: db 'Ω'
borderTL_TR: db 'Ω'


					;clrscr=[Clears the Entire Screen];	
clrscr: 
push cs
pop ds	;Initializing DS to CS 			
pusha	;(Push All)[Push AX, CX, DX, BX, original SP, BP, SI, and DI]
mov ax,0xb800
mov es,ax
mov di,0
nextchar:
mov word[es:di],0x0720 ;space
add di,2
cmp di,4000
jne nextchar
popa	;(Pop All)[Pop DI, SI, BP, original SP, BX, DX, CX, and AX]
ret


					;TrexHead=[Prints Trex Head (*)];
printTrexHead:
push 0x07	;Attribute
push TrexHead	;print GAME OVER
push 1	;length
push 13	;row
push 01	;col
call printMsg@Loc
ret


					;TrexBody=[Prints Trex Body (|)];
printTrexBody:
push 0x07	;Attribute
push TrexBody	;print GAME OVER
push 1	;length
push 14	;row
push 01	;col
call printMsg@Loc
ret


					;TrexRightLeg=[Prints Trex Right Leg (\)];
printTrexRightLeg:
push 0x07	;Attribute
push TrexRightLeg	;print GAME OVER
push 1	;length
push 15	;row
push 02	;col
call printMsg@Loc
ret


					;TrexLeftLeg=[Prints Trex Left Leg (/)];
printTrexLeftLeg:
push 0x07	;Attribute
push TrexLeftLeg	;print GAME OVER
push 1	;length
push 15	;row
push 00	;col
call printMsg@Loc
ret


					;PrintRoad=[Prints The Road (====) ];
PrintRoad: 
mov cx,0

loopRoad: 

push 11001010b	;Attribute
push num	;
push 1;length
push 16	;row
push cx	;col
call printMsg@Loc

inc cx
cmp cx,80
jne loopRoad
ret 


					;printBorder=[Prints the Specified Characters around the Screen Border];
					;It recieves Attribute as its Parameter and also empty the stack when RET
					
printBorder:
push bp
mov bp,sp
pusha
mov ah, 0x13 ; service 13 - print string
mov al, 1; subservice 01 – update cursor
mov bh, 0 ; output on page 0
mov bl, [bp+4];attrib
mov dh, 00	;row 00
mov dl, 00	;coloumn 00
mov cx, 1	;length of string
push cs
pop es ; segment of string
mov bp, borderTL_TR; Prints Selected Character as the msg

TopL_to_TopR:	;Top Left to Top Right
int 0x10 ; call BIOS video service
inc dl
cmp dl, 79
jne TopL_to_TopR

mov dl,00
mov dh, 24

BottomL_to_BottomR:	;Bottom Left to Bottom Right
int 0x10 ; call BIOS video service
inc dl
cmp dl,79
jne BottomL_to_BottomR

mov dl,00
mov dh,00
xor bp,bp
mov bp, borderLB	;Prints Selected Character as the msg

TopL_to_BottomL:	;Top Left to Bottom Left
int 0x10
inc dh
cmp dh,24
jne TopL_to_BottomL

mov dl,79
mov dh,00
xor bp,bp
mov bp, borderRB	;Prints Selected Character as the msg

TopR_to_BottomR:	;Top Right to Bottom Right
int 0x10	; call BIOS video service
inc dh
cmp dh,24
jne TopR_to_BottomR

EmptyStack:
pop bp
popa
ret 2

					;Prints Msg at the Specified Location using int 10h BIOS service
					;parameters are msg,length,attribute,row,col
printMsg@Loc:
push bp
mov bp,sp
pusha
mov ah, 0x13 ; service 13 - print string
mov al, 1 ; subservice 01 – update cursor
mov bh, 0 ; output on page 0
mov bl, [bp+12]; normal attrib
mov dh, [bp+6]	;row
mov dl,	[bp+4]	;col
mov cx, [bp+8] ; length of string
push cs
pop es ; segment of string
mov bp, [bp+10] ; Prints(GAME OVER)
int 0x10 ; call BIOS video service

popa
pop bp
ret 10


					;printScoreNum=[Prints Current Score on Screen]
					;Recieves Current Tick Count(Number) as the Parameter and Clears Stack when RET
printScoreNum:
push cs
pop ds
push bp
mov bp,sp
pusha
mov ax,0xb800
mov es,ax

mov bx,4
mov al,80
mul bl
add ax,66
shl ax,1
mov di,ax
mov ax,[bp+4]	; load number in ax
mov bx, 10	; use base 10 for division
mov cx, 0	; initialize count of digits

l:
mov dx, 0 ; zero upper half of dividend
div bx ; divide by 10
add dl, 0x30 ; convert digit into ascii value
push dx ; save ascii value on stack
inc cx ; increment count of values
cmp ax, 0 ; is the quotient zero
jnz l ; if no divide it again

np:
pop dx	; remove a digit from the stack
mov dh,01001010b	; Attribute= Red background with Green font
mov [es:di], dx ; print char on screen
add di, 2 ; move to next screen location
loop np ; repeat for all digits on stack

popa
pop bp
ret 2 


timer:
push cs
pop ds
push ax
mov ax, cs
mov ds, ax
inc word[cs:num1]
push word[cs:num1]	;pass num1 as the score to be printed

call printScoreNum

pop ax
ret


pillar1:
push cs
pop ds
push bp
mov bp,sp
mov ax, cs
mov ds, ax
add word [counter], 1
cmp word [counter], 8 ;timer remain in air
je skip9
jmp finish

skip9:
mov ax,0xb800
mov es,ax


q9:
mov bx,15
mov al,80
mul bl
add ax,79
shl ax,1
cmp di, 2400
jne skip5
mov di,ax

skip5:
mov al,0xDB;219dec=00db=û(Pillar Shape)
mov ah,0x01

mov bx,15
mov al,80
mul bl
add ax,60
shl ax,1
cmp si, 2400
jne skip6
mov si,ax

skip6:
mov al,0xDB	;;219dec=00db=û(Pillar Shape)
mov ah,0x07

mov bl,0xDB	;219dec=00db=û(Pillar Shape)
mov bh,0x07

q10:
mov word[es:di],ax
mov word[es:si],ax

t:
inc word[cs:num2]	;(Real time ISR(no clue where the control is i,e dos,command com))	;Using CS override(bcz DS is not initialized)
cmp word[cs:num2],3000
jne t
;push 0xb800
;pop es
cmp word [es:2402], 0x07db	;219dec=00db=û(Pillar Shape)
jne skip21
; mov word[es:0],0x0741
cmp word [es:2400], 0x072F	;2f=='/'
; mov word[es:2],0x0742
jne skip21
jmp start1

skip21:
mov word[es:di],0x0720
mov word[es:si],0x0720
sub si,2
sub di,2
call timer

mov word[counter],0

finish:
;jmp start1
add word [counter1], 1
cmp word [counter1], 120;timer pillar
jne skip11
push 10
call whitespace
pop bp
push 13
call appear
pop bp
mov word [counter1], 0

skip11:
;popa
pop bp
ret
jmp far [cs:oldisr1]
mov al, 0x20
out 0x20, al
iret

		
whitespace:
push cs
pop ds	
push bp
mov bp, sp 
sub sp, 2

pusha
mov cx, 3
mov dx, 0x0720
mov bx, [bp+4]
add bx, 2
mov [bp-2], bx
mov bx, [bp+4]

whitespace_loop:	
mov al, 80
mul bl
cmp bx, [bp-2]
je whitespace_legs

whitespace_other:
add ax, 1
shl ax, 1
mov di, ax
mov word[es:di],dx
; mov word[es:0],0x0743
inc bx
jmp next
													
whitespace_legs:
shl ax, 1
mov di, ax
mov word[es:di],dx
add di, 4
mov word[es:di],dx
													
next:	
loop whitespace_loop
popa
mov sp, bp
pop bp
ret
			
appear:
push cs
pop ds	
push bp
mov bp, sp
pusha
mov bx, [bp+4]		
mov al, 80
mul bl
add ax, 1
shl ax, 1
mov di, ax
mov al,'*'
mov ah, 0x07			
mov word[es:di], ax
inc bx
mov al, 80
mul bl
add ax, 1
shl ax, 1
mov di, ax
mov al,'|'
mov ah, 0x07			
mov word[es:di], ax
inc bx										
mov al, 80
mul bl
shl ax, 1
mov di, ax
mov al,'/'
mov ah, 0x07			
mov word[es:di], ax
add di, 4
mov al, '\'
mov word[es:di], ax
											
popa
pop bp 
ret
		
jump:
push cs
pop ds
push bp 
mov bp, sp
pusha
mov ax, 0xb800
mov es,ax
mov bx, 13

jump_loop:
push bx
call whitespace
pop bx
sub bx, 3
push bx

call appear
pop bx
push bx
pop bx
add bx, 3
push bx
pop bx
popa
pop bp
ret


kbisr:
push cs
pop ds
push ax
mov ax, cs
mov ds, ax
in al, 0x60 ; read a char from keyboard port
cmp al, 0x48 ; is the up key button
jne nextcmp ; no, try next comparison

call jump
jmp nomatch ; leave interrupt routine
		
nextcmp:
cmp al, 0x39 ; is the space key
jne nomatch ; no, leave interrupt routine

call jump 
		
nomatch:
pop ax
jmp far [cs:oldisr]	;interrupt chaining

;;NO need to use IRET as the chaining is used in previous line
;;The original ISR will automatically use IRET at its end 

; mov al, 0x20
; out 0x20, al ; send EOI to PIC
; pop ax
; iret


TerminateGame:
call clrscr

push 11001010b	;attribute
call printBorder

push 11001010b	;Attribute
push gOver	;print GAME OVER
push 12	;length
push 14	;row
push 31	;col
call printMsg@Loc

mov ax,0x4c00
int 21h

				;;;			THE PROGRAM STARTS FROM HERE:-      ;;;


start:
call clrscr
push 11001010b	;attribute
call printBorder


printLoading:
push 01001010b	;Attribute
push msg14;print LOADING msg
push 33;length
push 03	;row
push 21	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg15;print LOADING msg
push 33;length
push 04	;row
push 21	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg12;print LOADING msg
push 31;length
push 09	;row
push 22	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg12;print LOADING msg
push 31;length
push 13	;row
push 22	;col
call printMsg@Loc

mov bx,09
mov ax, 21
printVertical:
push 01001010b	;Attribute
push msg13;print LOADING msg
push 1;length
push bx	;row
push ax	;col
call printMsg@Loc
cmp dx,0
jz printV2

inc bx
cmp bx,14
jne printVertical 
mov dx,0
mov bx,08
mov ax,53


printV2:
inc bx
cmp bx,14
jne printVertical


printLoadingBox:
mov ax,10	;row
mov bx,22	;col
mov dx,0 ;flag

TLtoR:
push 01001010b	;Attribute
push num;print border for loading
push 1	;length
push ax	;row
push bx	;col
call printMsg@Loc

cmp dx,1; check if flag is 1(means Bottom L to R is being printed)
je BRtoL; 
cmp dx,2
je TLtoBL
cmp dx,3
je TRtoBR
inc bx
cmp bx,52
jne TLtoR

mov dx,1
mov ax,12
mov bx,53

BRtoL:

dec bx
cmp bx,22
jne TLtoR

mov dx,2
mov ax,13
mov bx,22

TLtoBL:

dec ax
cmp ax,10
jne TLtoR

mov dx,3
mov bx,52
mov ax,09

TRtoBR:

inc ax 
cmp ax,12
jne TLtoR

mov bx,23	; col


printLoadingMovement:
push 11001010b	;Attribute
push msg13	;print GAME OVER
push 1	;length
push 11	;row
push bx	;col
call printMsg@Loc
mov cx,65000
inc bx
cmp bx,52
jne Delay
je Done

Delay:
dec cx
cmp cx,0
jnz Delay
jmp printLoadingMovement

Done:



printMSGs:

push 01001010b	;Attribute
push message3	;print SPACE-BAR msg
push 33	;length
push 18	;row
push 21	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg4	;print ESC msg
push 33	;length
push 19	;row
push 21	;col
call printMsg@Loc


tryAgain: ;Checks whether the correct key is pressed
mov ah,0
int 16h
cmp al,0x20	;SPACE-BAR
je startGame
cmp al,0x1b	;ESC Key
je TerminateGame
jmp tryAgain


startGame:;new page
call clrscr
push 01001010b	;attribute
call printBorder

push 01001010b	;Attribute
push message2	;print GAME NAME
push 26	;length
push 01	;row
push 25	;col
call printMsg@Loc


					
push 01001010b	;Attribute
push message	;print ScoreString
push 6	;length
push 4	;row
push 60	;col
call printMsg@Loc

call PrintRoad
call printTrexHead
call printTrexBody
call printTrexLeftLeg
call printTrexRightLeg

push 01001010b	;Attribute
push msg8	;print 'INTRUCTIONS:'
push 12	;length
push 18	;row
push 03	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg9	;print '1-Press SPACE-BAR to JUMP'
push 25	;length
push 19	;row
push 03	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg10	;print '2-Press ARROW-UP to JUMP'
push 24	;length
push 20	;row
push 03	;col
call printMsg@Loc


push 01001010b	;Attribute
push msg11	;print '3-SCORE = Current Player Score'
push 30	;length
push 21	;row
push 03	;col
call printMsg@Loc


printsMiddlePArtition:
mov ax,17
loopPartition:
push 01001010b	;Attribute
push num	;print PArtition BOrder
push 1;length
push ax	;row
push 36	;col
call printMsg@Loc
inc ax
cmp ax, 24
jne loopPartition
pop ax

printsMiddlePArtition1:
mov ax,37
loopPartition1:
push 11001010b	;Attribute
push num	;print PArtition BOrder
push 1;length
push 20	;row
push ax	;col
call printMsg@Loc
inc ax
cmp ax, 44
jne loopPartition1
pop ax

printsMiddlePArtition2:
mov ax,17
loopPartition2:
push 01001010b	;Attribute
push num	;print PArtition BOrder
push 1;length
push ax	;row
push 44	;col
call printMsg@Loc
inc ax
cmp ax, 24
jne loopPartition2
pop ax



push 01001010b	;Attribute
push msg51	;print 'PROJECT: T-REX GAME'
push 19	;length
push 18	;row
push 50	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg6	;print 'MADE BY: '
push 9	;length
push 19	;row
push 50	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg7	;print '1-WALEED(19L-2256)'
push 18	;length
push 20	;row
push 50	;col
call printMsg@Loc

push 01001010b	;Attribute
push msg71	;print '2-HAMZA JAWAD(15L-4376)'
push 23	;length
push 21	;row
push 50	;col
call printMsg@Loc


					;Saving Old ISR's in oldisr and oldisr1;
xor ax,ax
mov es,ax 	;point es to 0 ivt

mov ax, [es:9*4]	;save offset of old routine(int 9h)
mov  [oldisr], ax
mov ax, [es:9*4+2]
mov  [oldisr+2], ax

mov ax, [es:8*4]	;save offset of old routine(int 8h)
mov  [oldisr1], ax
mov ax, [es:8*4+2]
mov  [oldisr1+2], ax

mov si, 2520	;1st hurdle(Left Pillar)
mov di, 2558	;2nd hurdle(Right Pillar)

cli	;disable interrupt
mov word [es:9*4], kbisr ; store offset at n*4
mov [es:9*4+2], cs ; store segment at n*4+2
sti	;enable interrupt


l20:
call pillar1
jmp l20

cli	;disable interrupt
mov word[es:8*4],pillar1
mov [es:8*4+2],cs
sti	;enable interrupt


start1:

push 11001010b	;attribute
call printBorder

push 11001010b	;Attribute
push gOver	;print GAME OVER
push 12	;length
push 10	;row
push 31	;col
call printMsg@Loc


; ExitGame:
; mov ax,0x4c00
; int 21h

						
TSR:
mov dx,start ;offset of start label
add dx,15	;(For rounding up Para(multiple of 16))
mov cl,4	;(2^4=16)  
shr dx,cl	;(shift right dx=(offset of program till where it should remain Resident IN MEmory(Discarding Initialization)) 4 time== dx/16 )
mov ax,0x3100  ;(ah: 31=service ,  al: 00= indicates nothing went wrong(Terminated Normally))
int 0x21 ;Transfers Control to MS DOS but the calculated para's stay resident in memory(Free MEM pointer points to the end of calculated para)

; ;Check memory situation using commamd in DOS : mem/c

