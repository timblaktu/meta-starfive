LDFLAGS:remove:class-nativesdk = "-fuse-ld=lld"

FILES:${PN} += "${libdir}/*"

PACKAGECONFIG = ""
LLVM_TARGETS_TO_BUILD = "RISCV;X86"

EXTRA_OECMAKE:append:class-native = " \
			-DCLANG_VENDOR="StarFive" \
			-DCLANG_ENABLE_ARCMT=OFF \
			-DCLANG_ENABLE_STATIC_ANALYZER=OFF \
			-DCLANG_PLUGIN_SUPPORT=OFF \
			-DCLANG_BUILD_TOOLS=ON \
			-DCMAKE_BUILD_TYPE=Release \
			-DLLVM_ENABLE_BINDINGS=OFF \
			-DLLVM_ENABLE_PLUGINS=ON \
			-DLLVM_ENABLE_OCAMLDOC=OFF \
			-DLLVM_ENABLE_TERMINFO=OFF \
			-DLLVM_INCLUDE_DOCS=OFF \
			-DLLVM_INCLUDE_EXAMPLES=OFF \
			-DLLVM_INCLUDE_TESTS=ON \
			-DLLVM_ENABLE_WARNINGS=OFF \
			-DLLVM_ENABLE_ASSERTIONS=TRUE \
			-DLLVM_INCLUDE_UTILS=ON \
			-DLLDB_PYTHON_EXE_RELATIVE_PATH="recipe-sysroot-native/usr/bin/python3-native/python3.9" \
			-DLLDB_PYTHON_RELATIVE_PATH="recipe-sysroot-native/usr/bin/python3-native/" \
                        -DLLDB_PYTHON_EXT_SUFFIX=".so" \
			"

PROVIDES += "llvm llvm${PV}"
PROVIDES:append:class-native = " llvm-native"
