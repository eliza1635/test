@echo off
SET TBBROOT=C:\oneTBB\oneTBB-tbb_2020
SET TBB_ARCH_PLATFORM=intel64\mingw14.1.0
SET TBB_TARGET_ARCH=intel64
SET CPATH=%TBBROOT%\include;%CPATH%
SET LIBRARY_PATH=C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;%LIBRARY_PATH%
SET PATH=C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;%PATH%
SET LD_LIBRARY_PATH=C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;%LD_LIBRARY_PATH%
