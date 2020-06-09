# Setup

1. Open a terminal and run `sudo mongod --dbpath /media/connor/DATA/Documents/db` to open a database
2. run `make mode=DEBUG` to build the executable (you can also use INFO, WARNING, or ERROR)
3. run `./output/emmoria` to start the game

Currently the database is locked onto my own computer.


Things I've learned

Singleton patterns make things easy but confusing.
Using the Observer pattern saves a ton of draw calls by delegating a single draw to a tilemap

This also isn't anywhere near publishing and the data isn't published here because I haven't separated the data from the db itself which is surprisingly large
I just wanted to have people be able to see this stuff if they were curious