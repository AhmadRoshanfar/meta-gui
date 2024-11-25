SUMMARY = "custom linux image for R-Scan device with egl driver for fast boot"
LICENSE= "CLOSED"

inherit core-image

# IMAGE_FSTYPES += "wic.gz squashfs"
# IMAGE_INSTALL:remove = "psplash"

IMAGE_LINGUAS = "en-us"

INITRAMFS_IMAGE = "core-image-minimal-initramfs"
MACHINE_FEATURES:remove = "qemu-usermode" 
MACHINE_FEATURES:append = "touchscreen screen"

DEVELOPMENT_FEATURES  = "debug-tweaks ssh-server-dropbear qtcreator-debug tools-debug"
IMAGE_FEATURES += "${DEVELOPMENT_FEATURES}"

PACKAGEGROUP_INSTALL    = "packagegroup-core-boot"
QT_DEVELOPMENT_INSTALL  = "qtbase qtquickcontrols-qmlplugins qtdeclarative qtquickcontrols2 qtcharts qtvirtualkeyboard "
DEVELOPMENT_INSTALL     = "rsync openssh-sftp-server read-edid edid-decode libdrm libdrm-tests zsh git systemd-analyze coreutils"
DEPLOYMENT_INSTALL      = "custom-fonts test testsystemd static-ip"
# SPLASH_INSTALL        = "dracut plymouth"
IMAGE_INSTALL += " ${PACKAGEGROUP_INSTALL}   \
                   ${DEPLOYMENT_INSTALL}     \
                   ${QT_DEVELOPMENT_INSTALL} \
                   ${DEVELOPMENT_INSTALL}    \
                 "

# IMAGE_INSTALL:append = " psplash-drm"
# PREFERRED_PROVIDER_virtual/psplash = "psplash-drm"
# PREFERRED_PROVIDER_virtual/psplash = "plymouth"
# SPLASH = "plymouth"

# KERNEL_CMDLINE:append = " quiet initcall_debug  drm_kms_helper.edid_firmware=edid/1280x1024.bin"

