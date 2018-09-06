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
./create <seed between 1 - 5> <difficulty>
```  

seed number greater than 5 or smaller than 1 has been set to randomly generator.

an example would be:
```
./create 6 2
```

### Functions

To get the dir the map gets saved to, call the following function.
```
LevelObj.getDir( void );
```  
To set map width and height, call the following function.
```
LevelObj.dimension(10, 30); // pass in width then height
```  
To set a map difficulty, call the following function.
```
LevelObj.difficulty(2); // difficulty between 1 - 3
```  
To change where to save the file, call the following function.
```
LevelObj.changeDir("Path/To/Dir");
```  
To show debug messages, we can toggle it on/off. call the following function
```
// toggle on
LevelObj.debug();
// toggle off
LevelObj.debug();
```  
To get the height/Width of the map, call the following function.
```
LevelObj.getHeight();
LevelObj.getWidth();
```  
To generate a map, call the following function.
```
LevelObj.makeMap(1); // give a seed between 1-5, any number other than that it will create a random map
```  
To save the current map, call the following function.
```
LevelObj.save(map); // pass it the generated map
```  
To load the map
```
LevelObj.load(); // returns a map from a saved file if saved.
```  


