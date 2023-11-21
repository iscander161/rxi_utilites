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

/**
 * @brief Main function of application
 * @param argc - number of arguments
 * @param argv - array of arguments
 * @return - result of function
 */
int main(int argc, char** argv)
{
    if(argc == 0x02){
        std::cout << "No arguments provided. Nothing to do yet." << std::endl;
        std::cout << "Press any key to continue..." << std::endl;
        getchar();
        return EXIT_SUCCESS;
    }
    rxiUtilNiosQSysXml("cpu.qsys", "D:\\Folder", "dps_ctrl_ch16");
    return EXIT_SUCCESS;
}
