/**
 * Description: For things that are directly connected to the pins on the board.
 *
 * Author: Jordan, Matthew, Peter
 *
 * Note: None
 * */

#ifndef INC_COMP_H_
#define INC_COMP_H_

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Variables ------------------------------------------------------------------*/
/*Data variables*/
extern HAL_StatusTypeDef r,g,b;
extern uint16_t conf, r_data, g_data, b_data;

/* Registers */
#define veml3328_addr           0x10
#define veml3328__conf          0x00
#define veml3328_reg_deviceID   0x0C
#define C_                      0x04
#define R_                      0x05
#define G_                      0x06
#define B_                      0x07
#define IR_                     0x08

/* Sensor resolutions */
#define res1 0.003
#define res2 0.006
#define res3 0.012
#define res4 0.024
#define res5 0.048
#define res6 0.096
#define res7 0.192
#define res8 0.328
#define res9 0.768

/* Command codes for registers */
typedef enum {
  SD1_on = 0,
  SD1_off = 1 // default
} SD1;

typedef enum{
  chnl_on = 0, // default
  chnl_GCIR_on = 1
} SD_ALS;

typedef enum {
	DGx1 = 0, // default
	DGx2 = 1,
	DGx4 = 2
} DG;

typedef enum {
  GAINx1 = 0, // default
  GAINx2 = 1,
  GAINx4 = 2,
  GAINx1_2 = 3
} GAIN;

typedef enum {
  SENS_hi = 0, // default
  SENS_lo = 1
} SENS;

typedef enum {
  IT_50 = 0, // default
  IT_100 = 1,
  IT_200 = 2,
  IT_400 = 3
} IT;

typedef enum {
  AF_auto = 0, // default
  AF_active = 1
} AF;

typedef enum{
  TRIG_inf = 0, // default
  TRIG_one = 1
} TRIG;

typedef enum {
  SD0_on = 0,
  SD0_off = 1 // default
} SD0;

/* Function prototypes ------------------------------------------------------------------*/
HAL_StatusTypeDef veml3328_init(void);
void veml3328_config(uint16_t mode);
void veml3328_rd_rgb(void);

#endif /* INC_COMP_H_ */




