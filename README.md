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