#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>

void print_error(const char *message)
{
    fprintf(stderr, "Error: %s\n", message)
}