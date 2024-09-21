BUILD_DIR=$(CURDIR)/build
TARGET_EXEC=kconv

.PHONY: build
build:
	cmake -B '$(BUILD_DIR)' -S '$(CURDIR)' -DCMAKE_EXPORT_COMPILE_COMMANDS=ON && \
		make -C '$(BUILD_DIR)'

.PHONY: clean
clean:
	rm -rf '$(BUILD_DIR)'
