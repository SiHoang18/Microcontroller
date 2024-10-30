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
#define PINA_Pin GPIO_PIN_1
#define PINA_GPIO_Port GPIOA
#define PINB_Pin GPIO_PIN_2
#define PINB_GPIO_Port GPIOA
#define PINC_Pin GPIO_PIN_3
#define PINC_GPIO_Port GPIOA
#define PIND_Pin GPIO_PIN_4
#define PIND_GPIO_Port GPIOA
#define PINE_Pin GPIO_PIN_5
#define PINE_GPIO_Port GPIOA
#define PINF_Pin GPIO_PIN_6
#define PINF_GPIO_Port GPIOA
#define PING_Pin GPIO_PIN_7
#define PING_GPIO_Port GPIOA
#define BUT0_Pin GPIO_PIN_0
#define BUT0_GPIO_Port GPIOB
#define BUT1_Pin GPIO_PIN_1
#define BUT1_GPIO_Port GPIOB
#define BUT2_Pin GPIO_PIN_2
#define BUT2_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_11
#define LED_GPIO_Port GPIOB
#define RED1_Pin GPIO_PIN_8
#define RED1_GPIO_Port GPIOA
#define AMBER1_Pin GPIO_PIN_9
#define AMBER1_GPIO_Port GPIOA
#define GREEN1_Pin GPIO_PIN_10
#define GREEN1_GPIO_Port GPIOA
#define RED2_Pin GPIO_PIN_12
#define RED2_GPIO_Port GPIOA
#define AMBER2_Pin GPIO_PIN_13
#define AMBER2_GPIO_Port GPIOA
#define GREEN2_Pin GPIO_PIN_14
#define GREEN2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_3
#define EN0_GPIO_Port GPIOB
#define EN1_Pin GPIO_PIN_4
#define EN1_GPIO_Port GPIOB
#define EN2_Pin GPIO_PIN_5
#define EN2_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_6
#define EN3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
