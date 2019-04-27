php-gtk3-tests
==============

Repositório para alguns testes com bind php-gtk3
> Repositoty to do some tests with php-gtk3 bind


Compile
==============

Você precisará das libs para desenvolvimento php-dev e tambem libgtk-3-dev, ou em algumas distribuições linux gnome-devel. No debian e ubuntu:
> You will need php-dev and libgtk-3-dev, or in some cases gnome-devel. On Debian and ubuntu:

```sh
:$ sudo apt-get install build-essential gnome-devel php-dev
```

Será necessário compilar o [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP)
> You will need compile [PHP-CPP](https://github.com/CopernicaMarketingSoftware/PHP-CPP) first

```sh
:$ git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP.git
:$ make
:$ make install
```

Depois disso é só começar a testar e começar a ajudar no desenvolvimento do bind:
> After that, just start test and start to help to dev this bind

```sh
:$ git clone https://github.com/scorninpc/php-gtk3-tests.git
:$ cd php-gtk3-tests
:$ make
:$ php -dextension=./php-gtk3.so test.php
```

Some images of progress
==============
![GTK interactive debugger](https://i.imgur.com/P50OpKF.jpg)
![GTK interactive debugger](https://i.imgur.com/NZkie9R.jpg)
![Widgets](https://i.imgur.com/UpBIYQB.jpg)
![Tooltips](https://i.imgur.com/cGECrWu.jpg)


Why PHP-CPP
==============

Alem de tornar o trabalho mais rapido, a sintax e a forma de programar se assemelha muito ao PHP. Assim, mais pessoas podem contribuir com o projeto. Outro ponto forte, talvez o mais importante, do motivo do uso do PHP-CPP, são as atualizações do Zend.h. Na migração do PHP5 para o PHP7 por exemplo, todo bind foi perdido

> In addition to making work faster, syntax and how to program closely resemble PHP, so more people can contribute to the project. Another strong point, perhaps the most important are the updates of Zend.h. In the migration from PHP5 to PHP7 for example, every bind was lost

Where to find me
==============

- Here (from project)
- scorninpc@php.net (personal)
- [https://twitter.com/ScornInPC](https://twitter.com/ScornInPC) (social media)
- phpgtk@googlegroups.com (php-gtk group)

for all: I'm sorry for my bad English
