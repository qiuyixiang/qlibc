# Main Makefile For qlibc

# Formal Version qlibc 1.0.0

# Create on : 2024-04-23
# Copyright : QiuYiXiang

-include ./Rules.mk

.DEFAULT_GOAL	:=	all

LIB_INCLUDE_FLAGS	:=	-iquote ./ -isystem $(INCLUDE_DIR)

# Build Component Of Assert
ASSERT	:=	assert
ASSERT_HEADERS	:=
ASSERT_SOURCE	:=	$(SOURCE_DIR)/$(ASSERT)
$(ASSERT).o: $(ASSERT_SOURCE)/$(ASSERT).c $(ASSERT_HEADERS)
	$(call _CHECK, $(BUILD_DIR))
	$(call _CMD, $(GCC) $(FLAGS) $(LIB_INCLUDE_FLAGS) -c $< -o $(BUILD_DIR)/$@)
	$(call _SHOW, "Build $(ASSERT) Library : $(BUILD_DIR)/$@")

DEPENDENCIES	:=	assert.o
AR_TARGET_OBJ	:=	$(addprefix $(BUILD_DIR)/, $(DEPENDENCIES))
$(LIBRARY_DIR)/$(NAME).a : $(DEPENDENCIES)
	$(call _CHECK, $(LIBRARY_DIR))
	$(call _CMD, $(AR) -r $@ $(AR_TARGET_OBJ))

# Main Build Target control the whole Project
.PHONY: all
all: $(LIBRARY_DIR)/$(NAME).a
	$(call _SHOW, "\\nBuild Library $(NAME) Successfully in $<")

# Test Cases
.PHONY: test
test: $(LIBRARY_DIR)/$(NAME).a
	$(call _CMD, (cd $(TEST_DIR); make ))

# Clean Generated Code and Object File
.PHONY: clean
clean:
	$(call _CMD, $(DELETE) -rf $(BUILD_DIR) $(LIBRARY_DIR))
	$(call _CMD, $(DELETE) -f $(TEST_DIR)/test $(TEST_DIR)/test.o)