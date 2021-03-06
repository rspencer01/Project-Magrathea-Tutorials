/**
 * @file graphics.h
 * @author  Robert Spencer <robert.spencer94@gmail.com>
 * @section DESCRIPTION
 *
 * This file contains a number of useful functions to do with graphics.
 */


#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdarg.h>
#include <vector3.h>

/// Initialises the opengl and glut environment.
void initialiseGraphics();
/// Find the normal of a triangle described by two vectors
Vector3 getNormal3f(Vector3 edgeA, Vector3 edgeB);
/// Print the given formatted string to the screen at the given position
void writeString(int x, int y, const char* format, ... );
/// Resize the screen and set the projection
void resize(int width, int height);

#endif
