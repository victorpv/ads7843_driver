#ifndef __ADS7843_H
#define __ADS7843_H


#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#define hwSPI 1

class Point {
 public:
  Point(void);
  Point(uint16_t x, uint16_t y, uint16_t z);
  
  bool operator==(Point);
  bool operator!=(Point);

  uint16_t x, y, z;
};

class ADS7843{
public:
#ifndef hwSPI
	ADS7843(int8_t cs, int8_t dclk, int8_t din, int8_t dout, int8_t irq);
#else
	ADS7843(int8_t cs, int8_t irq);
#endif
	void begin();
	void write(uint8_t dat);
	uint16_t read();
	Point getpos(uint8_t *flag);
	void getPosOnce(uint16_t *x, uint16_t *y);
	uint8_t check_irq(void);
	uint8_t wr(uint8_t dat);
private:
#ifndef hwSPI
	uint32_t _cs, _dclk, _din, _dout, _irq;
	volatile uint32 *_cs_port, *_dclk_port, *_din_port, *_dout_port;
	uint32_t cspinmask, _dclk_pin, _din_pin, _dout_pin;
#else
	uint32_t _cs, _irq;
	volatile uint32 *_cs_port;
	uint32_t cspinmask;
#endif
};

#endif
