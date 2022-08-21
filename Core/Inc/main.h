/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
/* USER CODE BEGIN Private defines */
#define KEYPAD_COL_0_GPIO       GPIOA
#define KEYPAD_COL_0_PIN        GPIO_PIN_0
#define KEYPAD_COL_1_GPIO       GPIOA
#define KEYPAD_COL_1_PIN        GPIO_PIN_1
#define KEYPAD_COL_2_GPIO       GPIOA
#define KEYPAD_COL_2_PIN        GPIO_PIN_2
#define KEYPAD_COL_3_GPIO       GPIOA
#define KEYPAD_COL_3_PIN        GPIO_PIN_3
#define KEYPAD_ROW_0_GPIO       GPIOA
#define KEYPAD_ROW_0_PIN        GPIO_PIN_4
#define KEYPAD_ROW_1_GPIO       GPIOA
#define KEYPAD_ROW_1_PIN        GPIO_PIN_5
#define KEYPAD_ROW_2_GPIO       GPIOA
#define KEYPAD_ROW_2_PIN        GPIO_PIN_6
#define KEYPAD_ROW_3_GPIO       GPIOA
#define KEYPAD_ROW_3_PIN        GPIO_PIN_7
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
