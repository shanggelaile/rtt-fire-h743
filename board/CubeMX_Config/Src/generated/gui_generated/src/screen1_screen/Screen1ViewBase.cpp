/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    buttonCallback(this, &Screen1ViewBase::buttonCallbackHandler)
{

    box1.setPosition(0, 0, 800, 480);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(53, 41, 230));

    buttonWithLabel1.setXY(602, 210);
    buttonWithLabel1.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_ID), touchgfx::Bitmap(BITMAP_BLUE_BUTTONS_ROUND_EDGE_SMALL_PRESSED_ID));
    buttonWithLabel1.setLabelText(touchgfx::TypedText(T_SINGLEUSEID2));
    buttonWithLabel1.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    buttonWithLabel1.setAction(buttonCallback);

    image1.setXY(102, 159);
    image1.setBitmap(touchgfx::Bitmap(BITMAP_RTTPICTURE_ID));

    add(box1);
    add(buttonWithLabel1);
    add(image1);
}

void Screen1ViewBase::setupScreen()
{

}

void Screen1ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        //Interaction1
        //When buttonWithLabel1 clicked change screen to Screen2
        //Go to Screen2 with screen transition towards East
        application().gotoScreen2ScreenSlideTransitionEast();
    }
}