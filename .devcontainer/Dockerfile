# [Choice] Debian / Ubuntu version: debian-10, debian-9, ubuntu-20.04, ubuntu-18.04
ARG VARIANT=buster
FROM mcr.microsoft.com/vscode/devcontainers/cpp:0-${VARIANT}

# Install QMK dependencies
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    build-essential \
    gcc \
    unzip \
    wget \
    zip \
    gcc-avr \
    binutils-avr \
    avr-libc \
    avrdude \
    dfu-programmer \
    dfu-util \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    git \
    clang-format \
    libusb-dev \
    teensy-loader-cli \
    python-pip-whl \
    python3.7-dev \
    python3-pip \
    python3-setuptools \
    python3-wheel
