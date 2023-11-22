# STM32F407 Demo / Prototype
This is a quick demonstration of I2C on the STM32F407 dev board. It uses a veml3328 optical sensor and a LED with an on-board PWM generator to adjust the light in correspondence to the change in light level.

# Directory
- **/Core/Src**: Contains the source code files.
  - `/main.c`: Main application source files.
  - `/veml3328_hardware.c`: 
  - `/veml3328_software.c`: 

# How It Works
## VEML 3328
The VEML3328 is a solar sensor that detects R, G, V, C, and IR using the I2C communication protocol. The datasheet can be found [here](https://www.vishay.com/docs/84968/veml3328.pdf). 

Note that this demo uses a dev board; information is available [here](https://www.mikroe.com/color-10-click).

### I2C
I2C is a serial communication protocol that uses 2 wires for transmit data, SDA (Serial Data) & SCL (Serial Clock). SDA line, as the name suggests, transmits data bits, and the SCL line transmits the clock signal. And beacuse it has a common clock signal shared between the [master and slave](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Single-Master-Single-Slave.png), the protocol is synchoronous (real-time communication). 

The [message structure](https://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Message-Frame-and-Bit-2.png) of I2C is simple. There are:
- **Start Condition:** Occurs when the SDA line transitions from a high (typically 3.3V or 5V) to low voltage before the SCL line transitions from high to low.

- **Address Frame:** A 7 to 10-bit sequence used to identify slave devices. Addressing is how I2C allows multiple deivce communication without a seperate line like SPI.

- **Read/Write:** A single bit signaling the slave whether the master intends to write data into it or receive data from it.

- **Data Frame:** An 8-bit long frame containing the data that is to be transmitted.

- **ACK/NACK:** Each message frame is succeeded by an acknowledgment bit from the receiving device, indicating the successful reception of the frame.

- **Stop Condition:** Occurs when the SDA line transitions from low to high voltage after the SCL line transitions from low to high.
 

## STM32f407
### Peripherals 
STM32 offers a software known as CubeMX, which allows configuration of pins to streamline development processes. This tool ensures that only the necessary pins/functions are activated, and it provides pre-written function templates.

#### Pinout
Refer to the board pinout diagram [here](https://microcontrollerslab.com/wp-content/uploads/2019/12/stm32f4-discovery-pinout.png) for a comprehensive overview of available pins.

#### Demo Configuration
For the purposes of this demo, the following pins should be activated:

    PE9: PWM
    PB8: SCL
    PB9: SDA

Alternatively, developers can directly use the provided .ioc file in this repo.

## Firmware
### Hardware Abstraction Layer (HAL) Driver
```C
HAL_StatusTypeDef veml3328_wr(uint8_t registerAddress, uint16_t value)
```
