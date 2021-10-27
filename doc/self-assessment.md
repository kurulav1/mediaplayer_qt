# Review form for project media-player-2019-7

**Name of project to be reviewed:** media-player-2019-7

**Names of reviewers:**
Atte Lautanala

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2p)



  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)



  * 1.3: Use of external libraries is justified and well documented. (2p)



## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)



  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)



  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)



## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2 / 2p)

    Building the software is documented in the project documentation and
    README file. When all library dependencies are installed, building the
    application requires only two commands: `cmake .` and `make`.

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2 / 2p)

    Dynamic memory allocation is used only when absolutely necessary.
    Ownership of dynamically allocated objects is passed to Qt library, which
    deletes them at appropriate time. Based on a test run with `valgrind`,
    memory leak does not occur within code of this application. However, some
    linked libraries have memory leaks.

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2 / 2p)

    C++ standard library containers and Qt classes and other functionality is
    used extensively in this application. No own solutions are used for
    container classes, for example.

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2 / 2p)

    The application has been tested by loading invalid files, such as empty
    audio files. The app does survive these inputs. Exception handling is not
    used, but other error conditions which could cause exceptions, such as file
    is null, are checked where necessary.


## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (9 / 0-10p)

    The implemented additional features are audio browsing and loading from
    external directories, displaying audio information by reading metadata,
    listing played and loaded audio files, mini-player mode, and support for
    multiple audio formats. Listing audio files is worth two points with
    sorting and searching, however, these are not implemented, so it counts
    as one point.

