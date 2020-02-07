def Settings( **kwargs ):
    return {
        'flags': ['c', '-Wall', '-Wextra', '-Werror', '-Ilibft', '-lft', '-ltermcap', '-Llibft'],
    }
