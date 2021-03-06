#pragma once

// STL includes
#include <string>

// hyperion incluse
#include "LedSpiDevice.h"

///
/// Implementation of the LedDevice interface for writing to Sk6801 led device.
///
class LedDeviceSk6812SPI : public LedSpiDevice
{
public:
	///
	/// Constructs the LedDevice for a string containing leds of the type Sk6812SPI
	///
	/// @param outputDevice The name of the output device (eg '/etc/SpiDev.0.0')
	/// @param baudrate The used baudrate for writing to the output device
	///

	LedDeviceSk6812SPI(const std::string& outputDevice,
					const unsigned baudrate);

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
	std::vector<uint8_t> _spiBuffer;

        uint8_t bitpair_to_byte[4];
};
