#! /bin/bash

function start_container() {
    gcc=$(docker ps -f status=running -f name=gcc -q)
    if [[ "$gcc" != "" ]]; then
       echo "Container already up"
       return
    fi
    docker build -t gcc:latest .
    docker run --name gcc -td -v ${PWD}:/usr/src gcc:latest
}

start_container
docker exec -it gcc /bin/bash
