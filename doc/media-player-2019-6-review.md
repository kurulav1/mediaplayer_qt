# Review form for project media-player-2019-6

**Name of project to be reviewed:** media-player-2019-6

**Names of reviewers:** Atte Lautanala, Joona Kukkonen, Joonatan Syrjänen, Väinö Kurula

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2 / 2p)

    The project differs from the rest of the Media Player- projects as it aims to
    produce an audio processor instead of a simple media player. The amount of
    functionalities included provides enough work for everyone.

  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2 / 2p)

    The project and its components are appropriately divided into classes which
    are well-documented. Private class memebers are used and the files are named
    clearly.

  * 1.3: Use of external libraries is justified and well documented. (2 / 2p)

    The project’s use of third-party libraries is indicated nicely on the project
    tree and the components are well-used.


## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 / 2 p)

    The repository contains at a considerable amount of git commits which have
    been done frequently throughout the project. Commit messages are short and
    descriptive and the size is reasonable. The Git server is also used to
    track progress of the project and issues.

  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2 / 2p)

    All project members have made commits to the repository. Based on the
    commit log, the work has been distributed in a reasonable way to all team
    members. The division of roles is well defined in project plan and matches
    to commit log. All team members are implementing crucial parts of the
    application.

  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (1 / 2p)

    Quality assurance and testing principles have not been documented. The
    repository does contain some test code, but it does not contain
    instructions how the application can be tested. Issues have been documented
    on the Git server.


## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (1 / 2p)

    Project is using CMake to build the application. However, the repository
    does not contain any instructions on how to build the project or use it.
    The project does compile with `cmake . && make`. Output of CMake is missing
    from `.gitignore` so `git status` lists a lot of untracked files when the
    project has been built.

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (1 / 2p)

    Smart pointers have been used appropriately. `audio_` field of
    `MicrophoneSource` class is a pointer for which memory is dynamically
    allocated but it seems that the allocated memory is not released. The
    project plan does not document memory management practices.

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2 / 2
p)

    Qt library is used in the project. Containers from the Qt library are used
    when appropriate. No own solutions are used.

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (1 / 2p)

    The application does compile and start. The repository does not contain any
    instructions on how to use the application or test it. Thus, the robustness
    of the implementation can not be tested. Some validation is done on the
    input and exceptions are used.


## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (10 / 0-10p)

    The project plan lists a variety of features, including graphical user
    interface and various source and sink components. The planned features
    are extensive, and it seems that some have been implemented already.
