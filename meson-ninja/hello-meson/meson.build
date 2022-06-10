project('tutorial', 'c')
executable('main', 'main.c', install : true)

## to find if git in PATH
prog_glslang = find_program('git')

gtkdep = [dependency('ncurses', version: '>=6.1.20200212'), dependency('zlib')]
exe = executable('demo', 'main.c', dependencies : gtkdep)
test('Hello world!', exe)

