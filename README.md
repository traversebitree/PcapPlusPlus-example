<!--
 Copyright (c) 2023 xykong
 
 This software is released under the MIT License.
 https://opensource.org/licenses/MIT
-->

## Usage
clone, generate, build.
```shell
git clone https://github.com/traversebitree/PcapPlusPlus-example.git
cd PcapPlusPlus-example
mkdir build
cd build
cmake -S .. -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Debug
cmake --build .
```
Go to the .exe directory and excute it.
```shell
cd .\src\app1\Debug\
.\app1.exe
```
