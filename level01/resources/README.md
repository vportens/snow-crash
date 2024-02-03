## Level 01:

Tu dois faire :
```bash
level01@SnowCrash:~$ cat /etc/passwd | grep flag01
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
Pour decoder le code : `42hDRfypTqqnw`

Tu dois mettre ce code dans [John the ripper](https://www.openwall.com/john/) (logiciel de decryptage) ce qui te donnera : `abcdefg`
```bash
kali@kali:~$ john --wordlist passwd
kali@kali:~$ john --show passwd
flag01:abcdefg:3001:3001::/home/flag/flag01:/bin/bash
1 password hash cracked, 0 left
```