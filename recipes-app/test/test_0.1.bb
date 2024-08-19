SUMMARY = "Qt5 smarthome QML demo application"
DESCRIPTION = "This is the Smarthome QML demo application. It shows some user interfaces for controlling an automated house"
HOMEPAGE = "http://www.basyskom.com/news/143-demos-qt5-port.html"
LICENSE = "CLOSED"

DEPENDS = "qtdeclarative "

#SRC_URI = "file://src"

SRC_URI = "git://github.com/AhmadRoshanfar/yocto.git;protocol=https;branch=main"
SRCREV = "${AUTOREV}"
PV = "1.0"

S = "${WORKDIR}/git"

#S = "${WORKDIR}/src"

require recipes-qt/qt5/qt5.inc

do_install() {
    install -d ${D}${datadir}/${P}
    install -m 0755 ${B}/test ${D}${datadir}/${P}
    install -d ${D}${sysconfdir}/init.d
    install -m 755 test ${D}${sysconfdir}/init.d/test
}

FILES:${PN} += "${datadir}"

inherit update-rc.d
INITSCRIPT_NAME="test"
INITSCRIPT_PARAMS= "defaults 10"
