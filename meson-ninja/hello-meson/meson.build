project('tutorial', 'c')
executable('main', 'main.c', install : true)

gtkdep = [dependency('ncurses', version: '>=6.1.20200212'), dependency('zlib')]
exe = executable('demo', 'main.c', dependencies : gtkdep)
test('Hello world!', exe)

