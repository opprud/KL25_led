# Build you first project in VS code
Adapted from : https://mcuoneclipse.com/2021/05/04/visual-studio-code-for-c-c-with-arm-cortex-m-part-1/

## Requirements
You need to install tools specified in the guide above
- Cmake
- ARM GCC
- Make or Ninja
- VS Code plugins

## Build targets
First we need to generate makefiles using `CMake`, cd into to the `build` dir

On OSX: `cmake -DCMAKE_MAKE_PROGRAM="ninja" -G "Ninja" ..`

On WIN: OSX: `cmake -DCMAKE_MAKE_PROGRAM="ninja.exe" -G "Ninja" ..`


The we can build directly in the `build` dir using `Make` or `Ninja`

`cmake --build .` builds execuables

`cmake --build . --target clean` cleans the build dir

``