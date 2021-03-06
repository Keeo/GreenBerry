#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/883158912/ADrawable.o \
	${OBJECTDIR}/_ext/1211055809/Camera.o \
	${OBJECTDIR}/_ext/1211055809/DayNightControl.o \
	${OBJECTDIR}/_ext/1211055809/Game.o \
	${OBJECTDIR}/_ext/987268033/Entity.o \
	${OBJECTDIR}/_ext/987268033/EntityManager.o \
	${OBJECTDIR}/_ext/987268033/Model.o \
	${OBJECTDIR}/_ext/39249803/Chunk.o \
	${OBJECTDIR}/_ext/39249803/ChunkModel.o \
	${OBJECTDIR}/_ext/39249803/Cube.o \
	${OBJECTDIR}/_ext/39249803/Map.o \
	${OBJECTDIR}/_ext/39249803/World.o \
	${OBJECTDIR}/_ext/40178556/MapNoise.o \
	${OBJECTDIR}/_ext/40178556/SimplexNoise.o \
	${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o \
	${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o \
	${OBJECTDIR}/_ext/1941172064/Ddm.o \
	${OBJECTDIR}/_ext/1941172064/Helper.o \
	${OBJECTDIR}/_ext/1941172064/Log.o \
	${OBJECTDIR}/_ext/1941191171/Window.o \
	${OBJECTDIR}/_ext/939158570/Particle.o \
	${OBJECTDIR}/_ext/939158570/RainParticle.o \
	${OBJECTDIR}/_ext/939158570/SnowParticle.o \
	${OBJECTDIR}/_ext/939158570/WeatherManager.o \
	${OBJECTDIR}/src/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/Frameworks/SFML/lib -L/C/Frameworks/boost/lib -L/C/Frameworks/glew/glew-1.10.0/lib/Release/Win32 -L/C/Frameworks/assimp-src/build2/contrib/zlib -L/C/Program\ Files\ \(x86\)/Assimp/lib -lsfml-graphics-s-d -lsfml-window-s-d -lsfml-system-s-d -lsfml-audio-s-d -lsfml-main-d -lsfml-network-s-d -lboost_serialization-mgw47-mt-d-1_54 -lzlib -lassimp

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/greenberry.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/greenberry.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/greenberry ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/883158912/ADrawable.o: /D/_school/s5/BP/GreenBerry/src/abstract/ADrawable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/883158912
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/883158912/ADrawable.o /D/_school/s5/BP/GreenBerry/src/abstract/ADrawable.cpp

${OBJECTDIR}/_ext/1211055809/Camera.o: /D/_school/s5/BP/GreenBerry/src/control/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/Camera.o /D/_school/s5/BP/GreenBerry/src/control/Camera.cpp

${OBJECTDIR}/_ext/1211055809/DayNightControl.o: /D/_school/s5/BP/GreenBerry/src/control/DayNightControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/DayNightControl.o /D/_school/s5/BP/GreenBerry/src/control/DayNightControl.cpp

${OBJECTDIR}/_ext/1211055809/Game.o: /D/_school/s5/BP/GreenBerry/src/control/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/Game.o /D/_school/s5/BP/GreenBerry/src/control/Game.cpp

${OBJECTDIR}/_ext/987268033/Entity.o: /D/_school/s5/BP/GreenBerry/src/entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/Entity.o /D/_school/s5/BP/GreenBerry/src/entity/Entity.cpp

${OBJECTDIR}/_ext/987268033/EntityManager.o: /D/_school/s5/BP/GreenBerry/src/entity/EntityManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/EntityManager.o /D/_school/s5/BP/GreenBerry/src/entity/EntityManager.cpp

${OBJECTDIR}/_ext/987268033/Model.o: /D/_school/s5/BP/GreenBerry/src/entity/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/Model.o /D/_school/s5/BP/GreenBerry/src/entity/Model.cpp

${OBJECTDIR}/_ext/39249803/Chunk.o: /D/_school/s5/BP/GreenBerry/src/model/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Chunk.o /D/_school/s5/BP/GreenBerry/src/model/Chunk.cpp

${OBJECTDIR}/_ext/39249803/ChunkModel.o: /D/_school/s5/BP/GreenBerry/src/model/ChunkModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/ChunkModel.o /D/_school/s5/BP/GreenBerry/src/model/ChunkModel.cpp

${OBJECTDIR}/_ext/39249803/Cube.o: /D/_school/s5/BP/GreenBerry/src/model/Cube.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Cube.o /D/_school/s5/BP/GreenBerry/src/model/Cube.cpp

${OBJECTDIR}/_ext/39249803/Map.o: /D/_school/s5/BP/GreenBerry/src/model/Map.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Map.o /D/_school/s5/BP/GreenBerry/src/model/Map.cpp

${OBJECTDIR}/_ext/39249803/World.o: /D/_school/s5/BP/GreenBerry/src/model/World.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/World.o /D/_school/s5/BP/GreenBerry/src/model/World.cpp

${OBJECTDIR}/_ext/40178556/MapNoise.o: /D/_school/s5/BP/GreenBerry/src/noise/MapNoise.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/40178556
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/40178556/MapNoise.o /D/_school/s5/BP/GreenBerry/src/noise/MapNoise.cpp

${OBJECTDIR}/_ext/40178556/SimplexNoise.o: /D/_school/s5/BP/GreenBerry/src/noise/SimplexNoise.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/40178556
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/40178556/SimplexNoise.o /D/_school/s5/BP/GreenBerry/src/noise/SimplexNoise.cpp

${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o: /D/_school/s5/BP/GreenBerry/src/observer/EventMessagingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2027516724
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o /D/_school/s5/BP/GreenBerry/src/observer/EventMessagingSystem.cpp

${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o: /D/_school/s5/BP/GreenBerry/src/observer/IEventMessagingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2027516724
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o /D/_school/s5/BP/GreenBerry/src/observer/IEventMessagingSystem.cpp

${OBJECTDIR}/_ext/1941172064/Ddm.o: /D/_school/s5/BP/GreenBerry/src/util/Ddm.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Ddm.o /D/_school/s5/BP/GreenBerry/src/util/Ddm.cpp

${OBJECTDIR}/_ext/1941172064/Helper.o: /D/_school/s5/BP/GreenBerry/src/util/Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Helper.o /D/_school/s5/BP/GreenBerry/src/util/Helper.cpp

${OBJECTDIR}/_ext/1941172064/Log.o: /D/_school/s5/BP/GreenBerry/src/util/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Log.o /D/_school/s5/BP/GreenBerry/src/util/Log.cpp

${OBJECTDIR}/_ext/1941191171/Window.o: /D/_school/s5/BP/GreenBerry/src/view/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941191171
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941191171/Window.o /D/_school/s5/BP/GreenBerry/src/view/Window.cpp

${OBJECTDIR}/_ext/939158570/Particle.o: /D/_school/s5/BP/GreenBerry/src/weather/Particle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/Particle.o /D/_school/s5/BP/GreenBerry/src/weather/Particle.cpp

${OBJECTDIR}/_ext/939158570/RainParticle.o: /D/_school/s5/BP/GreenBerry/src/weather/RainParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/RainParticle.o /D/_school/s5/BP/GreenBerry/src/weather/RainParticle.cpp

${OBJECTDIR}/_ext/939158570/SnowParticle.o: /D/_school/s5/BP/GreenBerry/src/weather/SnowParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/SnowParticle.o /D/_school/s5/BP/GreenBerry/src/weather/SnowParticle.cpp

${OBJECTDIR}/_ext/939158570/WeatherManager.o: /D/_school/s5/BP/GreenBerry/src/weather/WeatherManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/WeatherManager.o /D/_school/s5/BP/GreenBerry/src/weather/WeatherManager.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f3: ${TESTDIR}/_ext/1262165778/TestBoostSerializeClass.o ${TESTDIR}/_ext/1262165778/TestBoostSerializeTrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} /C/MinGW/lib/libcppunit.a `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/_ext/1262165778/testChunkClass.o ${TESTDIR}/_ext/1262165778/testChunkRunner1.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} /C/MinGW/lib/libcppunit.a `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/_ext/1262165778/newtestclass.o ${TESTDIR}/_ext/1262165778/newtestrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} /C/MinGW/lib/libcppunit.a `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/_ext/1262165778/TestMapNoiseClass.o ${TESTDIR}/_ext/1262165778/TestMapNoiseTtrunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} /C/MinGW/lib/libcppunit.a `cppunit-config --libs`   


${TESTDIR}/_ext/1262165778/TestBoostSerializeClass.o: /D/_school/s5/BP/GreenBerry/tests/TestBoostSerializeClass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/TestBoostSerializeClass.o /D/_school/s5/BP/GreenBerry/tests/TestBoostSerializeClass.cpp


${TESTDIR}/_ext/1262165778/TestBoostSerializeTrunner.o: /D/_school/s5/BP/GreenBerry/tests/TestBoostSerializeTrunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/TestBoostSerializeTrunner.o /D/_school/s5/BP/GreenBerry/tests/TestBoostSerializeTrunner.cpp


${TESTDIR}/_ext/1262165778/testChunkClass.o: /D/_school/s5/BP/GreenBerry/tests/testChunkClass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/testChunkClass.o /D/_school/s5/BP/GreenBerry/tests/testChunkClass.cpp


${TESTDIR}/_ext/1262165778/testChunkRunner1.o: /D/_school/s5/BP/GreenBerry/tests/testChunkRunner1.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/testChunkRunner1.o /D/_school/s5/BP/GreenBerry/tests/testChunkRunner1.cpp


${TESTDIR}/_ext/1262165778/newtestclass.o: /D/_school/s5/BP/GreenBerry/tests/newtestclass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/newtestclass.o /D/_school/s5/BP/GreenBerry/tests/newtestclass.cpp


${TESTDIR}/_ext/1262165778/newtestrunner.o: /D/_school/s5/BP/GreenBerry/tests/newtestrunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/newtestrunner.o /D/_school/s5/BP/GreenBerry/tests/newtestrunner.cpp


${TESTDIR}/_ext/1262165778/TestMapNoiseClass.o: /D/_school/s5/BP/GreenBerry/tests/TestMapNoiseClass.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/TestMapNoiseClass.o /D/_school/s5/BP/GreenBerry/tests/TestMapNoiseClass.cpp


${TESTDIR}/_ext/1262165778/TestMapNoiseTtrunner.o: /D/_school/s5/BP/GreenBerry/tests/TestMapNoiseTtrunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1262165778
	${RM} "$@.d"
	$(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -I/C/MinGW/msys/1.0/local/include -std=c++11 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/_ext/1262165778/TestMapNoiseTtrunner.o /D/_school/s5/BP/GreenBerry/tests/TestMapNoiseTtrunner.cpp


${OBJECTDIR}/_ext/883158912/ADrawable_nomain.o: ${OBJECTDIR}/_ext/883158912/ADrawable.o /D/_school/s5/BP/GreenBerry/src/abstract/ADrawable.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/883158912
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/883158912/ADrawable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/883158912/ADrawable_nomain.o /D/_school/s5/BP/GreenBerry/src/abstract/ADrawable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/883158912/ADrawable.o ${OBJECTDIR}/_ext/883158912/ADrawable_nomain.o;\
	fi

${OBJECTDIR}/_ext/1211055809/Camera_nomain.o: ${OBJECTDIR}/_ext/1211055809/Camera.o /D/_school/s5/BP/GreenBerry/src/control/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1211055809/Camera.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/Camera_nomain.o /D/_school/s5/BP/GreenBerry/src/control/Camera.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1211055809/Camera.o ${OBJECTDIR}/_ext/1211055809/Camera_nomain.o;\
	fi

${OBJECTDIR}/_ext/1211055809/DayNightControl_nomain.o: ${OBJECTDIR}/_ext/1211055809/DayNightControl.o /D/_school/s5/BP/GreenBerry/src/control/DayNightControl.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1211055809/DayNightControl.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/DayNightControl_nomain.o /D/_school/s5/BP/GreenBerry/src/control/DayNightControl.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1211055809/DayNightControl.o ${OBJECTDIR}/_ext/1211055809/DayNightControl_nomain.o;\
	fi

${OBJECTDIR}/_ext/1211055809/Game_nomain.o: ${OBJECTDIR}/_ext/1211055809/Game.o /D/_school/s5/BP/GreenBerry/src/control/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1211055809
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1211055809/Game.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1211055809/Game_nomain.o /D/_school/s5/BP/GreenBerry/src/control/Game.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1211055809/Game.o ${OBJECTDIR}/_ext/1211055809/Game_nomain.o;\
	fi

${OBJECTDIR}/_ext/987268033/Entity_nomain.o: ${OBJECTDIR}/_ext/987268033/Entity.o /D/_school/s5/BP/GreenBerry/src/entity/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/987268033/Entity.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/Entity_nomain.o /D/_school/s5/BP/GreenBerry/src/entity/Entity.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/987268033/Entity.o ${OBJECTDIR}/_ext/987268033/Entity_nomain.o;\
	fi

${OBJECTDIR}/_ext/987268033/EntityManager_nomain.o: ${OBJECTDIR}/_ext/987268033/EntityManager.o /D/_school/s5/BP/GreenBerry/src/entity/EntityManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/987268033/EntityManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/EntityManager_nomain.o /D/_school/s5/BP/GreenBerry/src/entity/EntityManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/987268033/EntityManager.o ${OBJECTDIR}/_ext/987268033/EntityManager_nomain.o;\
	fi

${OBJECTDIR}/_ext/987268033/Model_nomain.o: ${OBJECTDIR}/_ext/987268033/Model.o /D/_school/s5/BP/GreenBerry/src/entity/Model.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/987268033
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/987268033/Model.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/987268033/Model_nomain.o /D/_school/s5/BP/GreenBerry/src/entity/Model.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/987268033/Model.o ${OBJECTDIR}/_ext/987268033/Model_nomain.o;\
	fi

${OBJECTDIR}/_ext/39249803/Chunk_nomain.o: ${OBJECTDIR}/_ext/39249803/Chunk.o /D/_school/s5/BP/GreenBerry/src/model/Chunk.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/39249803/Chunk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Chunk_nomain.o /D/_school/s5/BP/GreenBerry/src/model/Chunk.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/39249803/Chunk.o ${OBJECTDIR}/_ext/39249803/Chunk_nomain.o;\
	fi

${OBJECTDIR}/_ext/39249803/ChunkModel_nomain.o: ${OBJECTDIR}/_ext/39249803/ChunkModel.o /D/_school/s5/BP/GreenBerry/src/model/ChunkModel.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/39249803/ChunkModel.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/ChunkModel_nomain.o /D/_school/s5/BP/GreenBerry/src/model/ChunkModel.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/39249803/ChunkModel.o ${OBJECTDIR}/_ext/39249803/ChunkModel_nomain.o;\
	fi

${OBJECTDIR}/_ext/39249803/Cube_nomain.o: ${OBJECTDIR}/_ext/39249803/Cube.o /D/_school/s5/BP/GreenBerry/src/model/Cube.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/39249803/Cube.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Cube_nomain.o /D/_school/s5/BP/GreenBerry/src/model/Cube.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/39249803/Cube.o ${OBJECTDIR}/_ext/39249803/Cube_nomain.o;\
	fi

${OBJECTDIR}/_ext/39249803/Map_nomain.o: ${OBJECTDIR}/_ext/39249803/Map.o /D/_school/s5/BP/GreenBerry/src/model/Map.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/39249803/Map.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/Map_nomain.o /D/_school/s5/BP/GreenBerry/src/model/Map.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/39249803/Map.o ${OBJECTDIR}/_ext/39249803/Map_nomain.o;\
	fi

${OBJECTDIR}/_ext/39249803/World_nomain.o: ${OBJECTDIR}/_ext/39249803/World.o /D/_school/s5/BP/GreenBerry/src/model/World.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/39249803
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/39249803/World.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/39249803/World_nomain.o /D/_school/s5/BP/GreenBerry/src/model/World.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/39249803/World.o ${OBJECTDIR}/_ext/39249803/World_nomain.o;\
	fi

${OBJECTDIR}/_ext/40178556/MapNoise_nomain.o: ${OBJECTDIR}/_ext/40178556/MapNoise.o /D/_school/s5/BP/GreenBerry/src/noise/MapNoise.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/40178556
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/40178556/MapNoise.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/40178556/MapNoise_nomain.o /D/_school/s5/BP/GreenBerry/src/noise/MapNoise.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/40178556/MapNoise.o ${OBJECTDIR}/_ext/40178556/MapNoise_nomain.o;\
	fi

${OBJECTDIR}/_ext/40178556/SimplexNoise_nomain.o: ${OBJECTDIR}/_ext/40178556/SimplexNoise.o /D/_school/s5/BP/GreenBerry/src/noise/SimplexNoise.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/40178556
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/40178556/SimplexNoise.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/40178556/SimplexNoise_nomain.o /D/_school/s5/BP/GreenBerry/src/noise/SimplexNoise.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/40178556/SimplexNoise.o ${OBJECTDIR}/_ext/40178556/SimplexNoise_nomain.o;\
	fi

${OBJECTDIR}/_ext/2027516724/EventMessagingSystem_nomain.o: ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o /D/_school/s5/BP/GreenBerry/src/observer/EventMessagingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2027516724
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem_nomain.o /D/_school/s5/BP/GreenBerry/src/observer/EventMessagingSystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem.o ${OBJECTDIR}/_ext/2027516724/EventMessagingSystem_nomain.o;\
	fi

${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem_nomain.o: ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o /D/_school/s5/BP/GreenBerry/src/observer/IEventMessagingSystem.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/2027516724
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem_nomain.o /D/_school/s5/BP/GreenBerry/src/observer/IEventMessagingSystem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem.o ${OBJECTDIR}/_ext/2027516724/IEventMessagingSystem_nomain.o;\
	fi

${OBJECTDIR}/_ext/1941172064/Ddm_nomain.o: ${OBJECTDIR}/_ext/1941172064/Ddm.o /D/_school/s5/BP/GreenBerry/src/util/Ddm.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1941172064/Ddm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Ddm_nomain.o /D/_school/s5/BP/GreenBerry/src/util/Ddm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1941172064/Ddm.o ${OBJECTDIR}/_ext/1941172064/Ddm_nomain.o;\
	fi

${OBJECTDIR}/_ext/1941172064/Helper_nomain.o: ${OBJECTDIR}/_ext/1941172064/Helper.o /D/_school/s5/BP/GreenBerry/src/util/Helper.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1941172064/Helper.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Helper_nomain.o /D/_school/s5/BP/GreenBerry/src/util/Helper.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1941172064/Helper.o ${OBJECTDIR}/_ext/1941172064/Helper_nomain.o;\
	fi

${OBJECTDIR}/_ext/1941172064/Log_nomain.o: ${OBJECTDIR}/_ext/1941172064/Log.o /D/_school/s5/BP/GreenBerry/src/util/Log.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941172064
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1941172064/Log.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941172064/Log_nomain.o /D/_school/s5/BP/GreenBerry/src/util/Log.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1941172064/Log.o ${OBJECTDIR}/_ext/1941172064/Log_nomain.o;\
	fi

${OBJECTDIR}/_ext/1941191171/Window_nomain.o: ${OBJECTDIR}/_ext/1941191171/Window.o /D/_school/s5/BP/GreenBerry/src/view/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1941191171
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1941191171/Window.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1941191171/Window_nomain.o /D/_school/s5/BP/GreenBerry/src/view/Window.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1941191171/Window.o ${OBJECTDIR}/_ext/1941191171/Window_nomain.o;\
	fi

${OBJECTDIR}/_ext/939158570/Particle_nomain.o: ${OBJECTDIR}/_ext/939158570/Particle.o /D/_school/s5/BP/GreenBerry/src/weather/Particle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/939158570/Particle.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/Particle_nomain.o /D/_school/s5/BP/GreenBerry/src/weather/Particle.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/939158570/Particle.o ${OBJECTDIR}/_ext/939158570/Particle_nomain.o;\
	fi

${OBJECTDIR}/_ext/939158570/RainParticle_nomain.o: ${OBJECTDIR}/_ext/939158570/RainParticle.o /D/_school/s5/BP/GreenBerry/src/weather/RainParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/939158570/RainParticle.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/RainParticle_nomain.o /D/_school/s5/BP/GreenBerry/src/weather/RainParticle.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/939158570/RainParticle.o ${OBJECTDIR}/_ext/939158570/RainParticle_nomain.o;\
	fi

${OBJECTDIR}/_ext/939158570/SnowParticle_nomain.o: ${OBJECTDIR}/_ext/939158570/SnowParticle.o /D/_school/s5/BP/GreenBerry/src/weather/SnowParticle.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/939158570/SnowParticle.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/SnowParticle_nomain.o /D/_school/s5/BP/GreenBerry/src/weather/SnowParticle.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/939158570/SnowParticle.o ${OBJECTDIR}/_ext/939158570/SnowParticle_nomain.o;\
	fi

${OBJECTDIR}/_ext/939158570/WeatherManager_nomain.o: ${OBJECTDIR}/_ext/939158570/WeatherManager.o /D/_school/s5/BP/GreenBerry/src/weather/WeatherManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/939158570
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/939158570/WeatherManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/939158570/WeatherManager_nomain.o /D/_school/s5/BP/GreenBerry/src/weather/WeatherManager.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/939158570/WeatherManager.o ${OBJECTDIR}/_ext/939158570/WeatherManager_nomain.o;\
	fi

${OBJECTDIR}/src/main_nomain.o: ${OBJECTDIR}/src/main.o src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -g -DENABLE_BOOST_WORKAROUND -DGLEW_STATIC -DSFML_STATIC -I/C/Frameworks/SFML/include -I/C/Frameworks/boost/include/boost-1_54 -I/C/Frameworks/glm -I/C/Program\ Files\ \(x86\)/Assimp/include -std=c++11 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main_nomain.o src/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/main.o ${OBJECTDIR}/src/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/greenberry.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
