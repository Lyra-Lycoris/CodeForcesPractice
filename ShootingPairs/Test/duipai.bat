@echo off

for /l %%i in (1,1,1000) do (
  gen.exe %%i > in.txt
  sol.exe < in.txt > out1.txt
  brute.exe < in.txt > out2.txt
  fc out1.txt out2.txt > nul
  if errorlevel 1 (
    echo WA on test %%i
    pause
    exit
  )
)