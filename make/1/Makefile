#
# # # # # # # # # # # # # # # #
# <target>: <prerrequisites>
# <Tab>	<commands>
# # # # # # # # # # # # # # # #
#

a.txt: b.txt c.txt
	cat b.txt c.txt > a.txt

b.txt:
	date > b.txt

c.txt:
	ps > c.txt

## $@ target
d.log e.log:
	touch $@

## $^ all prerrequisites
%.exe: %.log
	cat $^

tmp = Hello-World.log
test:
	@echo $(tmp)
	date > $(tmp)

home:
	@echo $$HOME   # shell variable

.PHONY: clean

clean:
	rm -f [a-z].txt
	rm -f *.log

