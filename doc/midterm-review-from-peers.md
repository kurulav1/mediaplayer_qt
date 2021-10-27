# Midterm review form for Media Player 7

**Name of project to be reviewed: media-player-2019-7**

**Names of reviewers:** Media Player 5
- Henri Tuovinen
- Sakari Sarkkinen
- Lauri Koskenniemi
- Axel Ojutkangas

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2p)

    * The implementation is clear and corresponds well with the selected topic and scope. However, we think there could have been more planned features
    considering the size of the group (4 people). 1p  
    <br />


  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

    * The structure uses standard Qt implementations for media playback and is well structured and easy to interpret.
    This has the drawback of making addition of new features difficult, but since the project is still a work in progress, this is fine.
    We wish there were more comments in the code. 2p  
    <br />



  * 1.3: Use of external libraries is justified and well documented. (2p)

    * The project uses Qt and Qt Multimedia module. This is well documented in README.md. 2p  




## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

    * Git commits have been very frequent and each commit has a clear, descriptive log.
    Branches have not been used frequently at the time of this report. 2p  
    <br />



  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

    * The group has 4 people and one has been selected to be the project manager.
    There are no additional responsibilities assigned besides the project manager,
    so it is not very clear who implements what part of the project. 1p  
    <br />



  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

    * The project does not currently have anything regarding testing the code.
    The project is a work in progress, and uses mostly existing Qt implementations, so this is mostly fine. 1p  



## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

    * Building and using the software is well documented in README.md. 2p  
    <br />



  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

    * Memory management has not been implemented. There are no destructors in the header files.
    We hope these will be implemented. 1p  
    <br />



  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

    * The project uses existing Qt implementations, which is appropriate and wise. 2p  
    <br />




  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

    * There are no try - catch error handling implemented. The implementations are standard Qt so error handling should be mostly unnecessary. 2p  



## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (0-10p)

    * The basic functions are part of the features. 2p  
    Metadata 2p  
    Supports multiple audio formats 2p  
    Audio file listing, searching and sorting 2p  
    <br />
    If these are implemented, the total is 8p  
