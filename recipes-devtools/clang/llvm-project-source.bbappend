FILESEXTRAPATHS:prepend := "${THISDIR}/clang:"

SRCREV = "092b6c5ee3707ea10b9f10d0a674e8d12395369b"
BRANCH = "release/17.x"

SRC_URI = "\
    ${BASEURI} \
    file://llvm-config \
    file://libunwind.pc.in \
    file://0001-Handle-seteq-setne-conditions-for-CZERO_NEZ-CZERO_EQ.patch \
    file://0002-neon2rvv-support-type-convert-between-fixed-vector-a.patch \
    file://0003-Add-an-optional-for-optimizing-Insert-Read-Write-CSR.patch \
    file://0004-RISCV-Add-prefetch-instructions.patch \
    file://0005-RISCV-Add-customer-cache-instructions.patch \
    file://0006-RISCV-Add-multilib-v-b-support-for-baremetal-toolcha.patch \
    file://0007-RISCV-Change-baremetal-multilib-directory-name-to-al.patch \
    file://0008-RISCV-Support-b-letter-in-march-string.patch \
    file://0001-libcxxabi-Find-libunwind-headers-when-LIBCXXABI_LIBU.patch \
    file://0002-compiler-rt-support-a-new-embedded-linux-target.patch \
    file://0003-compiler-rt-Simplify-cross-compilation.-Don-t-use-na.patch \
    file://0004-llvm-TargetLibraryInfo-Undefine-libc-functions-if-th.patch \
    file://0005-llvm-allow-env-override-of-exe-and-libdir-path.patch \
    file://0006-clang-driver-Check-sysroot-for-ldso-path.patch \
    file://0007-clang-Driver-tools.cpp-Add-lssp_nonshared-on-musl.patch \
    file://0008-clang-Prepend-trailing-to-sysroot.patch \
    file://0009-clang-Look-inside-the-target-sysroot-for-compiler-ru.patch \
    file://0010-clang-Define-releative-gcc-installation-dir.patch \
    file://0011-clang-Add-lpthread-and-ldl-along-with-lunwind-for-st.patch \
    file://0012-Pass-PYTHON_EXECUTABLE-when-cross-compiling-for-nati.patch \
    file://0013-Check-for-atomic-double-intrinsics.patch \
    file://0014-libcxx-Add-compiler-runtime-library-to-link-step-for.patch \
    file://0015-clang-llvm-cmake-Fix-configure-for-packages-using-fi.patch \
    file://0016-clang-Fix-resource-dir-location-for-cross-toolchains.patch \
    file://0017-clang-driver-Add-dyld-prefix-when-checking-sysroot-f.patch \
    file://0018-clang-Use-python3-in-python-scripts.patch \
    file://0019-For-x86_64-set-Yocto-based-GCC-install-search-path.patch \
    file://0020-llvm-Do-not-use-find_library-for-ncurses.patch \
    file://0021-llvm-Insert-anchor-for-adding-OE-distro-vendor-names.patch \
    file://0022-compiler-rt-Do-not-use-backtrace-APIs-on-non-glibc-l.patch \
    file://0023-clang-Fix-x86-triple-for-non-debian-multiarch-linux-.patch \
    file://0024-libunwind-Added-unw_backtrace-method.patch \
    file://0025-clang-Do-not-use-install-relative-libc-headers.patch \
    file://0027-Fix-lib-paths-for-OpenEmbedded-Host.patch \
    file://0028-Correct-library-search-path-for-OpenEmbedded-Host.patch \
    file://0029-lldb-Link-with-libatomic-on-x86.patch \
    file://0030-compiler-rt-Enable-__int128-for-ppc32.patch \
    file://0031-llvm-Do-not-use-cmake-infra-to-detect-libzstd.patch \
    file://0032-compiler-rt-Fix-stat-struct-s-size-for-O32-ABI.patch \
    file://0033-compiler-rt-Undef-_TIME_BITS-along-with-_FILE_OFFSET.patch \
    file://0034-ToolChains-Gnu.cpp-ARMLibDirs-search-also-in-lib32.patch \
    "
