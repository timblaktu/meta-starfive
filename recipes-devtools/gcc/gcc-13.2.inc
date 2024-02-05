require gcc-common.inc

# Third digit in PV should be incremented after a minor release

PV = "13.2.0"

# BINV should be incremented to a revision after a minor gcc release

BINV = "13.2.0"

FILESEXTRAPATHS =. "${FILE_DIRNAME}/gcc:${FILE_DIRNAME}/gcc/backport:"

DEPENDS =+ "mpfr gmp libmpc zlib zstd flex-native"
NATIVEDEPS = "mpfr-native gmp-native libmpc-native zlib-native flex-native zstd-native"

LICENSE = "GPL-3.0-with-GCC-exception & GPL-3.0-only"

LIC_FILES_CHKSUM = "\
    file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
    file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
    file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
    file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1 \
    file://COPYING.RUNTIME;md5=fe60d87048567d4fe8c8a0ed2448bcc8 \
"
# snapshot from git
#RELEASE ?= "9b6bf076c11cba0f9ccdace63e8b4044b1a858ea"
#BASEURI ?= "https://git.linaro.org/toolchain/gcc.git/snapshot/gcc-${RELEASE}.tar.gz"
#SOURCEDIR = "gcc-${RELEASE}"
#BASEURI ?= "https://repo.or.cz/official-gcc.git/snapshot/${RELEASE}.tar.gz;downloadfilename=gcc-${PV}-${RELEASE}.tar.gz"
#SOURCEDIR ?= "official-gcc-${@'${RELEASE}'[0:7]}"

# from snapshot
#RELEASE ?= "13-20230520"
#SOURCEDIR ?= "gcc-${RELEASE}"
#BASEURI ?= "https://gcc.gnu.org/pub/gcc/snapshots/${RELEASE}/gcc-${RELEASE}.tar.xz"

# official release
RELEASE ?= "${PV}"
BASEURI ?= "${GNU_MIRROR}/gcc/gcc-${PV}/gcc-${PV}.tar.xz"
SOURCEDIR ?= "gcc-${PV}"

SRC_URI = "${BASEURI} \
           file://0001-RISC-V-Add-stub-support-for-existing-extensions-priv.patch \
           file://0002-PATCH-1-5-RISC-V-Recognize-Zicond-extension.patch \
           file://0003-PATCH-2-5-RISC-V-Generate-Zicond-instruction-for-bas.patch \
           file://0004-PATCH-3-5-RISC-V-RISC-V-Conditional-Move-costing-was.patch \
           file://0005-committed-RISC-V-Avoid-sub-word-mode-comparisons-wit.patch \
           file://0006-PATCH-3-5-RISC-V-Cost-model-for-Zicond.patch \
           file://0007-committed-RISC-V-Fix-20010221-1.c-with-zicond.patch \
           file://0008-committed-RISC-V-Remove-errant-hunk-of-code.patch \
           file://0009-PATCH-3-5-RISC-V-Generate-Zicond-instruction-for-sel.patch \
           file://0010-PATCH-v3-RISC-V-Generate-Zicond-instruction-for-sele.patch \
           file://0011-committed-RISC-V-Handle-more-cases-in-riscv_expand_c.patch \
           file://0012-committed-RISC-V-Fix-bug-in-condition-canonicalizati.patch \
           file://0013-committed-RISC-V-Fix-minor-testsuite-problem-with-zi.patch \
           file://0014-RISC-V-Use-splitter-to-generate-zicond-in-another-ca.patch \
           file://0015-RISC-V-zicond-Fix-opt2-pattern.patch \
           file://0016-RISC-V-Fix-Zicond-ICE-on-large-constants.patch \
           file://0017-RISC-V-typo-add-closing-paren-to-a-comment.patch \
           file://0018-RISC-V-Add-support-for-XVentanaCondOps-reusing-Zicon.patch \
           file://0019-RISC-V-Add-Types-to-Un-Typed-Zicond-Instructions.patch \
           file://0020-RISC-V-Add-zicond-tests.patch \
           file://0021-Fix-INSN-costing-and-more-zicond-tests.patch \
           file://0022-RISC-V-Rework-branch-costing-model-for-if-conversion.patch \
           file://0023-RISC-V-Also-invert-the-cond-move-condition-for-GEU-a.patch \
           file://0024-RISC-V-Avoid-extraneous-EQ-or-NE-operation-in-cond-m.patch \
           file://0025-RISC-V-Fold-all-the-cond-move-variants-together.patch \
           file://0026-RISC-V-Provide-FP-conditional-branch-instructions-fo.patch \
           file://0027-add-multilib-config-for-baremetal.patch \
           file://0028-add-b-extension-support.patch \
           file://0029-RISC-V-Handle-different-sigcontext-struct-layout.patch \
           file://0030-RISCV-default-enable-align-functions-16-and-align-lo.patch \
           file://0001-gcc-4.3.1-ARCH_FLAGS_FOR_TARGET.patch \
           file://0002-gcc-poison-system-directories.patch \
           file://0003-64-bit-multilib-hack.patch \
           file://0004-Pass-CXXFLAGS_FOR_BUILD-in-a-couple-of-places-to-avo.patch \
           file://0005-Use-the-defaults.h-in-B-instead-of-S-and-t-oe-in-B.patch \
           file://0006-cpp-honor-sysroot.patch \
           file://0007-Define-GLIBC_DYNAMIC_LINKER-and-UCLIBC_DYNAMIC_LINKE.patch \
           file://0008-libtool.patch \
           file://0009-gcc-armv4-pass-fix-v4bx-to-linker-to-support-EABI.patch \
           file://0010-Use-the-multilib-config-files-from-B-instead-of-usin.patch \
           file://0011-aarch64-Fix-include-paths-when-S-B.patch \
           file://0012-Avoid-using-libdir-from-.la-which-usually-points-to-.patch \
           file://0013-Ensure-target-gcc-headers-can-be-included.patch \
           file://0014-Don-t-search-host-directory-during-relink-if-inst_pr.patch \
           file://0015-libcc1-fix-libcc1-s-install-path-and-rpath.patch \
           file://0016-handle-sysroot-support-for-nativesdk-gcc.patch \
           file://0017-Search-target-sysroot-gcc-version-specific-dirs-with.patch \
           file://0018-Add-ssp_nonshared-to-link-commandline-for-musl-targe.patch \
           file://0019-Re-introduce-spe-commandline-options.patch \
           file://0020-libgcc_s-Use-alias-for-__cpu_indicator_init-instead-.patch \
           file://0021-gentypes-genmodes-Do-not-use-__LINE__-for-maintainin.patch \
           file://0022-libatomic-Do-not-enforce-march-on-aarch64.patch \
           file://0023-Fix-install-path-of-linux64.h.patch \
           file://0024-Avoid-hardcoded-build-paths-into-ppc-libgcc.patch \
           file://0025-gcc-testsuite-tweaks-for-mips-OE.patch \
           file://CVE-2023-4039.patch \
           file://0026-aarch64-Fix-loose-ldpstp-check-PR111411.patch \
"
SRC_URI[sha256sum] = "e275e76442a6067341a27f04c5c6b83d8613144004c0413528863dc6b5c743da"

S = "${TMPDIR}/work-shared/gcc-${PV}-${PR}/${SOURCEDIR}"
B = "${WORKDIR}/gcc-${PV}/build.${HOST_SYS}.${TARGET_SYS}"

# Language Overrides
FORTRAN = ""
JAVA = ""

SSP ?= "--disable-libssp"
SSP:mingw32 = "--enable-libssp"

EXTRA_OECONF_BASE = "\
    ${SSP} \
    --enable-libitm \
    --enable-lto \
    --disable-bootstrap \
    --with-system-zlib \
    ${@'--with-linker-hash-style=${LINKER_HASH_STYLE}' if '${LINKER_HASH_STYLE}' else ''} \
    --enable-linker-build-id \
    --with-ppl=no \
    --with-cloog=no \
    --enable-checking=release \
    --enable-cheaders=c_global \
    --without-isl \
"

EXTRA_OECONF_INITIAL = "\
    --disable-libgomp \
    --disable-libitm \
    --disable-libquadmath \
    --with-system-zlib \
    --disable-lto \
    --disable-plugin \
    --enable-linker-build-id \
    --enable-decimal-float=no \
    --without-isl \
    --disable-libssp \
"

EXTRA_OECONF_PATHS = "\
    --with-gxx-include-dir=/not/exist{target_includedir}/c++/${BINV} \
    --with-sysroot=/not/exist \
    --with-build-sysroot=${STAGING_DIR_TARGET} \
"

CVE_STATUS[CVE-2021-37322] = "cpe-incorrect: Is a binutils 2.26 issue, not gcc"
CVE_STATUS[CVE-2023-4039] = "fixed-version: Fixed via CVE-2023-4039.patch included here. Set the status explictly to deal with all recipes that share the gcc-source"
