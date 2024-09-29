from setuptools import setup, Extension

math_matrix_module = Extension(
    'MatrixMath',
    sources = [
        'src/matrix_math_module.cpp'
    ]
)

setup(
    name = 'Math_with_matrix',
    version = '1.0.0',
    description = 'Python Package with function_for_multiple_matrix C++ extension',
    author = 'Anastasia Moroz',
    author_email = '',
    ext_modules = [math_matrix_module]
)