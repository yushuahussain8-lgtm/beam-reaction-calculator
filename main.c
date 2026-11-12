#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Read one number from the terminal. Return 1 on success or 0 on error. */
static int read_number(const char *prompt, double *value) {
    char line[128];
    char *end;

    printf("%s", prompt);
    fflush(stdout);

    if (!fgets(line, sizeof line, stdin)) return 0;
    if (!strchr(line, '\n') && !feof(stdin)) return 0;

    errno = 0;
    double number = strtod(line, &end);
    if (end == line || errno == ERANGE || !isfinite(number)) return 0;

    while (isspace((unsigned char)*end)) end++;
    if (*end != '\0') return 0;

    *value = number;
    return 1;
}

int main(void)

{
    double span, load, distance;

    puts("Beam Reaction Calculator");

    if (!read_number("Beam span (m): ", &span) || span <= 0) 
    
    {
        puts("Enter a span greater than zero.");
        return 1;
    }

    if (!read_number("Downward point load (kN): ", &load) || load < 0)
    
    {

        puts("Enter a load of zero or more kN.");
        return 1;
    }

    if (!read_number("Distance from left support (m): ", &distance) ||
        distance < 0 || distance > span) 
        
        {

        printf("Enter a distance between 0 and %g m.\n", span);
        return 1;
    }

    /* Take moments about each support to find the opposite reaction. */
    double rightReaction = load * (distance / span);
    double leftReaction = load * ((span - distance) / span);

    printf("Left support reaction: %.2f kN upward\n", leftReaction);
    printf("Right support reaction: %.2f kN upward\n", rightReaction);

    return 0;
}