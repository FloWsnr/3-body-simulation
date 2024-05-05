from pathlib import Path
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


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


class Matplotlib_Vis(Visualization):
    def __init__(self, csv_file: Path | str):
        super().__init__(csv_file)

        self.fig = plt.figure(figsize=(10, 10))
        self.ax = self.fig.add_subplot(projection="3d")
        # limits of the axis (x, y, z)
        self.ax.set_xlim3d([-3e11, 3e11])
        self.ax.set_ylim3d([-3e11, 3e11])
        self.ax.set_zlim3d([-10e10, 10e10])
        self.scatter = self.ax.scatter([], [], [])

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
        self.scatter.set_edgecolor("black")
        self.scatter.set_alpha(0.9)
        self.ax.set_title(f"Time: {frame}")

    def animate(self):
        frames = self.data_groups.groups.keys()
        ani = animation.FuncAnimation(
            self.fig, self.update_scatter, frames=frames, interval=10
        )

        # To save the animation using Pillow as a gif
        writer = animation.PillowWriter(
            fps=120, metadata=dict(artist="Me"), bitrate=1800
        )
        ani.save("scatter.gif", writer=writer)
        plt.show()


if __name__ == "__main__":
    path = Path(__file__).resolve().parents[2] / "data.csv"
    vis = Matplotlib_Vis(path)
    vis.animate()
