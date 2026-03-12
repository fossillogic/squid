dir = include_directories('.')

app_lib = static_library('app-code',
    files(
        'app.c',
        'magic.c',
        'help.c',
        'process.c',
        'system.c',
        'service.c',
        'health.c',
        'calc.c',
        'monitor.c',
        'echo.c',
        'env.c',
        'inspect.c',
        'introspect.c',
        'this.c',
        'permit.c',
        'notebook.c',
        'view.c',
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
