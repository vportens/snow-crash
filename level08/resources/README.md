## Level08:

On passe le binaire dans un decompilateur et on vois ceci d'interessant :    
```c
int main(int argc,char **argv,char **envp)

{
  char *pcVar1;
  int __fd;
  size_t __n;
  ssize_t sVar2;
  int in_GS_OFFSET;
  int fd;
  int rc;
  char buf [1024];
  undefined local_414 [1024];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc == 1) {
    printf("%s [file to read]\n",*argv);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  pcVar1 = strstr(argv[1],"token");
  if (pcVar1 != (char *)0x0) {
    printf("You may not access \'%s\'\n",argv[1]);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  __fd = open(argv[1],0);
  if (__fd == -1) {
    err(1,"Unable to open %s",argv[1]);
  }
  __n = read(__fd,local_414,0x400);
  if (__n == 0xffffffff) {
    err(1,"Unable to read fd %d",__fd);
  }
  sVar2 = write(1,local_414,__n);
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return sVar2;
}
```

On remarque 2 choses, on doit lire un fichier qui ne doit pas contenir ```token```
Ici le fichier token a seulement les droits de lecture et de d'ecriture par le owner.  
Mais un moyen assez facile de changer cela est de faire un lien symbolique telque :   
```ln -s /home/user/level08/token /tmp/test.txt```
Maintenant on poura executer le binaire avec notre fichier ```test.txt``` (qui pointe vers token) 

quif5eloekouj29ke0vouxean

don't forget to ```su flag08 ```

25749xKZ8L7DkSCwJkT9dyv6f