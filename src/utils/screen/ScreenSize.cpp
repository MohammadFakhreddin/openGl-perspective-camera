#include "ScreenSize.h"

#if WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#endif

//...

void ScreenSize::getScreenResolution(unsigned int& width, unsigned int& height) {
#if WIN32
	width = (int)GetSystemMetrics(SM_CXSCREEN);
	height = (int)GetSystemMetrics(SM_CYSCREEN);
#else
	Display* disp = XOpenDisplay(NULL);
	Screen* scrn = DefaultScreenOfDisplay(disp);
	width = scrn->width;
	height = scrn->height;
#endif
}