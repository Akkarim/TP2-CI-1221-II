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
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/ColadePrioridades/ColaPrioridades.o \
	${OBJECTDIR}/ConjuntodeConjuntos/CnjCnjs.o \
	${OBJECTDIR}/Diccionario/Diccionario.o \
	${OBJECTDIR}/Grafo/ListaAdyacencia.o \
	${OBJECTDIR}/Grafo/MatrizAdyacencia.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp2-ci-1221-ii.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp2-ci-1221-ii.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tp2-ci-1221-ii ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/ColadePrioridades/ColaPrioridades.o: ColadePrioridades/ColaPrioridades.cpp
	${MKDIR} -p ${OBJECTDIR}/ColadePrioridades
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ColadePrioridades/ColaPrioridades.o ColadePrioridades/ColaPrioridades.cpp

${OBJECTDIR}/ConjuntodeConjuntos/CnjCnjs.o: ConjuntodeConjuntos/CnjCnjs.cpp
	${MKDIR} -p ${OBJECTDIR}/ConjuntodeConjuntos
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ConjuntodeConjuntos/CnjCnjs.o ConjuntodeConjuntos/CnjCnjs.cpp

${OBJECTDIR}/Diccionario/Diccionario.o: Diccionario/Diccionario.cpp
	${MKDIR} -p ${OBJECTDIR}/Diccionario
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Diccionario/Diccionario.o Diccionario/Diccionario.cpp

${OBJECTDIR}/Grafo/ListaAdyacencia.o: Grafo/ListaAdyacencia.cpp
	${MKDIR} -p ${OBJECTDIR}/Grafo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grafo/ListaAdyacencia.o Grafo/ListaAdyacencia.cpp

${OBJECTDIR}/Grafo/MatrizAdyacencia.o: Grafo/MatrizAdyacencia.cpp
	${MKDIR} -p ${OBJECTDIR}/Grafo
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Grafo/MatrizAdyacencia.o Grafo/MatrizAdyacencia.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
