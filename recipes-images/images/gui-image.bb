SUMMARY = "custom linux image"
LICENSE= "CLOSED"

inherit core-image

# IMAGE_FSTYPES += "wic.gz squashfs"
# INIT_MANAGER = "systemd"
# IMAGE_INSTALL:remove = "psplash"
INITRAMFS_IMAGE = "core-image-minimal-initramfs"

IMAGE_LINGUAS = "en-us"

MACHINE_FEATURES:remove = "qemu-usermode" 
MACHINE_FEATURES:append = "touchscreen screen"

DISTRO_FEATURES:remove = "3g x11 bluetooth pulseaudio gstreamer wifi nfc vulkan nfs ipv6 ext2 alsa acl"
DISTRO_FEATURES:append = "pam wayland"

DEPLOYMENT_FEATURES   = "splash weston"
DEVELOPMENT_FEATURES  = "debug-tweaks ssh-server-dropbear qtcreator-debug tools-debug"
IMAGE_FEATURES += "${DEVELOPMENT_FEATURES} \
                   ${DEPLOYMENT_FEATURES} "


PACKAGEGROUP_INSTALL = "packagegroup-core-boot packagegroup-core-weston"
QT_INSTALL           = "qtbase qtquickcontrols-qmlplugins qtdeclarative qtquickcontrols2 qtcharts qtvirtualkeyboard qtwayland "
DEVELOPMENT_INSTALL  = "rsync openssh-sftp-server read-edid edid-decode libdrm libdrm-tests zsh git"
DEPLOYMENT_INSTALL   = "custom-fonts test  wayland coreutils "
# SPLASH_INSTALL       = "dracut plymouth"
# usbutils coreutils
IMAGE_INSTALL += " ${PACKAGEGROUP_INSTALL} \
                   ${DEPLOYMENT_INSTALL}   \
                   ${QT_INSTALL}           \
                   ${DEVELOPMENT_INSTALL}  \
                 "

# IMAGE_INSTALL:append = " psplash-drm"
# PREFERRED_PROVIDER_virtual/psplash = "psplash-drm"
# PREFERRED_PROVIDER_virtual/psplash = "plymouth"
# SPLASH = "plymouth"

# KERNEL_CMDLINE:append = " quiet initcall_debug  drm_kms_helper.edid_firmware=edid/1280x1024.bin"
