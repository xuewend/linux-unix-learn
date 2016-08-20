#ifndef SIGNAL_FUNCTIONS_H
#define SIGNAL_FUNCTIONS_H

#include <signal.h>
#include "../lib/tlpi_hdr.h"

int printSigMask(FILE *,const char *);
int printPendingSigs(FILE *,const char *);

void printSigset(FILE *,const char *,const sigset_t *mask);

#endif
