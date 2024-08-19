SUMMARY = "Hello recipe"
DESCRIPTION = "shows a hello world message at console"
LICENSE = "CLOSED"

python do_display_banner() {
    bb.plain("***********************************************");
    bb.plain("*                                             *");
    bb.plain("*             Hello recipe                    *");
    bb.plain("*                                             *");
    bb.plain("***********************************************");
}

SECTION = "examples"
SRC_URI = "file://hello.c"
S = "${WORKDIR}"

do_compile(){
    ${CC} ${CFLAGS} ${LDFLAGS} hello.c -o hello
}

do_install(){
    install -d ${D}${bindir}
    install -m 0755 hello ${D}${bindir}/
}

addtask display_banner before do_build

FILES_${PN} += "${bindir}"

