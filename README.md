# clips
Command Line Interface Programs

This is a project to replace GNU Coreutils with a set of programs, written entirely in c/c++, and licensed to be more permissive.

You are expected to understand that all files are currently released under the MIT license but will be released under the LOLicense (Hereby referred to as LOL) once its details are ironed out.

Files that are in a ready to use state will be under a directory using the format "READY-foo".

Files that are in a work in progress state will be under a directory using the format "WIP-bar".

All programs can be run with the argument "help" or "info" to get more information on using the program.  Man pages will be created for all programs at a later date.

A make file for the full set of clips utils will be created when all programs are deemed sufficient to replace GNU Coreutils.  Make files for each program will be created as time goes on.  Currently you are not expected to use these as a full replacement for the GNU Coreutils.

If a make file exists in a programs directory that means that I currently use the program on my system without issue.
***This does not mean that the program is guaranteed to work without issue.  Use at your own risk.***

If you have any requests for a specific program to be completed but do not see a directory for it please submit it as an issue and I will attempt to work on it ASAP.

A current list of the programs, their status and what they are intended to replace can be found in files.txt.

***Currently all clips are compiled using clang++.***
