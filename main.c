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
        log_info("%d option numbers have been selected...", option_numbers);

        if (!setjmp(s_jumpBuffer)) {
                // try
                for(int iterator = 0; iterator < option_numbers; ++iterator) {
                        log_debug("Loop %d inside main...", iterator);
                        // Read one number to choose a image filter.
                        int option;
                        scanf("%d", &option);
                        log_info("%d case was chosen...", option);

                        switch(option) {
                                // Grayscale filter.
                                case 1: {
                                        log_debug("Grayscale filter was initialized...");
                                        image = grayscale(image);
                                        break;
                                }
                                // Sepia filter.
                                case 2: {
                                        log_debug("Sepia filter was initialized...");
                                        image = sepia_filter(image);
                                        break;
                                }
                                // Blur filter.
                                case 3: {
                                        log_debug("Blur filter was initialized...");
                                        image = blur(image);
                                        break;
                                }
                                // Rotate image.
                                case 4: {
                                        log_debug("Rotate image was initialized...");
                                        int how_many_times = 0;
                                        scanf("%d", &how_many_times);
                                        image_rotation (how_many_times, image);
                                        break;
                                }
                                // Mirror effect filter.
                                case 5: {
                                        log_debug("Mirror effect filter was initialized...");
                                        image = mirror_effect(image);
                                        break;
                                }
                                // Color invert filter.
                                case 6: {
                                        log_debug("Color invert filter was initialized...");
                                        image = color_invert(image);
                                        break;
                                }
                                // Cut image.
                                case 7: {
                                        log_debug("Cut image was initialized...");
                                        image = cut_image(image);
                                        break;
                                }
                                default: {
                                        log_warn("Selected case doesn't exist...");
                                }
                        }

                }

                print_pixels_of_image(image);
                log_debug("The pixels of image was successfully printed!");
        } else {
                // catch
                log_error("An error occurred in main...");
        }

        return 0;
}
