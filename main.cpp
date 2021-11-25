/*
 * Copyright (c) 2021, Koncepto.io
 * SPDX-License-Identifier: Apache-2.0
 */
#include "as621x/as621x.h"
#include "mbed.h"

namespace {
#define WAIT 1000ms
}

using namespace sixtron;

static DigitalOut led1(LED1);

int main()
{
    AS621X::Config_t cfg;
    double t;

    I2C i2c(I2C_SDA, I2C_SCL);
    i2c.frequency(100000);
    AS621X sensor(&i2c, AS621X::Add1Pin::SCL, AS621X::Add0Pin::VSS);

    printf("\n\n-------------------\n");
    printf("--- AS621X Demo ---\n");

    printf("Alert pin is %senabled.\n", sensor.is_alert_enabled() ? "" : "not ");
    sensor.read_config(&cfg);
    cfg.cr = sixtron::AS621X::ConversionRate::_125ms;
    sensor.write_config(&cfg);

    sensor.read_temperature(AS621X::RegisterAddress::THigh, &t);
    printf("THigh: %lf\n", t);

    sensor.read_temperature(AS621X::RegisterAddress::TLow, &t);
    printf("TLow: %lf\n", t);

    while (true) {
        led1 = !led1;

        sensor.read_temperature(AS621X::RegisterAddress::Tval, &t);
        printf("Temperature: %lf\n", t);

        ThisThread::sleep_for(WAIT);
    }
}
