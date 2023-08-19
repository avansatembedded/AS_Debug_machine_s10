/*
 * LTDC.c
 *
 *  Created on: 13-Jun-2023
 *      Author: midhunkumar
 */
#include "main.h"

globalFontSelector_t globalFontSelector;

LTDC_HandleTypeDef hltdc;
LTDC_LayerCfgTypeDef pLayerCfg = {0};
LTDC_LayerCfgTypeDef pLayerCfg1 = {0};
uint32_t stringHead =0;
void MX_LTDC_Init(void)
{
	/* USER CODE BEGIN LTDC_Init 0 */

	/* USER CODE END LTDC_Init 0 */



	LL_GPIO_SetOutputPin(LCD_BL_GPIO_Port, LCD_BL_Pin);

	/* USER CODE BEGIN LTDC_Init 1 */
	LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_LTDC);
	/* USER CODE END LTDC_Init 1 */
	hltdc.Instance = LTDC;
	hltdc.Init.HSPolarity = LTDC_HSPOLARITY_AL;
	hltdc.Init.VSPolarity = LTDC_VSPOLARITY_AL;
	hltdc.Init.DEPolarity = LTDC_DEPOLARITY_AL;
	hltdc.Init.PCPolarity = LTDC_PCPOLARITY_IPC;
	hltdc.Init.HorizontalSync = 15;
	hltdc.Init.VerticalSync = 15;
	hltdc.Init.AccumulatedHBP = 14;
	hltdc.Init.AccumulatedVBP = 5;
	hltdc.Init.AccumulatedActiveW = 494;
	hltdc.Init.AccumulatedActiveH = 277;
	hltdc.Init.TotalWidth = 500;
	hltdc.Init.TotalHeigh = 279;
	hltdc.Init.Backcolor.Blue = 0x00;
	hltdc.Init.Backcolor.Red = 0x00;
	hltdc.Init.Backcolor.Green = 0x00;
	if (HAL_LTDC_Init(&hltdc) != HAL_OK)
	{
		Error_Handler();
	}

	pLayerCfg.WindowX0 = 0;
	pLayerCfg.WindowX1 = LTDC_LAYER1_WIDTH-1;
	pLayerCfg.WindowY0 = 0;
	pLayerCfg.WindowY1 = LTDC_LAYER1_HEIGHT-1;
	pLayerCfg.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;//LTDC_PIXEL_FORMAT_ARGB8888;
	pLayerCfg.Alpha = 100;
	pLayerCfg.Alpha0 = 100;
	pLayerCfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg.FBStartAdress = (uint32_t)LTDC_LAYER1_START_ADDRS;
	pLayerCfg.ImageWidth = LTDC_LAYER1_WIDTH;
	pLayerCfg.ImageHeight = LTDC_LAYER1_HEIGHT;
	pLayerCfg.Backcolor.Blue = 0;
	pLayerCfg.Backcolor.Green = 0;
	pLayerCfg.Backcolor.Red = 0;
	if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg, 0) != HAL_OK)
	{
		Error_Handler();
	}

	pLayerCfg1.WindowX0 = 0;
	pLayerCfg1.WindowX1 = LTDC_LAYER2_WIDTH-1;
	pLayerCfg1.WindowY0 = 0;
	pLayerCfg1.WindowY1 = LTDC_LAYER2_HEIGHT-1;
	pLayerCfg1.PixelFormat = LTDC_PIXEL_FORMAT_RGB565;
	pLayerCfg1.Alpha = 100;
	pLayerCfg1.Alpha0 = 100;
	pLayerCfg1.BlendingFactor1 = LTDC_BLENDING_FACTOR1_CA;
	pLayerCfg1.BlendingFactor2 = LTDC_BLENDING_FACTOR2_CA;
	pLayerCfg1.FBStartAdress = (uint32_t)LTDC_LAYER2_START_ADDRS;//LTDC_ram;//&sampleArr[0];
	pLayerCfg1.ImageWidth = LTDC_LAYER2_WIDTH;
	pLayerCfg1.ImageHeight = LTDC_LAYER2_HEIGHT;
	pLayerCfg1.Backcolor.Blue = 0x00;
	pLayerCfg1.Backcolor.Green = 0x00;
	pLayerCfg1.Backcolor.Red = 0x00;
	if (HAL_LTDC_ConfigLayer(&hltdc, &pLayerCfg1, 1) != HAL_OK)
	{
		Error_Handler();
	}


}


void LTDC_draw_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t layer,  uint16_t colour)
{
	uint32_t layerWidth = 0;
	__IO uint8_t *sdRamPtr = 0x00;
	uint16 i;
	uint8_t pixelWidth = 2;

	if( layer == LTDC_CAPA_UNO)
		{
			layerWidth = LTDC_LAYER1_WIDTH;
			stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
			sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER1_START_ADDRS + stringHead);
		}
		else
		{
			layerWidth = LTDC_LAYER2_WIDTH;
			stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
			sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER2_START_ADDRS + stringHead);
		}


	for(i=0; i< ((x1 - x0)); i++)
	{
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * 0 )+ ( i *pixelWidth) ) = colour & 0xFF;
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * 0 )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;

		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * ((y1-x0)-1) )+ ( i *pixelWidth) ) = colour & 0xFF;
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * ((y1-x0)-1) )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
	}

	for(i=0; i< ((y1 - y0)); i++)
	{
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * i ) /*+ ( i *pixelWidth) */) = colour & 0xFF;
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * i ) /*+ ( i *pixelWidth) +1 */) = (colour>>8) & 0xFF;

		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * i) + ( pixelWidth * (x1-x0) ) ) = colour & 0xFF;
		*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * i) + ( pixelWidth *(x1-x0)) +1) = (colour>>8) & 0xFF;
	}


}


 void LTDC_draw_filled_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t layer,  uint16_t colour)
{
	uint32_t layerWidth = 0;
	__IO uint8_t *sdRamPtr = 0x00;
	uint16 i;
	uint16 j;
	uint8_t pixelWidth = 2;

	if( layer == LTDC_CAPA_UNO)
		{
			layerWidth = LTDC_LAYER1_WIDTH;
			stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
			sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER1_START_ADDRS + stringHead);
		}
		else
		{
			layerWidth = LTDC_LAYER2_WIDTH;
			stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
			sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER2_START_ADDRS + stringHead);
		}


	for(j=0; j< ((y1 - y0)); j++)
	{
		for(i=0; i< ((x1 - x0)); i++)
		{
			*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * j )+ ( i *pixelWidth) ) = colour & 0xFF;
			*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * j )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;

		}

    }


}




void LTDC_put_string(uint16_t x0, uint16_t y0, uint8_t *strPtr, uint8_t layer,  uint16_t colour)
{


	//uint32_t stringHead =0;
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t i = 0, fontByte = 0;
	__IO uint8_t *sdRamPtr = 0x00;
	uint16_t fontBitmaptIndex = 0;
	uint8_t charWidth = 0;
	uint8_t charHeight = 0;
	uint8_t temp = 0;
	uint8 startChar = '!';
	uint8_t pixelWidth = 2;
	uint8_t charSpace = 0;
	uint32_t layerWidth = 0; 


	uint16_t *fontDescrptPtr  =  ( uint16_t * )globalFontSelector.fontDescrptPtr;
	uint8_t *fontBitMap       =  ( uint8_t * )globalFontSelector.fontBitMap;
	charHeight = globalFontSelector.fontHeight;
	charSpace = globalFontSelector.interCharSpace;

	if( layer == LTDC_CAPA_UNO)
	{
		layerWidth = LTDC_LAYER1_WIDTH;
		stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
		sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER1_START_ADDRS + stringHead);
	}
	else
	{
		layerWidth = LTDC_LAYER2_WIDTH;
		stringHead = ( ( y0 ) * (layerWidth * pixelWidth) )+ ( ( x0 + 1 ) * pixelWidth );
		sdRamPtr = (__IO uint8_t *) ( LTDC_LAYER2_START_ADDRS + stringHead);
	}

	while(*strPtr != 0x00)
	{
		if( *strPtr != ' ')
		{
			temp = (uint8_t)(*strPtr)-startChar;
		}
		else
		{
			temp = (uint8_t)94U;
		}
		temp = temp *2;
		fontBitmaptIndex = (uint16_t) *(  fontDescrptPtr + temp + 1   );
		charWidth =( uint8_t )*(  fontDescrptPtr  + temp  );

		if( (charWidth > 0) && (charWidth <= 8 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			//  sdRamPtr = sdRamPtr + (charWidth * pixelWidth ) ;
		}
		//*******************************************************************************************************************************************************
		if( (charWidth > 8) && (charWidth <= 16 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*2) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			//  sdRamPtr = sdRamPtr + 8;
			for(i=0; i< ( charWidth-8 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*2)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
		}
		//*******************************************************************************************************************************************************
		if( (charWidth > 18) && (charWidth <= 24 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*3) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*3)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< ( charWidth-16 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*3)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}

				}
			}
		}
		//*******************************************************************************************************************************************************

		if( (charWidth > 24) && (charWidth <= 32 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*4) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*4)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*4)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< ( charWidth-24 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*4)+3 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
		}

		//*******************************************************************************************************************************************************
		if( (charWidth > 32) && (charWidth <= 40 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*5) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*5)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*5)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*5)+3 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< ( charWidth-32 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*5)+4 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
		}

		//*******************************************************************************************************************************************************
		if( (charWidth > 40) && (charWidth <= 48 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6)+3 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6)+4 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< ( charWidth-40 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*6)+5 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}

		}

		//*******************************************************************************************************************************************************
		if( (charWidth > 48) && (charWidth <= 56 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}

				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+3 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+4 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+5 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< ( charWidth-48 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*7)+6 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 48*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 48*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
		}

		//*******************************************************************************************************************************************************
		if( (charWidth > 56) && (charWidth <= 64 ) )
		{
			for(i=0; i<8; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8) ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( i *pixelWidth) +1) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+1 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 8*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+2 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 16*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+3 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 24*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+4 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 32*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+5 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 40*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}
			for(i=0; i< 8 ; i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+6 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 48*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 48*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}

			for(i=0; i< ( charWidth-56 ); i++)
			{
				for(row = 0; row < charHeight; row++)
				{
					fontByte = *(  fontBitMap + (fontBitmaptIndex + (row*8)+7 ) );
					if(fontByte & (0x80>>i))
					{
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 56*pixelWidth ) + ( i *pixelWidth)      ) = colour & 0xFF;
						*(__IO uint8_t *) ( sdRamPtr + ( ( layerWidth * pixelWidth ) * row )+ ( 56*pixelWidth ) + ( i *pixelWidth) +1   ) = (colour>>8) & 0xFF;
					}
				}
			}

		}
		sdRamPtr = sdRamPtr +  ( charWidth * pixelWidth ) + charSpace;
		strPtr++;
	}

}

void LTDC_font_select( uint8_t font)
{

	switch( font )
	{
	case FONT_BRITANICA_BOLD18Pts:
		globalFontSelector.fontDescrptPtr =   britannicBold_18ptDescriptors;
		globalFontSelector.interCharSpace =   britannicBold_18ptCharSpace;
		globalFontSelector.fontBitMap =       britannicBold_18ptBitmaps;
		globalFontSelector.fontHeight =       britannicBold_18ptCharHeight;
		break; 
	case FONT_CENTURY_GOTHIC18Pts:
		globalFontSelector.fontDescrptPtr =  centuryGothic_18ptDescriptors;
		globalFontSelector.interCharSpace =  centuryGothic_18ptCharSpace;
		globalFontSelector.fontBitMap =      centuryGothic_18ptBitmaps;
		globalFontSelector.fontHeight =      centuryGothic_18ptCharHeight;
		break;    
	case FONT_TIMES_NEW_ROMAN18Pts:     
		globalFontSelector.fontDescrptPtr =   timesNewRoman_18ptDescriptors;
		globalFontSelector.interCharSpace =   timesNewRoman_18ptCharSpace;
		globalFontSelector.fontBitMap =       timesNewRoman_18ptBitmaps;
		globalFontSelector.fontHeight =       timesNewRoman_18ptCharHeight;

		break;
	case FONT_TIMES_NEW_ROMAN48Pts:
		globalFontSelector.fontDescrptPtr =  timesNewRoman_48ptDescriptors;
		globalFontSelector.interCharSpace =  timesNewRoman_48ptCharSpace;
		globalFontSelector.fontBitMap =  timesNewRoman_48ptBitmaps;
		globalFontSelector.fontHeight = timesNewRoman_48ptCharHeight ;
		break;
	case FONT_TIMES_NEW_ROMAN8Pts:

		globalFontSelector.fontDescrptPtr =  timesNewRoman_8ptDescriptors;
		globalFontSelector.interCharSpace = timesNewRoman_8ptCharSpace;
		globalFontSelector.fontBitMap =  timesNewRoman_8ptBitmaps;
		globalFontSelector.fontHeight = timesNewRoman_8ptCharHeight;
		break;

	default:

		globalFontSelector.fontDescrptPtr =  timesNewRoman_8ptDescriptors;
		globalFontSelector.interCharSpace = timesNewRoman_8ptCharSpace;
		globalFontSelector.fontBitMap =  timesNewRoman_8ptBitmaps;
		globalFontSelector.fontHeight = timesNewRoman_8ptCharHeight;
		break;
	}


}



