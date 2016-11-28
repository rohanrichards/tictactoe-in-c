/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2015 Assignment #1 
* Full Name        : Rohan Moon Richards
* Student Number   : s3550153
* Start up code provided by Paul Miller
***********************************************************************/
N.B
I created new files, I could not see anywhere that indicated this was
not allowed. I use menu.c and menu.h to handle the main menu.
Obviously these must be included in the compile instructions for the
final file to work properly. They will be included in my submission through
blackboard.

My coordinate system allows for upper case, lower case and any order.
You can also change the set of delimeters if you need so you can accept
white-space etc.

I didn't find a need to use the FAILURE type from the input_result enum, I 
preferred to handle my incorrect input errors locally as that seemed a 
little cleaner, and so found no reason to return out of them with failures.

I realize my clear screen function is a little hacky and doesn't really 
account for many resolutions, but I felt in this instance it was more than
enough.

I am predominantly a game developer which is why I felt the need to clear the screen, and its because of this I used the sleep() function on computer 
turns and when important information is displayed. I think the effect is worth
it though.
