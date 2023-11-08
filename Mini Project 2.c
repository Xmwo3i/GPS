#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define structures for user and distance
struct User
{
    char name[100];
    double latitude;
    double longitude;
    double altitude;
};

struct Distance
{
    char name[100];
    double distance;
};

double calculate_distance(struct User user1, struct User user2)
{
    double lat_diff = user1.latitude - user2.latitude;
    double long_diff = user1.longitude - user2.longitude;
    double alt_diff = user1.altitude - user2.altitude;
    return sqrt(lat_diff * lat_diff + long_diff * long_diff + alt_diff * alt_diff);
}

void scan_user(struct User *user)
{
    printf("Enter user details (Name Latitude Longitude Altitude): ");
    scanf("%s %lf %lf %lf", user->name, &user->latitude, &user->longitude, &user->altitude);
}

void fill_users(struct User *our_user, struct User **other_users, int *num_users)
{
    // Input data for our user
    printf("Enter your details (Name Latitude Longitude Altitude): ");
    scan_user(our_user);

    printf("Enter the path of the input text file: ");
    char file_path[100];
    scanf("%s", file_path);

    FILE *input_file = fopen(file_path, "r");

    if (input_file == NULL)
    {
        printf("Failed to open the input file.\n");
        exit(1);
    }

    // Read the number of other users from the file
    fscanf(input_file, "%d", num_users);

    // Allocate memory for other_users
    *other_users = (struct User *)malloc(*num_users * sizeof(struct User));

    // Input data for other users from the file
    for (int i = 0; i < *num_users; i++)
    {
        fscanf(input_file, "%s %lf %lf %lf", (*other_users)[i].name, &(*other_users)[i].latitude, &(*other_users)[i].longitude, &(*other_users)[i].altitude);
    }

    fclose(input_file);
}

void calculate_distances(struct User our_user, struct User *other_users, int num_users, struct Distance *distances)
{
    for (int i = 0; i < num_users; i++)
    {
        distances[i].distance = calculate_distance(our_user, other_users[i]);
        strcpy(distances[i].name, other_users[i].name);
    }
}

struct User find_closest_user(struct Distance *distances, struct User *other_users, int num_users)
{
    struct User closest_user = other_users[0];
    double closest_distance = distances[0].distance;

    for (int i = 1; i < num_users; i++)
    {
        if (distances[i].distance < closest_distance)
        {
            closest_distance = distances[i].distance;
            for (int j = 0; j < num_users; j++)
            {
                if (strcmp(distances[j].name, distances[i].name) == 0)
                {
                    closest_user = other_users[j];
                    break;
                }
            }
        }
    }

    return closest_user;
}

int main()
{
    struct User our_user;
    struct User *other_users = NULL;
    int num_users;

    // Fill the user data from the input text file
    fill_users(&our_user, &other_users, &num_users);

    // Calculate distances between our user and other users
    struct Distance *distances = (struct Distance *)malloc(num_users * sizeof(struct Distance));
    calculate_distances(our_user, other_users, num_users, distances);

    // Display user details
    printf("Reference user:\n");
    printf("User %s:\n", our_user.name);
    printf("Latitude %.2lf\n", our_user.latitude);
    printf("Longitude %.2lf\n", our_user.longitude);
    printf("Altitude  %.2lf\n", our_user.altitude);
    printf("\nList of other users:\n");

    for (int i = 0; i < num_users; i++)
    {
        printf("User %s:\n", other_users[i].name);
        printf("Latitude %.2lf\n", other_users[i].latitude);
        printf("Longitude %.2lf\n", other_users[i].longitude);
        printf("Altitude  %.2lf\n", other_users[i].altitude);
        printf("\n");
    }

    // Display distances and find the closest user
    printf("Actual distances from our user were:\n");
    for (int i = 0; i < num_users; i++)
    {
        printf("User number: %d at distance %.6lf named %s\n", i, distances[i].distance, distances[i].name);
    }

    struct User closest = find_closest_user(distances, other_users, num_users);

    printf("\nNearest user to reference user:\n");
    printf("User %s:\n", closest.name);
    printf("Latitude %.2lf\n", closest.latitude);
    printf("Longitude %.2lf\n", closest.longitude);
    printf("Altitude  %.2lf\n", closest.altitude);

    // Free dynamically allocated memory
    free(other_users);
    free(distances);

    return 0;
}
