CURRENT_DIR := $(shell pwd)
PROJECT := test
SOURCE := source.list
TARGET := test.jar
OUT := out
MAINCLASS := ThreadCaseDemo

.PHONY: all jar

all: jar

javac: preinit
	javac -cp $(CURRENT_DIR)/$(OUT)/$(PROJECT) -d $(CURRENT_DIR)/$(OUT)/$(PROJECT)  @$(CURRENT_DIR)/$(SOURCE)
	rm -f $(CURRENT_DIR)/$(SOURCE)

preinit:
	@find $(CURRENT_DIR)/ -name "*.java" > $(CURRENT_DIR)/$(SOURCE)
	mkdir -p $(CURRENT_DIR)/$(OUT)/$(PROJECT)

jar: javac
	jar -cvf $(TARGET) -C $(CURRENT_DIR)/$(OUT)/$(PROJECT) .

run: jar
	java -cp $(TARGET) $(MAINCLASS)

clean:
	rm -rf $(OUT) $(TARGET)

