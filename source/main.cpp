/**
 * @file main.cpp
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Main file of RXI-utility application
 * @version 0.1
 * @date 2023-11-21
 * @copyright Copyright (c) 2023
 */

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include "app_args.h"
#include "rxi_utils.h"

/* Private function prototypes -----------------------------------------------*/
static int app_exit();

/**
 * @brief Main function of application
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return - result of function
 */
int main(int argc, char** argvs)
{
    if(argc == 0x01){
        std::cout << "No arguments provided. Nothing to do yet." << std::endl;
        return EXIT_SUCCESS;
    }

    if(argc != 0x04){
        std::cout << "Arguments error." << std::endl;
        return EXIT_SUCCESS;
    }

    rxiUtilNiosQSysXml(argvs[1], argvs[2], argvs[3]);

    return EXIT_SUCCESS;
}

static int app_exit()
{
    std::cout << "Press any key to continue..." << std::endl;
    getchar();
    return EXIT_SUCCESS;
}
