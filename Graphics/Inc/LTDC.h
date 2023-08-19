
#ifndef __LTDC_H
#define __LTDC_H



/* LCD Layer mapping to SDRAM */

enum
{
	LTDC_CAPA_UNO =0,
	LTDC_CAPA_DOS,
};

#define LTDC_LAYER1_HEIGHT		 			272U
#define LTDC_LAYER1_WIDTH  				 	480UL
#define LTDC_LAYER1_SIZE   		 			(LTDC_LAYER1_HEIGHT * LTDC_LAYER1_WIDTH )
#define LTDC_LAYER1_START_ADDRS             SD_B2_START


#define LTDC_LAYER2_HEIGHT		 			272U
#define LTDC_LAYER2_WIDTH  				 	480UL
#define LTDC_LAYER2_SIZE   		 			(LTDC_LAYER2_HEIGHT * LTDC_LAYER2_WIDTH )
#define LTDC_LAYER2_START_ADDRS              LTDC_LAYER1_START_ADDRS + ( LTDC_LAYER1_SIZE * 2)

//#define LTDC_LAYER_MIRR_START_ADDRS              LTDC_LAYER1_START_ADDRS + LTDC_LAYER1_SIZE

//extern uint8_t gram[272*480];



/* colour definitions */
#define GREEN 				0x0F0F
#define LEAF_GREEN 			0xA7A7
#define BLUE				0x1F1F
#define UJALA_BLUE 			0x9F9F
#define CYAN 				0x7777
#define PINK 				0xF7F7
#define ROSE 				0xF8F8
#define RED			     	0xC0C0


enum
{
  FONT_BRITANICA_BOLD18Pts,
  FONT_CENTURY_GOTHIC18Pts,
  FONT_TIMES_NEW_ROMAN18Pts,
  FONT_TIMES_NEW_ROMAN48Pts,
  FONT_TIMES_NEW_ROMAN8Pts,

};

typedef struct
{
	uint16_t *fontDescrptPtr;
	uint8_t *fontBitMap;
	uint8_t  fontHeight;
	uint8_t  interCharSpace;


}globalFontSelector_t;

extern globalFontSelector_t globalFontSelector;




void MX_LTDC_Init(void);
void LTDC_draw_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t layer, uint16_t colour);
void LTDC_draw_filled_rectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t layer, uint16_t colour );
void LTDC_put_string(uint16_t x0, uint16_t y0, uint8_t *strPtr, uint8_t layer,  uint16_t colour);
void LTDC_font_select( uint8_t font);


#endif
