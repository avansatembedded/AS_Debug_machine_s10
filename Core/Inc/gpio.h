/*
 * gpio.h
 *
 *  Created on: 13-Jun-2023
 *      Author: midhunkumar
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_
/*   LCD Pins ******************************************/
/* HSYNC  */
#define LCD_HSYNC_Pin 					LL_GPIO_PIN_6
#define LCD_HSYNC_GPIO_Port 			GPIOC
/* VSYNC  */
#define LCD_VSYNC_Pin 					LL_GPIO_PIN_4
#define LCD_VSYNC_GPIO_Port 			GPIOA
/* CLK  */
#define LCD_CLK_Pin 					LL_GPIO_PIN_7
#define LCD_CLK_GPIO_Port 				GPIOG
/* BUSY  */
#define LCD_BUSY_Pin 					LL_GPIO_PIN_2
#define LCD_BUSY_GPIO_Port 				GPIOE
/* IRQ */
#define LCD_IRQ_Pin 					LL_GPIO_PIN_14
#define LCD_IRQ_GPIO_Port 				GPIOA
/* DE  */
#define LCD_DE_Pin 						LL_GPIO_PIN_10
#define LCD_DE_GPIO_Port 				GPIOF
/* BL  */
#define LCD_BL_Pin 						LL_GPIO_PIN_3
#define LCD_BL_GPIO_Port 				GPIOG

/* R2  */
#define LCD_R2_Pin 						LL_GPIO_PIN_10
#define LCD_R2_GPIO_Port 				GPIOC
/* R3  */
#define LCD_R3_Pin 						LL_GPIO_PIN_0
#define LCD_R3_GPIO_Port 				GPIOB
/* R4  */
#define LCD_R4_Pin 					LL_GPIO_PIN_11
#define LCD_R4_GPIO_Port 				GPIOA
/* R5  */
#define LCD_R5_Pin 					LL_GPIO_PIN_12
#define LCD_R5_GPIO_Port 				GPIOA
/* R6  */
#define LCD_R6_Pin 					LL_GPIO_PIN_1
#define LCD_R6_GPIO_Port 				GPIOB
/* R7  */
#define LCD_R7_Pin 					LL_GPIO_PIN_6
#define LCD_R7_GPIO_Port 				GPIOG

/* G2  */
#define LCD_G2_Pin 					LL_GPIO_PIN_6
#define LCD_G2_GPIO_Port 				GPIOA
/* G3  */
#define LCD_G3_Pin 					LL_GPIO_PIN_10
#define LCD_G3_GPIO_Port 				GPIOG
/* G4  */
#define LCD_G4_Pin 					LL_GPIO_PIN_10
#define LCD_G4_GPIO_Port 				GPIOB
/* G5  */
#define LCD_G5_Pin 					LL_GPIO_PIN_11
#define LCD_G5_GPIO_Port 				GPIOB
/* G6  */
#define LCD_G6_Pin 					LL_GPIO_PIN_7
#define LCD_G6_GPIO_Port 				GPIOC
/* G7  */
#define LCD_G7_Pin 					LL_GPIO_PIN_3
#define LCD_G7_GPIO_Port 				GPIOD

/* B2  */
#define LCD_B2_Pin 					LL_GPIO_PIN_6
#define LCD_B2_GPIO_Port 				GPIOD
/* B3  */
#define LCD_B3_Pin 					LL_GPIO_PIN_11
#define LCD_B3_GPIO_Port 				GPIOG
/* B4  */
#define LCD_B4_Pin 					LL_GPIO_PIN_12
#define LCD_B4_GPIO_Port 				GPIOG
/* B5  */
#define LCD_B5_Pin 					LL_GPIO_PIN_3
#define LCD_B5_GPIO_Port 				GPIOA
/* B6  */
#define LCD_B6_Pin 					LL_GPIO_PIN_8
#define LCD_B6_GPIO_Port 				GPIOB
/* B7  */
#define LCD_B7_Pin 					LL_GPIO_PIN_9
#define LCD_B7_GPIO_Port 				GPIOB


void MX_GPIO_Init(void);


#endif /* INC_GPIO_H_ */
