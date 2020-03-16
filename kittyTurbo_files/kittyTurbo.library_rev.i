VERSION		EQU	53
REVISION	EQU	1

DATE	MACRO
		dc.b '16.3.2020'
		ENDM

VERS	MACRO
		dc.b 'kittyTurbo.library 53.1'
		ENDM

VSTRING	MACRO
		dc.b 'kittyTurbo.library 53.1 (16.3.2020)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: kittyTurbo.library 53.1 (16.3.2020)',0
		ENDM
