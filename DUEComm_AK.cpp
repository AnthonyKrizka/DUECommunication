
#include <Wire.h>
#include <SPI.h>
#include "DUEComm_AK.h"

// Select I2C port, can be Wire or Wire1
i2c::i2c(TwoWire* a) {
	if (port != &Wire || port != &Wire1) return;		// Not a valid entry
	i2c::port = a;																// I2C port
} //i2c constructor

// Write a single bit to selected device and register
void i2c::write(uint8_t dev, uint8_t add, uint8_t dat) {
	i2c::port->beginTransmission(dev);
	i2c::port->write(add);																		// Write to address
	i2c::port->write(dat);																		// Write Data
	i2c::port->endTransmission();
} //i2c.write

// Read Multiple Bytes from register
void i2c::read(uint8_t dev, uint8_t add, uint8_t size, uint8_t *datOut) {
	i2c::port->beginTransmission(dev);
	i2c::port->write(add);
	i2c::port->endTransmission(false);
	i2c::port->requestFrom(dev, size);
	uint32_t timeout = micros() + 10 * size;
	while (i2c::port->available() && micros() < timeout) {
		datOut[--size] = i2c::port->read();
	}
} //i2c.read()

// Read single bytes from register
uint8_t i2c::read(uint8_t dev, uint8_t add) {
	i2c::port->beginTransmission(dev);
	i2c::port->write(add);
	i2c::port->endTransmission(false);
	i2c::port->requestFrom(dev, (uint8_t)1);
	return i2c::port->read();
} //i2c.read()

// Returns true if there is a device present on the given address location
bool i2c::scan(uint8_t add) {
	uint8_t error;
	Wire.beginTransmission(add);
	error = Wire.endTransmission();																	// Wire.endTransmission returns a value depending on device presence
	if (error == 0){																								// device found
		return true;
	}
	return false;																										//
} //i2c.scan

// Write data to specified register
void spiWrite(uint8_t reg, uint8_t val, const DUEpin *dpin) {
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
	dpin->port->PIO_ODSR &= ~(0b1 << dpin->pin);
	SPI.transfer(reg);
	SPI.transfer(val);
	dpin->port->PIO_ODSR |= (0b1 << dpin->pin);
	SPI.endTransaction();
} //spiWrite

// Read indicated register and fill pointer location with data
void spiRead(uint8_t reg, uint8_t size, const DUEpin *dpin, uint8_t *datOut) {
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
	uint8_t cnt = 0;
	dpin->port->PIO_ODSR &= ~(0b1 << dpin->pin);
	SPI.transfer((reg + cnt) | 0b1 << 7);
	do {
		datOut[cnt] = SPI.transfer((reg + cnt++) | (0b1 << 7));
	} while (size > cnt);
	dpin->port->PIO_ODSR |= (0b1 << dpin->pin);
	SPI.endTransaction();
} //spiRead

// Read single byte from specified register and return byte
uint8_t spiRead(uint8_t reg, const  DUEpin *dpin) {
	SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
	dpin->port->PIO_ODSR &= ~(0b1 << dpin->pin);
	SPI.transfer(reg | (0b1 << 7));
	uint8_t temp = SPI.transfer(0x00);
	dpin->port->PIO_ODSR |= (0b1 << dpin->pin);
	SPI.endTransaction();
	return temp;
} //spiRead


