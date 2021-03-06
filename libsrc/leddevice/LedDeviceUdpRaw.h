#pragma once

// STL includes
#include <string>

// hyperion incluse
#include "LedUdpDevice.h"

///
/// Implementation of the LedDevice interface for writing to Ws2801 led device.
///
class LedDeviceUdpRaw : public LedUdpDevice
{
public:
	///
	/// Constructs the LedDevice for a string containing leds of the type Ws2801
	///
	/// @param outputDevice The name of the output device (eg '/etc/SpiDev.0.0')
	/// @param baudrate The used baudrate for writing to the output device
	///

	LedDeviceUdpRaw(const std::string& outputDevice,
					const unsigned baudrate,
					const unsigned latchTime);

	///
	/// Writes the led color values to the led-device
	///
	/// @param ledValues The color-value per led
	/// @return Zero on succes else negative
	///
	virtual int write(const std::vector<ColorRgb> &ledValues);

	/// Switch the leds off
	virtual int switchOff();

private:

	/// the number of leds (needed when switching off)
	size_t mLedCount;
};
