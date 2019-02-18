#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>
#include <functional>
#include <wiringPi.h>
#include <vector>
#include <PCD8544.h>

#define NO_IMAGE 0
#define ENTER 1
#define BACKSPACE 2
#define DEL 3
#define UPPER 4
#define SYMBOL 5
#define EXIT 6
#define BTN1 7
#define BTN2 0
#define BTN3 21
#define BTN4 22
#define BL 30

using namespace std;

struct Point{
    int x;
    int y;
};

class Button
{
public:
    Button(string text = "", int x = 0, int y = 0, int image = NO_IMAGE);
    void setPosition(int x, int y);
    void draw(bool hover);
    void setAction(function<void()>);
    void click();
protected:
    int x, y;
    int image = NO_IMAGE;
    string text;
    function<void()> callback = [](){};
};

class Keyboard
{
public:
    Keyboard();
    void setTitle(string);
    void draw();
    void up();
    void down();
    void back();
    void press();
    string popup(string title = "Keyboard");

    void initPin();

private:
    void genKeySet(int idx);
    void del();
    void upper();
    void symbol();
    void cancel();
    void enter();

    bool visible;
    string title;
    string text;
    Point hoverItem;
    vector<Button*> buttons[3];
    int currentKeySet;
    Button *keyMap[3][4][11];
};

#endif // KEYBOARD_H
