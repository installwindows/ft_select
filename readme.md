ft\_select
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

Un terminal peut être deux modes: canonique et non-canonique. Dans le premier mode, l'input de l'utilisateur est retourné par `read()` ligne par ligne, soit après avoir appuyé sur la touche <kbd>Enter</kbd>. Dans le second mode, chaque touche est directement retourné par `read()`.
Le terminal a des attributs affectant son interaction avec l'utilisateur. Il peut par exemple output chaque input de l'utilisateur ou automatiquement revenir au début de la ligne suivante après output un `\n`.

Pour faire des changements, on peut utiliser `ioctl()`, ou bien `tcsetattr()`. Pour ce qui est du second cas, j'utilise deux structures, une pour l'ancienne configuration `struct termios oldtio;` et une pour la nouvelle `struct termios newtio;`. `newtio` sera dès lors prête à être modifié et appliqué au terminal et `oldtio` devra être réappliqué lorsqu'on quitte le programme, car autrement, la nouvelle configuration sera persistante dans le terminal ayant lancé notre programme. `oldtio` est initializée par `tcgetattr(0, &oldtio);` et `newtio` par `newtio = oldtio;`. Une fois les modifications faites, on utilise `tcsetattr(0, TCANOW, &newtio);` pour setter la nouvelle configuration. Et rendu à la fin du programme: `tcsetattr(0, TCANOW, &oldtio);`.


Flag | Description
--- | ---
**c\_iflag**
BRKINT | Allow BREAK condition, which is a bunch of zeroes to do seemingly legacy stuff?
ECHO | Echo input
ECHOCTL | Echo control characters other than tab, newline, START and STOP
ECHOE | ERASE is performed visually as \b space \b
ECHOK
ECHOKE | asjsdlkf 


Termcaps
--------

Liste de mots magiques utiles:

Mot magique | Description | Exemple
--- | --- | ---
-- | **Screen information** | --
`co` | Screen width in lines | `int width = tgetnum("co")`
`li` | Screen height in lines | `int height = tgetnum("li")`
 | **Cursor motion** |
`cm` | Position cursor at line _l_, column _c_ | `tputs(tgoto(tgetstr("cm", NULL), c, l), 0, putchar)`
`ho` | Move cursor to upper left corner (home) |
`ll` | Move cursor to lower left corner |
`cr` | Move cursor to begining of line |
-- | **Clear parts of sreen** | --
`cl` | Empty the screen of any characters and position the cursor at the upper left corner |
`cd` | The cursor current line is anniliated and so is the lines bellow it |
`ce` | Kills from the cursor to the end of line |
`ec` | Remove `n` chars right of the cursor |



ft\_select
----------

`main`
 1. initialize termcaps
 2. start selection loop

`ft_select`
 1. update screen
 2. read input
 3. check for signals

