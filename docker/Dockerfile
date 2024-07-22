FROM debian:stable-slim

# git
RUN apt-get update && apt-get install -y libpq-dev bison libreadline-dev git build-essential autoconf automake libtool re2c libxml2-dev libcurl4-openssl-dev libssl-dev libbz2-dev  libjpeg-dev libpng-dev libxpm-dev libfreetype6-dev libzip-dev libsqlite3-dev libonig-dev libxslt1-dev libgtk-3-dev libgladeui-dev libgtksourceview-3.0-dev libwnck-dev

# php-src
WORKDIR /php-gtk-build
RUN git clone -b PHP-8.2.18 https://github.com/php/php-src.git PHP-8.2.18

WORKDIR /php-gtk-build/PHP-8.2.18
RUN ./buildconf --force
RUN ./configure --prefix=/usr/local/php-gtk3 --disable-cgi --disable-shared --enable-static --with-pgsql --with-pdo-mysql --with-pdo-pgsql --with-pgsql --with-ffi --with-readline --with-openssl --enable-soap --enable-sockets --with-bz2 --with-zlib --enable-mbstring --with-curl --with-xsl
RUN make -j 4 && make install 
ENV PATH=${PATH}:/usr/local/php-gtk3/bin

# php-cpp
WORKDIR /php-gtk-build
RUN git clone https://github.com/fast-debug/PHP-CPP.git 
WORKDIR /php-gtk-build/PHP-CPP
RUN make -j 4 && make install

# exports
ENV PATH=${PATH}:/php-gtk-build
WORKDIR /php-gtk-build
COPY run.sh ./
ENTRYPOINT ["run.sh"]