#############################################################################
# boards/bes/common/Makefile
#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.  The
# ASF licenses this file to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance with the
# License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
# License for the specific language governing permissions and limitations
# under the License.
#
#############################################################################

include $(TOPDIR)/Make.defs

include board/Make.defs
include src/Make.defs

DEPPATH += --dep-path board
DEPPATH += --dep-path src

CSRCS_DEPS :=
CONFIG_ARCH_BOARD_CUSTOM_NAME_STR := $(subst ",,$(CONFIG_ARCH_BOARD_CUSTOM_NAME))

ifneq ($(wildcard $(BOARD_CSRCS)),)
BES_BOARD_TARGET := libbesboard_$(CONFIG_ARCH_BOARD_CUSTOM_NAME_STR).a

$(BES_SDK_TARGET) : install_$(BES_BOARD_TARGET)

.PHONY:install_$(BES_CHIP_TARGET)
BOARD_COBJS = $(BOARD_CSRCS:.c=.o)

INSTALL_CMD := mv -f
install_$(BES_BOARD_TARGET): $(BES_BOARD_TARGET)
	$(INSTALL_CMD) $(BES_BOARD_TARGET) $(BOARD_DIR)/configs/$(CONFIG_ARCH_BOARD_CUSTOM_NAME_STR)/$(BES_BOARD_TARGET) -v
	$(INSTALL_CMD) $(BOARD_COBJS) $(BOARD_DIR)/configs/$(CONFIG_ARCH_BOARD_CUSTOM_NAME_STR) -v


BIN := $(BES_BOARD_TARGET)
$(BIN): $(BOARD_COBJS)
	$(call ARCHIVE, $@, $(BOARD_COBJS))

$(BOARD_COBJS): %.o: %.c
	$(call COMPILE, $<, $@)

endif

CSRCS_DEPS += $(BES_SDK_TARGET)

$(CSRCS) : $(CSRCS_DEPS)
$(BES_SDK_TARGET) :
ifneq ($(wildcard $(BES_SDK_BUILDIR)/Makefile),)
	$(MAKE) -C $(BES_SDK_BUILDIR) $@ BES_NUTTX_BOARD_DIR=$(BOARD_DIR)
endif

context ::
	ln -sf $(BOARDDIR)/board/etc etc

clean ::
ifneq ($(wildcard $(BES_SDK_BUILDIR)/Makefile),)
	$(MAKE) -C $(BES_SDK_BUILDIR) clean BES_NUTTX_BOARD_DIR=$(BOARD_DIR)
endif
ifneq ($(BOARD_CSRCS),)
	$(call DELFILE, $(BIN))
	$(call CLEAN)
endif

distclean ::
ifneq ($(wildcard $(BES_SDK_BUILDIR)/Makefile),)
	$(MAKE) -C $(BES_SDK_BUILDIR) clean BES_NUTTX_BOARD_DIR=$(BOARD_DIR)
endif
	rm -f etc

CFLAGS += $(BES_SDK_FLASGS)
include $(TOPDIR)/boards/Board.mk

ARCHSRCDIR = $(TOPDIR)$(DELIM)arch$(DELIM)$(CONFIG_ARCH)$(DELIM)src
BOARDDIR = $(ARCHSRCDIR)$(DELIM)board
CFLAGS += $(shell $(INCDIR) "$(CC)" $(BOARDDIR)$(DELIM)include)
