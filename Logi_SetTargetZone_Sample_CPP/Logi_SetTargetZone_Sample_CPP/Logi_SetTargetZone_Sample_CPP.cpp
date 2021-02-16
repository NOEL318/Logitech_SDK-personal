//Logitech G213
//Compilar en Visual Studio como proyecto
#include "stdafx.h"
#include "LogitechLEDLib.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
    //Iniciar LED SDK
    bool LedInitialized = LogiLedInitWithName("SetTargetZone Sample C++");
	//estatus
    if (!LedInitialized)
    {
//si está mal poner un mensaje
        std::cout << "LogiLedInit() failed." << std::endl;
//finalizar programa
        return 0;
    }
//si sale bien mostrar mensaje
    std::cout << "LED SDK Initialized" << std::endl;
//Seteat los colores al iniciar el sistema de leds
    
LogiLedSetTargetDevice(LOGI_DEVICETYPE_ALL);

    //Se muestran los colores en las zonas 1,2,3,4 y 5
    LogiLedSetLighting(0, 0, 0);
//for aun en desarrollo para animación
    /*for (int i = 1; i <= 100;i++) {
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, i, 100, 0, 0);
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 2, 100, 100, 100);
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 3, 0, 100, 0);
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 4, 0, 100, 100);
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 5, 0, 0, 0);
    }
*/
//While que enciende y apaga en color blanco la sección 5 (teclado numerico)
    while(1){

        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 5, 0, 0, 0);
        LogiLedSetLightingForTargetZone(LogiLed::DeviceType::Keyboard, 5, 100, 100, 100);
}
//Finaliza while
    std::cout << "Press \"ENTER\" to continue...";
    std::cin.ignore();
//Apaga las luces mensaje
    std::cout << "LED SDK Shutting down" << std::endl;
//Apaga el sistema de iluminación
    LogiLedShutdown();
//Se detiene la ejecución 
    return 0;
}

