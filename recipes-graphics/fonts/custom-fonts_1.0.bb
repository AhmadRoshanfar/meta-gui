SUMMARY = "using custom fonts"
DESCRIPTION = "Adding custom fonts for R-Scan app"
LICENSE = "CLOSED"

# inherit allarch fontcache

FONT_PACKAGES = "${PN}"

SRC_URI = "file://fonts.tar.xz"

do_install () {
        install -d ${D}${datadir}/fonts/custom-fonts
        install -m 644 ${WORKDIR}/*.ttf ${D}${datadir}/fonts/custom-fonts
}

FILES:${PN} = "${datadir}/fonts"
