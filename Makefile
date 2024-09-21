BUILD_DIR=$(CURDIR)/build
TARGET_EXEC=kconv

.PHONY: build
build:
	cmake -B '$(BUILD_DIR)' -S '$(CURDIR)' && \
		make -C '$(BUILD_DIR)'

.PHONY: clean
clean:
	rm -rf '$(BUILD_DIR)'
