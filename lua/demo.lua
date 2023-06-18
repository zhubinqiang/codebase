#!/usr/bin/env lua

require("myModule")

-- refer to https://www.runoob.com/lua/lua-tutorial.html
-- https://www.tutorialspoint.com/lua/lua_variables.htm

-- This is single comment
-- This is single comment

--[[
	multi line comment
	multi line comment
	multi line comment
--]]

-- global variable
a = 123
print(a)

print(b) -- b --> nil
b = 456
print(b)

local c = 789
print(c)

-- print(type("Hello world"))
-- print(type('Hello world'))
-- print(type(print))
-- print(type(type))
-- print(type(true))
-- print(type(nil))
-- print(type(type(X)))

function handle_table(args)
	local tab1 = {key1 = "val1", key2 = "vla2", "val3"}
	for k, v in pairs(tab1) do
		print(k .. "=" .. v)
	end

	tab1.key1 = nil -- delete
	for k, v in pairs(tab1) do
		print(k .. "=" .. v)
	end

	local tab2 = {}
	tab2[1] = "lua"
	tab2[2] = "user"
	for i,j in pairs(tab2) do
		print(i, j)
	end
	print(tab2)
	tab2 = nil
end



function if_else(a, b)
	if (a > b) then
		print("a > b")
	elseif (a < b) then
		print("a < b")
	else
		print("a = b")
	end

	print(type(X))          -- nil
	print( X == nil)        -- true
	print(type(X) == nil)   -- false
	print(type(X) == "nil") -- true

	-- 0 is true
	-- nil, false is flase
	if ( 0 ) then
		print("0 is true")
	end

	local A = true
	local B = false
	if ( A and B) then
		print("A and B")
	end

	if ( A or B) then
		print("A or B")
	end

	if ( not B) then
		print("not B")
	end

end

function loop(args)
	local i = 1
	local s = 0
	while(true) do
		s = s + i
		i = i + 1

		if(i > 100) then
			break
		end
	end
	print("while: s = 1 + 2 + ... + 100 = " .. s)

	for j = 5,1,-1 do
		print(j)
	end

	i = 1
	s = 0
	repeat
		s = s + i
		i = i + 1
	until(i > 100)
	print("repeat: s = 1 + 2 + ... + 100 = " .. s)

end

function handle_string()
	local s1 = "abc"
	print("\"String\"", s1)

	local s2 = 'wXYZ'
	print("\"String\"", s2)

	local s3 = [[abcdefg]]
	print("\"String\"", s3)

	print(string.len(s1))
	print(#s1)

	print(string.upper(s1))
	print(string.lower(s2))

	-- string.gsub(mainString,findString,replaceString,num)
	print(string.gsub('aaaa', 'a', 'z', 3))

	-- string.find (str, substr, [init, [plain]])
	print(string.find('hello lua user', 'lua', 1))

	print(string.reverse(s1))

	print(string.format("this value is: %d", 5))

	print(string.char(97, 98, 99, 100))
	print(string.byte('ABCD', 1))
	print(string.byte('ABCD'))


	print(string.rep("abcd", 2))

	print("www." .. "google." .. "com")

	for word in string.gmatch("hello lua user", "%a+") do
		print(word)
	end

	print(string.match("I have 2 questions for you.", "%d+ %a+"))
end

function handle_array()
	-- index start from 1
	local array = {1, 2, 3, 4, 5}
	for i = 0, #array do
		print(array[i])
	end

	local two = {}
	for i = 1, 9 do
		two[i] = {}
		for j = 1, 9 do
			two[i][j] = i * j
		end
	end

	for i = 1, 9 do
		for j = 1, 9 do
			print(two[i][j])
		end
	end
end

function handle_iterator()
	local array = {"A", "B", "C"}
	for key, value in ipairs(array) do
		print(key, value)
	end
end

function handle_module()
	-- export LUA_PATH=.
	print(myModule.add(1, 2))
	print(myModule.pi)
end


local function handle_io(args)
	local file = io.open("a.txt", 'r')
	-- print(file:read())
	for line in file:lines() do
		print(line)
	end
	io.close(file)

	file = io.open("output.txt", 'w')
	file:write("hello\n")
	file:close()
end

function sum(...)
	local s = 0
	for i, v in ipairs{...} do
		s = s + v
	end

	return s
end

-- if_else(1, 3)
-- loop()
-- s = sum()
-- handle_table()
-- handle_string()
-- handle_array()
-- handle_iterator()
-- handle_module()
handle_io()

