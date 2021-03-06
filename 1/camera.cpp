#include <GL/glut.h>
#include <math.h>
#include <camera.h>

Camera::Camera()
{
  Position = Vector3(-1,0,0);
  ViewDir = Vector3(1,0,0);
  UpVector = Vector3(0,1,0);
}

void Camera::Render()
{
  // Find the point we are looking at
  Vector3 viewPoint = Position + ViewDir;
  gluLookAt(Position.x,Position.y,Position.z,
            viewPoint.x,viewPoint.y,viewPoint.z,
            UpVector.x,UpVector.y,UpVector.z);
}

void Camera::MoveForward( float d)
{
  Position = Position + ViewDir*d;
}

void Camera::RotateY( float theta )
{
  Vector3 rightDir = ViewDir.cross(UpVector);
  ViewDir = ViewDir*cos(theta) - rightDir*sin(theta);
  ViewDir.normalise();
}

void Camera::RotateX( float theta )
{
  Vector3 rightDir = ViewDir.cross(UpVector);
  ViewDir = ViewDir*cos(theta) + UpVector*sin(theta);
  UpVector = rightDir.cross(ViewDir);
  ViewDir.normalise();
  UpVector.normalise();
}
