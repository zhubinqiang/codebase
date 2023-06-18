#!/usr/bin/env lua

myModule = {}

myModule.pi = 3.1415926

function myModule.add(a, b)
	return a + b
end

local function private_print(args)
	print(args)
end

function myModule.show(args)
	private_print(args)
end

return myModule


