# clips
Command Line Interface Programs

This is a project to replace GNU Coreutils with a set of programs, written entirely in c/c++, and licensed to be as permissive as possible.

Telegram for clips:  https://t.me/joinchat/KG5lhAvsbtt7uQfOGkBr9g

Telegram for LOLicense: https://t.me/lolicense

***A current list of the programs, their status and what they are intended to replace can be found in files.md.***

## Goals
The end goal of clips is to provide users with a MIT-Like licensed group of CLI utilities in the vein of GNU Coreutils.  It will also expand upon the GNU set of utilities to provide additional functionality.  The source code, written in c/c++, should be easily understood, conform as closely as possible to c++ standards and hold close to the Unix philosphy.  Each program should do one job and do it well with as little overhead as possible.

## License
You are expected to understand that all files are currently released under the MIT license but will be released under the LOLicense (Hereby referred to as LOL) once its details are ironed out.

## Workflow
Information on each program can be found in files.md.
The information on each file is stored in a chart, from oldest to newest, with the following information:

Program name, Program it intends to replace, Directory, Function, Current State.

All programs can be run with the argument "help" or "info" to get more information on using the program.  Man pages will be created for all programs at a later date.

## Installation
A (recursive) make file for the full set of clips utils will be created when all programs are deemed sufficient to replace GNU Coreutils.  Make files for each program will be created as time goes on.  Currently you are not expected to use these as a full replacement for the GNU Coreutils.

If a make file exists in a programs directory, and is labeled as "READY" under Current State in files.md, that means that I currently use the program on my system without issue.
***This does not mean that the program is guaranteed to work without issue.  Use at your own risk.***

If you have any requests for a specific program to be completed but do not see a directory for it please submit it as an issue and I will attempt to work on it ASAP.

***Currently all clips are compiled using clang++.***

## Dependencies
Both of the following dependencies have to be installed: 
..* clang++
..* commandEr (https://github.com/Wittmaxi/CommandEr)
