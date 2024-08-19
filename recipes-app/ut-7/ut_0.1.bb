SUMMARY = "Qt5 smarthome QML demo application"
DESCRIPTION = "This is the Smarthome QML demo application. It shows some user interfaces for controlling an automated house"
HOMEPAGE = "http://www.basyskom.com/news/143-demos-qt5-port.html"
LICENSE = "CLOSED"

DEPENDS = "qtdeclarative qtquickcontrols2 qtcharts"

SRC_URI = "file://src"

S = "${WORKDIR}/src"

require recipes-qt/qt5/qt5.inc

do_install() {
    install -d ${D}${datadir}/${P}
    install -m 0755 ${B}/ut ${D}${datadir}/${P}
}

FILES:${PN} += "${datadir}"

