SUMMARY = "Static network configuration"
LICENSE = "CLOSED"
SRC_URI = "file://70-static.network"

do_install() {
    install -d ${D}/etc/systemd/network
    install -m 0644 ${WORKDIR}/70-static.network ${D}/etc/systemd/network/
}

FILES_${PN} = "/etc/systemd/network/70-static.network"