***Any and all contributions are appreciated and, given that they follow the guidelines and goals of the clips project, will be accepted.***

In terms of directory structure or data submission, when contributing to the clips project the following guidelines will make the inclusion of your code a less painful experience and assist in reaching our goals a quicker.  The guidelines are as follows (using clips/src/mvf as an example where examples are provided):

1. Each program will have it's own directory disignated as the programs name.  When possible a three letter abbreviation should be used.

2. The directory should contain at least the three files which will be standard for clips.  For example: mvf.cpp, README.md and our makefile standard. Additional files are allowed as needed but these three should be considered the minimum.

3. When commiting you should include an extended description that includes, at minimum, the following information: 
Program name, the GNU Coreutils program it intends to replace (or the new function it is adding that is not present in GNU Coreutils), the programs directory, the programs function, and its current state.  Please see clips/files.md for examples.

4. It is helpful, but not required of you, to give a list of the dependencies, which compiler you are using, and which operating system you are writing on.

5. It is expected that all contributions are written to follow posix standards as to reach the maximum number of users and be as OS independent as possible.

6. Any programs submitted that are not posix compliant should, if possible, include a version that is.  If the program must be OS dependent it is expected that this will be included in the details of the submission.

7. Coding style should follow the style found throughout all of the currently submitted programs.  Feel free to copy one of the programs already submitted and use it as a base.

8. Source file directories are expected to be in "clips/src/".  This keeps clips organized and easier to read.

9. Most major changes are made around midnight EST.  You are expected to pull before you make any changes to your code to ensure you are up to date with the repo.

10. Experimental libraries may be used.  If an experimental library is to be used you MUST state this in your submission.  This will allow for the proper amount of testing before it is deemed ready.  This will also allow those using or working on the program to understand any risks.

***If you feel like your submission should have been included and it was not please file an issue with what you committed, why you feel it should have been included and any other details to make your case and the code will be considered for a second time.***
