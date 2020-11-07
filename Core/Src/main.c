/*
 * main.c
 *
 *  Created on: Aug 8, 2020
 *      Author: ugur
 */
#include "main.h"

void SystemClock_Config(void);

int i,j,k,l,m;

int segment1[10] = {0x1000,0x1CC0,0x0900,0x0840,0x04C0,0x0240,0x0200,0x18C0,0x0000,0x0040};
int segment2[10] = {0x4000,0x7300,0x2400,0x2100,0x1300,0x0900,0x0800,0x6300,0x0000,0x0100};

int main(void)
{

	RCC->AHB1ENR |= (1<<2);
	RCC->AHB1ENR |= (1<<3);
	RCC->AHB1ENR |= (1<<4);

	GPIOE->MODER |= (1<<14);
	GPIOE->MODER &= ~(1<<15);
	GPIOE->OTYPER &= ~(1<<7);
	GPIOE->OSPEEDR |= (1<<14);
	GPIOE->OSPEEDR &= ~(1<<15);

	GPIOE->MODER |= (1<<18);
	GPIOE->MODER &= ~(1<<19);
	GPIOE->OTYPER &= ~(1<<9);
	GPIOE->OSPEEDR |= (1<<18);
	GPIOE->OSPEEDR &= ~(1<<19);

	GPIOE->MODER |= (1<<22);
	GPIOE->MODER &= ~(1<<23);
	GPIOE->OTYPER &= ~(1<<11);
	GPIOE->OSPEEDR |= (1<<22);
	GPIOE->OSPEEDR &= ~(1<<23);

	GPIOE->MODER |= (1<<26);
	GPIOE->MODER &= ~(1<<27);
	GPIOE->OTYPER &= ~(1<<13);
	GPIOE->OSPEEDR |= (1<<26);
	GPIOE->OSPEEDR &= ~(1<<27);

	GPIOD->MODER |= (1<<16);
	GPIOD->MODER &= ~(1<<17);
	GPIOD->OTYPER &= ~(1<<8);
	GPIOD->OSPEEDR |= (1<<16);
	GPIOD->OSPEEDR &= ~(1<<17);

	GPIOD->MODER |= (1<<18);
	GPIOD->MODER &= ~(1<<19);
	GPIOD->OTYPER &= ~(1<<9);
	GPIOD->OSPEEDR |= (1<<18);
	GPIOD->OSPEEDR &= ~(1<<19);

	GPIOD->MODER |= (1<<20);
	GPIOD->MODER &= ~(1<<21);
	GPIOD->OTYPER &= ~(1<<10);
	GPIOD->OSPEEDR |= (1<<20);
	GPIOD->OSPEEDR &= ~(1<<21);

	GPIOD->MODER |= (1<<22);
	GPIOD->MODER &= ~(1<<23);
	GPIOD->OTYPER &= ~(1<<11);
	GPIOD->OSPEEDR |= (1<<22);
	GPIOD->OSPEEDR &= ~(1<<23);

	GPIOD->MODER |= (1<<24);
	GPIOD->MODER &= ~(1<<25);
	GPIOD->OTYPER &= ~(1<<12);
	GPIOD->OSPEEDR |= (1<<24);
	GPIOD->OSPEEDR &= ~(1<<25);

	GPIOD->MODER |= (1<<26);
	GPIOD->MODER &= ~(1<<27);
	GPIOD->OTYPER &= ~(1<<13);
	GPIOD->OSPEEDR |= (1<<26);
	GPIOD->OSPEEDR &= ~(1<<27);

	GPIOD->MODER |= (1<<28);
	GPIOD->MODER &= ~(1<<29);
	GPIOD->OTYPER &= ~(1<<14);
	GPIOD->OSPEEDR |= (1<<28);
	GPIOD->OSPEEDR &= ~(1<<29);


	GPIOC->MODER |= (1<<12);
	GPIOC->MODER &= ~(1<<13);
	GPIOC->OTYPER &= ~(1<<6);
	GPIOC->OSPEEDR |= (1<<12);
	GPIOC->OSPEEDR &= ~(1<<13);

	GPIOC->MODER |= (1<<14);
	GPIOC->MODER &= ~(1<<15);
	GPIOC->OTYPER &= ~(1<<7);
	GPIOC->OSPEEDR |= (1<<14);
	GPIOC->OSPEEDR &= ~(1<<15);

	GPIOC->MODER |= (1<<16);
	GPIOC->MODER &= ~(1<<17);
	GPIOC->OTYPER &= ~(1<<8);
	GPIOC->OSPEEDR |= (1<<16);
	GPIOC->OSPEEDR &= ~(1<<17);

	GPIOC->MODER |= (1<<18);
	GPIOC->MODER &= ~(1<<19);
	GPIOC->OTYPER &= ~(1<<9);
	GPIOC->OSPEEDR |= (1<<18);
	GPIOC->OSPEEDR &= ~(1<<19);

	GPIOC->MODER |= (1<<20);
	GPIOC->MODER &= ~(1<<21);
	GPIOC->OTYPER &= ~(1<<10);
	GPIOC->OSPEEDR |= (1<<20);
	GPIOC->OSPEEDR &= ~(1<<21);

	GPIOC->MODER |= (1<<22);
	GPIOC->MODER &= ~(1<<23);
	GPIOC->OTYPER &= ~(1<<11);
	GPIOC->OSPEEDR |= (1<<22);
	GPIOC->OSPEEDR &= ~(1<<23);

	GPIOC->MODER |= (1<<24);
	GPIOC->MODER &= ~(1<<25);
	GPIOC->OTYPER &= ~(1<<12);
	GPIOC->OSPEEDR |= (1<<24);
	GPIOC->OSPEEDR &= ~(1<<25);

	GPIOD->ODR = 0xFF00;
	GPIOC->ODR = 0x0FF0;



  HAL_Init();


  SystemClock_Config();


  while(1)
  {

	  for(l=0;l<10;l++)
	  {
		  for(i=0;i<650;i++)
		  {
			  GPIOE->ODR = 0x0080;
		  	  HAL_Delay(10);
		  	  GPIOE->ODR = 0x0200;
		  	  HAL_Delay(10);
		  	  GPIOE->ODR = 0x0800;
		  	  HAL_Delay(10);
		  	  GPIOE->ODR = 0x2000;
		  	  HAL_Delay(10);
		  }
		  GPIOC->ODR = segment1[l];
	  }

	  HAL_Delay(2000);

	  for(m=0;m<10;m++)
	  {
		  for(j=0;j<650;j++)
		  {
			  GPIOE->ODR = 0x2000;
			  HAL_Delay(10);
			  GPIOE->ODR = 0x0800;
			  HAL_Delay(10);
			  GPIOE->ODR = 0x0200;
			  HAL_Delay(10);
			  GPIOE->ODR = 0x0080;
			  HAL_Delay(10);
		  }
		  GPIOD->ODR = segment2[m];
	  }
	  HAL_Delay(2000);
  }
}


void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }


  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}


void Error_Handler(void){}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line){}
#endif
