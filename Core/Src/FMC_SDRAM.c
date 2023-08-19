/*
 * FMC_SDRAM.c
 *
 *  Created on: 13-Jun-2023
 *      Author: midhunkumar
 */

#include "main.h"



 void MX_FMC_Init(void)
{
	SDRAM_HandleTypeDef hsdram1;


	LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN FMC_Init 0 */

  /* USER CODE END FMC_Init 0 */

  FMC_SDRAM_TimingTypeDef SdramTiming = {0};

  /* USER CODE BEGIN FMC_Init 1 */
  LL_AHB3_GRP1_EnableClock( LL_AHB3_GRP1_PERIPH_FMC );


  /* USER CODE END FMC_Init 1 */

  /** Perform the SDRAM1 memory initialization sequence
  */
  hsdram1.Instance = FMC_SDRAM_DEVICE;
  /* hsdram1.Init */
	hsdram1.Init.SDBank = FMC_SDRAM_BANK2;
  hsdram1.Init.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_8;
  hsdram1.Init.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_12;
  hsdram1.Init.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_8;
  hsdram1.Init.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
  hsdram1.Init.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
  hsdram1.Init.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
  hsdram1.Init.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_3;
  hsdram1.Init.ReadBurst = FMC_SDRAM_RBURST_DISABLE;
  hsdram1.Init.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_2;

  /* SdramTiming */
  SdramTiming.LoadToActiveDelay = 16;
  SdramTiming.ExitSelfRefreshDelay = 16;
  SdramTiming.SelfRefreshTime = 16;
  SdramTiming.RowCycleDelay = 16;
  SdramTiming.WriteRecoveryTime = 16;
  SdramTiming.RPDelay = 16;
  SdramTiming.RCDDelay = 16;

  if (HAL_SDRAM_Init(&hsdram1, &SdramTiming) != HAL_OK)
  {
    Error_Handler( );
  }
  HAL_Delay(1);

	/* USER CODE BEGIN FMC_Init 2 */
	/* USER CODE BEGIN FMC_Init 2 */
	FMC_SDRAM_CommandTypeDef Command;
	/* Step 1 and Step 2 already done in HAL_SDRAM_Init() */
	/* Step 3: Configure a clock configuration enable command */
	 Command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE; /* Set MODE bits to "001" */
	 Command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK2; /* configure the Target Bank bits */
	 Command.AutoRefreshNumber      = 1;
	 Command.ModeRegisterDefinition = 0;
	 HAL_SDRAM_SendCommand(&hsdram1, &Command, 0xfff);

	 HAL_Delay(100); /* Step 4: Insert 100 us minimum delay - Min HAL Delay is 1ms */
	 /* Step 5: Configure a PALL (precharge all) command */
	 Command.CommandMode            = FMC_SDRAM_CMD_PALL; /* Set MODE bits to "010" */
	 HAL_SDRAM_SendCommand(&hsdram1, &Command, 0xfff);
	 /* Step 6: Configure an Auto Refresh command */
	 Command.CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE; /* Set MODE bits to "011" */
	 Command.AutoRefreshNumber      = 2;
	 HAL_SDRAM_SendCommand(&hsdram1, &Command, 0xfff);
	 HAL_Delay(100);

	 /* Step 7: Program the external memory mode register */
	 Command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;/*set the MODE bits to "100" */
	 Command.ModeRegisterDefinition =  (uint32_t)0 | 0<<3 | 2<<4 | 0<<7 | 1<<9;
	 HAL_SDRAM_SendCommand(&hsdram1, &Command, 0xfff);
	 HAL_Delay(100);
	 /* Step 8: Set the refresh rate counter - refer to section SDRAM refresh timer register in RM0455 */
	 /* Set the device refresh rate
	  * COUNT = [(SDRAM self refresh time / number of row) x  SDRAM CLK] – 20
			  = [(64ms/4096) * 100MHz] - 20 = 1562.5 - 20 ~ 1542 */
	 HAL_SDRAM_ProgramRefreshRate(&hsdram1, 2792);   //2792, 1386

	 HAL_Delay(1);




  /* USER CODE END FMC_Init 2 */
}

