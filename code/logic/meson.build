dir = include_directories('.')

app_lib = static_library('app-code',
    files(
        'app.c',
        'magic.c',
        'help.c',
        'process.c',
        'system.c',
        'service.c',
        'echo.c',
        'env.c',
        'permit.c',
        'scan.c',
        'ping.c'
        'this.c'
    ),
    install: true,
    dependencies: [code_deps],
    include_directories: dir)

app_dep = declare_dependency(
    link_with: [app_lib],
    dependencies: [code_deps],
    include_directories: dir)

# This is the main executable for the app
executable('squid', 'main.c', install: true, dependencies: [app_dep], include_directories: dir)
