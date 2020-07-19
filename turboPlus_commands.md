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

**Vbl Wait [y beam]**

	Wait for a beam position, 
	you don’t have access to internals of retroMode.library, 
	so this command will work, just like "wait vbl" command.

**Reserve Check [items]**

	[items] creates a list of empty check zones.

**Check Erase**

	Free the memory of check list.

	Amos Kittens:
	
		Amos Kittens know it needs to free memory, thanks to context system.
		
	Amos Pro:

		You must call this command, before your basic program exists or else you might memory leek.

Reset Check [n] 

	Erase a check [n]

**[id]=Check([first] To [last],[x],[y])**

	Check if coordinate is inside the [range] of check zones, and return the check [id].
	
	[First],[last] is the [range] of check zones.
	
		Note: The first id in the table is "1" not "0".
	
	[x],[y]	the coordinate to check.
	
**Set Check [id],[x],[y] To [x1],[y1]**
		
	[ID] is the check ID, first ID number is 1, not 0.		
	[x],[y] upper left corner
	[x1],[y1] right, lower corner.

n=Hit Spr Check([check start] To [check end],[offset x],[offset y],[sprite n])

	Check the range checks from [check start] to [check end], 
	where [Offset x], [offset y] is offset from hot spot in the [sprite n].

n=Hit Bob Check([check start] To [check end],[offset x],[offset y],[bob n])

	Check the range checks from [check start] to [check end], 
	where [Offset x], [offset y] is offset from hot spot in the [bob n].

n=Hit Spr Zone([offset x],[offset y],[sprite n])

	A=Hzone(X Sprite(n)+[offset x],Y Sprite(n)+(offset y))

n=Hit Bob Zone([offset x],[offset y],[bob n])

	A=Zone(X bob(n)+[offset x],Y bob(n)+(offset y))

**n=Raw Key(n)**

	This command is same as key state command in Amos Pro, 
	unlike Key Sate, Raw Key command is designed to work when multitasking is disabled.

	Amos Kittens:

		This command will enable multitasking for a short period.
		but only works if "Multi No" command was used to do it.

**R Move [dx],[dy]**

	Relative to the graphic cursor xgr, ygr

**R Draw [dx],[dy]**

	Draw a line relative to graphic cursor xgr, ygr
	same as draw xgr,ygr to xgr+[dx],ygr+[dy]
	
	Unlike R Box, R Bar, this command does change graphic cursor (xgr,ygr).

**R Box [dx],[dy]**

	Draw a box relative to graphic cursor xgr, ygr
	same as box xgr,ygr to xgr+[dx],ygr+[dy]
	
	Command does not change graphic cursor, 
	you need to move graphic cursor your self with R home 
	or Xgr, Ygr commands.

**R Home [x],[y]**

	moves graphic cursor to x,y
	Reamended using standard command instead using addons have look at Gr Locate.

	same as:
  
		xgr=[x] : ygr=[y]

	and command:
	
		gr locate [x],[y]

**R Bar [dx],[dy]**

	Draw a bar relative to graphic cursor xgr, ygr
	same as box xgr,ygr to xgr+dx,ygr+dy

	Command does not change graphic cursor, 
	you need to move graphic cursor your self with R home 
	or Xgr, Ygr commands.

**Object Limit [n]**

	“Object Limit” command has misleading name it should be called Reserve Objects.
	The command defines number of objects items in the list.

	If [n] is set to 0 the objects are freed.

	Amos Kittens:
		
		This command should not be needed, the list should grow automatically.
		However, if you use this command, then the list don’t need to be reallocated.
		
	Amos Pro:
	
		this used to needed in Trubo extention, where it be defined to max 32.
		but should not be needed in Turbo Plus, 
		where you can have up to 32000 objects.
	
	
**Reserve Object [object],[number of elements]**

	Create an object with x number of elements.
	an object is a list of draw commands,
	that are not interpreted in the normal way.

**Define Draw [object],[element] To [x],[y]**

	Adds a draw command into the object list at element position.
	[x],[y] is relative coordinates, can be negative and positive numbers.

**Define Move [object],[element] To [x],[y]**

	Adds a move command into the object list at element position.	
	[x],[y] is relative coordinates, can be negative and positive numbers.

**Define Stop [object],[element]**

	Adds a stop command into the object list at element position.

**Define Attr [object],[element] To [colors],[drawmode]**

	Insets an attribute command int the element list of the object.

	this command can’t be combined with existing command in same
	element location, it will overwrite what ever is located there.

**Object Draw [object]**

	Draw object relative to 0,0 on the screen.

**R Object Draw [object],[x],[y]**

	Draw object relative to X,Y on the screen.

**Object Mag Draw [object],[element]**

	Draw the object on the screen.

	if [mul]>0 then object coordinates is multiplied by [mul]
	if [mul]<0 then object coordinates is divided by [mul]

	Amos Kittens:
	
		For Amos kittens this command is able to take double as [mul],
		this gives it better scaling, everything else is the same.

**R Object Mag Draw [object],[x],[y],[mul]**

	Position the object relative on the screen.

	if [mul]>0 then object coordinates is multiplied by [mul]
	if [mul]<0 then object coordinates is divided by [mul]

	Amos Kittens:
	
		For Amos kittens this command is able to take double as [mul],
		this gives it better scaling, everything else is the same.


**Object Erase [object]**

	Free the memoey of a object.

**Object Save s$,[n] To [n]**

	Object Load s$,[n]


**Line 3d [x1],[y1],[z1] To [x2],[y2],[z2]**

	Draws a line between x1,x1,y1 to x2,y2,z3

**Eye 3d [x],[y]**

	Set the center of the screen

**Multi Blit [start] To [end]**

	Scroll graphics, execute stored blit up/left.
	
**Blit Erase [n]**

	Erase blit [n] from memory.

**Blit Speed [n],[shift]**

	Sets the speed of blit
	[shift] value from -15 to 15

**Blit Int On [start] To [end]**

	Enable blit interrupts from [start] to [end].

**Blit Int Off**

	Disable blit interrupts.

**Blit Int Change [start] To [end]**

	Change the blits that are executed in the interrupt scrolling system.
	Using this you can change the parameters of the scroll without turning the blitter interrupt off.
	The same as Blit Int On (start to end) but while the interrupt is being executed.

**Blit Int Wait [on/off]**

	Default for all blit’s are in wait state, noting is drawn/done.
	To enable blits, set Blit Int Wait to False.

**Blit Left [screen],[x],[y] To [x1],[y1],[shift]**

	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

	Amos Kittens:

		There is no shift limit.

	Amos Pro:
	
		[shift] has to be value between -15 and 15.

**Blit Up [screen],[x],[y] To [x1],[y1],[shift]**

	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] if shift negative negative move up, if posetive move down.

	Amos Kittens:

		There is no shift limit.

	Amos Pro:
	
		[shift] has to be value between -15 and 15.
	
		This command is buggy It looks like bytes per row issue,
		I suggest using Blit Store Up instead, if your writing for Amos Pro.

**Blit Store Left [screen],[n],[x],[y] To [x1],[y1],[shift]**

	Store zone [n]
	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

**Blit Store Up [screen],[n],[x],[y] To [x1],[y1],[shift]**

	Store zone [n]
	[x],[y] top left corner.
	[x1],[y] right, bottom corner.
	[shift] value from -15 to 15

*Blit Clear [bit]*

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

**F Plot [x],[y],[color]**

	If your changing colors often then this command can be faster then normal Plot command.
	if your not changing color often, it should be faster to preset color with ink command.

	This command does not change graphic cursor.

**n=F Point(x,y)**

	Same as normal point command, no difference in speed.

	This command does not change graphic cursor.

**F Circle [x],[y],[r],[color]**

	Same as normal circle command, no difference in speed.

	This command does not change graphic cursor.

**F Draw [x],[y]**

	Same as normal draw command, no difference in speed.

	This command does change graphic cursor.

**F Draw [x0],[y0] To [x1],[y1]**

	Same as normal draw command, no difference in speed.

	This command does change graphic cursor.

**n=F Sqr(n)**

	Same as normal sqr command, no difference in speed.

**n=Left Click**

	This command should work while in exec/forbid(). 
	
	Amos Kittens:

		This command will enable multitasking for a short period.
		but only works if "Multi No" command was used to do it.

**Reserve Stars [n]**

	Reserve stars, or random dots in x,y plain

**Define Star [n],[x],[y],[x speed],[y speed]**

	Set star [n] coordinate [x],[y] and speed

**Display Stars**
	
	draws stars and computes the next position of the stars.

**Stars Erase**

	Erase stars / dots

**Stars Compute [n start] To [n end]**

	Calculate the new position of the stars.
	from [n start] to [n end]

**Stars Draw**

	Draw stars/dots

**Stars Speed [start] To [end],[speed x],[speed y]**

	Change the speed of of a range of star from start to end.-	
	First star is at 1, if start is 0, you will get illegal function call.	  

Stars Clip [x0],[y0],[x1],[y1] 

	Limit where stars are drawn

**Stars Int On [clear]**

	if [clear] is true, it screen will be automaticly cleared
	This command enabled stars to be drawn automatically, at vertical blanking.

	Amos Pro:
	
		Can't be used with double buffer.

**Stars Int Off**

	Disable automatic update for stars.

Set Planes [mask]

	This command should defines what color index bit to changed.

Plane Offset [screen nr],[plain],[xoffset],[yoffset] 

	This command is not supported.

Plane Swap [screen nr],[plain1],[plain2] 

	Swaps bits in color value on the screen. 	
	plain1/2 is bit position to swap.
	
	Plain is old terminology used for planar graphic format, describing how the colors are stored.
	on Amiga computer, how the colors are stores is how ever irrelevant.

	The key thing here is that the color index value will changes on all pixels on the screen.

Plane Shift Up [screen nr],[start] To [end]

	plains change order, planes are shifted in circle way, what is on the [end] become the [start].
	
	[tmp]=[end]
	[end]=[start+2]
	[start+1]=[start]
	[start]=[tmp]

Plane Shift Down [screen nr],[start] To [end]

	Planes are shifted in circle way, what is on the [start] become the [end].

Plane Update [screen] 

**F Paste Icon [x],[y],[n]**

	On Amos Kittens:

		Same as normal paste icon (uses retroMode.library).
	
	On Amos Pro:
	
		* This command uses blitter.
	
		* This command is made for speed, does not do testing.

		* This command can crash your computer.

**F 32 Icon [x],[y],[n]**

	On Amos Kittens:

		Same as normal paste icon (uses retroMode.library).
	
	On Amos Pro:

		* This command should only work with 32-pixel width icons.

		* This command uses blitter.
	
		* This command is made for speed, does not do testing.

		* This command can crash your computer.

**F 16 Icon [x],[y],[n]**

	On Amos Kittens:

			Same as normal paste icon (uses retroMode.library).
	
	On Amos Pro:

			* This command should only work with 16-pixel width icons.

			* This command uses blitter.

		* This command is made for speed, does not do testing.

		* This command can crash your computer.

**F 16proc Icon [x],[y],[n]**

	Amos Kittens:

		Same as normal paste icon (uses retroMode.library).

	Amos Pro:
	
			* This command should only work with 16-pixel width icons.
	
			* This command uses CPU
		
			* This command is made for speed, does not do testing.

			* This command can crash your computer.

**F 32proc Icon [x],[y],[n]**

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

**n=Cpu Info**

	This command returns CPU type..
	Because OS4.1 uses same ID numbers for PowerPC as 680x0, to avoid mistakes $1000 is added for PPC.

	= CPUTYPE_68X00
	or 
	= $1000 | CPUTYPE_PPC

	Id numbers can be found in file "exectags.h" in the AmigaOS4.1 SDK.

**n=Math Info**

	Amos Kittens will just return 882, it does not check for coprocessor

	000 - no coprocessor installed
	881 - MC68881 coprocessor installed
	882 - MC68882 coprocessor installed
		
**F Put Block [n],[x],[y]**

	Amos Kittens:
	
		Same as Amos Pro "Put Block" command, no speed difference.

**Reserve Static Block [n]**

	Amos Pro: 
	
		Amos Pro uses a linked lists, this can be slow.

	Amos Kittens:
		
		Amos Kittens does not use linked list, but it has to
		search etch entry to find the correct block, when it does a lookup.
	
	This command allocates a array[0..n], 
	
	Insted of lookup the block in the list checking etch entry.
	The array[] buffer short cuts the list, because the index becomes the same as the ID.
	What this means is that static blocks does not need to search for the block, when used.

**Static Block Erase**

	Erases the fast lookup table from memory.

**Build Static Block**

	Fill in the static array.
	Etch entry in the array points directly to block with same id as index value.

	array[0...n]=blocks.find(0...n)

**F Put Static Block [n],[x],[y]**

	Draw a block from the static array.

Scene Load s$,[bank]

	load the scene map into Amos [bank]
	
	Scene can be created by this commands:
	
	Reserve As Work 8,4+(Scene X-1)*(Scene Y-1)
	Doke Start(8),Scene Y
	Doke Start(8)+2,Scene X
	
	Data is stored from start(8)+4 to 4+(Scene X-1)*(Scene Y-1)
	
Scene Icon Bank [bank] 

	Set the icon bank to use.

**Scene Bank [bank]**

	Set the current scene bank, 
	and Icon bank also has to exist in bank 2, if not then this command will return a error.

**n=Scene Check(x,y)**

	return the icon image number at x,y

n=Scene 16 Check(x,y)

	return the icon image number at x,y

	Don’t know this command works, sorry.

**Scene Change [x],[y],[value]**

	Change [value] in the scene at map position [x],[y]

Scene 16 Change [x],[y],[value]

	Change [value] in the scene at map position [x],[y]

	Don’t know this command works, sorry.

Scene 16 Draw [map x],[map y],[w],[h],[pixel x],[pixel y]

	Draw a map 

Scene 16 Def [n],[n],[n],[n],[n],[n],[n],[n] 

	A command for a tiles / map system

Scene 16 Restore [n]

	A command for a tiles / map system

Scene 16 Limit [n]

	A command for a tiles / map system

n=Scene 32 Check(n,n)

	A command for a tiles / map system

Scene 32 Change [x],[y],[value] 

	Change [value] in the scene at map position [x],[y]

Scene 32 Draw [map x],[map y],[w],[h],[pixel x],[pixel y]

	A command for a tiles / map system

Scene 16 View [n],[x1],[y1] To [x2],[y2] 

	Define the draw area for the map

	[n] is unkown for now.
	[x1],[y1] upper left corner
	[x2],[y2] lower right corner

Scene 32 View [n],[x1],[y1] To [x2],[y2]

	Define the draw area for the map
	
	[n] is unkown for now.
	[x1],[y1] upper left corner
	[x2],[y2] lower right corner

Scene 16 Do [map x],[map y]

	Draw the map from icon x,y in the map to the view defined.

Scene 32 Do [map x],[map y] 

	Draw the map from icon x,y in the map to the view defined.

Scene 16 Top [n],[n]

	A command for a tiles / map system

Scene 32 Top [n],[n] 

	A command for a tiles / map system

Scene 16 Bottom [n],[n] 

	A command for a tiles / map system

Scene 32 Bottom [n],[n]

	A command for a tiles / map system

Scene 16 Left [n],[n]

	A command for a tiles / map system

Scene 32 Left [n],[n]

	A command for a tiles / map system

Scene 16 Right [n],[n]

	A command for a tiles / map system

Scene 32 Right [n],[n]

	A command for a tiles / map system

**n=Scene X**

	Returns the width of the scene map

**n=Scene Y**

	Returns the height of the scene map

Scene Palette [n]

	A command for a tiles / map system

Scene Mask Palette [n]

	A command for a tiles / map system

Amos Pri [value]

	Set Amos priority

n=Bit Field Ins([var],[star bit],[width],[value])

n=Bit Field Ext([var],[start bit],[width])

n=Byte Hunt([start] To [end],[action],[val1] To [val2])

Workbench Open  

**Memory Fill [start] To [end],text$**

	Fill memory with text

**n=Range([value],[start] To [end])**

	if value is less then [start] then [value] is [start]
	if value is more then [end] then [value] is [end].

**n=Texp([bool],[true val],[false val])**

	This is similar example in the C language.
	
	ret = [bool] ? [true val] : [false val]
	
	Returns a value depending on true or false input, 
	so instead of “IF … THEN … ELSE … END IF“
	you make code cleaner and there is no branching.
	So should be faster.

**n=T Clip([value],[div])**

	Round down, returns a value that can be dividable by [div].
	
	This command does the same as:
	n = [value] - ( [value] mod [div] )

**n=Between([min],[value],[max])**

	This command returns true if value is more then min, 
	and values is less then max, if this not the case then false is returned.

	Same as "([min] < [value] < [max])"

n=Bank End(n)

Debug  
