# AMS AS621x example
A simple demo using an AS6212 to demonstrate some of the data that can be retrieved.

## Requirements
### Hardware requirements
The following boards are required:
- Zest Sensor T-RH
- Zest Core MTXDot

### Software requirements
AMS AS621x example makes use of the following libraries (automatically
imported by `mbed deploy` or `mbed import`):
- ams-as621x
- zest-core-mtxdot

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target enabling instructions:
```shell
mbed import https://gitlab.com/koncepto/CATIE/3sqair/software/ams-621x-example.git ams-as621x-example
```

Alternatively:

- Clone to "ams-as621x-example" and enter it:
  ```shell
  git clone https://gitlab.com/koncepto/CATIE/3sqair/software/ams-621x-example.git ams-as621x-example
  cd ams-as621x-example
  ```

- Deploy software requirements with:
  ```shell
  mbed deploy
  ```

Enable the custom target:
```shell
cp zest-core-mtxdot/custom_targets.json .
```

Compile the project:
```shell
mbed compile
```

Program the target device with a Segger J-Link debug probe and
[`sixtron_flash`](https://github.com/catie-aq/6tron-flash) tool:
```shell
sixtron_flash stm32l151cc BUILD/ZEST_CORE_MTXDOT/GCC_ARM/ams-as621x-example.elf
```

Debug on the target device with the probe and Segger
[Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger)
software.
