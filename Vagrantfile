# -*- mode: ruby -*-
# vi: set ft=ruby :
#
# Copyright 2014-present, Apstra, Inc. All rights reserved.
#
# This source code is licensed under End User License Agreement found in the
# LICENSE file at http://apstra.com/eula
#

Vagrant.configure(2) do |config|
  config.vm.box = "ubuntu-14.04"
  config.vm.box_url = "http://buildfiles/apstrktr/ubuntu-14.04-amd64-vbox.box"

  config.vm.network "forwarded_port", guest: 9999, host: 9999

  config.vm.provider "virtualbox" do |vb|
    vb.customize ["modifyvm", :id, "--natdnshostresolver1", "on"]
  end

  config.vm.synced_folder "vagrant-profile", "/home/vagrant/profile"

  config.vm.provision "shell", inline: <<-SHELL
    source ~/profile/.bashrc

    cd /vagrant
    if ! grep '127.0.0.1' /etc/hosts | grep mongodb; then
      sudo sed -i '/127.0.0.1/s|$| mongodb|' /etc/hosts
    fi

    # Installing mongodb-3.4.x
    sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv 0C49F3730359A14518585931BC711F9BA15703C6
    echo "deb [ arch=amd64 ] http://repo.mongodb.org/apt/ubuntu trusty/mongodb-org/3.4 multiverse" | \
        sudo tee /etc/apt/sources.list.d/mongodb-org-3.4.list
    sudo apt-get update
    sudo apt-get install -y mongodb-org

    # Installing python tools
    sudo apt-get install -y python-dev python-pip python-virtualenv
    sudo pip install -r requirements.txt

    # Installing Docker
    # https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/#install-using-the-repository
    sudo apt-get remove -y docker docker-engine docker.io
    sudo apt-get update
    sudo apt-get install -y \
        linux-image-extra-$(uname -r) \
        linux-image-extra-virtual \
        apt-transport-https \
        ca-certificates \
        curl \
        software-properties-common

    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    sudo add-apt-repository \
       "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
       $(lsb_release -cs) \
       stable"
    sudo apt-get update
    sudo apt-get install -y docker-ce
    sudo echo 'DOCKER_OPTS="--insecure-registry 10.1.2.21:5000"' >> /etc/default/docker
    sudo usermod vagrant -aG docker
    sudo service docker restart

    pip uninstall docker-py; pip uninstall docker; pip install docker

    # Installing Docker Compose
    sudo pip install -U docker-compose==1.14.0

    # Install test infra related stuff
    sudo apt-get install -y pkg-config libvirt-dev python-libvirt
    sudo apt-get install -y libffi6 libffi-dev libssl-dev
    sudo apt-get install -y git

    # Install mysql server
    DEBIAN_FRONTEND=noninteractive apt-get update
    sudo apt-get install -y mysql-server-5.5
    sudo apt-get install -y libmysqlclient-dev

    # Install python dependencies
    cd /vagrant
    sudo python /vagrant/setup_slicer.py develop
    sudo python /vagrant/setup_systest.py develop
    sudo python /vagrant/setup_concierge.py develop

    # Move back to home folder
    cd /vagrant
  
    # Emacs
    sudo apt-get install -y emacs
    cp -R /vagrant/emacs.d ~/.emacs.d

    # Vim
    # TODO
    # Download .vimrc from github

  SHELL
end
