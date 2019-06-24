[![Build Status](https://gitlab.nwmqpa.com/qLiardeaux/PSU_zappy_2018/badges/master/build.svg)](https://gitlab.nwmqpa.com/qLiardeaux/PSU_zappy_2018/pipelines/)
[![coverage report](https://gitlab.nwmqpa.com/qLiardeaux/PSU_zappy_2018/badges/master/coverage.svg)](https://gitlab.nwmqpa.com/qLiardeaux/PSU_zappy_2018/commits/master)
# Zappy

Year-End Epitech project.

### Installing

```
make
```

## Running the tests

```
make tests_run
```

## How to run
### Server:

```
./zappy_server -p 6000 -x 30 -y 30 -f 1000 -c 3 -n "team1" "team2"
```
* -p --port: set at which port to listen for ai clients
* -x --width: set width of the map
* -y --height: set height of the map
* -f --freq: frequence of the server
* -c --clients: number of clients by team
* -n --names: names of the teams
* -r --resources: use a personal resource file in csv format (optional)

### AI:
```
./zappy_ai -p 6000 -h "127.0.0.1" -n "team1"
```
* -p: port to listen to server
* -h: hostname of the server
* -n: team name of the client

### Graphical:
```
./zappy_graphical -p 6001 -h "127.0.0.1"
```
* -p: port to listen to server (+1 to ai port by default)
* -h: hostname of the server

## Authors

* **Quentin Liardeaux**
* **Loan Petit**
* **Antoine Herbosa**
* **Hugo Trinh-quy**
* **Niels George-peillex**
* **Kilian Perrier**
