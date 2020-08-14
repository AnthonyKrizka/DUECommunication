// DUEComm.h

#ifndef _DUECOMM_h
	#define _DUECOMM_h

	#if defined(ARDUINO) && ARDUINO >= 100
		#include "arduino.h"
	#else
		#include "WProgram.h"
	#endif

	#include <Wire.h>
	
	// I2C read/ Write Functions
	class i2c {
	public:
		void read(uint8_t dev, uint8_t add, uint8_t size, uint8_t *datOut);
		uint8_t read(uint8_t dev, uint8_t add);
		void write(uint8_t dev, uint8_t add, uint8_t dat);
		bool scan(uint8_t add);
		i2c(TwoWire* a);

	private:
		TwoWire* port;
	};

	typedef struct {
		Pio *port;												// PIO port 
		uint8_t pin;											// Location on PIO port
		uint8_t pinNum;										// Digital pin number	
	}DUEpin;

	void spiWrite(uint8_t reg, uint8_t val, const DUEpin *pin);
	void spiRead(uint8_t reg, uint8_t size, const DUEpin *pin, uint8_t *datOut);
	uint8_t spiRead(uint8_t reg, const DUEpin *pin);

	static const DUEpin DUEpin0 = { PIOA, 8, 0 };
	static const DUEpin DUEpin1 = { PIOA, 9, 1 };
	static const DUEpin DUEpin2 = { PIOB, 25, 2 };
	static const DUEpin DUEpin3 = { PIOC, 28, 3 };
	static const DUEpin DUEpin4 = { PIOC, 26,  };
	static const DUEpin DUEpin5 = { PIOC, 25, 5 };
	static const DUEpin DUEpin6 = { PIOC, 24, 6 };
	static const DUEpin DUEpin7 = { PIOC, 23, 7 };
	static const DUEpin DUEpin8 = { PIOC, 22, 8 };
	static const DUEpin DUEpin9 = { PIOC, 21, 9 };
	static const DUEpin DUEpin10 = { PIOC, 29, 10 };
	static const DUEpin DUEpin11 = { PIOD, 7, 11 };
	static const DUEpin DUEpin12 = { PIOD, 8, 12 };
	static const DUEpin DUEpin13 = { PIOB, 27, 13 };
	static const DUEpin DUEpin14 = { PIOD, 4, 14 };
	static const DUEpin DUEpin15 = { PIOD, 5, 15 };
	static const DUEpin DUEpin16 = { PIOA, 13, 16 };
	static const DUEpin DUEpin17 = { PIOA, 12, 17 };
	static const DUEpin DUEpin18 = { PIOA, 11, 18 };
	static const DUEpin DUEpin19 = { PIOA, 10, 19 };
	static const DUEpin DUEpin20 = { PIOB, 12, 20 };
	static const DUEpin DUEpin21 = { PIOB, 13, 21 };
	static const DUEpin DUEpin22 = { PIOB, 26, 22 };
	static const DUEpin DUEpin23 = { PIOA, 14, 23 };
	static const DUEpin DUEpin24 = { PIOA, 15, 24 };
	static const DUEpin DUEpin25 = { PIOD, 0, 25 };
	static const DUEpin DUEpin26 = { PIOD, 1, 26 };
	static const DUEpin DUEpin27 = { PIOD, 2, 27 };
	static const DUEpin DUEpin28 = { PIOD, 3, 28 };
	static const DUEpin DUEpin29 = { PIOD, 6, 29 };
	static const DUEpin DUEpin30 = { PIOD, 9, 30 };
	static const DUEpin DUEpin31 = { PIOA, 7, 31 };
	static const DUEpin DUEpin32 = { PIOD, 10, 32 };
	static const DUEpin DUEpin33 = { PIOC, 1, 33 };
	static const DUEpin DUEpin34 = { PIOC, 2, 34 };
	static const DUEpin DUEpin35 = { PIOC, 3, 35 };
	static const DUEpin DUEpin36 = { PIOC, 4, 36 };
	static const DUEpin DUEpin37 = { PIOC, 5, 37 };
	static const DUEpin DUEpin38 = { PIOC, 6, 38 };
	static const DUEpin DUEpin39 = { PIOC, 7, 39 };
	static const DUEpin DUEpin40 = { PIOC, 8, 40 };
	static const DUEpin DUEpin41 = { PIOC, 9, 41 };
	static const DUEpin DUEpin42 = { PIOA, 19, 42 };
	static const DUEpin DUEpin43 = { PIOA, 20, 43 };
	static const DUEpin DUEpin44 = { PIOC, 19, 44 };
	static const DUEpin DUEpin45 = { PIOC, 18, 45 };
	static const DUEpin DUEpin46 = { PIOC, 17, 46 };
	static const DUEpin DUEpin47 = { PIOC, 16, 47 };
	static const DUEpin DUEpin48 = { PIOC, 15, 48 };
	static const DUEpin DUEpin49 = { PIOC, 14, 49 };
	static const DUEpin DUEpin50 = { PIOC, 13, 50 };
	static const DUEpin DUEpin51 = { PIOC, 12, 51 };
	static const DUEpin DUEpin52 = { PIOB, 21, 52 }; 
	static const DUEpin DUEpin53 = { PIOB, 14, 53 };
	static const DUEpin DUEpinA0 = { PIOA, 16, 54 };
	static const DUEpin DUEpinA1 = { PIOA, 24, 55 };
	static const DUEpin DUEpinA2 = { PIOA, 23, 56 };
	static const DUEpin DUEpinA3 = { PIOA, 22, 57 };
	static const DUEpin DUEpinA4 = { PIOA, 6, 58 };
	static const DUEpin DUEpinA5 = { PIOA, 4, 59 };
	static const DUEpin DUEpinA6 = { PIOA, 3, 60 };
	static const DUEpin DUEpinA7 = { PIOA, 2, 61 };
	static const DUEpin DUEpinA8 = { PIOB, 17, 62 };
	static const DUEpin DUEpinA9 = { PIOB, 18, 63 };
	static const DUEpin DUEpinA10 = { PIOB, 19, 64 };
	static const DUEpin DUEpinA11 = { PIOB, 20, 65 };
	static const DUEpin DUEpinDAC0 = { PIOB, 15, 66 };
	static const DUEpin DUEpinDAC1 = { PIOB, 16, 67 };
	static const DUEpin DUEpinCANRX = { PIOA, 1, 68 };
	static const DUEpin DUEpinCANTX = { PIOA, 0, 69 };
	static const DUEpin DUEpinSCL1 = { PIOA, 17, 71 };
	static const DUEpin DUEpinSDA1 = { PIOA, 18, 70 };
	static const DUEpin DUEpin77 = { PIOA, 28, 77 };
	static const DUEpin DUEpin87 = { PIOA, 29, 87 };
		
	static const DUEpin *pin0 = &DUEpin0;
	static const DUEpin *pin1 = &DUEpin1;
	static const DUEpin *pin2 = &DUEpin2;
	static const DUEpin *pin3 = &DUEpin3;
	static const DUEpin *pin4 = &DUEpin4;
	static const DUEpin *pin5 = &DUEpin5;
	static const DUEpin *pin6 = &DUEpin6;
	static const DUEpin *pin7 = &DUEpin7;
	static const DUEpin *pin8 = &DUEpin8;
	static const DUEpin *pin9 = &DUEpin9;
	static const DUEpin *pin10 = &DUEpin10;
	static const DUEpin *pin11 = &DUEpin11;
	static const DUEpin *pin12 = &DUEpin12;
	static const DUEpin *pin13 = &DUEpin13;
	static const DUEpin *pin14 = &DUEpin14;
	static const DUEpin *pin15 = &DUEpin15;
	static const DUEpin *pin16 = &DUEpin16;
	static const DUEpin *pin17 = &DUEpin17;
	static const DUEpin *pin18 = &DUEpin18;
	static const DUEpin *pin19 = &DUEpin19;
	static const DUEpin *pin20 = &DUEpin20;
	static const DUEpin *pin21 = &DUEpin21;
	static const DUEpin *pin22 = &DUEpin22;
	static const DUEpin *pin23 = &DUEpin23;
	static const DUEpin *pin24 = &DUEpin24;
	static const DUEpin *pin25 = &DUEpin25;
	static const DUEpin *pin26 = &DUEpin26;
	static const DUEpin *pin27 = &DUEpin27;
	static const DUEpin *pin28 = &DUEpin28;
	static const DUEpin *pin29 = &DUEpin29;
	static const DUEpin *pin30 = &DUEpin30;
	static const DUEpin *pin31 = &DUEpin31;
	static const DUEpin *pin32 = &DUEpin32;
	static const DUEpin *pin33 = &DUEpin33;
	static const DUEpin *pin34 = &DUEpin34;
	static const DUEpin *pin35 = &DUEpin35;
	static const DUEpin *pin36 = &DUEpin36;
	static const DUEpin *pin37 = &DUEpin37;
	static const DUEpin *pin38 = &DUEpin38;
	static const DUEpin *pin39 = &DUEpin39;
	static const DUEpin *pin40 = &DUEpin40;
	static const DUEpin *pin41 = &DUEpin41;
	static const DUEpin *pin42 = &DUEpin42;
	static const DUEpin *pin43 = &DUEpin43;
	static const DUEpin *pin44 = &DUEpin44;
	static const DUEpin *pin45 = &DUEpin45;
	static const DUEpin *pin46 = &DUEpin46;
	static const DUEpin *pin47 = &DUEpin47;
	static const DUEpin *pin48 = &DUEpin48;
	static const DUEpin *pin49 = &DUEpin49;
	static const DUEpin *pin50 = &DUEpin50;
	static const DUEpin *pin51 = &DUEpin51;
	static const DUEpin *pin52 = &DUEpin52;
	static const DUEpin *pin53 = &DUEpin53;
	static const DUEpin *pinA0 = &DUEpinA0;
	static const DUEpin *pinA1 = &DUEpinA1;
	static const DUEpin *pinA2 = &DUEpinA2;
	static const DUEpin *pinA3 = &DUEpinA3;
	static const DUEpin *pinA4 = &DUEpinA4;
	static const DUEpin *pinA5 = &DUEpinA5;
	static const DUEpin *pinA6 = &DUEpinA6;
	static const DUEpin *pinA7 = &DUEpinA7;
	static const DUEpin *pinA8 = &DUEpinA8;
	static const DUEpin *pinA9 = &DUEpinA9;
	static const DUEpin *pinA10 = &DUEpinA10;
	static const DUEpin *pinA11 = &DUEpinA11;
	static const DUEpin *pinDAC0 = &DUEpinDAC0;
	static const DUEpin *pinDAC1 = &DUEpinDAC1;
	static const DUEpin *pinCANRX = &DUEpinCANRX;
	static const DUEpin *pinCANTX = &DUEpinCANTX;
	static const DUEpin *pinSCL1 = &DUEpinSCL1;
	static const DUEpin *pinSDA1 = &DUEpinSDA1;
	static const DUEpin *pin77 = &DUEpin77;
	static const DUEpin *pin87 = &DUEpin87;
	

#endif