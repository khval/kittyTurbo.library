# Info

Documentation for Kitty Craft Extensions commands.

Commands listed as 
**bold**
are commands that are implemented.

Commands listed as
*italic*
are commands started on.

Command without description, are not implemented.

At bottom of the list you will find none supported commands.

# List of commands

**Multi Yes**

    Enable multitasking, calls function exec.library/permit()

    You need too call “Multi Yes” equality number of times as “Multi No” is executed, 
    it should be safe to use this command in reclusive loop, but you probably should not. 

    (Warning do not mix with craft extension, they do not keep the same count)

**Multi No**

    Disable multitasking, executes function exec.library/forbid()

    Do not abuse this command!!!
    This is not a magic bullet, it should not be used to speed up your basic program.

    On AmigaOS4.1 the mouse, keyboard, audio, +++, needs multitasking, disabling multitasking
    for a long-time course bad sound, keyboard / mouse locking up, plus graphics will not be updated,
    if multitasking is disabled, some of the basic command might result in dead locks,
    as it they might wait for graphic engine, or a system event,
    that will never happen, while multitasking is disabled.

    If you need safe atomic protection, look at the OS4.1 SDK in the folder. 
    “SDK:Documentation/Autodocs/exec.h”, See functions MutexObtain() and MutexRelease().

    Only when it written you most disable multitasking, should you disable multitasking,
    and when you keep the multitasking disabled as short as possible.
    
    (Warning do not mix with craft extension, they do not keep the same count)

**n=Lsl.b(value,shift)**

    Shifts bits down/left, resulting bits moving to left.
    
    The command can be explained mathematical like this.
    
    result = value * (2^shift)
    
    In effect this command is often used for quick multiply,
    provided you can convert your multipay value to 2^shift format.
    
    Example:
    lsl.b($81818181,1)=$81818102

**n=Lsl.w(value,shift)**


    Shifts bits down/left, resulting bits moving to left.
    
    The command can be explained mathematical like this.
    
    result = value * (2^shift)
    
    In effect this command is often used for quick multiply,
    provided you can convert your multipay value to 2^shift format.
    
    Example:
    lsl.w($81818181,1)=$81810302

**n=Lsl.l(value,shift)**

    Shifts bits down/left, resulting bits moving to left.
    
    The command can be explained mathematical like this.
    
    result = value * (2^shift)
    
    In effect this command is often used for quick multiply,
    provided you can convert your multipay value to 2^shift format.
    
    Example:
    lsl.l($81818181,1)=$03030302

**n=Lsr.b(value,shift)**

    Shifts bits up/right, resulting bits moving to right.
    This command only effect low byte, the high bytes are kept.

    Example:
    lsl.b($81818181,1)=$81818140

**n=Lsr.w(value,shift)**

    Shifts bits up/right, resulting bits moving to right.
    This command only effect the two low bytes, the high bytes are kept.

    Example:
    lsr.w($81818181,1)=$818140C0

**n=Lsr.l(value,shift)**

    Shifts bits up/right, resulting bits moving to right.
    
    To example the command to none computer geeks.
    The command can be explained mathematical like this.
    
    result = value / (2^shift)
    
    In effect this command is often used for quick divide,
    provided you can convert your divide value to 2^shift format.

    Example:
    lsr.l($81818181,1)=$40C0C0C0

**n=L Swap(n)**

**n=Test.b(n,n)**

    Check is low bytes is equal

**n=Test.w(n,n)**

    Check if low word is equal

**n=Test.l(n,n)**

    Check if int is equal

Vbl Wait [y beam] 

    Wait for a beam position, 
    you don’t have access to internal of retro mode, 
    so this command, will work just wait vbl

Reserve Check n 

Check Erase  

n=Check(n To n,n,n)

Set Check n,n,n To n,n 

Reset Check n 

n=Hit Spr Zone(n,n,n)

n=Hit Bob Zone(n,n,n)

n=Hit Spr Check(n To n,n,n,n)

n=Raw Key(n)

**R Move dx,dy**

    Relative to the graphic cursor xgr, ygr

**R Draw dx,dy**

    Draw a line relative to graphic cursor xgr, ygr
    same as draw xgr,ygr to xgr+dx,ygr+dy
    
    Unlike R Box, R Bar, this command does change graphic cursor (xgr,ygr).

**R Box dx,dy**

    Draw a box relative to graphic cursor xgr, ygr
    same as box xgr,ygr to xgr+dx,ygr+dy
    
    Command does not change graphic cursor, 
    you need to move graphic cursor your self with R home 
    or Xgr, Ygr commands.

**R Home x,y**

    moves graphic cursor to x,y
    Reamended using standard command instead using addons have look at Gr Locate.

    same as:
  
        xgr=x : ygr=y

    and command:
    
        gr locate x.y

**R Bar dx,dy**

    Draw a bar relative to graphic cursor xgr, ygr
    same as box xgr,ygr to xgr+dx,ygr+dy

    Command does not change graphic cursor, 
    you need to move graphic cursor your self with R home 
    or Xgr, Ygr commands.


Reserve Object n,n 

Define Draw n,n To n,n 

Define Move n,n To n,n 

Define Stop n,n 

Define Attr n,n To n,n 

Object Draw n 

R Object Draw n,n,n 

Object Mag Draw n,n 

R Object Mag Draw n,n,n,n 

Object Erase n 

Line 3d x,y,z To x,y,z 

Eye 3d x,y 

Object Save s$,n To n 

Object Load s$,n 

Multi Blit [start] To [end] 

**Blit Erase [n]**

	Erase blit [n] from memory.

**Blit Speed [n],[shift]**

    Sets the speed of blit
    [shift] value from -15 to 15

Blit Int On [start] To [end] 

Blit Int Off  

Blit Int Change [start] To [end]

Blit Int Wait [n] 

Blit Left [screen],[x],[y] To [x1],[y1],[shift]

	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

Blit Up [screen],[x],[y] To [x1],[y1],[shift]

	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

Blit Store Left [screen],[n],[x],[y] To [x1],[y1],[shift]

	Store zone [n]
	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

Blit Store Up [screen],[n],[x],[y] To [x1],[y1],[shift]

	Store zone [n]
	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

Blit Clear [bit]

    This command clears all or some of bit plains. 
    on Amiga computers with planar graphics this command should be faster than Cls command.
    On modern graphic cards, this command its slower, instead of clearing one or two bitmaps, 
    this command has to mask the image with a AND operation, to remove bits from the color value.

    bit %001 clear plain 0
    bit %010 clear plain 1
    bit %011 clear plain 1 and 0
    bit %100 clear plain 2
    bit %101 clear plain 2 and 0
    bit %110 clear plain 2 and 1
    bit %111 clear plain 2,1 and 0  

**F Plot x,y,[color]**

    If your changing colors often then this command can be faster then normal Plot command.
    if your not changing color often, it should be faster to preset color with ink command.

    This command does not change graphic cursor.

**n=F Point(x,y)**

    Same as normal point command, no difference in speed.

    This command does not change graphic cursor.

**F Circle x,y,r,[color]**

    Same as normal circle command, no difference in speed.

    This command does not change graphic cursor.

**F Draw x,y**

    Same as normal draw command, no difference in speed.

    This command does change graphic cursor.

**F Draw x,y To x,y**

    Same as normal draw command, no difference in speed.

    This command does change graphic cursor.

**n=F Sqr(n)**

    Same as normal sqr command, no difference in speed.

n=Left Click

    This command should work while in exec/forbid(), this is not the case for Amos Kittens / AmigaOS 4.1, 
    because the USB stack has run for the mouse keys to be processed.

    You should really avoid writing code that is not system fremedly.
    I will suggest using Amos Pro command "Mouse Click" or "Mouse Key" instead of this command.

**Reserve Stars n**

    Reserve stars, or random dots in x,y plain

**Define Star n,x,y,x speed,y speed**

    Set star [n] coordinate [x],[y] and speed

**Display Stars**
    
    draws stars and computes the next position of the stars.

**Stars Erase**

    Erase stars / dots

Stars Compute [n start] To [n end]

    Calculate the new position of the stars.
    from [n start] to [n end]

**Stars Draw**

    Draw stars/dots

**Stars Speed [start] To [end],[speed x],[speed y]**

    Change the speed of of a range of star from start to end.-    
    First star is at 1, if start is 0, you will get illegal function call.      

Stars Clip x0,y0,x1,y1 

    Limit where stars are drawn

Stars Int On n 

Stars Int Off  

Object Limit n 

Set Planes n 

Plane Offset n,n,n,n 

Plane Swap n,n,n 

Plane Shift Up n,n To n 

Plane Shift Down n,n To n 

Plane Update n 

F Paste Icon [x],[y],[n]

    On Amos Kittens:

        Same as normal paste icon (uses retroMode.library).
    
    On Amos Pro:
    
        * This command uses blitter.
    
        * This command is made for speed, does not do testing.

        * This command can crash your computer.

F 32 Icon [x],[y],[n]

    On Amos Kittens:

        Same as normal paste icon (uses retroMode.library).
    
    On Amos Pro:

        * This command should only work with 32-pixel width icons.

        * This command uses blitter.
    
        * This command is made for speed, does not do testing.

        * This command can crash your computer.

F 16 Icon [x],[y],[n]

    On Amos Kittens:

        Same as normal paste icon (uses retroMode.library).
    
    On Amos Pro:

        * This command should only work with 16-pixel width icons.

        * This command uses blitter.

        * This command is made for speed, does not do testing.

        * This command can crash your computer.

F 16proc Icon [x],[y],[n]

    On Amos Kittens:

        Same as normal paste icon (uses retroMode.library).

    On Amos Pro:
    
        * This command should only work with 16-pixel width icons.
    
        * This command uses CPU
        
        * This command is made for speed, does not do testing.

        * This command can crash your computer.

F 32proc Icon [x],[y],[n]

    On Amos Kittens:

        Same as normal paste icon (uses retroMode.library).

    On Amos Pro:

        * This command should only work with 32-pixel width icons.

        * This command uses CPU

        * This command is made for speed, does not do testing.

        * This command can crash your computer.

n=X Icon(n)

    Return width in words of icon[n]
	words width = icon [n] pixel width / 16

n=Y Icon(n)

    return pixel height of icon [n]

n=Planes Icon(n)

    Should returns number of bit plains. (on Amos Kittens this command will return 8.)   

n=Icon Check(n)

n=Cpu Info

	This command returns CPU type..
	Because OS4.1 uses same ID numbers for PowerPC as 680x0, to avoid mistakes $1000 is added for PPC.

	= CPUTYPE_68X00
	or 
	= $1000 | CPUTYPE_PPC

	Id numbers can be found in file "exectags.h" in the AmigaOS4.1 SDK.

n=Math Info

	Amos Kittens will just return 882, it does not check for coprocessor

	000 - no coprocessor installed
	881 - MC68881 coprocessor installed
	882 - MC68882 coprocessor installed
		
F Put Block n,n,n 

Reserve Static Block n 

Static Block Erase  

Build Static Block  

F Put Static Block n,n,n 

Scene Load s$,n 

Scene Icon Bank n 

Scene Bank n 

    A command for a tiles / map system

n=Scene Check(n,n)

    A command for a tiles / map system

n=Scene 16 Check(n,n)

    A command for a tiles / map system

Scene Change n,n,n 

    A command for a tiles / map system

Scene 16 Change n,n,n 

    A command for a tiles / map system

Scene 16 Draw n,n,n,n,n,n 

    A command for a tiles / map system

Scene 16 Def n,n,n,n,n,n,n,n 

    A command for a tiles / map system

Scene 16 Restore n 

    A command for a tiles / map system

Scene 16 Limit n 

    A command for a tiles / map system

n=Scene 32 Check(n,n)

    A command for a tiles / map system

Scene 32 Change n,n,n 

    A command for a tiles / map system

Scene 32 Draw n,n,n,n,n,n 

    A command for a tiles / map system

Scene 16 View n,n,n To n,n 

    A command for a tiles / map system

Scene 32 View n,n,n To n,n 

    A command for a tiles / map system

Scene 16 Do n,n 

    A command for a tiles / map system

Scene 32 Do n,n 

    A command for a tiles / map system

Scene 16 Top n,n 

    A command for a tiles / map system

Scene 32 Top n,n 

    A command for a tiles / map system

Scene 16 Bottom n,n 

    A command for a tiles / map system

Scene 32 Bottom n,n 

    A command for a tiles / map system

Scene 16 Left n,n 

    A command for a tiles / map system

Scene 32 Left n,n 

    A command for a tiles / map system

Scene 16 Right n,n 

    A command for a tiles / map system

Scene 32 Right n,n 

    A command for a tiles / map system

n=Scene X  

    A command for a tiles / map system

n=Scene Y  

    A command for a tiles / map system

Scene Palette n 

    A command for a tiles / map system

Scene Mask Palette n 

    A command for a tiles / map system

Amos Pri [value]

    Set Amos priority

n=Bit Field Ins(n,n,n,n)

n=Bit Field Ext(n,n,n)

n=Hit Bob Check(n To n,n,n,n)

n=Byte Hunt(n To n,n,n To n)

Workbench Open  

**Memory Fill [start] To [end],text$**

    Fill memory with text

**n=Range(value,start To end)**

    if value is less then [start] then [value] is [start]
    if value is more then [end] then [value] is [end].

n=Texp(n,n,n)

n=T Clip(n,n)

**n=Between(min,value,max)**

    This command returns true if value is more then min, 
    and values is less then max, if this not the case then false is returned.

    Same as "(min < value < max)"

n=Bank End(n)

Debug  
