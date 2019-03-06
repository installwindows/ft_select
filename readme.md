ft_select
=========

Utilitaire console utilisant les [termcaps][1] offrant en sélection les arguments qui lui sont passés.

[1]: https://www.gnu.org/software/termutils/manual/termcap-1.3/html_mono/termcap.html

Usage
-----

```console
$ ft_select item1 item2 item3 ...
```

- <kbd>&larr;</kbd><kbd>&uarr;</kbd><kbd>&darr;</kbd><kbd>&rarr;</kbd> Se déplacer
- <kbd>space</kbd> Sélectionner/déselectionner
- <kbd>Enter</kbd> Valider la sélection
- <kbd>delete</kbd> ou <kbd>backspace</kbd> Supprimer de la liste
- <kbd>ESC</kbd> Quitter

Quelques fonctions à utiliser (ou non)
--------------------------------------

* isatty, ttyname, ttyslot
* ioctl
* getenv
* tcsetattr, tcgetattr
* tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
* open, close write
* malloc, free
* read, exit
* signal
