# setpa5s
Application to set atten value on TDT System 3 PA5 devices. Uses TDT activeX control for the PA5.

The solution here ran on MSVC 2017 community. 

Installed 
- TDT Drivers (v92) (64 bit, legacy USB)
- TDT ActiveX for PA5 (v92)

The "setpa5s" project does not work. It compiles, but exe does not work as expected. 
I don't know activex well at all, and don't want or need to spend time to figure this out. 

There are two key differences that I see:
1. SetPA5 uses a dummy dialog (which is never opened). The PA5 is opened, atten set, inside the OnInitDialog() method. setpa5s doesn't use a dialog and all, but doesn't work. 
2. SetPA5 uses the activeX control class created waaaay back when I originally created the program, probably 10 years ago. setpa5s uses one that was created recently (using the just-installed PA5 ocx). The old one works, the new one doesn't?

I do not know which of these two differences matters. 


Instead, compile "SetPA5" project (Release, x64). 

Invoke like this:

  SetPA5.exe a1 a2  
  SetPA5.exe a1  
  SetPA5.exe NONE a2  
  SetPA5.exe a1 NONE  
 
 
