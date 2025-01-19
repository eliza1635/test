#!/bin/csh
setenv TBBROOT "C:\oneTBB\oneTBB-tbb_2020"
setenv TBB_ARCH_PLATFORM "intel64\mingw14.1.0"
setenv TBB_TARGET_ARCH "intel64"
setenv CPATH "${TBBROOT}\include;$CPATH"
setenv LIBRARY_PATH "C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;$LIBRARY_PATH"
setenv PATH "C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;$PATH"
setenv LD_LIBRARY_PATH "C:\oneTBB\oneTBB-tbb_2020\build\windows_intel64_gcc_mingw14.1.0_release;$LD_LIBRARY_PATH"
