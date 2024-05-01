from pathlib import Path
import pandas as pd
import pyvista as pv

from writer import VTIWriter


def load_data(filename: Path | str) -> pd.DataFrame:
    header = ["t", "name", "mass", "x", "y", "z", "v_x", "v_y", "v_z"]
    data = pd.read_csv(filename)
    data.columns = header
    return data


def group_by_time(data: pd.DataFrame):
    return data.groupby("t")


def get_data_as_dict(data: pd.DataFrame) -> dict:

    dict_data = {
        "mass": data["mass"].values,
        "position": data[["x", "y", "z"]].values,
        "velocity": data[["v_x", "v_y", "v_z"]].values,
        "name": data["name"].values,
    }
    return dict_data


if __name__ == "__main__":
    path = Path(__file__).resolve().parents[2] / "data.csv"
    data = load_data(path)
    data = group_by_time(data)

    directory = Path(__file__).parent / "data"
    vti_writer = VTIWriter(directory)

    for timestep, t_data in data:
        name = f"{int(timestep):010d}_data.vtk"
        dict_data = get_data_as_dict(t_data)
        vti_writer.write(dict_data, name, timestep=timestep)
    vti_writer.close()
