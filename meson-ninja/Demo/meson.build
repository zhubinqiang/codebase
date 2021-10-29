## refer to https://mesonbuild.com/Meson-sample.html
project('Demo', 'c')

incdir = include_directories('include')

libcat = shared_library('cat', 'cat/cat.c',
  install : true,
  include_directories : incdir
  )

staticcat = static_library('cat', 'cat/cat.c',
  install : true,
  include_directories : incdir
  )

executable('cat', ['cat/main.c', 'cat/cat.c'],
  install : true,
  include_directories : incdir
  )

executable('cat-dyamic', 'cat/main.c',
  install : true,
  include_directories : incdir,
  link_with : libcat
  )

executable('cat-static', 'cat/main.c',
  install : true,
  include_directories : incdir,
  link_with : staticcat
  )

_opt = get_option('libdir')
message('=======================opt: @0@'.format(_opt))


install_headers('include/mylib.h', subdir : 'projname')

## share/progname/run.sh
install_data('run.sh', install_dir : get_option('datadir') / 'progname')

## etc/run.sh
install_data('run.sh', install_dir : '/etc/')

## {datadir}/{projectname}/new-name.txt
install_data('run.sh', rename : 'new-name.txt')

install_data('run.sh', install_dir : '/etc/', rename : 'run.sh.txt')


