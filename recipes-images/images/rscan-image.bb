SUMMARY = "custom linux image for R-Scan device"
LICENSE= "CLOSED"

inherit core-image

# IMAGE_FSTYPES += "wic.gz squashfs"

IMAGE_LINGUAS = "en-us"

MACHINE_FEATURES:remove = "qemu-usermode" 
MACHINE_FEATURES:append = "touchscreen screen"

DISTRO_FEATURES:remove = "3g x11 bluetooth pulseaudio gstreamer wifi nfc vulkan nfs ipv6 ext2 alsa acl"
DISTRO_FEATURES:append = "pam wayland"

DEPLOYMENT_FEATURES   = "splash weston"
DEVELOPMENT_FEATURES  = "debug-tweaks ssh-server-dropbear qtcreator-debug tools-debug"
IMAGE_FEATURES += "${DEVELOPMENT_FEATURES} \
                   ${DEPLOYMENT_FEATURES} "

PACKAGEGROUP_INSTALL = "packagegroup-core-boot"
QT_INSTALL           = "qtbase qtquickcontrols-qmlplugins qtdeclarative qtquickcontrols2 qtcharts qtvirtualkeyboard qtwayland "
DEVELOPMENT_INSTALL  = "rsync openssh-sftp-server read-edid edid-decode libdrm libdrm-tests zsh git"
DEPLOYMENT_INSTALL   = "usbutils custom-fonts test coreutils wayland weston-xwayland "

IMAGE_INSTALL += " ${PACKAGEGROUP_INSTALL} \
                   ${DEPLOYMENT_INSTALL}   \
                   ${QT_INSTALL}           \
                   ${DEVELOPMENT_INSTALL}  \
                 "

KERNEL_CMDLINE:append = " quiet initcall_debug  drm_kms_helper.edid_firmware=edid/1280x1024.bin"
