from pathlib import Path
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


from writer import VTIWriter


class Visualization:
    def __init__(self, csv_file: Path | str) -> pd.DataFrame:
        header = ["t", "name", "mass", "x", "y", "z", "v_x", "v_y", "v_z"]
        data = pd.read_csv(csv_file, header=None)
        data.columns = header
        self.data = data

    def _group_by_time(self):
        return self.data.groupby("t")


class VTP_Vis(Visualization):
    def __init__(self, csv_file: Path | str, vtp_dir: Path | str) -> pd.DataFrame:
        self.vti_writer = VTIWriter(vtp_dir)
        super().__init__(csv_file)

    def _get_data_as_dict(self, data: pd.DataFrame) -> dict:

        dict_data = {
            "mass": data["mass"].values,
            "position": data[["x", "y", "z"]].values,
            "velocity": data[["v_x", "v_y", "v_z"]].values,
            "name": data["name"].values,
        }
        return dict_data

    def write(self):
        grouped_data = self._group_by_time()
        for timestep, t_data in grouped_data:
            dict_data = self._get_data_as_dict(t_data)

            vti_file = f"{int(timestep):010d}_data.vtp"
            self.vti_writer.write(dict_data, vti_file, timestep=timestep)
        self.vti_writer.close()


from pathlib import Path
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


class Matplotlib_Vis(Visualization):
    def __init__(self, csv_file: Path | str):
        super().__init__(csv_file)

        self.fig = plt.figure(figsize=(10, 10))
        self.ax = self.fig.add_subplot(projection="3d")
        # limits of the axis (x, y, z)
        self.ax.set_xlim3d([-10e12, 10e12])
        self.ax.set_ylim3d([-10e12, 10e12])
        self.ax.set_zlim3d([-10e12, 10e12])
        self.scatter = self.ax.scatter([], [], [])

        # Reindex the time to 0,1,2,3 ... n instead of 0,1000,2000,3000 ... n*1000
        self.data["t"] = self.data["t"] // 86000

        # Normalize the mass with logaritmic scale
        self.data["mass"] = self.data["mass"].apply(lambda x: np.log(x))
        # Scale to 1-100
        self.data["mass"] = (self.data["mass"] - self.data["mass"].min()) / (
            self.data["mass"].max() - self.data["mass"].min()
        ) * 99 + 1

        self.data_groups = self._group_by_time()

        # colors for each planet and the sun
        self.colors = [
            "red",  # Mercury
            "yellow",  # Sun
            "orange",  # Venus
            "blue",  # Earth
            "red",  # Mars
            "brown",  # Jupiter
            "purple",  # Saturn
            "blue",  # Uranus
            "blue",  # Neptune
            "white",  # Pluto
        ]

    def update_scatter(self, frame):
        data_t = self.data_groups.get_group(frame)
        x = data_t["x"].values
        y = data_t["y"].values
        z = data_t["z"].values
        names = data_t["name"].values
        mass = data_t["mass"].values

        self.scatter._offsets3d = (x, y, z)
        self.scatter.set_sizes(mass)
        self.scatter.set_facecolor(self.colors)
        self.ax.set_title(f"Time: {frame}")

    def animate(self):
        frames = self.data_groups.groups.keys()
        ani = FuncAnimation(self.fig, self.update_scatter, frames=frames, interval=10)
        plt.show()


if __name__ == "__main__":
    path = Path(__file__).resolve().parents[2] / "data.csv"
    vis = Matplotlib_Vis(path)
    vis.animate()
