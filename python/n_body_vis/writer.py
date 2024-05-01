from pathlib import Path
from typing import Union
from xml.etree import ElementTree as ET
import pyvista as pv
import numpy as np


class VTIWriter:
    def __init__(self, directory: Union[Path, str]) -> None:
        directory = Path(directory)
        directory.mkdir(parents=True, exist_ok=True)
        self.directory = directory

        self.pvd_file = self.directory / "data.pvd"
        self.pvd_root = ET.Element("VTKFile", type="Collection", version="0.1")
        self.pvd_collection = ET.SubElement(self.pvd_root, "Collection")

        self.vti_file = None
        self.polydata = None

    def write(self, data: dict, file_name: str, timestep: int = 0) -> None:
        """Adds multiple data arrays to a single file. The data is saved in a
        VTI file format.
        Furthermore, the data is added to a PVD file, which is a collection of all
        VTI files. This allows for easy visualization of the data in ParaView.
        """
        self._open_file(file_name)
        self._create_polydata(data["position"])
        for key, value in data.items():
            if key == "position":
                continue
            self._add_data(value, name=key)
        self._save_timestep(timestep)

    def close(self) -> None:
        if self.pvd_root is not None:
            self._save_pvd()

    def _open_file(self, file_name: str) -> None:
        vti_file = self.directory / file_name
        self.vti_file = vti_file

        if self.vti_file.exists():
            raise FileExistsError(f"File {self.vti_file} already exists")

    def _create_polydata(self, points: np.ndarray) -> None:
        self.polydata = pv.PolyData(points)

    def _add_data(self, data: np.ndarray, name: str = "value") -> None:
        self.polydata[name] = data

    def _save_timestep(self, timestep: int) -> None:
        self.polydata.save(self.vti_file)
        if self.pvd_root is not None:
            timestep = ET.SubElement(
                self.pvd_collection,
                "DataSet",
                timestep=str(timestep),
                file=str(self.vti_file.relative_to(self.directory)),
            )

    def _save_pvd(self) -> None:
        tree = ET.ElementTree(self.pvd_root)
        tree.write(self.pvd_file)
