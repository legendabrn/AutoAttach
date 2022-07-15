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
