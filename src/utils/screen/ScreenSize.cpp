#include "ScreenSize.h"

#if WIN32
#include <windows.h>
#else
#include <CoreGraphics/CGDisplayConfiguration.h>
#endif

void ScreenSize::getScreenResolution(unsigned int& width, unsigned int& height) {
#if WIN32
	width = (int)GetSystemMetrics(SM_CXSCREEN);
	height = (int)GetSystemMetrics(SM_CYSCREEN);
#else
	auto mainDisplayId = CGMainDisplayID();
	width = CGDisplayPixelsWide(mainDisplayId);
	height = CGDisplayPixelsHigh(mainDisplayId);
#endif
}