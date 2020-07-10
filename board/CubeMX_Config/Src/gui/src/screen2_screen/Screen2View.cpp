#include <gui/screen2_screen/Screen2View.hpp>
#include <rtthread.h>
#include <rtdevice.h>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
		time_t now;
		struct tm *clock;
		now = time(RT_NULL);
		clock = gmtime(&now);
		
		analogHours = clock->tm_hour;
		analogMinutes = clock->tm_min;
		analogSeconds = clock->tm_sec;
	
 
  analogClock1.setTime24Hour(analogHours, analogMinutes, analogSeconds);

}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::handleTickEvent()
{
	tickCounter++;

	if (tickCounter % 60 == 0)
	{
		if (++analogSeconds >= 60)
		{
			analogSeconds = 0;
			if (++analogMinutes >= 60)
			{
				analogMinutes = 0;
				if (++analogHours >= 24)
				{
					analogHours = 0;
				}
			}
		}

		// Update the clocks
		analogClock1.setTime24Hour(analogHours, analogMinutes, analogSeconds);
	}


}
