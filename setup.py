from setuptools import setup, Extension
import pybind11

setup(
    name='world_tokenizer_cpp',
    version='1.2',
    description='Python package with C++ extension',
    ext_modules=[
        Extension(
            'world_tokenizer_cpp',
            sources=['world_tokenizer_python.cpp'],
            include_dirs=[pybind11.get_include()],
            language='c++',
            extra_compile_args=['-std=c++20'],
        ),
    ],
)