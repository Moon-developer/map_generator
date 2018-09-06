# map_generator
Generator a map for Bomberman, save and load game map.

### Requirements

This program uses boost and cmake. So on a mac make sure to install with the following commands.
```
brew install boost --c++11
brew install cmake
```

### Setup

To get the program working run the following commands
```
git clone https://github.com/Moondog360/map_generator.git
cd map_generator
mkdir build
cd build
cmake ..
make
```

Once done, you can now run the executable

### How-to

When running the executable, you give it two arguments. First argument is the seed number.
Second argument is the map level difficulty.
```
./create <seed> <difficulty>
```  

an example would be:
```
./create 15324 2
```
