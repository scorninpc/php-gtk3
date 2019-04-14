php-gtk3-tests
==============

Repositório para alguns testes com bind php-gtk3
> Repositoty to do some tests with php-gtk3 bind


Compile
==============
Primeiro de tudo, é necessário compilar o [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP)
> You will need compile [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP) first

```sh
:$ git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
:$ make
:$ make install
```

Você precisará das libs para desenvolvimento php-dev e tambem libgtk-3-dev, ou em algumas distribuições linux gnome-devel. No debian e ubuntu:
> You will need php-dev and libgtk-3-dev, or in some cases gnome-devel. On Debian and ubuntu:

```sh
:$ sudo apt-get install build-essential gnome-devel
```

Depois isso é só começar a testar e começar a ajudar no desenvolvimento do bind:
> After that, just start test and start to help to dev this bind

```sh
:$ make clean; make
:$ php -dextension=./php-gtk3.so test.php
```


Why PHP-CPP
==============

Alem de tornar o trabalho mais rapido, a sintax e a forma de programar se assemelha muito ao PHP. Assim, mais pessoas podem contribuir com o projeto. Outro ponto forte, talvez o mais importante, do motivo do uso do PHP-CPP, são as atualizações do Zend.h. Na migração do PHP5 para o PHP7 por exemplo, todo bind foi perdido

> Alem de tornar o trabalho mais rapido, a sintax e a forma de programar se assemelha muito ao PHP, assim, mais pessoas podem contribuir com o projeto. Outro ponto forte, talvez o mais importante são as atualizações do Zend.h. Na migração do PHP5 para o PHP7 por exemplo, todo bind foi perdido

Where to find me
==============

- Here (from project)
- scorninpc@php.net (personal)
- phpgtk@googlegroups.com (php-gtk group)

for all: I'm sorry for my bad English
