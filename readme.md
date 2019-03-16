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

Termcap? Termcap!
-----------------

C'est deux trucs, le premier est une base de données et l'autre une _library_. Il y a dans cette base de données la descriptions des capacités de centaines de terminaux différents. La _library_ est l'_application programmer's interface_ de la base de données.

Initialization
--------------

La fonction **tgetent** récupère la description du terminal <code>termtype</code> dans la variable <code>buffer</code>. Les autres fonctions de termcap utilisent en interne ce buffer. La taille de ce dernier est conventionnellement 2048. Dans la version Mac, le manuel indique que le _buffer_ est ignoré, donc on peut simplement passer <code>NULL</code> en premier argument.
```c
char	*termtype = getenv("TERM");

tgetent(NULL, termtype);
```
S'il n'y a aucune erreur, les fonctions **tgetflag**, **tgetnum**, **tgetstr**, **tgoto** et **tputs** peuvent manupuler le terminal grâce à des mots magiques.

Canonique ou non?
-----------------



Termcaps
--------
Liste de mots magiques utiles:

Mot magique | Description | Fonction
--- | --- | ---
**co** | Screen width in lines | <code>int width = tgetnum("co")</code>
**li** | Screen height in lines | int height = tgetnum("li")

