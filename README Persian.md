EMF مخفف Effective Multi Microcontroller Framework است.
هدف EMF فراهم کردن توابعی استاندارد ، موثر و هم سان برای راه اندازی میکروکنترلر های مختلف در کامپایلرهای مختلف است.

EMF_C _CORE و EMF_C_EXTENTION  شامل توابع کامپایلرهای به زبان برنامه نویسی C 
و EMF_CPP_CORE و EMF_CPP_EXTENTION شامل توابع کامپایلرهای به زبان برنامه نویسی C ++
می باشد 

EMF  از دو بخش اصلی تشکیل شده است :
۱) EMF_C _CORE   و  EMF_CPP_CORE ، شامل توابع مورد نیاز جهت استاندارد سازی موارد زیر می باشد :
-Variable Types
-Watchdog
-MCU Speed + Restart MCU
-Bit Manipulation
-GIO
-Delay
-Button
-EEPROM or Write flash
-Math + String + Time + TrueFloat + Convert

۲) سایر توابع در پوشه هایی با نام EMF_C_EXTENTION و  EMF_CPP_EXTENTION پیاده سازی خواهد شد.

تمام فایلهای EMF ،  دارای DNA مربوط به خود هستند که در آخر نام هر فایل نوشته شده اند.
هدف از نوشتن DNA  در انتهای نام فایلها این است که همخوانی و همپوشانی فایلها به سرعت قابل تشخیص باشد.

هر گاه  میکروکنترلر در فایل Config.h تعیین می شود ، مجموعه ای از Define ها ( که ما آن را DNA اسم گذاری کرده ایم ) تعریف می شود ، که این DNA ها موارد زیر را مشخص می کند
-نام IDE
-درایور مبنا
-گروه بندی میکروکنترلر
-خانواده  میکروکنترلر
-نام میکروکنترلر

مثلا)
زمانی که  در فایل Config.h  ، دی ان ای  اصلی (MCU DNA) زیر تعریف می شود
IAR__HAL__F0__STM32F030X6__STM32F030F4P6

آنگاه سایر DNA های مربوط  به  دی ان ای اصلی ، در فایل زیر مشخص خواهند شد 
EMF.MCU.IAR__HAL__F0__STM32F030X6__STM32F030F4P6.h

که شامل موارد زیر می باشد:
    //MCU DNA!
    IAR__HAL__F0__STM32F030X6__STM32F030F4P6 (1)

    //Family DNA!
    IAR__HAL__F0__STM32F030X6 (1)

    //Driver DNA!
    IAR__HAL__F0 (1)

    //IDE DNA!
    IAR (1)

این DNA ها به ما کمک خواهند کرد که کدنویسی تکراری کاهش یابد و همچنین همخوانی فایلهای ایجاد شده در EMF با نوع IDE ، میکروکنترلر ، درایور و ... مشخص باشد.

تمامی فایلهای ایجاد شده در EMF موظف هستند که چه در نام گذاری و چه در کد نویسی ، DNA کد خود را مشخص کنند.

- سایر استانداردهای پیشنهادی برای EMF در فایل Standard.h ذکر شداند.
- ورژن EMF در فایل EMF.h  و همچنین سوابق Git پروژه ذکر شده است.
 - در بالای هر فایل ، سوابق تغییرات مربوط به آن فایل نوشته شده است.


 Help : Add EMF Lib to IAR(Genereted Project With Stm32Cube Mx)
==============================================================
1)Create Project with "STM32Cube Mx"
2)
2-1)Copy All *.h File From "EMF\EMF_CPP_CORE" and "EMF\EMF_CPP_EXTENTION"  to "Core\Inc" in Main Folder Project
2-2)Copy All *.cpp File From "EMF\EMF_CPP_CORE" and "EMF\EMF_CPP_EXTENTION" to "Core\Src" in Main Folder Project
3)Open Project and "Right Click" in Project Name in "Workspace" and select Add>Add Files
and add All EMF Files(in Main Folder Project "\Core\Inc" and "Core\Src" Folders)
4)Right Click in Project Name in "Workspace" and select "Options..."
4-1)C/C++ Compiler>Language1 : select c++
4-2)C/C++ Compiler>Encodings:
select All Encoding to "UTF-8"
5)#include "EMF.h"  in "Main.c"
6)Open "EMF.Config.h and UnComment Target MCU define and save file
7)Add EMF_init(); in main Function



Help : Add EMF Lib to IDE3000
=============================
1)Create New Project in IDE3000
2)
2-1)Copy All *.h File From "EMF\EMF_CPP_CORE" and "EMF\EMF_CPP_EXTENTION"  to Main Folder Project
2-2)Copy All *.c File From "EMF\EMF_CPP_CORE" and "EMF\EMF_CPP_EXTENTION" to Main Folder Project
3)Open Project and "Right Click" in Project Name in "Workspace" and select "Add Files To Project" 
and add All *.h , *.c EMF Files(in Main Folder Project)
4)#include "EMF.h"  in "Main.c"
5)Open "EMF.Config.h and UnComment Target MCU define and save file
7)Add EMF_init(); in main Function