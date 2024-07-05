require linux-mainline-common.inc
FILESEXTRAPATHS =. "${FILE_DIRNAME}/linux-starfive:"
SUMMARY = "StarFive Dubhe kernel recipe"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"
KERNEL_VERSION_SANITY_SKIP = "1"

SRCREV = "${AUTOREV}"
BRANCH = "master"

FORK:starfive-dubhe = "starfive-tech"
BRANCH:starfive-dubhe = "starfive-6.6.31-dubhe"
SRCREV:starfive-dubhe = "6c96d5ea01245001abf386db780cd14584d1df7c"

FORK:starfive-jh8100 = "starfive-tech"
BRANCH:starfive-jh8100 = "starfive-6.6.10-dev-external-jh8100"
SRCREV:starfive-jh8100 = "9da8129da97b9fb9fb1662475935f52e546b9385"

LINUX_VERSION ?= "6.6.10"
LINUX_VERSION:starfive-dubhe = "6.6.31"
LINUX_VERSION:starfive-jh8100 = "6.6.10"

LINUX_VERSION_EXTENSTION:append:starfive-dubhe = "-starlight"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:starfive-dubhe = " \
        git://github.com/${FORK}/linux.git;protocol=https;branch=${BRANCH} \
        file://cpio.cfg \
        "

SRC_URI:starfive-jh8100 = "\
	git://github.com/${FORK}/linux.git;protocol=https;branch=${BRANCH} \
	file://jh8100.cfg \
	"

INITRAMFS_IMAGE_BUNDLE:starfive-dubhe = "1"
INITRAMFS_IMAGE:starfive-dubhe = "dubhe-image-initramfs"

KBUILD_DEFCONFIG:starfive-dubhe = "starfive_dubhe_defconfig"
KBUILD_DEFCONFIG:starfive-jh8100 = "jh8100_defconfig"

COMPATIBLE_MACHINE = "(starfive-dubhe|starfive-jh8100)"

FILES:${KERNEL_PACKAGE_NAME}-base += "/usr/*"
