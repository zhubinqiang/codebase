.PHONY: clean, parpare
SPEC = mycat.spec
RPMDIR = rpmbuild
SRC = src
RPM_NAME = mycat-1
TEMPDIR = $(shell mktemp -d)
TMP = $(TEMPDIR)/$(RPM_NAME)

default: build

build: prepare
	rpmbuild -ba $(SPEC) --define "_topdir ${PWD}/$(RPMDIR)"

prepare:
	$(shell mkdir -p $(RPMDIR); cd $(RPMDIR); mkdir -p BUILD BUILDROOT RPMS SOURCES SPECS SRPMS)
	echo $(TMP)
	$(shell mkdir -p $(TMP); cp -r $(SRC)/*.c $(TMP); cp -r $(SRC)/Makefile $(TMP))
	$(shell tar czf $(RPMDIR)/SOURCES/$(RPM_NAME).tar.gz $(TMP))
	$(shell cp $(SPEC) $(RPMDIR)/SPECS)
	# $(shell cp $(SRC)/*.patch $(RPMDIR)/SOURCES)
	# $(shell cp $(SRC)/*.tar.gz $(RPMDIR)/SOURCES)

clean:
	rm -rf $(RPMDIR)

