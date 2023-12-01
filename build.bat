@echo off

set "directoryPath=bin"

if not exist "%directoryPath%" (
    mkdir "%directoryPath%"
)

clang++ .\src\symlink_mods.cpp -o bin\pz_symlink.exe -Iinclude -std=c++20 -lKernel32 -DUNICODE -D_UNICODE -mconsole -static