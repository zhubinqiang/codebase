#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

import xmlrpc.client

s = xmlrpc.client.ServerProxy('http://localhost:8000')
print(s.pow(2,3))  # Returns 2**3 = 8
print(s.add(2,3))  # Returns 5
print(s.mul(5,2))  # Returns 5*2 = 10

# Print list of available methods
print(s.system.listMethods())
# print(s.system.methodHelp('add'))

print(s.add2(2,3))  # Returns 5
print(s.mul2(5,2))  # Returns 5*2 = 10


