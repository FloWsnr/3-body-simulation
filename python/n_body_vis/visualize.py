from pathlib import Path

import pandas as pd
import pyvista as pv


def load_data(filename: Path | str):
    header = ["t", "name", "mass", "x", "y", "z", "v_x", "v_y", "v_z"]
    data = pd.read_csv(filename)
    data.columns = header
    return data


def group_by_time(data: pd.DataFrame):
    return data.groupby("t")


def visualize(data: pd.DataFrame):
    names = data["name"].values
    masses = data["mass"].values
    points = data[["x", "y", "z"]].values
    vel = data[["vel_x", "vel_y", "vel_z"]].values
    grid = pv.PolyData(points)
    grid["name"] = names
    grid["mass"] = masses
    grid["velocity"] = vel
    grid.plot(show_edges=True)


if __name__ == "__main__":
    path = Path(__file__).resolve().parents[2] / "data.csv"
    data = load_data(path)
    data = group_by_time(data)

    # iterate over each time step
    for timestep in data:
        visualize(timestep)
