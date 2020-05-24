Multi Yes  

Multi No  

n=Lsl.b(n,n)

    Shifts bits down/left, resulting bits moving to left.
    This command only effect low byte, the high bytes are kept.

    Example:
    lsl.b($81818181,1)=$81818102
        
n=Lsl.w(n,n)

    Shifts bits down/left, resulting bits moving to left.
    This command only effect low bytes, the high bytes are kept.

    Example:
    lsl.b($81818181,1)=$81810202

n=Lsl.l(n,n)

    Shifts bits down/left, resulting bits moving to left.
    
    To example the command to none computer geeks.
    The command can be explained mathematical like this.
    
    result = value * (2^shift)
    
    In effect this command is often used for quick multiply,
    provided you can convert your multipay value to 2^shift format.
    
    Example:
    lsl.b($81818181,1)=$03030302
    
n=Lsr.b(n,n)

    Shifts bits up/right, resulting bits moving to right.
    This command only effect low byte, the high bytes are kept.

    Example:
    lsl.b($81818181,1)=$81818140

n=Lsr.w(n,n)

    Shifts bits up/right, resulting bits moving to right.
    This command only effect the two low bytes, the high bytes are kept.

    Example:
    lsl.b($81818181,1)=$818140C0

n=Lsr.l(n,n)

    Shifts bits up/right, resulting bits moving to right.
    
    To example the command to none computer geeks.
    The command can be explained mathematical like this.
    
    result = value / (2^shift)
    
    In effect this command is often used for quick divide,
    provided you can convert your divide value to 2^shift format.

    Example:
    lsl.b($81818181,1)=$40C0C0C0

n=L Swap(n)

n=Test.b(n,n)

n=Test.w(n,n)

Vbl Wait n 

Reserve Check n 

Check Erase  

n=Check(n To n,n,n)

Set Check n,n,n To n,n 

Reset Check n 

n=Hit Spr Zone(n,n,n)

n=Hit Bob Zone(n,n,n)

n=Hit Spr Check(n To n,n,n,n)

n=Raw Key(n)

R Move n,n 

R Draw n,n 

R Box n,n 

R Home n,n 

R Bar n,n 

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

Line 3d n,n,n To n,n,n 

Eye 3d n,n 

Object Save s$,n To n 

Object Load s$,n 

Blit Store Left n,n,n,n To n,n,n 

Multi Blit n To n 

Blit Erase n 

Blit Speed n,n 

Blit Left n,n,n To n,n,n 

F Plot n,n,n 

Blit Clear n 

n=Left Click  

Reserve Stars n 

Define Star n,n,n,n,n 

Display Stars  

Stars Erase  

Stars Compute n To n 

Stars Draw  

Stars Speed n To n,n,n 

Stars Clip n,n,n,n 

n=F Point(n,n)

F Circle n,n,n,n 

n=F Sqr(n)

Stars Int On n 

Stars Int Off  

Blit Int On n To n 

Blit Int Off  

F Draw n,n To n,n 

F Draw n,n 

Object Limit n 

Set Planes n 

Plane Offset n,n,n,n 

Plane Swap n,n,n 

Plane Shift Up n,n To n 

Plane Shift Down n,n To n 

Plane Update n 

F Paste Icon n,n,n 

F 32 Icon n,n,n 

F 16 Icon n,n,n 

F 16proc Icon n,n,n 

F 32proc Icon n,n,n 

n=X Icon(n)

n=Y Icon(n)

n=Planes Icon(n)

n=Cpu Info  

n=Math Info  

F Put Block n,n,n 

Reserve Static Block n 

Static Block Erase  

Build Static Block  

F Put Static Block n,n,n 

Scene Bank n 

n=Scene Check(n,n)

n=Scene 16 Check(n,n)

Scene Change n,n,n 

Scene 16 Change n,n,n 

Scene 16 Draw n,n,n,n,n,n 

Scene 16 Def n,n,n,n,n,n,n,n 

Scene 16 Restore n 

Scene 16 Limit n 

n=Scene 32 Check(n,n)

Scene 32 Change n,n,n 

Scene 32 Draw n,n,n,n,n,n 

Scene 16 View n,n,n To n,n 

Scene 32 View n,n,n To n,n 

Scene 16 Do n,n 

Scene 32 Do n,n 

Scene 16 Top n,n 

Scene 32 Top n,n 

Scene 16 Bottom n,n 

Scene 32 Bottom n,n 

Scene 16 Left n,n 

Scene 32 Left n,n 

Scene 16 Right n,n 

Scene 32 Right n,n 

n=Scene X  

n=Scene Y  

Amos Pri n 

n=Bit Field Ins(n,n,n,n)

n=Bit Field Ext(n,n,n)

n=Hit Bob Check(n To n,n,n,n)

n=Byte Hunt(n To n,n,n To n)

Workbench Open  

Scene Load s$,n 

Memory Fill n To n,s$ 

Blit Int Change n To n 

Blit Int Wait n 

n=Range(value,start To end)

    if value is less then [start] then [value] is [start]
    if value is more then [end] then [value] is [end].

n=Texp(n,n,n)

Blit Up n,n,n To n,n,n 

Blit Store Up n,n,n,n To n,n,n 

n=Icon Check(n)

Scene Icon Bank n 

n=T Clip(n,n)

n=Between(min,value,max)

    This command returns true if value is more then min, 
    and values is less then max, if this not the case then false is returned.

    Same as "(min < value < max)"

Scene Palette n 

Scene Mask Palette n 

n=Bank End(n)

Debug  

