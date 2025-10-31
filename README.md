# Digital RPG Sheet
This program is supposed to be an all-in-one program that does digitally everything that would normally be done with pen and paper for my [personal TTRPG project](https://docs.google.com/document/d/1X3FUnN8CY1-O3SPx0vCQ-vkcU-pxpgy2zVNcy9_-aCg/edit?usp=sharing).

## Installation, Use, and Updating
To install this program for personal use, find the [latest release](https://github.com/K00lmans/digital-RPG-sheet/releases/latest) and download the updater.zip files for your OS[^1]. Then, unzip the files to your preferred location and run updater.exe. All files included in the zipped folder must stay next to the updater.exe for it to work. The program will then automatically install itself as well as create the needed folders. As the name implies, to update this program, simply run the updater.exe and if there is an update avalible it will update itself. It is recommended to always start the program using the updater.exe; however, if you only want to start one subprogram or do not want to update, the individual exe files are within the data folder and can be independently launched.

## Running the Code Yourself
If you want to access the code itself, whether for contributing to this project or otherwise, first you must get the files onto your computer either by downloading it as a zipped file and unzipping it where you want it or by running the following git command.
```
git clone https://github.com/K00lmans/digital-RPG-sheet.git
```
Once you have the files, you must install the dependencies for this program. The easiest way would be to use vcpkg to automatically install the required dependencies. If you do not want to or cannot use vcpkg, then you must manually install the files listed in [vcpkg.json](/vcpkg.json) and then position them so that they can be found by CMAKE.

> [!WARNING]
> I personally use CLion to automatically manage all of these things and therefore can not provide specific help on how to do it manually.

Once you have the files on your computer, you must create a folder called `saves` somewhere in your filesystem. This file must be somewhere above your build/deployment folder for it to be found by the program.

## Roadmap
- [ ] [Version 1.0](https://github.com/K00lmans/digital-RPG-sheet/milestone/5)
  - [x] [Functional Updater](https://github.com/K00lmans/digital-RPG-sheet/issues/3)
  - [ ] [Functional Character Creator](https://github.com/K00lmans/digital-RPG-sheet/issues/4)
- [ ] [Linux Release](https://github.com/K00lmans/digital-RPG-sheet/milestone/3)
  - [ ] [Linux Updater](https://github.com/K00lmans/digital-RPG-sheet/issues/1)
  - [ ] [Linux Character Creator](https://github.com/K00lmans/digital-RPG-sheet/issues/2)
- [ ] [Character Sheet](https://github.com/K00lmans/digital-RPG-sheet/milestone/6)
  - [ ] [Sheet UI](https://github.com/K00lmans/digital-RPG-sheet/issues/6)
  - [ ] [Sheet Functionality](https://github.com/K00lmans/digital-RPG-sheet/issues/7)
- [ ] [Creator Leveling](https://github.com/K00lmans/digital-RPG-sheet/milestone/7)
  - [ ] [Expand UI](https://github.com/K00lmans/digital-RPG-sheet/issues/8)
  - [ ] [Ability Selection](https://github.com/K00lmans/digital-RPG-sheet/issues/9)
  - [ ] [Leveling System](https://github.com/K00lmans/digital-RPG-sheet/issues/10)
- [ ] [Homebrew Creator/Editor](https://github.com/K00lmans/digital-RPG-sheet/milestone/8)
  - [ ] [Base System](https://github.com/K00lmans/digital-RPG-sheet/issues/11)
  - [ ] [Lineages](https://github.com/K00lmans/digital-RPG-sheet/issues/12)
  - [ ] [Abilities](https://github.com/K00lmans/digital-RPG-sheet/issues/13)
  - [ ] [Backgrounds](https://github.com/K00lmans/digital-RPG-sheet/issues/14)
  - [ ] [Items](https://github.com/K00lmans/digital-RPG-sheet/issues/15)
- [ ] [Better Updater](https://github.com/K00lmans/digital-RPG-sheet/milestone/9)
  - [ ] [UI Loading Bar](https://github.com/K00lmans/digital-RPG-sheet/issues/16)
  - [ ] [Application Selection Window](https://github.com/K00lmans/digital-RPG-sheet/issues/5)
  - [ ] [Detailed Update Information](https://github.com/K00lmans/digital-RPG-sheet/issues/18)
  - [ ] [Make Pretty](https://github.com/K00lmans/digital-RPG-sheet/issues/19)
- [ ] [Mac Release](https://github.com/K00lmans/digital-RPG-sheet/milestone/10)
  - [ ] [Mac Updater](https://github.com/K00lmans/digital-RPG-sheet/issues/20)
  - [ ] [Mac Character Creator](https://github.com/K00lmans/digital-RPG-sheet/issues/21)
- *More to come!*

## Repository Info
![GitHub contributors](https://img.shields.io/github/contributors/k00lmans/digital-RPG-sheet)
![GitHub Downloads (all assets, all releases)](https://img.shields.io/github/downloads/k00lmans/digital-RPG-sheet/total)
![GitHub Release](https://img.shields.io/github/v/release/k00lmans/digital-RPG-sheet?label=version)
![GitHub commits since latest release](https://img.shields.io/github/commits-since/k00lmans/digital-RPG-sheet/latest)
![GitHub License](https://img.shields.io/github/license/k00lmans/digital-RPG-sheet)

[^1]: Currently, Windows only.
