SECTION DATA
N1: CONST 3
N0: CONST 4
N2: SPACE 3
N3: SPACE 6
SECTION TEXT
COPY N1, N2
jmp lol
LOAD N1
ADD N3 + 4
lol: add N1
STORE N2
OUTPUT N2
