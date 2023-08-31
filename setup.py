from setuptools import setup
from setuptools import find_packages

setup(
    name='secm',
    version='0.1.0',
    description='API to control sensolytics SECM and SDC',
    url='https://git.rwth-aachen.de/henrik.spitzenpfeil/secm',
    author='Henrik Spitzenpfeil',
    author_email='henrik.spitzenpfeil@rwth-aachen.de',
    license= 'BSD 2-clause',
    packages=find_packages(),
    include_package_data=True,
    classifiers= [
        'Development Status :: 2 - Pre-Alpha',
        'Intended Audience :: Science/Research',
        'Operating System :: Windows',
        'Programming Language :: Python :: 3'
        ],
)


