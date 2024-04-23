# Main Makefile For qlibc
# Create On : 2024-04-23
# Copyright : QiuYiXiang

-include ./Rules.mk

# This Makefile Controls All of the Project

.DEFAULT_GOAL =	all

# Build Assert
ASSERT	:=	assert
ASSERT_BUILD_DIR	:=	$(BUILD_DIR)
ASSERT_SOURCE_DIR	:=	$(SOURCE_DIR)/$(ASSERT)
ASSERT_HEADERS		:=	
$(ASSERT).o: $(ASSERT_SOURCE_DIR)/$(ASSERT).c $(ASSERT_HEADERS)
	$(call _check, $(ASSERT_BUILD_DIR))
	$(call _cmd, $(GCC) $(FLAGS) -c $< -o $(ASSERT_BUILD_DIR)/$@)


# Variable For Building Targets
DEPENDENCIES		:=	assert.o
AR_DEPENDENCY		:=	$(addprefix $(BUILD_DIR)/, $(DEPENDENCIES))

$(LIBRARY_DIR)/$(NAME).a: $(DEPENDENCIES) $(AR_DEPENDENCY)
	$(call _check, $(LIBRARY_DIR))
	$(call _cmd, $(AR) -r $@ $(AR_DEPENDENCY))

# The Default Main Target !
# Generate Library File in the lib path 
.PHONY: all test
all: $(LIBRARY_DIR)/$(NAME).a
	@echo "Successful Build Library in $< !!!"

export NAME
export V
export GCC STD_VERSION
# Test Cases
test: $(LIBRARY_DIR)/$(NAME).a
	$(call _cmd, (cd $(TEST_DIR); make))
	
# Clean Generated Target
.PHONY: clean
clean:
	$(call _cmd, $(DELETE) -r $(BUILD_DIR) $(LIBRARY_DIR))
	$(call _cmd, $(DELETE) -f $(TEST_DIR)/test)
	@echo "Clean Generated Code Successfully !"
