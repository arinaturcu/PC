// Turcu Arina Emanuela 313CA

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void task_2(int** map, int* dim); // ARE CITIRI

void modify(int** map, int* dim, char type[1], int line, int index);

void swap(int** map, char type[1], int line, int index);

void delete(int** map, char type[1], int line, int index);
