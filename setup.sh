#!/bin/bash

g++ -c -fPIC keyboard.cpp -o keyboard.o

g++ -shared -o libkeyboard.so keyboard.o

sudo mv libkeyboard.so /usr/lib/libkeyboard.so
sudo cp keyboard.h /usr/include/keyboard.h