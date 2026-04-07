from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "meu_modulo",
        ["modulos.cpp"],
        cxx_std = 17,
    ),
]

setup(
    name="meu_modulo",
    description="Parte final projeto programação estruturada",
    ext_modules=ext_modules,
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
)

