# siteUpdater

siteUpdater is a C++ based post editor for my personal website, stevenan.com

  - Implemented from the ground up text editor using Linked Lists
  - Each node holds a line of code of HTML
  - Adds posts automatically and shifts lines down whenever necessary

>>Hoping to add FTP upload/download to save even more trouble in the future

## Changelog

8/14/2015 01:25:11 VERSION 1.1

	-Changed template format from testing (int) to string
	-Added file reading
	-Added regular text file for testing
	-Upon success of regular test file, added test HTML file (works great :))
	-Fixed bug with numItems assigned as a template value 
	-Made display function to print out contents of list line by line
	-main.exe added for Windows systems/compilation
	
8/14/2015 04:19:23 VERSION 1.2

	-Display function now has another argument, lines
	-Lines allows the client to print out line numbers, similar to :set nu in Vim
	-Made filename a global variable
	-Display prints out seperator lines as well as the number of lines in a file
	-Added a destructor

8/14/2015 17:18:08 VERSION 1.3
	
	-Added getHead function in linkedList.h
	-Added removeFunction to delete single lines
	-Overloaded removeFunction for multiple deletion (ranged)

8/15/2015 01:48:24 VERSION 1.3b [INCOMPLETE PUSH]

	-TODO: erase functions in main
	-TODO: test range function
	-TODO: test removeFromList function

8/16/2015 02:48:24 VERSION 1.4 [FIXED ISSUES]

	-erase function in main
	-range function works fine (might remove this later)
	-Added insertAtIndex function
	-Both instances of removeFromList functions tested and working properly

8/16/2015 17:30:37 VERSION 1.5

	-Added menu
	-erase function now works with single line deletion (same end/begin parameter)
	-moved file operations into function called loadIntoFile
	-Added and implemented a couple of menu commands
	-displayCommands function added
	-everything works so far :) 

8/17/2015 01:38:53 VERSION 1.6

	-Added replace command
	-Added overwrite class method to linkedList
	-Added findNode, since I'm doing it in nearly every single class method, basically returns a pointer to a node at a given 
	integer position. (1 is the identifier of the first item, since it correlates with line numbers)
	-Added setter to node.h for item

8/18/2015 00:12:23 VERSION 1.7

	-Added backup function to backup files
	-Added output function to write to files
	-Tested with music.html, added music.html
	-Successfully edited a working HTML file and outputted a working HTML file. 

8/18/2015 16:42:11 VERSION 1.8

	-removed subLine function
	-added output with custom file name option
	-added addsong function for music.html

8/18/2015 15:43:33 VERSION 1.9

	-modified menu to display site music page
	-removed replace line function, not needed by user
	-created video object to encapsulate url, caption, title of youtube video
	-added output function in menu
	-song function fixed
	-added remove sections of html code
	-removed some redundant files
