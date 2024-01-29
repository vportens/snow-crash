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


Il y a un fichier level02.pcap

Ces fichiers sont a ouvrir avec wireshark, ici le fichier une fois ouvert on peut utiliser l'option ```FOLLOW--> TCP Stream``` et on obtient un mot de passe partiel : 
<img src="./srcs/img/wireshark_global_img.png">

si on regarde les transferts qui correspondent au ```.``` on peut voir que ca corresponds au transfere d'un packet de 1 byte : 7f 
<img src="./srcs/img/wireshark_global_img.png">

en ascii 7f correspond a DEL

le mot de passe est donc : 
```ft_waNDReL0L```