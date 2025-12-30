#include <stdio.h>
#include <string.h>
#include <time.h>

#define SERIAL_PORT "/dev/ttyUSB0"
#define LOG_FILE "object_log.csv"

int extract_distance(const char *line) {
    int distance = -1;
    sscanf(line, "Object detected, distance = %d cm", &distance);
    return distance;
}

int main(void) 
{
   
    FILE *serial = fopen(SERIAL_PORT, "r");
    if (!serial) 
    {
        perror("Error opening serial port");
        return 1;
    }

    // Open log file (create if not exists)
    FILE *log = fopen(LOG_FILE, "a");
    if (!log) 
    {
        perror("Error opening log file");
        fclose(serial);
        return 1;
    }

    printf("Data logger started...\n");
    printf("Listening on %s\n", SERIAL_PORT);

    char line[256];
    int last_distance = -1;

    while (1) {
        // Read one line from serial
        if (fgets(line, sizeof(line), serial))
        {

            // Remove newline characters
            line[strcspn(line, "\r\n")] = 0;

            // Extract distance
            int current_distance = extract_distance(line);

            // Check valid detection & distance change
            if (current_distance > 0 &&
                current_distance != last_distance) {

                // Get current time
                time_t now = time(NULL);
                struct tm *t = localtime(&now);

                char timestamp[32];
                strftime(timestamp, sizeof(timestamp),
                         "%Y-%m-%d %H:%M:%S", t);

                // Write log entry
                fprintf(log, "%s,DETECTED,%d\n",
                        timestamp, current_distance);
                fflush(log);  // ensure immediate write

                printf("Logged: %s | distance = %d cm\n",
                       timestamp, current_distance);

                last_distance = current_distance;
            }
        }
    }

    fclose(serial);
    fclose(log);
    return 0;
}

