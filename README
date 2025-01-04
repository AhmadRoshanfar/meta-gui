# meta-GUI

**meta-GUI** is a Yocto meta-layer designed for building Qt-based applications on Wayland. It simplifies the setup and integration process for running GUI applications on embedded systems.

## Features

- Supports Qt-based application development
- Targets the Wayland display server protocol
- Compatible with NanoPi-M4B and other Rockchip-based devices

## Getting Started

### Cloning Repositories

Clone the required Yocto repositories:

```bash
git clone -b scarthgap git://git.yoctoproject.org/poky
git clone -b scarthgap https://github.com/openembedded/meta-openembedded.git
git clone -b scarthgap https://git.yoctoproject.org/meta-arm
git clone -b scarthgap https://git.yoctoproject.org/meta-rockchip
git clone https://github.com/meta-qt5/meta-qt5.git -b scarthgap
```

### Adding Layers

Add the necessary layers to your build configuration:

```bash
cd poky
source oe-init-build-env build
bitbake-layers add-layer ../meta-qt5
bitbake-layers add-layer ../meta-gui
```

### Verifying Layers

Check the added layers using:

```bash
bitbake-layers show-layers
```

### Configuring Local Settings

Edit the `conf/local.conf` file to configure your build:

```bash
vim conf/local.conf
```

Set the following variables:

```plaintext
MACHINE ??= "nanopi-m4b"
distro ="gui-distro"
```

### Building the Image

Build your Yocto image:

```bash
bitbake gui-image
```
