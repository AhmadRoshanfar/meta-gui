LICENSE = "CLOSED"
inherit systemd

SYSTEMD_AUTO_ENABLE = "enable"
SYSTEMD_SERVICE:${PN} = "run-test-app.service"

SRC_URI:append = " file://run-test-app.service "
FILES:${PN} += "${systemd_unitdir}/system/run-test-app.service"

do_install:append() {
  install -d ${D}/${systemd_unitdir}/system
  install -m 0644 ${WORKDIR}/run-test-app.service ${D}/${systemd_unitdir}/system
}
