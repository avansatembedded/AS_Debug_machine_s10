/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"




/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void system_init( void );





static void MX_SPI2_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
uint32_t i;


unsigned short int temp;
__IO uint8_t *Bptr;
__IO uint8_t *Lptr;

unsigned long long k =0;
uint8_t random;
int main(void)
{

	/* MCU Configuration--------------------------------------------------------*/



	system_init();


	// MX_SPI2_Init();
	// MX_SPI1_Init();

	HAL_Delay(2000);
	//
	for( k=0x0000; k< ( (480*272)*2); k= k+2)
	{
		*(__IO uint8_t *) (LTDC_LAYER1_START_ADDRS + k + 1) = *(__IO uint8_t *) (LTDC_LAYER2_START_ADDRS + k + 1) = (uint8_t)0x00;
		*(__IO uint8_t *) (LTDC_LAYER1_START_ADDRS + k + 2) = *(__IO uint8_t *) (LTDC_LAYER2_START_ADDRS + k + 2) = (uint8_t)0x00;
	}
	LTDC_font_select(FONT_BRITANICA_BOLD18Pts);
	LTDC_put_string(10, 10, "ABCDEFGHIJWXYZabcd efg", LTDC_CAPA_DOS ,GREEN );


	LTDC_font_select(FONT_CENTURY_GOTHIC18Pts);
	LTDC_put_string(10, 40, "ABCDEFGHIJWXYZabcd efg", LTDC_CAPA_DOS ,0x07FF );


	LTDC_font_select(FONT_TIMES_NEW_ROMAN18Pts);
	LTDC_put_string(10, 65, "GABCDEFGHIJWXYZabcd efg", LTDC_CAPA_DOS ,BLUE );

	LTDC_font_select(FONT_TIMES_NEW_ROMAN8Pts);
	LTDC_put_string(10, 100, "ABCDEFGHIJWXYZabcd efg", LTDC_CAPA_DOS ,CYAN );

	LTDC_font_select(FONT_TIMES_NEW_ROMAN48Pts);
	LTDC_put_string(10, 120, "ABCDabcd efg", LTDC_CAPA_DOS ,0x07FF );

	LTDC_font_select(FONT_TIMES_NEW_ROMAN48Pts);
	LTDC_put_string(12, 122, "ABCDabcd efg", LTDC_CAPA_UNO ,BLUE );



	LTDC_draw_rectangle(0, 0, 240, 100, LTDC_CAPA_DOS,  BLUE);

	LTDC_draw_filled_rectangle(0, 150, 240, 250, LTDC_CAPA_DOS,  BLUE);


	while (1)
	{

	}

}


static void system_init( void )
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();
	/* Configure the peripherals common clocks */
	PeriphCommonClock_Config();
	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	/* Initialize MEDTLS lib */
	//MX_MBEDTLS_Init();
	/* Initialize FMC for external SD RAM */
	MX_FMC_Init();
	/* Initialize LTDC RGB LCD controller */
	MX_LTDC_Init();

}

static void MX_SPI1_Init(void)
{

	/* USER CODE BEGIN SPI1_Init 0 */

	/* USER CODE END SPI1_Init 0 */

	LL_SPI_InitTypeDef SPI_InitStruct = {0};

	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* Peripheral clock enable */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SPI1);

	/* USER CODE BEGIN SPI1_Init 1 */

	/* USER CODE END SPI1_Init 1 */
	/* SPI1 parameter configuration*/
	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_HARD_OUTPUT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI1, &SPI_InitStruct);
	LL_SPI_SetStandard(SPI1, LL_SPI_PROTOCOL_MOTOROLA);
	/* USER CODE BEGIN SPI1_Init 2 */

	/* USER CODE END SPI1_Init 2 */

}

/**
 * @brief SPI2 Initialization Function
 * @param None
 * @retval None
 */
static void MX_SPI2_Init(void)
{

	/* USER CODE BEGIN SPI2_Init 0 */

	/* USER CODE END SPI2_Init 0 */

	LL_SPI_InitTypeDef SPI_InitStruct = {0};
	/* Peripheral clock enable */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_SPI2);


	/* USER CODE BEGIN SPI2_Init 1 */

	/* USER CODE END SPI2_Init 1 */
	/* SPI2 parameter configuration*/
	SPI_InitStruct.TransferDirection = LL_SPI_FULL_DUPLEX;
	SPI_InitStruct.Mode = LL_SPI_MODE_MASTER;
	SPI_InitStruct.DataWidth = LL_SPI_DATAWIDTH_8BIT;
	SPI_InitStruct.ClockPolarity = LL_SPI_POLARITY_LOW;
	SPI_InitStruct.ClockPhase = LL_SPI_PHASE_1EDGE;
	SPI_InitStruct.NSS = LL_SPI_NSS_HARD_OUTPUT;
	SPI_InitStruct.BaudRate = LL_SPI_BAUDRATEPRESCALER_DIV2;
	SPI_InitStruct.BitOrder = LL_SPI_MSB_FIRST;
	SPI_InitStruct.CRCCalculation = LL_SPI_CRCCALCULATION_DISABLE;
	SPI_InitStruct.CRCPoly = 10;
	LL_SPI_Init(SPI2, &SPI_InitStruct);
	LL_SPI_SetStandard(SPI2, LL_SPI_PROTOCOL_MOTOROLA);
	/* USER CODE BEGIN SPI2_Init 2 */

	/* USER CODE END SPI2_Init 2 */

}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
