
# EMF
# Effective Multi Microcontroller Framework

EMF stands for **Effective Multi Microcontroller Framework**.
The goal of EMF is to provide standard, efficient and uniform functions for launching different microcontrollers in different compilers.

**EMF_C_CORE** and **EMF_C_EXTENTION** include functions for **C programming language** compilers.

**EMF_CPP_CORE** and **EMF_CPP_EXTENTION** include functions for **C++ programming language** compilers.

## EMF Consists of two main parts:
1) **EMF_C_CORE** and **EMF_CPP_CORE**, which include functions required to standardize the following:
-**Variable Types**

-**Watchdog**

-**MCU Speed ​​+ Restart MCU**

-**Bit Manipulation**

-**GIO**

-**Delay**

-**Button**

-**EEPROM or Write flash**

-**Math + String + Time + TrueFloat + Convert**

2) Other functions will be implemented in folders named **EMF_C_EXTENTION** and **EMF_CPP_EXTENTION**.

All EMF files have their own DNA, which is written at the end of each file name.

The purpose of writing DNA at the end of file names is to quickly identify file matches and overlaps.

Whenever a microcontroller is defined in the Config.h file, a set of Defines (which we have named DNA) is defined, which specify the following:

-IDE name

-Base driver

-Microcontroller grouping

-Microcontroller family

-Microcontroller name

## For example)
When the following main DNA (MCU DNA) is defined in the Config.h file

    #define IAR__HAL__F0__STM32F030X6__STM32F030F4P6

Then other DNAs related to the main DNA will be defined in the following file

EMF.MCU.IAR__HAL__F0__STM32F030X6__STM32F030F4P6.h

Which includes the following:
    //Family DNA!
    #define IAR__HAL__F0__STM32F030X6 (1)

    //Group DNA!
    #define IAR__HAL__F0 (1)

    //Driver DNA!
    #define IAR__HAL (1)

    //IDE DNA!
    #define IAR (1)

These DNAs will help us reduce repetitive coding and also ensure that files created in EMF are compatible with the type of IDE, microcontroller, driver, etc.

All files created in EMF are required to specify their code DNA, both in naming and coding.

- Other proposed standards for EMF are listed in the **Standard.h** file.

- The EMF version is listed in the **EMF.h** file, as well as the project's Git records.

- At the top of each file, the change records for that file are written.


 ## Help : Add EMF Lib to IAR(Genereted Project With Stm32Cube Mx)

1)
Create Project with "STM32Cube Mx"

2)
2-1)
Copy All *.h File From **EMF\EMF_CPP_CORE** and **EMF\EMF_CPP_EXTENTION**  to **Core\Inc** in Main Folder Project

2-2)
Copy All *.cpp File From **EMF\EMF_CPP_CORE** and **EMF\EMF_CPP_EXTENTION** to **Core\Src** in Main Folder Project

3)
Open Project and "Right Click" in Project Name in "Workspace" and **select Add>Add Files
and add All EMF Files**(in Main Folder Project **\Core\Inc"** and **Core\Src** Folders)

4)
Right Click in Project Name in "Workspace" and select "Options..."

4-1)
C/C++ Compiler>Language1 : **select c++**

4-2)
C/C++ Compiler>Encodings:
select All Encoding to "UTF-8"

5)
#include "EMF.h"  in "Main.c"

6)
Open **EMF.Config.h** and UnComment Target MCU define and save file

7)
Add **EMF_init();** in main Function



## Help : Add EMF Lib to Holtek IDE3000

1)
Create New Project in Holtek IDE3000

2)
2-1)Copy All *.h* File From **EMF\EMF_CPP_CORE** and **EMF\EMF_CPP_EXTENTION**  to Main Folder Project

2-2)Copy All *.c File From **EMF\EMF_CPP_CORE** and **EMF\EMF_CPP_EXTENTION** to Main Folder Project

3)
Open Project and "Right Click" in Project Name in "Workspace" and select "Add Files To Project" 
and add All *.h , *.c EMF Files(in Main Folder Project)

4)
#include "EMF.h"  in "Main.c"

5)
Open **EMF.Config.h** and UnComment Target MCU define and save file

6)
Add **EMF_init();** in main Function
## Badges

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)


## Authors

- E.Rahmanian (www.Elecstar.ir) [@ElecStar-ir](https://github.com/elecstar-ir)