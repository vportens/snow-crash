## Level 00:
Tu devras trouver les fichiers accessible au user : `flag00`  
Pour cela :
```bash
level00@SnowCrash:~$ cat $(find / -user flag00 2> /dev/null)
```
Tu y trouvera le mot de passe crypte : ```cdiiddwpgswtgt```

Une fois decrypte avec le [Rot13](https://cachesleuth.com/multidecoder/), 
cela donne  `nottoohardhere`.
