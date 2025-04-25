#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdlib.h>

int skibisi = 0; // Initialize the variable skibisi to 0
char rate[10];
char rate2[10];

int main() {
    char string[100];
    bool exit_requested = false;
    char* moon = NULL;
    int divine = 0; // Initialize the variable divine to a default value

    initscr();    // Initialize ncurses
    curs_set(0);  // Hide the cursor

    while (!exit_requested) {
        clear();

        printw("input:\n");
        printw("Moons: Moons orbiting planets\n");
        printw("Planets:Rocks Orbiting the Universe.\n");
        printw("Physics:See The Laws of physics in space.\n");
        printw("Orbit: The Moon you are currently Orbiting\n");
        printw("Colonize: Make Your Space Empire\n");
        printw("Space: What is Outer-Space.\n");
        printw("Black Holes:Black Holes Are the remnant of a dead star.\n");
        printw("Plants:The Vegetables and Fruits in Space.\n");
        printw("Nebulae: Large Enormous Dust and gas clouds.\n");
        printw("Supernovae:A supernova is a powerful and luminous explosion of a star.\n");
        printw("Credit:The People* it took to make this.\n");
        printw("Stars:Those Shiny things you see on a dark clear night.\n");
        printw("Galaxies:Mini Universes in the universe.\n");
        printw("Spacecrafts: These vechiles were sent to space to explore.\n");
        printw("Heroes:Our Heroes who contributed massively to science.\n");
        printw("Signal:Call Humans to see stuff.\n");
        printw("History:Story of Space Race, MY FAVOURITE.\n");
        printw("Exit: To go back to the menu\n");

        refresh();

        scanw("%s", string);

        clear();

        if (strcmp(string, "Moons") == 0) {
            printw("Choose a moon to orbit:\n");
            printw("Titan\n");
            printw("Europa\n");
            printw("Triton\n");
            printw("Lunar\n");

            refresh();

            scanw("%s", string);
            moon = strdup(string);

            if (strcmp(moon, "Titan") == 0) {
                bool move = true;
                int x = 0;
                printw("TITAN IS A MOON WITH HAZARD LEVEL B AND LOW RADIATION");
                refresh();
                sleep(5);
                clear();
                while (move) {
                    clear();
                    mvprintw(0, x, "#");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "d") == 0) {
                        x += 2;
                    }

                    if (strcmp(string, "a") == 0) {
                        x -= 2;
                    }

                    if (strcmp(string, "Exit") == 0) {
                        move = false;
                    }
                }
            } else if (strcmp(moon, "Europa") == 0) {
                bool move = true;
                int x = 0;
                printw("WARNING: WHEN MOVING ON EUROPA YOU WILL MOVE FARTHER THAN YOU EXPECTED\n");
                printw("EUROPA IS A HAZARD LEVEL S AND HAS HIGH RADIATION");
                refresh();
                sleep(8);
                clear();

                while (move) {
                    clear();
                    mvprintw(0, x, "#");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "d") == 0) {
                        x += 5;
                    }

                    if (strcmp(string, "a") == 0) {
                        x -= 5;
                    }

                    if (strcmp(string, "Exit") == 0) {
                        move = false;
                    }
                }
            } else if (strcmp(moon, "Triton") == 0) {
                bool move = true;
                int x = 0;
                int direction = 1;  // 1 represents moving forward, -1 represents moving backward
                if (skibisi == 0) {
                    printw("THERE IS NO DATA OF TRITON, GET DATA OF TRITON");
                }
                if (skibisi == 1) {
                    printw("TRITON HAS THE LEVEL %s HAZARD AND HAS %s RADIATION", rate2, rate);
                }
                refresh();
                sleep(5);
                clear();
                while (move) {
                    clear();
                    mvprintw(0, x, "#");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "d") == 0) {
                        x += 2 * direction;  // Move forward or backward based on the direction
                        direction *= -1;     // Reverse the direction for the next movement
                    }

                    if (strcmp(string, "a") == 0) {
                        x -= 2 * direction;  // Move forward or backward based on the direction
                        direction *= -1;     // Reverse the direction for the next movement
                    }

                    if (strcmp(string, "Exit") == 0) {
                        move = false;
                    }

                    if (strcmp(string, "Rate") == 0) {
                        clear();
                        printw("How was the radiation on Triton? Rate it from Low, Medium, Hard: ");
                        refresh();
                        scanw("%s", rate);
                        clear();
                        printw("And how was the hazard? Rate it from S to F: ");
                        refresh();
                        scanw("%s", rate2);
                        clear();
                        printw("TRITON HAS THE HAZARD %s AND %s RADIATION", rate2, rate);
                        skibisi = 1;
                        refresh();
                        sleep(2);
                    }
                }
            } else if (strcmp(moon, "Lunar") == 0) {
                bool move = true;
                int x = 0;
                printw("LUNAR IS A MOON WITH HAZARD LEVEL S AND NO RADIATION");
                refresh();
                sleep(5);
                clear();
                while (move) {
                    clear();
                    mvprintw(0, x, "#");
                    mvprintw(15, 15, "||USA FLAG||");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "d") == 0) {
                        x += 2;
                    }

                    if (strcmp(string, "a") == 0) {
                        x -= 2;
                    }

                    if (strcmp(string, "Exit") == 0) {
                        move = false;
                    }
                }
            }

            free(moon);
            moon = NULL;
        } else if (strcmp(string, "Orbit") == 0) {
            if (moon) {
                clear();
                printw("You are currently orbiting: %s\n", moon);
                refresh();
                sleep(2);
            } else {
                clear();
                printw("You are not currently orbiting any moon\n");
                refresh();
                sleep(2);
            }
        } else if (strcmp(string, "Exit") == 0) {
            exit_requested = true;
        } else if (strcmp(string, "Colonize") == 0) {
            clear();
            printw("Which Moon would you like to colonize? You can only colonize once so choose wisely\n");
            refresh();
            scanw("%s", string);
            clear();
            if (divine == 1) {
                printw("You Cannot Colonize Your Planet, Scum\n");
                refresh();
                sleep(5);
                return 1;
            } else {
                if (strcmp(string, "Titan") == 0) {
                    printw("You have three-quarters of Saturn's land, but you cannot colonize any other moon.\n");
                    printw("More Cities\n");
                    printw("Less Cities\n");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "More Cities") == 0) {
                        refresh();
                        printw("More Cities are made");
                        int Cities = 10;
                        while (1) {
                            Cities++;
                            sleep(10);
                            break;
                        }
                        clear();
                        printw("There are now %d many cities", Cities);
                        refresh();
                        sleep(2);
                    } else if (strcmp(string, "Less Cities") == 0) {
                        refresh();
                        printw("Less Cities are made");
                        int Cities = 10;
                        while (1) {
                            Cities--;
                            sleep(10);
                            break;
                        }
                        clear();
                        printw("There are now %d many cities", Cities);
                        refresh();
                        sleep(2);
                    } 
            }  else if (strcmp(string, "Europa") == 0) {
                    printw("You have three-quarters of Jupiter's land, but you cannot colonize any other moon. The only way to colonize is through WHITE PEACE\n");
                    printw("White Peace\n");
                    printw("More Cities\n");
                    printw("Less Cities\n");
                    refresh();

                    scanw("%s", string);

                    if (strcmp(string, "White Peace") == 0) {
                        divine = 0;
                        clear();
                        printw("You can now colonize\n");
                        printw("You don't own any piece of Titan anymore\n");
                        refresh();
                        sleep(2);
                    } else if (strcmp(string, "More Cities") == 0) {
                        printw("More Cities are made");
                        int Cities = 10;
                        while (1) {
                            Cities++;
                            sleep(10);
                            break;
                        }
                        clear();
                        printw("There are now %d many cities", Cities);
                        refresh();
                        sleep(2);
                    } else if (strcmp(string, "Less Cities") == 0) {
                        printw("Less Cities are made");
                        int Cities = 10;
                        while (1) {
                            Cities--;
                            sleep(10);
                            break;
                        }
                        clear();
                        printw("There are now %d many cities", Cities);
                        refresh();
                        sleep(2);
                }
                        }
        }
    } else if (strcmp(string, "Signal") == 0) {
        printw("Sending Signals\n");
        sleep(5);
        printw("GET LOST, WE SENT YOU HERE BECAUSE WE HATE YOU.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Planets") == 0) {
        printw("The Sun: The sun isn't a planet but is very important star and we orbit it.\n");
        printw("Mercury: A planet closet to the sun and is not the hottest and is named after the god of financial gain.\n");
        printw("Venus: Finnaly the hottest and is named after the god of love.\n");
        printw("Earth:Our planet is in the goldilocks zone a scientific term for the area in space where it is not hot yeat not cold.\n");
        printw("Mars:Named after the god of war and is called the red planet.\n");
        printw("Jupiter:Named after the god of the sky and thunder and is the biggest planet.\n");
        printw("Saturn:Another god but one of time and has rings.\n");
        printw("Uranus:Named After god of heavens and orbits vertically not horzantally.\n");
        printw("Neptune:Finnaly Finished named after god of sea and is the farthest.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "History") == 0) {
        printw("Humans were only able to make that small step after several other space firsts happened. In 1957 the first artificial satellite, Sputnik 1, was launched into space by Russia.\n");
        printw("The United States launched several satellites of their own afterward. Both countries hoped to be the first to send a human into space.\n");
        printw("It wasn’t until 1961 that a person went to space: On April 12, Russia’s Yuri Gagarin became the first. Less than a month later the United States’ Alan Shepard became the first American in space.\n");
        printw("Following these milestones, President John F. Kennedy issued a challenge to the National Aeronautics and Space Administration (NASA) to put a human on the moon in 10 years or less.\n");
        printw("NASA went to work. On July 16, 1969, the spacecraft Apollo 11 prepared to launch a crew of three astronauts into space … and the history books.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Credits") == 0) {
        printw("Good job to HASSAN YOU GUESSED IT.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Heroes") == 0) {
        printw("Galileo Galilei: He Found the telescope and found moons on Jupiter and the rings of Saturn.\n");
        printw("Isaac Newton: discovered gravity and invented Calculus.\n");
        printw("Edmond Halley: discovered Halley's Comet.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Spacecraft") == 0) {
        printw("The ISS: The International Space Station is our main satitlite and is the most exspensive thing.\n");
        printw("Saturn V:The Rocket took in Apollo 11 to go to the Moon.\n");
        printw("Sputnik I:The first artificial satitlite known to man launched in 1957 by Russia.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Nebulae") == 0) {
        printw("Helix Nebula: Is a planetary nebula located 665+13 light-years away.\n");
        printw("Orion Nebula: diffuse nebula in the milky way galaxy located in Orion's Belt.\n");
        printw("Crab Nebula:The Crab Nebula is a supernova remant and a pulsar wind.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Galaxies") == 0) {
        printw("Milky Way: Not the chocolate bar, the galaxy we live in.\n");
        printw("Andromeda Galaxy: Also Known as Messier 31.\n");
        printw("Triangulum Galaxy: Also Known as Messier 33.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Space") == 0) {
        printw("Outer-Space is a vacuum that has everythig in the world and has planets and galaxies and the universe and moons and asteroids.\n");
        printw("And has stars and nebulae and black holes possibly white holes and comets and supernovas , collisions happening every second.\n");
        printw("Yet people don't see the beauty of space as it is the most crazy thing to think that there is an expanding universe but it is actually.\n");
        printw("I hope this makes you like space and realise it's beauty and its importance.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Aliens") == 0) {
        printw("Bro They Don't Exist You Have To Stop, TAKE A SHOWER.\n");
        printw("Self Destruction in 3.\n");
        sleep(1);
        printw("2.\n");
        sleep(1);
        printw("1");
        sleep(1);
        return 1;
    } else if (strcmp(string, "Physics") == 0) {
        refresh();
        clear();
        printw("First of all, NO GRAVITY.\n");
        printw("So You Fly everywhere.\n");
        printw("GOT IT.\n");
        refresh();
        clear();
        if (strcmp(string, "Yes") == 0) {
            printw("Second off, No Atmosphere so no AIR.\n");
            printw("So you can't breathe.\n");
            printw("GOT IT.\n");
            refresh();
            clear();
            if (strcmp(string, "Yes") == 0) {
                printw("Third off,THE WHOLE of Space is all inertia.\n");
                printw("Don't know what that means it means If nothing touchs you, YOU WILL MOVE IN A STRAIGHT LINE.\n");
                printw("GOT IT.\n");
                refresh();
                clear();
                if (strcmp(string, "Yes") == 0) {
                    printw("Now, you know space physics.\n");
                    printw("BYE.\n");
                    refresh();
                    clear();
                    
                    getch();
                    return 1;
                }
            }
        }
    } else if (strcmp(string, "Plants") == 0) {
        printw("Lettuce.\n");
        printw("Chinese Cabbages.\n");
        printw("Swiss Chard.\n");
        printw("Radishes.\n");
        printw("And Peas.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Stars") == 0) {
        printw("Sirius: The Brightest Star on the clear night sky no kidding sirius in greek means glowing.\n");
        printw("Rigel:Rigel is a blue supergiant star.\n");
        printw("Canopus:Canopus is the brightest star in the southern constellation of Carina and the second-brightest star in the night sky.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Supernovae") == 0) {
        refresh();
        clear();
        printw("Kepler's Supernova:The supernova remnant of SN 1604.\n");
        printw("Simeis 147:It was discovered in 1952 at the Crimean Astrophysical Observatory by Grigory Shajn.\n");
        printw("Vela SNR:The Vela supernova remnant is a supernova remnant in the southern constellation Vela.\n");
        
        getch();
        return 1;
    } else if (strcmp(string, "Black Holes") == 0) {
        clear();
        refresh();
        printw("TON 618:How could i forget they are the biggest thing in the universe and are a supermassive black holes and an AGN.\n");
        printw("Messier 61:Messier 61 is an intermediate barred spiral black hole.\n");
        printw("Hercules A:Hercules A is a bright astronomical radio source.\n");
        
        getch();
        return 1;
    }

    endwin();  // End ncurses

    return 0;
}
}

