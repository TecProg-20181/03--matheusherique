/**
 * This file is part of Photopobre project.
 * @file main.c
 * @brief This file the main of project. Include all functions used in others
 * header.
 */

#include <stdio.h>
#include "photofilters.h"

int main() {
        log_debug("Main was initialized...");
        Image image;

        image = read_pixels_of_image(image);

        // Read one number to choose a image filter.
        int option_numbers;
        scanf("%d", &option_numbers);
        assert(&option_numbers != NULL);
        if(option_numbers <= 0){
                log_error("You have to select a number greater than or equal to 1!\n");
                assert(option_numbers != 0);
        }

        log_debug("%d option numbers have been selected...", option_numbers);

        if(!setjmp(s_jumpBuffer)) {
                // try
                for(unsigned int iterator = 1; iterator <= option_numbers; iterator++) {
                        if(iterator == 1) {
                                log_info("Loop %dst inside main...", iterator);
                        } else if(iterator == 2) {
                                log_info("Loop %dnd inside main...", iterator);
                        } else if(iterator == 3) {
                                log_info("Loop %drd inside main...", iterator);
                        } else {
                                log_info("Loop %dth inside main...", iterator);
                        }

                        // Read one number to choose a image filter.
                        int option;
                        scanf("%d", &option);
                        assert(&option != NULL);
                        log_info("%d case was chosen...", option);

                        switch(option) {
                                // Grayscale filter.
                                case 1: {
                                        log_debug("Initializing Grayscale filter...");
                                        image = grayscale(image);
                                        break;
                                }
                                // Sepia filter.
                                case 2: {
                                        log_debug("Initializing Sepia filter...");
                                        image = sepia_filter(image);
                                        break;
                                }
                                // Blur filter.
                                case 3: {
                                        log_debug("Initializing Blur filter...");
                                        image = blur(image);
                                        break;
                                }
                                // Rotate image.
                                case 4: {
                                        log_debug("Initializing Rotate image...");
                                        image = image_rotation(image);
                                        break;
                                }
                                // Mirror effect filter.
                                case 5: {
                                        log_debug("Initializing Mirror effect filter...");
                                        image = mirror_effect(image);
                                        break;
                                }
                                // Color invert filter.
                                case 6: {
                                        log_debug("Initializing Color invert filter...");
                                        image = color_invert(image);
                                        break;
                                }
                                // Cut image.
                                case 7: {
                                        log_debug("Initializing Cut image...");
                                        image = cut_image(image);
                                        break;
                                }
                                default: {
                                        log_warn("Selected case doesn't exist...");
                                }
                        }

                }

                print_pixels_of_image(image);
        } else {
                // catch
                log_error("Error %s occurred!\n", strerror(errno));
        }

        return 0;
}
