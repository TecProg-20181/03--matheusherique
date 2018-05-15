/**
 * This file is part of Photopobre project.
 * @file calculations.c
 * @brief This file include all functions used for the calcules of project.
 *
 */

#include "calculations.h"

int minimum(int a, int b) {
        assert (&a != NULL);
        assert (&b != NULL);
        int which_input = 0;

        if (!setjmp(s_jumpBuffer)) {
                // try
                if (a < b) {
                        which_input = a;
                } else {
                        which_input = b;
                }
        } else {
                // catch
                log_error("Error %s occurred\n", strerror(errno));
        }

        return which_input;
}


int maximum(int a, int b) {
        assert (&a != NULL);
        assert (&b != NULL);
        int which_input = 0;

        if (!setjmp(s_jumpBuffer)) {
                // try
                if (a > b) {
                        which_input = a;
                } else {
                        which_input = b;
                }
        } else {
                // catch
                log_error("Error %s occurred\n", strerror(errno));
        }

        return which_input;
}
