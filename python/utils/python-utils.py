#!/usr/bin/env python3
# -*- coding: UTF-8 -*-
# ********************************************************
# @file: python-utils.py
# @author: ZhuBinQiang <zhu.binqiang@163.com>
# @create time: 2021-06-07 14:53:43
# @last modified: 2021-06-07 14:53:43
# @description:
# ********************************************************

json_file = '''
{
  "books": {
    "book1": {
      "title": "The Three-Body Problem",
      "author": "Liu, Cixin"
    },
    "book2": {
      "title": "Gang of Four Design Patterns",
      "author": ["Erich Gamma", "Richard Helm", "Ralph Johnson", "John Vlissides"]
    },
    "book3": {
      "title": "Captivate",
      "author": "Vanessa Van Edwards"
    },
    "book4": {
      "title": "The Book of Pride",
      "author": "Mason Funk"
    }
  }
}
'''

## refer to https://www.runoob.com/python/python-json.html
import json
from collections import OrderedDict
def handle_json():
    # data = json.load(open('path/to/jsfile'))
    # data = json.load(open('path/to/jsfile'), object_pairs_hook=OrderedDict)
    data = json.loads(json_file)
    print(data)
    print(json.dumps(data, sort_keys=True, indent=4, separators=(',', ': ')))
    # print(json.dumps(data, sort_keys=False, indent=4, separators=(',', ': ')))


yaml_file = '''
books:
    - title: The Three-Body Problem
      author: 'Liu, Cixin'
    - title: Gang of Four Design Patterns
      author:
        - Erich Gamma
        - Richard Helm
        - Ralph Johnson
        - John Vlissides
    - title: The Book of Pride
      author: Mason Funk
    - title: Captivate
      author: Vanessa Van Edwards
'''

import yaml
from collections import OrderedDict
## copy from https://tendcode.com/article/yaml_order/
def ordered_yaml_load(stream, Loader=yaml.SafeLoader,
                      object_pairs_hook=OrderedDict):
    class OrderedLoader(Loader):
        pass

    def _construct_mapping(loader, node):
        loader.flatten_mapping(node)
        return object_pairs_hook(loader.construct_pairs(node))

    OrderedLoader.add_constructor(
        yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG,
        _construct_mapping)
    return yaml.load(stream, OrderedLoader)

def handle_yaml():
    # data = yaml.load(open('/path/to/file'), Loader=yaml.Loader)
    data = yaml.load(yaml_file, Loader=yaml.Loader)
    print(data)

    ## PyYAML version to > 3.13 to avoid [unexpected keyword argument 'sort_keys']
    yaml.dump(data, open('a.yaml', 'w'), default_flow_style=False,sort_keys=False)

    # ordered_data = ordered_yaml_load(open('/path/to/file'))
    ordered_data = ordered_yaml_load(yaml_file)
    print(ordered_data)


## refer to https://www.cainiaojc.com/note/qa55ip.html
## chmod 600 ~/.netrc
## machine example.com
##     login user
##     password p@ssw0rD
def handle():
    import netrc
    netrc = netrc.netrc()
    remoteHostName = "example.com"
    authTokens = netrc.authenticators(remoteHostName)
    print("Remote Host Name:%s" % (remoteHostName))
    print("User Name at remote host:%s" % (authTokens[0]))
    print("Account Password:%s" % (authTokens[1]))
    print("Password for the user name at remote host:%s" % (authTokens[2]))
    macroDictionary = netrc.macros
    print(macroDictionary)

    import base64
    print(base64.b64encode("password".encode("utf-8")))
    print(base64.b64decode(b'cGFzc3dvcmQ='.decode("utf-8")))

def cartesian_product():
    import itertools
    a = [1, 2, 3]
    b = ['a', 'b', 'c']
    for (x, y) in itertools.product(a, b):
        print("%d --> %s" %(x, y))

def main():
    handle_json()
    handle_yaml()
    cartesian_product()

if __name__ == "__main__":
    main()

