# Setup 

>sh setup.sh

# Note 
To compile programs with Keyboard, you need to add:

>    -lkeyboard

# Test

>cd examples/

>g++ -o Test keyboard_test.cpp -lpcd8544 -lwiringPi -lkeyboard

>./Test