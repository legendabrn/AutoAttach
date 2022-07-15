# Plugin AutoAttach for x64dbg
### How to use it?
To change the status of the plugin, you need to write the command `AutoAttachStatus (0/1)`\
To specify a process, you must write the `AutoAttachProcess` command and enter the process name
### Sleep
If suddenly you need a delay before the attached, then this can be done through AutoAttachSleep by specifying milliseconds in the arguments
### Example sleep
AutoAttachSleep 1000
### Example select process
AutoAttachProcess dota2.exe
### Example enable AutoAttach
AutoAttachStatus 1
### Example disable AutoAttach
AutoAttachStatus 0
### if anything, commands are entered here :)
![image](https://user-images.githubusercontent.com/84228488/179224847-49aef67d-b5da-436d-9554-8f9edcd223a7.png)
