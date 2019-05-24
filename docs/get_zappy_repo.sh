#!/bin/bash

git clone git@git.epitech.eu:/quentin.liardeaux@epitech.eu/PSU_zappy_2018 && \
cd PSU_zappy_2018 && \
git remote add gitlab git@gitlab.nwmqpa.com:qLiardeaux/PSU_zappy_2018.git && \
git checkout master && \
git pull origin master && \
git pull gitlab master && \
git branch develop && \
git checkout develop && \
git pull origin develop && \
git pull gitlab develop
