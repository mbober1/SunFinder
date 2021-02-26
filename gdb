sudo openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -s tcl


####################################

export PICO_SDK_PATH=../../pico-sdk
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j4

####################################


sudo minicom -D /dev/ttyACM0 -b 115200