@echo off

REM alltest.cmd - execute all test cases
REM
REM (c) 1998-2003 (W3C) MIT, ERCIM, Keio University
REM See tidy.c for the copyright notice.
REM
REM <URL:http://tidy.sourceforge.net/>
REM
REM CVS Info:
REM
REM    $Author: creitzel $
REM    $Date: 2003/03/19 18:33:11 $
REM    $Revision: 1.1 $

for /F "tokens=1*" %%i in (testcases.txt) do call onetest.cmd %%i %%j
