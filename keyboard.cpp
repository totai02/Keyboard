#include "keyboard.h"

static const unsigned char enter_img[] = {0xE0, 0x10, 0x10, 0x10, 0x10, 0x90, 0xCE, 0x81,
                                          0x81, 0x81, 0xE1, 0x01, 0x01, 0x01, 0xFE, 0x03,
                                          0x04, 0x04, 0x04, 0x04, 0x04, 0x05, 0x04, 0x04,
                                          0x04, 0x04, 0x04, 0x04, 0x04, 0x03};
static const unsigned char backspace_img[] = {0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
                                              0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
                                              0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
                                              0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
                                              0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
                                              0x11, 0x11, 0x11, 0x11, 0x11, 0x0E};
static const unsigned char del_img[] = {0x3E, 0x41, 0x49, 0x5D, 0x49, 0x49, 0x49, 0x41, 0x3E};
static const unsigned char upper_img[] = {0xFE, 0x01, 0x09, 0x7D, 0x09, 0x01, 0xFE, 0x00,
                                          0x01, 0x01, 0x01, 0x01, 0x01, 0x00};
static const unsigned char symbol_img[] = {0xFE, 0x01, 0x01, 0x7D, 0x01, 0x75, 0x5D, 0x01,
                                           0x55, 0x7D, 0x01, 0x01, 0xFE, 0x00, 0x01, 0x01,
                                           0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                                           0x01, 0x00};
static const unsigned char exit_img[] = {0x3E, 0x41, 0x55, 0x49, 0x55, 0x41, 0x3E};

static const unsigned char enter_hover_img[] = {0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0x70, 0x3E, 0x7F,
                                                0x7F, 0x7F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFE, 0x03,
                                                0x07, 0x07, 0x07, 0x07, 0x07, 0x06, 0x07, 0x07,
                                                0x07, 0x07, 0x07, 0x07, 0x07, 0x03};
static const unsigned char backspace_hover_img[] = {0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
                                                    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
                                                    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
                                                    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
                                                    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F,
                                                    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0E};
static const unsigned char del_hover_img[] = {0x3E, 0x7F, 0x77, 0x63, 0x77, 0x77, 0x77, 0x77, 0x3E};
static const unsigned char upper_hover_img[] = {0xFE, 0xFF, 0xF7, 0x83, 0xF7, 0xFF, 0xFE, 0x00,
                                                0x01, 0x01, 0x01, 0x01, 0x01, 0x00};
static const unsigned char symbol_hover_img[] = {0xFE, 0xFF, 0xFF, 0x83, 0xFF, 0x8B, 0xA3, 0xFF,
                                                 0xAB, 0x83, 0xFF, 0xFF, 0xFE, 0x00, 0x01, 0x01,
                                                 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
                                                 0x01, 0x00};
static const unsigned char exit_hover_img[] = {0x3E, 0x7F, 0x6B, 0x77, 0x6B, 0x7F, 0x3E};

Button::Button(string text, int x, int y, int image)
{
    this->text = text;
    this->image = image;
    this->x = x;
    this->y = y;
}

void Button::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Button::draw(bool hover)
{
    LCDsetTinyFont(true);

    if (image == NO_IMAGE)
    {
        if (hover)
        {
            LCDfillrect(x, y - 1, 5 * text.size()+ 1, 7, BLACK);
            LCDsetTextColor(WHITE);
            LCDdrawstring_P(x, y, text.c_str());
        }
        else
        {
            LCDsetTextColor(BLACK);
            LCDdrawstring_P(x, y, text.c_str());
        }
    }
    else
    {
        if (hover)
        {
            if (image == ENTER) LCDdrawbitmap(x, y, enter_hover_img, 15, 11, BLACK);
            else if (image == BACKSPACE) LCDdrawbitmap(x, y, backspace_hover_img, 46, 5, BLACK);
            else if (image == DEL) LCDdrawbitmap(x, y, del_hover_img, 9, 7, BLACK);
            else if (image == SYMBOL) LCDdrawbitmap(x, y, symbol_hover_img, 13, 9, BLACK);
            else if (image == UPPER) LCDdrawbitmap(x, y, upper_hover_img, 7, 9, BLACK);
            else if (image == EXIT) LCDdrawbitmap(x, y, exit_hover_img, 7, 7, BLACK);
        }
        else
        {
            if (image == ENTER) LCDdrawbitmap(x, y, enter_img, 15, 11, BLACK);
            else if (image == BACKSPACE) LCDdrawbitmap(x, y,backspace_img, 46, 5, BLACK);
            else if (image == DEL) LCDdrawbitmap(x, y, del_img, 9, 7, BLACK);
            else if (image == SYMBOL) LCDdrawbitmap(x, y, symbol_img, 13, 9, BLACK);
            else if (image == UPPER) LCDdrawbitmap(x, y, upper_img, 7, 9, BLACK);
            else if (image == EXIT) LCDdrawbitmap(x, y, exit_img, 7, 7, BLACK);
        }
    }
}

void Button::setAction(function<void ()> cb)
{
    callback = cb;
}

void Button::click()
{
    callback();
}

Keyboard::Keyboard()
{
    visible = false;
    currentKeySet = 0;
    hoverItem.x = 0;
    hoverItem.y = 0;
    genKeySet(0);
    genKeySet(1);
    genKeySet(2);
}

void Keyboard::setTitle(string title)
{
    this->title = title;
}

void Keyboard::draw()
{
    LCDclear();
    LCDdrawrect(1, 9, 82, 9, BLACK);

    LCDsetTinyFont(false);
    LCDdrawstring_P((84 - title.size() * 6) / 2, 1, title.substr(0, 14).c_str());

    string displayText = text + "_";
    if (displayText.size() > 16)
    {
        displayText = displayText.substr(displayText.size() - 16, 17);
    }
    LCDsetTinyFont(true);
    LCDdrawstring_P(3, 11, displayText.c_str());
    for (int i = 0; i < buttons[currentKeySet].size(); i++)
    {
        if (buttons[currentKeySet][i] == keyMap[currentKeySet][hoverItem.x][hoverItem.y]) buttons[currentKeySet][i]->draw(true);
        else buttons[currentKeySet][i]->draw(false);
    }
    LCDdisplay();
}

void Keyboard::up()
{
    int x = hoverItem.x;
    int y = hoverItem.y;
    do
    {
        hoverItem.y--;
        if (hoverItem.y < 0) hoverItem.y = 10;
    } while (keyMap[currentKeySet][hoverItem.x][hoverItem.y] == keyMap[currentKeySet][x][y]);
    draw();
}

void Keyboard::down()
{
    int x = hoverItem.x;
    int y = hoverItem.y;
    do
    {
        hoverItem.y++;
        if (hoverItem.y > 10) hoverItem.y = 0;
    } while (keyMap[currentKeySet][hoverItem.x][hoverItem.y] == keyMap[currentKeySet][x][y]);
    draw();
}

void Keyboard::back()
{
    int x = hoverItem.x;
    int y = hoverItem.y;
    do
    {
        hoverItem.x++;
        if (hoverItem.x > 3) hoverItem.x = 0;
    } while (keyMap[currentKeySet][hoverItem.x][hoverItem.y] == keyMap[currentKeySet][x][y]);
    draw();
}

void Keyboard::press()
{
    keyMap[currentKeySet][hoverItem.x][hoverItem.y]->click();
    draw();
}

string Keyboard::popup(string title)
{
    if (title.compare("")) this->title = title;
    text = "";
    draw();
    visible = true;
    while (digitalRead (BTN4) == LOW);
    delay(250);
    while (visible)
    {
        if(digitalRead (BTN1) == LOW)
        {
            back();
            delay(250);
        }
        if(digitalRead (BTN2) == LOW)
        {
            up();
            delay(250);
        }
        if(digitalRead (BTN3) == LOW)
        {
            down();
            delay(250);
        }
        if(digitalRead (BTN4) == LOW)
        {
            press();
            delay(250);
        }
      delay(100);
    }

    LCDclear();
    LCDdisplay();

    return text;
}

void Keyboard::initPin()
{
    pinMode (BL, OUTPUT);
    digitalWrite(BL, HIGH);

    pinMode (BTN1, INPUT);
    pullUpDnControl (BTN1, PUD_UP) ;

    pinMode (BTN2, INPUT);
    pullUpDnControl (BTN2, PUD_UP) ;

    pinMode (BTN3, INPUT);
    pullUpDnControl (BTN3, PUD_UP) ;

    pinMode (BTN4, INPUT);
    pullUpDnControl (BTN4, PUD_UP) ;
}

void Keyboard::del()
{
    if (text.size() > 0) text = text.substr(0, text.size() - 1);
}

void Keyboard::upper()
{
    if (currentKeySet != 2)
    {
        if (currentKeySet == 0) currentKeySet = 1;
        else currentKeySet = 0;
    }
    draw();
}

void Keyboard::symbol()
{
    if (currentKeySet != 2) currentKeySet = 2;
    else currentKeySet = 0;
    draw();
}

void Keyboard::cancel()
{
    text = "";
    visible = false;
}

void Keyboard::enter()
{
    visible = false;
}

void Keyboard::genKeySet(int idx)
{
    string classKey1, classKey2, classKey3;

    if (idx == 0)
    {
        classKey1 = "QWERTYUIOP";
        classKey2 = "ASDFGHJKL";
        classKey3 = "ZXCVBNM";
    }
    else if (idx == 1)
    {
        classKey1 = "qwertyuiop";
        classKey2 = "asdfghjkl";
        classKey3 = "zxcvbnm";
    }
    else if (idx == 2)
    {
        classKey1 = "1234567890";
        classKey2 = "+-=<>/\\*:";
        classKey3 = "()_.@!?";
    }

    for (int i = 0; i < 10; i++)
    {
        Button *btn = new Button(classKey1.substr(i, 1), 10 + i * 7, 20);
        buttons[idx].push_back(btn);
        keyMap[idx][0][i + 1] = btn;
        btn->setAction([this, classKey1, i](){
            text += classKey1.substr(i, 1);
        });
    }

    for (int i = 0; i < 9; i++)
    {
        Button *btn = new Button(classKey2.substr(i, 1), 10 + i * 7, 27);
        buttons[idx].push_back(btn);
        keyMap[idx][1][i + 1] = btn;
        btn->setAction([this, classKey2, i](){
            text += classKey2.substr(i, 1);
        });
    }

    for (int i = 0; i < 8; i++)
    {
        Button *btn = new Button(classKey3.substr(i, 1), 17 + i * 7, 35);
        buttons[idx].push_back(btn);
        keyMap[idx][2][i + 2] = btn;
        btn->setAction([this, classKey3, i](){
            text += classKey3.substr(i, 1);
        });
    }

    Button *keyENTER = new Button("", 67, 36, ENTER);
    Button *keySPACE = new Button("", 18, 41, BACKSPACE);
    Button *keyDEL = new Button("", 73, 28, DEL);
    Button *keySYMBOL = new Button("", 2, 38, SYMBOL);
    Button *keyUPPER = new Button("", 2, 28, UPPER);
    Button *keyEXIT = new Button("", 2, 20, EXIT);

    keyENTER->setAction([this](){
        enter();
    });
    keySPACE->setAction([this](){
        text += " ";
    });
    keyDEL->setAction([this](){
        del();
    });
    keySYMBOL->setAction([this](){
        symbol();
    });
    keyUPPER->setAction([this](){
        upper();
    });
    keyEXIT->setAction([this](){
        cancel();
    });

    buttons[idx].push_back(keyENTER);
    buttons[idx].push_back(keySPACE);
    buttons[idx].push_back(keyDEL);
    buttons[idx].push_back(keySYMBOL);
    buttons[idx].push_back(keyUPPER);
    buttons[idx].push_back(keyEXIT);

    keyMap[idx][0][0] = keyEXIT;
    keyMap[idx][1][0] = keyUPPER;
    keyMap[idx][2][0] = keySYMBOL;
    keyMap[idx][2][1] = keySYMBOL;
    keyMap[idx][3][0] = keySYMBOL;
    keyMap[idx][3][1] = keySYMBOL;
    keyMap[idx][3][2] = keySPACE;
    keyMap[idx][3][3] = keySPACE;
    keyMap[idx][3][4] = keySPACE;
    keyMap[idx][3][5] = keySPACE;
    keyMap[idx][3][6] = keySPACE;
    keyMap[idx][3][7] = keySPACE;
    keyMap[idx][3][8] = keySPACE;
    keyMap[idx][1][10] = keyDEL;
    keyMap[idx][2][9] = keyENTER;
    keyMap[idx][2][10] = keyENTER;
    keyMap[idx][3][9] = keyENTER;
    keyMap[idx][3][10] = keyENTER;
}
