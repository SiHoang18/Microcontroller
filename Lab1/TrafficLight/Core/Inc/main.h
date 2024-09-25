/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED1_Pin GPIO_PIN_3
#define RED1_GPIO_Port GPIOA
#define YELLOW1_Pin GPIO_PIN_4
#define YELLOW1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_5
#define GREEN1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_6
#define RED2_GPIO_Port GPIOA
#define YELLOW2_Pin GPIO_PIN_7
#define YELLOW2_GPIO_Port GPIOA
#define PINA1_Pin GPIO_PIN_0
#define PINA1_GPIO_Port GPIOB
#define PINB1_Pin GPIO_PIN_1
#define PINB1_GPIO_Port GPIOB
#define PINC1_Pin GPIO_PIN_2
#define PINC1_GPIO_Port GPIOB
#define GREEN2_Pin GPIO_PIN_8
#define GREEN2_GPIO_Port GPIOA
#define PINA_Pin GPIO_PIN_9
#define PINA_GPIO_Port GPIOA
#define PINB_Pin GPIO_PIN_10
#define PINB_GPIO_Port GPIOA
#define PINC_Pin GPIO_PIN_11
#define PINC_GPIO_Port GPIOA
#define PIND_Pin GPIO_PIN_12
#define PIND_GPIO_Port GPIOA
#define PINE_Pin GPIO_PIN_13
#define PINE_GPIO_Port GPIOA
#define PINF_Pin GPIO_PIN_14
#define PINF_GPIO_Port GPIOA
#define PING_Pin GPIO_PIN_15
#define PING_GPIO_Port GPIOA
#define PIND1_Pin GPIO_PIN_3
#define PIND1_GPIO_Port GPIOB
#define PINE1_Pin GPIO_PIN_4
#define PINE1_GPIO_Port GPIOB
#define PINF1_Pin GPIO_PIN_5
#define PINF1_GPIO_Port GPIOB
#define PING1_Pin GPIO_PIN_6
#define PING1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
