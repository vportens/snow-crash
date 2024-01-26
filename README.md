# SNOW-CRASH
## Capture the flags
***

### Concept 
Un project secu qui va nous faire naviger de niveau en niveau pour nous faire trouver les flags necessaire au passage de ceux-ci.
Pour ce project il est necessaire de telecharger un .iso dans lequel tu seras mis a l'epreuve.

## Level 00:
Tu devras trouver les fichiers accessible au user : ```flag00```  
Pour cela : ```find / -user flag00 2> /dev/null```   
Tu y trouvera le mot de passe crypte : ```cdiiddwpgswtgt```

Une fois decrypte ( https://cachesleuth.com/multidecoder/), 
cela donne  ```nottoohardhere```



## Level 01:
Tu dois faire :
```/etc/passwd```
cela retourne : 
```flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash```

Pour decoder le code : ```42hDRfypTqqnw```
Tu dois mettre ce code dans John the ripper (logiciel de decryptage) ce qui te donnera : ```abcdefg```

## Level 02:
