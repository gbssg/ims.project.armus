#ifndef DRIVE_CONTROL_H
#define DRIVE_CONTROL_H

extern int richtungl;
extern int richtungr;

extern long aktuelleZeit;

extern bool update;

void setupDC();
void driveControl(int rl, int rr);
#endif
