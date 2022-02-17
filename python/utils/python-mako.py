#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# refer to https://www.cnblogs.com/zhangshihai1232/articles/6296435.html
# ********************************************************

from mako.template import Template
from mako.lookup import TemplateLookup

class User(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

def getUsers():
    users = []
    for i in range(5):
        user = User(chr(65+i), 20+i)
        users.append(user)
    return users

def main():
    users = getUsers()

    t = Template(filename='mako-template/makedown.tmpl')
    print(t.render(title='Users', rows=users))

    lookup = TemplateLookup(directories=['./mako-template/'], collection_size=500, filesystem_checks=True)
    t = lookup.get_template('html.tmpl')
    content = t.render(title='Users', rows=users)
    print(content)


if __name__ == '__main__':
    main()

