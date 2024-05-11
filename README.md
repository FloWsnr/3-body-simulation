# 3-body-simulation

Small simulator for N body problems to learn C++ and some physics.
The simulator outputs a csv file with the positions of the bodies at each timestep.
These positions can be plotted with the python script provided.

## Showcase

The following gif shows the solar system simulation with the provided config file. The code
is sufficiently fast to simulate the solar system (10 bodies) for 1 billion seconds in around 5 min.

<img src="./images/solar_system.gif" width="500" />

Now, let's see what happens when we add a rogue sun to the solar system. The second sun has the same mass as
the original sun and quickly disrupts the orbits of the planets.

<img src="./images/two_suns.gif" width="500" />


## Installation

Install necessary packages
```bash
sudo apt-get install build-essential cmake
```

Install the python requirements
```bash
poetry install
```

## Usage
A json config is required with the following format:
```json
{
    "Logging": {
        "LogFile": "log.txt",
        "LogEvery": 1000
    },
    "Simulation": {
        "Timestep": 1,
        "Duration": 1000000,
        "DataFile": "data.csv",
        "WriteEvery": 1000
    },
    "Bodies": {
        "Body1": {
            "Name": "Mercury",
            "Mass": 3.301e23,
            "Pos": [
                57.909e9,
                0.0,
                0.0
            ],
            "Vel": [
                0.0,
                47.36e3,
                0.0
            ]
        },
        "Body2": {
            "Name": "Venus",
            "Mass": 4.867e24,
            "Pos": [
                108.209e9,
                0.0,
                0.0
            ],
            "Vel": [
                0.0,
                35.02e3,
                0.0
            ]
        }
    }
}
```
Then run the program with the config file as argument
```bash
./3-body-simulation -c config.json
```

Such a config for the solar system is provided in the app directory.
