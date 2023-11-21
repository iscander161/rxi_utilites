/**
 * @file rxi_utils.cpp
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Source file of RXI utilities
 * @version 0.1
 * @date 2023-11-21
 * @copyright Copyright (c) 2023
 */

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "rxi_utils.h"

/*
 *
 */
eRxiUtilsErrorCode rxiUtilNiosQSysXml(std::string pathToQSysFile, std::string pathToHexFile, std::string HexFileName)
{
    /* Variables */
    std::string resultString = "<parameter name=\"initializationFileName\">" + pathToHexFile + "\\" + HexFileName + ".hex</parameter>";
    std::string searchString = HexFileName + ".hex";        /*!< String for search */
    std::stringstream inSS;                                 /*!< Input string stream */
    std::stringstream outSS;                                /*!< Output string stream */
    std::ofstream qSysFile;                                 /*!< Input file object */
    std::string tempLine;                                   /*!< String for temporary line */
    unsigned long lineSpaceCount;                           /*!< Space count in line for XML-struct safety */

    std::cout << "Searching substring to replace is " << std::endl << searchString << std::endl;

    /* Input file */
    qSysFile.open(pathToQSysFile, std::ios::in);
    if(!qSysFile.is_open())
    {
        std::cout << "Error: Can't open file for reading " << pathToQSysFile << std::endl;
        return RXI_ERROR__OPEN_FILE_ERROR;
    }

    /* Search nessesary string */
    inSS << qSysFile.rdbuf();
    while(!inSS.eof())
    {
        std::getline(inSS, tempLine);

        if(tempLine.find(searchString) != std::string::npos)
        {
            /* XML struct safety */
            lineSpaceCount = tempLine.find_first_not_of("\t ", 0);
            resultString.insert(0, std::string(lineSpaceCount, ' '));
            std::cout << "Result string is " << std::endl << resultString << std::endl;
            tempLine = resultString;    // Replace string
        }
        outSS << tempLine + "\n";
    }

    /* Reopen file for writing data */
    qSysFile.close();
    qSysFile.open(pathToQSysFile, std::ios::out | std::ios::trunc);
    if(!qSysFile.is_open())
    {
        std::cout << "Error: Can't open file for writing " << pathToQSysFile << std::endl;
        return RXI_ERROR__OPEN_FILE_ERROR;
    }

    qSysFile << outSS.rdbuf();
    qSysFile.close();

    return RXI_ERROR__OK;
}
