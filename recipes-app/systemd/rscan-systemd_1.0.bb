LICENSE = "CLOSED"
inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} = "run-rscan.service"

SRC_URI:append = " file://run-rscan.service "
FILES:${PN} += "${systemd_unitdir}/system/run-rscan.service"

do_install:append() {
  install -d ${D}/${systemd_unitdir}/system
  install -m 0644 ${WORKDIR}/run-rscan.service ${D}/${systemd_unitdir}/system
}
