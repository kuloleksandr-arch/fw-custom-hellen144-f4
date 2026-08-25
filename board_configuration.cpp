#include "pch.h"
#include "hellen_meta.h"
#include "defaults.h"
#include "board_overrides.h"

static void customBoardDefaultConfiguration() {

    // Keep the existing Hellen F4 hardware defaults
    setHellenVbatt();
    setHellenCan();
    setDefaultHellenAtPullUps();

    // ------------------------------------------------------------
    // CAN1
    // ------------------------------------------------------------

    engineConfiguration->canTxPin = Gpio::B6;
    engineConfiguration->canRxPin = Gpio::B12;


    // ------------------------------------------------------------
    // INJECTORS
    // ------------------------------------------------------------

    engineConfiguration->injectionPins[0] = Gpio::B4;
    engineConfiguration->injectionPins[1] = Gpio::B5;
    engineConfiguration->injectionPins[2] = Gpio::B0;
    engineConfiguration->injectionPins[3] = Gpio::B1;


    // ------------------------------------------------------------
    // IGNITION
    // ------------------------------------------------------------

    engineConfiguration->ignitionPins[0] = Gpio::A0;
    engineConfiguration->ignitionPins[1] = Gpio::A1;
    engineConfiguration->ignitionPins[2] = Gpio::A2;
    engineConfiguration->ignitionPins[3] = Gpio::A3;


    // ------------------------------------------------------------
    // CRANK / CAM
    // ------------------------------------------------------------

    engineConfiguration->triggerInputPins[0] = Gpio::C6;
    engineConfiguration->camInputs[0] = Gpio::C7;


    // ------------------------------------------------------------
    // ANALOG INPUTS
    // ------------------------------------------------------------

    engineConfiguration->map.sensor.hwChannel = EFI_ADC_4;
    engineConfiguration->tps1_1AdcChannel = EFI_ADC_5;

    engineConfiguration->clt.adcChannel = EFI_ADC_6;
    engineConfiguration->iat.adcChannel = EFI_ADC_7;

    engineConfiguration->afr.hwChannel = EFI_ADC_10;
    engineConfiguration->vbattAdcChannel = EFI_ADC_11;


    // ------------------------------------------------------------
    // AUXILIARY ANALOG INPUTS
    // ------------------------------------------------------------

    engineConfiguration->auxLinear1.hwChannel = EFI_ADC_12;
    engineConfiguration->auxLinear2.hwChannel = EFI_ADC_13;


    // ------------------------------------------------------------
    // FAN / IDLE / TACHO
    // ------------------------------------------------------------

    engineConfiguration->fanPin = Gpio::B14;
    engineConfiguration->idle.solenoidPin = Gpio::B15;
    engineConfiguration->tachOutputPin = Gpio::E11;


    // ------------------------------------------------------------
    // Basic engine defaults
    // ------------------------------------------------------------

    engineConfiguration->cylindersCount = 4;

    engineConfiguration->ignitionMode = IM_INDIVIDUAL_COILS;

    engineConfiguration->crankingInjectionMode = IM_SIMULTANEOUS;

    engineConfiguration->injectionMode = IM_SEQUENTIAL;
}


void setup_custom_board_overrides() {
    custom_board_DefaultConfiguration = customBoardDefaultConfiguration;
}
