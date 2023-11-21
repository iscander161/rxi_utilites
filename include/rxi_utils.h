/**
 * @file rxi_utils.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Header file of RXI utilities
 * @version 0.1
 * @date 2023-11-21
 * @copyright Copyright (c) 2023
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _RXI_UTILS_H_
#define _RXI_UTILS_H_

/* Includes ------------------------------------------------------------------*/

/**
 * @brief Enum of RXI-Utils error codes
 */
typedef enum RxiUtilsErrorCode{
    RXI_ERROR__OPEN_FILE_ERROR = -2,    /*!< Open file error */
    RXI_ERROR__ERROR = -1,              /*!< Unknown error */
    RXI_ERROR__OK = 0,                  /*!< Everything is OK */
}eRxiUtilsErrorCode;

/**
 * @brief
 * @param pathToQSysFile
 * @param pathToFile
 * @param HexFileName
 * @return - result of
 */
eRxiUtilsErrorCode rxiUtilNiosQSysXml(std::string pathToQSysFile, std::string pathToHexFile, std::string HexFileName);

#endif /* _RXI_UTILS_H_ */
