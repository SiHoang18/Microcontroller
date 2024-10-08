/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Blinky_7SEG.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define CLOCK 2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t matrix[3][8] = {
	{
		0b00111100,
	    0b01100110,
	    0b01100110,
	    0b01111110,
	    0b01111110,
	    0b01100110,
	    0b01100110,
	    0b01100110
	},{
		0b01111100,
		0b10000100,
		0b10000100,
		0b01111100,
		0b01111100,
		0b10000100,
		0b10000100,
		0b01111100
	},{
		0b01111000,
		0b10000100,
		0b00000100,
		0b00000100,
		0b00000100,
		0b00000100,
		0b10000100,
		0b01111000
	}
};
void setRow(int index){
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET);
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);
	switch (index){
	case 0:
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
		break;
	default:
		break;
	}
}

void setCol(uint8_t colData){
	HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, (colData & 0x01) ? RESET : SET);
	HAL_GPIO_WritePin(ENM1_GPIO_Port, ENM1_Pin, (colData & 0x02) ? RESET : SET);
	HAL_GPIO_WritePin(ENM2_GPIO_Port, ENM2_Pin, (colData & 0x04) ? RESET : SET);
	HAL_GPIO_WritePin(ENM3_GPIO_Port, ENM3_Pin, (colData & 0x08) ? RESET : SET);
	HAL_GPIO_WritePin(ENM4_GPIO_Port, ENM4_Pin, (colData & 0x10) ? RESET : SET);
	HAL_GPIO_WritePin(ENM5_GPIO_Port, ENM5_Pin, (colData & 0x20) ? RESET : SET);
	HAL_GPIO_WritePin(ENM6_GPIO_Port, ENM6_Pin, (colData & 0x40) ? RESET : SET);
	HAL_GPIO_WritePin(ENM7_GPIO_Port, ENM7_Pin, (colData & 0x80) ? RESET : SET);
}
void updateLedMatrix(){
    static int k = 0, i = 0, j = 0;

    if(flag[0]){
        setTime(2, 0);
        if(flag[1]){
            setTime(2, 1);
            setRow(j);
            setCol(matrix[k][j] >> i);
            j = (j + 1) % 8;
            if(j == 0){
                i = (i + 1) % 8;
                if(i == 0){
                    k = (k + 1) % 3;
                }
            }
        }
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  updateLedMatrix();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
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

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|EN0_Pin
                          |EN1_Pin|EN2_Pin|EN3_Pin|ENM2_Pin
                          |ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin
                          |ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, PINA_Pin|PINB_Pin|PINC_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|PIND_Pin|PINE_Pin|PINF_Pin
                          |PING_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin EN0_Pin
                           EN1_Pin EN2_Pin EN3_Pin ENM2_Pin
                           ENM3_Pin ENM4_Pin ENM5_Pin ENM6_Pin
                           ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|EN0_Pin
                          |EN1_Pin|EN2_Pin|EN3_Pin|ENM2_Pin
                          |ENM3_Pin|ENM4_Pin|ENM5_Pin|ENM6_Pin
                          |ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PINA_Pin PINB_Pin PINC_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin PIND_Pin PINE_Pin PINF_Pin
                           PING_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = PINA_Pin|PINB_Pin|PINC_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|PIND_Pin|PINE_Pin|PINF_Pin
                          |PING_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void  HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
    runTime();
}
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
