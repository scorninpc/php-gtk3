
# Table of contents

- [How to compile PHP-GTK on Linux with Docker](#how-to-compile-php-gtk-on-linux-with-docker)
- [How to install PHP-GTK on Linux with Docker](#how-to-install-php-gtk-on-linux-with-docker)

# How to compile PHP-GTK on Linux with Docker

This is extremely experimental

1. Create a working folder

2. Inside this folder, choose the `Dockerfile` from `/docker` folder in repository. This named with php version like `DockerfileX.X.XX`, and rename it to `Dockerfile`

3. You will need `run.sh` too. Only this two files

4. Now create the image with `docker build -t php-gtk3-image . `. `php-gtk3-image` is the final image name, and you can change if you want

5. Clone the php-gtk3 repository to php-gtk3-source with `git clone git@github.com:scorninpc/php-gtk3.git php-gtk3-source`

6. Now you can build source with docker with command `docker run --name php-gtk3-container --rm -v $PWD:/app php-gtk3-image build 4`

7. If all works fine, you can test your build with `docker run --name php-gtk3-container --rm -v $PWD:/app php-gtk3-image php -m`. You will see  `php-gtk3` extension on the list

# How to install PHP-GTK on Linux with Docker

1. After compile, you can install compiled locally. Run command `docker run --name php-gtk3-container --rm -v $PWD:/app php-gtk3-image php-copy`. This will create a folder locally called `usr` and some `.so` files

2. Give user permission to the `usr` with `sudo chown $USER:$USER -R $PWD/usr/local/php-gtk3`

3. Copy libs to the lib folder with `sudo cp libphpcpp.so.2.3 /lib/`, `sudo cp libgladeui-2.so.13 /lib/` and `sudo cp libgtksourceview-3.0.so.1 /lib/`

4. Move `src/local/php-gtk3` to system folders with `sudo mv $PWD/usr/local/php-gtk3 /usr/local/`

5. Create the syslink with `sudo ls -s /usr/local/php-gtk3/bin/php /usr/bin/php-gtk3`

6. now you should be able to run `php-gtk3` command to execute your scripts