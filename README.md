# setpa5s
Application to set atten value on TDT System 3 PA5 devices. Uses TDT activeX control for the PA5.

The solution here ran on MSVC 2017 community. 

Installed 
- TDT Drivers (v92) (64 bit, legacy USB)
- TDT ActiveX for PA5 (v92)

The "setpa5s" project does not work. It compiles, but exe does not work as expected. 
I don't know activex well at all, and don't want or need to spend time to figure this out. 


Instead, compile "SetPA5" project (Release, x64). 

Invoke like this:

 SetPA5.exe a1 a2  
 SetPA5.exe a1  
 SetPA5.exe NONE a2  
 SetPA5.exe a1 NONE  
 
 
