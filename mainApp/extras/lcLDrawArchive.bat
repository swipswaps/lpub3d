@echo off
Title Create LeoCAD unofficial library archive
rem --
rem  README
rem  How to setup LeoCad libraries for LPub 3D Viewer
rem	 1. create a sub-directory in your LDRAW directory and name it LeoCAD-Libraries.
rem  2. place this file in your LDRAW directory and run it (double-click).
rem  3. review command window and "LDRAW directory"\LeoCadLibrary-archive-log.txt details
rem  4. copy and paste (or download from LDraw.org) complete.zip to LeoCAD-Libraries
rem --
SETLOCAL
@break off
@color 0a
@cls
ECHO -Start
ECHO.
set zipExe="C:\program files\7-zip\7z.exe"
set ldrawPath="C:\Users\Trevor\LDraw"
set outputPath="C:\Users\Trevor\LDraw"

ECHO -Archive custom content
ECHO.
cd /D %outputPath%\
ECHO -Create 'LeoCAD-Libraries' folder
ECHO.
if not exist ".\LeoCAD-Libraries\" (
  mkdir ".\LeoCAD-Libraries\"
)
ECHO -Download unofficial content from LDraw.org
ECHO.
rem -------------------------------------------------------------------------
if not exist "%TEMP%\$" (
  md "%TEMP%\$"
)
set n=WebContentDownload.vbs
set t=%TEMP%\$\%n% ECHO
set WebCONTENT="%~dp0LeoCAD-Libraries\ldrawunf.zip"
set WebNAME=http://www.ldraw.org/library/unofficial/ldrawunf.zip
del %TEMP%\$\%n%
if exist %WebCONTENT% (
 del %WebCONTENT%
)
:WEB CONTENT SAVE-AS Download-- VBS
>%t% Option Explicit
>>%t% On Error Resume Next
>>%t%.
>>%t% Dim args, http, fileSystem, adoStream, url, target, status
>>%t%.
>>%t% Set args = Wscript.Arguments
>>%t% Set http = CreateObject("WinHttp.WinHttpRequest.5.1")
>>%t% url = args(0)
>>%t% target = args(1)
>>%t% WScript.Echo "Getting '" ^& target ^& "' from '" ^& url ^& "'..."
>>%t%.
>>%t% http.Open "GET", url, False
>>%t% http.Send
>>%t% status = http.Status
>>%t%.
>>%t% If status ^<^> 200 Then
>>%t% WScript.Echo "FAILED to download: HTTP Status " ^& status
>>%t% WScript.Quit 1
>>%t% End If
>>%t%.
>>%t% Set adoStream = CreateObject("ADODB.Stream")
>>%t% adoStream.Open
>>%t% adoStream.Type = 1
>>%t% adoStream.Write http.ResponseBody
>>%t% adoStream.Position = 0
>>%t%.
>>%t% Set fileSystem = CreateObject("Scripting.FileSystemObject")
>>%t% If fileSystem.FileExists(target) Then fileSystem.DeleteFile target
>>%t% If Err.Number ^<^> 0 Then
>>%t%   WScript.Echo "Error - CANNOT DELETE: '" ^& target ^& "', " ^& Err.Description
>>%t%   WScript.Echo "The file may be in use by another process."
>>%t%   adoStream.Close
>>%t%   Err.Clear
>>%t% Else
>>%t%  adoStream.SaveToFile target
>>%t%  adoStream.Close
>>%t%  WScript.Echo "Download successful!"
>>%t% End If
>>%t%.
>>%t% 'WebContentDownload.vbs
>>%t% 'Title: BATCH to VBS to Web Content Downloader
>>%t% 'CMD ^> cscript //Nologo %TEMP%\$\%n% %WebNAME% %WebCONTENT%
>>%t% 'VBS Created on %date% at %time%
>>%t%.
rem -------------------------------------------------------------------------
ECHO. 
ECHO BATCH to VBS to Web Content Downloader
ECHO.
ECHO File "%n%" is done compiling.
ECHO.
ECHO WEB URL: "%WebNAME%" 
ECHO is ready to be downloaded to...
ECHO FOLDER: %WebCONTENT%
ECHO.
ECHO.
ECHO If you are ready to continue and download the content, Press any key!
PAUSE >NUL
@echo on
cscript //Nologo %TEMP%\$\%n% %WebNAME% %WebCONTENT% && @echo off
ECHO.
ECHO.
ECHO -Merge custom and unofficial content 
ECHO.
cd /D %ldrawPath%\Unofficial\
%zipExe% a -tzip %outputPath%\LeoCAD-Libraries\ldrawunf.zip p\ > %outputPath%\LeoCadLibrary-archive-log.txt
%zipExe% a -tzip %outputPath%\LeoCAD-Libraries\ldrawunf.zip parts\ >> %outputPath%\LeoCadLibrary-archive-log.txt
ECHO -Finshed
ECHO.
ECHO If everything went well then, Press any key to EXIT!
PAUSE >NUL
ENDLOCAL
EXIT
