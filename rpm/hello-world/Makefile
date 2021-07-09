.PHONY: clean, parpare
SPEC = hello-world.spec
RPMDIR = rpmbuild

default: build

build: prepare
	rpmbuild -ba $(SPEC) --define "_topdir ${PWD}/$(RPMDIR)"

prepare:
	$(shell mkdir -p $(RPMDIR); cd $(RPMDIR); mkdir -p BUILD BUILDROOT RPMS SOURCES SPECS SRPMS)

clean:
	rm -rf $(RPMDIR)

