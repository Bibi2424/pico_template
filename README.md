# Pico Template

Simple project for the Pi Pico to serve as template.

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