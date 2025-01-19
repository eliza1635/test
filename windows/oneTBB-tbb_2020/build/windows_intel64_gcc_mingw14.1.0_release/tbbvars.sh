#!/bin/sh
export TBBROOT="C:/oneTBB/oneTBB-tbb_2020"
export TBB_ARCH_PLATFORM="intel64\mingw14.1.0"
export TBB_TARGET_ARCH="intel64"
export CPATH="${TBBROOT}/include;$CPATH"
export LIBRARY_PATH="C:/oneTBB/oneTBB-tbb_2020/build/windows_intel64_gcc_mingw14.1.0_release;$LIBRARY_PATH"
export PATH="C:/oneTBB/oneTBB-tbb_2020/build/windows_intel64_gcc_mingw14.1.0_release;$PATH"
export LD_LIBRARY_PATH="C:/oneTBB/oneTBB-tbb_2020/build/windows_intel64_gcc_mingw14.1.0_release;$LD_LIBRARY_PATH"
