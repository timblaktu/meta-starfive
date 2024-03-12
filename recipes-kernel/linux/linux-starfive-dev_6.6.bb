require linux-mainline-common.inc
FILESEXTRAPATHS =. "${FILE_DIRNAME}/linux-starfive:"
SUMMARY = "StarFive Dubhe kernel recipe"

LIC_FILES_CHKSUM = "file://COPYING;md5=6bc538ed5bd9a7fc9398086aedcd7e46"
KERNEL_VERSION_SANITY_SKIP = "1"

SRCREV = "${AUTOREV}"
BRANCH = "master"

FORK:starfive-dubhe = "starfive-tech"
BRANCH:starfive-dubhe = "starfive-6.6.10-dubhe"
SRCREV:starfive-dubhe = "c657db3b77ea6a5406ff86fd0b1aa4ce26b45c7e"

FORK:starfive-jh8100 = "starfive-tech"
BRANCH:starfive-jh8100 = "starfive-6.6.10-dev-jh8100"
SRCREV:starfive-jh8100 = "0272068c64b55a16d32da216913f8558f94bee5c"

LINUX_VERSION ?= "6.6.10"
LINUX_VERSION:starfive-dubhe = "6.6.10"
LINUX_VERSION:starfive-jh8100 = "6.6.10"

LINUX_VERSION_EXTENSTION:append:starfive-dubhe = "-starlight"

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:starfive-dubhe = " \
        git://github.com/${FORK}/linux.git;protocol=https;branch=${BRANCH} \
        file://cpio.cfg \
        "

SRC_URI:starfive-jh8100 = "\
	git://github.com/${FORK}/linux.git;protocol=https;branch=${BRANCH} \
	"

INITRAMFS_IMAGE_BUNDLE:starfive-dubhe = "1"
INITRAMFS_IMAGE:starfive-dubhe = "dubhe-image-initramfs"

KBUILD_DEFCONFIG:starfive-dubhe = "starfive_dubhe_defconfig"
KBUILD_DEFCONFIG:starfive-jh8100 = "jh8100_defconfig"

COMPATIBLE_MACHINE = "(starfive-dubhe|starfive-jh8100)"

FILES:${KERNEL_PACKAGE_NAME}-base += "/usr/*"
