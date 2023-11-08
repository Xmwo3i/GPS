# GPS

This program calculates the distance between a reference user and other users based on their geographical positions (latitude, longitude, and altitude). It then identifies the closest user to the reference user.

## Table of content
- [Introduction](#introduction)
- [Input](#input)
- [Output](#output)
- [How to Use](#how-to-use)
- [Note](#note)
- [Author](#author)

  

## Introduction

This User Distance Calculator is a C program designed to determine the closest user to a reference user based on their geographical coordinates. It calculates the distances using latitude, longitude, and altitude, providing valuable insights into proximity.

## Input

The program takes input from the user and an input text file:

1. User details (reference user):
    - Enter the reference user's details, including Name, Latitude, Longitude, and Altitude.
    - The user is prompted to enter this information manually.

2. Other Users:
    - An input text file should be provided with the data for other users.
    - The first line of the file should be an integer, indicating the number of other users.
    - Each following line should contain data for each other user, including Name, Latitude, Longitude, and Altitude.
    - Users are read from the text file for the calculation.

## Output

The program produces the following output:

1. User Details:
    - Reference User's Name, Latitude, Longitude, and Altitude.

2. List of Other Users:
    - Name, Latitude, Longitude, and Altitude of other users.

3. Actual Distances:
    - The calculated distances between the reference user and other users.
    - The user number, distance, and name of each user are displayed.

4. Nearest User:
    - The user name, latitude, longitude, and altitude of the nearest user to the reference user.
    
## How to Use

1. Compile the program using your preferred C environment.
2. Run the compiled program.
3. Follow the on-screen instructions to provide user details for the reference user.
4. Enter the path to an input text file that contains the data for other users.
5. The program will calculate distances and display the results.

## Note

Make sure the input file follows the specified format for a successful run of the program.

## Author

Prepared by: Mostafa Faghani

Enjoy using the User Distance Calculator!
