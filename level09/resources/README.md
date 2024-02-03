
## Level09:
Apres decompilation du binaire on remarque une boucle interessante : 
```c
while (true)
{
  var_120 = (var_120 + 1);
  int32_t ecx_1 = 0xffffffff;
  int32_t edi_1 = argv[1];
  while (ecx_1 != 0)
    {
    bool cond:0_1 = 0 != *edi_1;
    edi_1 = (edi_1 + 1);
    ecx_1 = (ecx_1 - 1);
    if ((!cond:0_1))
      {
        break;
      }
    }
  if (var_120 >= ((!ecx_1) - 1))
  {
    break;
  }
  putchar((*(var_120 + argv[1]) + var_120));
}
```

c'est le traitement de l'argument donne lors de l'exec, qui va incrementer chaque caractere de sa position, Exemple :    
```bash
./level09 aaaaa
abcde
```
Lors de la lecture du fichier `token` on voit le resultat du password a travers cette fonction et nous devons retrouver le password original. L'operation n'est pas complique et peut etre fais a la main (moi) ou avec une fonction (merci monsieur fcatinau pour celle-ci) :    

```c
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    if (argc != 2)
        return 0;
    int fd = open(argv[1], O_RDONLY);
    char buff[4096];
    int ret = read(fd, buff, 4096);
    int log = open("output", O_APPEND);
    for (int i = 0; i < ret; i++)
    {
        char c = buff[i];
        c -= i;
        write(1,&c,1);
    }
}
```

```bash
./a.out token
f3iji1ju5yuevaus41q1afiuq
```