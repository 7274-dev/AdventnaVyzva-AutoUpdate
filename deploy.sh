#!/bin/usr/bash
sudo systemctl stop apache2
sudo rm -rf var/www/html/*
cd ~
sudo git clone https://github.com/7274-dev/AdventnaVyzva-Stranka.git
cd ~/AdventnaVyzva-Stranka/website/
sudo mv ~/AdventnaVyzva-Stranka/website/* /var/www/html
cd ~
sudo rm -rf ~/AdventnaVyzva-Stranka
sudo systemctl start apache2
