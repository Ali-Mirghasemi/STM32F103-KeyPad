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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "KeyPad.h"
#include "KeyPad_Port.h"
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
static const KeyPad_KeyValue KEYPAD_MAP[] = {
  '7', '8', '9', '/',
  '4', '5', '6', '*',
  '1', '2', '3', '-',
  'O', '0', '=', '+',
};
static const KeyPad_PinConfig KEYPAD_COLS[] = {
  {KEYPAD_COL_0_GPIO, KEYPAD_COL_0_PIN},
  {KEYPAD_COL_1_GPIO, KEYPAD_COL_1_PIN},
  {KEYPAD_COL_2_GPIO, KEYPAD_COL_2_PIN},
  {KEYPAD_COL_3_GPIO, KEYPAD_COL_3_PIN},
};
static const KeyPad_PinConfig KEYPAD_ROWS[] = {
  {KEYPAD_ROW_0_GPIO, KEYPAD_ROW_0_PIN},
  {KEYPAD_ROW_1_GPIO, KEYPAD_ROW_1_PIN},
  {KEYPAD_ROW_2_GPIO, KEYPAD_ROW_2_PIN},
  {KEYPAD_ROW_3_GPIO, KEYPAD_ROW_3_PIN},
};

static const KeyPad_Config KEYPAD_CONFIG = KEYPAD_CONFIG_INIT(KEYPAD_MAP, KEYPAD_COLS, KEYPAD_ROWS);

static KeyPad keypad;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
KeyPad_HandleStatus onPressed(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state);
KeyPad_HandleStatus onHold(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state);
KeyPad_HandleStatus onReleased(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_USART1_UART_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  KeyPad_init(&KEYPAD_DRIVER);
  
  KeyPad_add(&keypad, &KEYPAD_CONFIG);
  KeyPad_onPressed(&keypad, onPressed);
  KeyPad_onHold(&keypad, onHold);
  KeyPad_onReleased(&keypad, onReleased);
  
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  HAL_TIM_Base_Start_IT(&htim2);
  
  HAL_UART_Transmit(&huart1, (uint8_t*) "Running...\r\n", 12, 1000);
  
  while (1)
  {
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
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
KeyPad_HandleStatus onPressed(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state) {
  HAL_UART_Transmit(&huart1, (uint8_t*) &value, sizeof(value), 1); 
  return KeyPad_NotHandled;
}
KeyPad_HandleStatus onHold(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state) {
  
  return KeyPad_NotHandled;
}
KeyPad_HandleStatus onReleased(KeyPad* keypad, KeyPad_KeyValue value, KeyPad_State state) {
  HAL_UART_Transmit(&huart1, (uint8_t*) "\r\n", 2, 10);
  return KeyPad_NotHandled;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim) {
  switch ((uint32_t) htim->Instance) {
    case TIM2_BASE:
      KeyPad_handle();
      break;
  }
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
