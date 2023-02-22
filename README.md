## 学了忘，忘了学
----------------------------------
### choose the program want to test then modify CMakeLists in the source dir
### then launch the terminal
1. build the configure folder in the source dir
```
  mkdir build
```
2. go to the build folder which just touch
```
  cd build
```
3. configure the MinGW Makefiles
```
  cmake -G "MinGW Makefiles" ..
```
4. build the target
```
  cmake --build .
```
5. insatll
```
  cmake --install . --prefix "your file path"
```
