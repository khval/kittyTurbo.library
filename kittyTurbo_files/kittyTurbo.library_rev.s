VERSION = 53
REVISION = 1

.macro DATE
.ascii "16.3.2020"
.endm

.macro VERS
.ascii "kittyTurbo.library 53.1"
.endm

.macro VSTRING
.ascii "kittyTurbo.library 53.1 (16.3.2020)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: kittyTurbo.library 53.1 (16.3.2020)"
.byte 0
.endm
