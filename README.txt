READ ME FOR INSTRUCTIONS ON HOW TO USE POSITIONCALCULATION.EXE

positionCalculation.exe is a simple position calculation utility
that makes use of a library of custom functions and structures.
It starts by asking for the user's data, which includes you name,
latitude (in meters south of some reference latitude), longitude
(in meters west of some reference longitude), and altitude (in
meters relative to sea level). Then, the program askes if you want
to enter the other users' data manually or through a file. If you
choose manually, the data for each other user is entered in an 
identical manner as it was for your data. If you choose using a 
file, it will ask for a file name and take the data from there
(**NOTE** the data in your file must be formatted properly, as
outlined in the assignment documentation. For an example of what
the file should look like, see the file users.txt). The program
then calculates the distance between each other user and you,
displaying this data. Finally, the program tells you which other
user is the closest to you.