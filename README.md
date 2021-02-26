# SunFinder
![IMG_20210210_142918](https://user-images.githubusercontent.com/44072895/109316033-78d46d80-784b-11eb-86a2-9024d794835f.jpg)

# Requirements

## Hardware
### 2x Tower Pro Micro Servo 9g
### Mini Pan Tilt (https://www.thingiverse.com/thing:708819)
### 4x Photoresistors (one is unused due to the lack of a free analog port on RPi Pico)

## Software

```
git clone https://github.com/mbober1/SunFinder
cd SunFinder
mkdir build
cd build
```
Change path to pico-sdk in CMakeLists.txt (line 3)
```
export PICO_SDK_PATH=../../pico-sdk
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4
```
