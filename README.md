# Pico Template

Simple project for the Pi Pico to serve as template. The application is actually the `blink` project from [pico-examples](https://github.com/raspberrypi/pico-examples).

# Initial config

Most of the steps are close to the official [Getting Started guide](https://datasheets.raspberrypi.org/pico/getting_started_with_pico.pdf). I did not used the `pico_setup.sh` because I didn't wanted to use VSCode.

For Windows, I used [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) with Debian (Ubuntu should also be fine) and can pretty much follow the official procedure for Linux.

I also decided to use Ninja instead of Make but there should be no differences.

```bash
sudo apt update
sudo apt install cmake gcc-arm-none-eabi libnewlib-arm-none-eabi build-essential ninja-build
```

Then go into this template folder and init all submodules

```bash
git submodule update --init --recursive
```

# Generate and Build

Run cmake to generate build files

```bash
cmake -Bbuild -G "Ninja"
```

Go into build directory and build the project

```bash
cd build
ninja
```

The uf2 file will be located in `build/src/PicoTemplate.uf2`.
Simply copy this file to the RPi folder after connecting a usb cable to the Pi Pico while holding the BOOTSEL button.


# PicoProbe

Follow instructions to build openocd and install gdb(-multiarch). I can confirm that it works on WSL.

To pass the usb from Windows to linux, use [usbipd](https://learn.microsoft.com/en-ca/windows/wsl/connect-usb#attach-a-usb-device).

## Openocd

```bash
sudo src/openocd -f interface/cmsis-dap.cfg -c "adapter speed 5000" -f target/rp2040.cfg -s tcl
```

## GDB

```bash
gdb-multiarch src/<application-name>.elf
```

```gdb
target remote localhost:3333
load
monitor reset init
continue
```

Then use [gdb commands](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
